/*
	Ali Boyaci - Algorithms

	N Queens with evolutionary algorithm

	Representation: permutations
	Recombination:	cut and cross fill
	Recombination probability: 100%
	Mutation: swap
	Mutation probality: 70%
	Parent selection: best 2 out of random 5
	Survival selection: replace worst
	Population size: 100
	Number of offsprings: 1
	Initialization: random
	Terminal Condition: Solution or 10,000 fitness evoluation
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "n_queens.h"

ind* population[POPULATION_SIZE];
ind* sub_population[SUB_POPULATION_SIZE]; /* for parent selection */

int initialize_population()
{
	int i;

	for (i=0; i< POPULATION_SIZE; i++)
	{
		population[i] = malloc(sizeof(ind));
		memset(population[i], 0, sizeof(ind));
		
		initialize_genes(population[i]->genes);
		
		randomize_array(population[i]->genes);

		population[i]->generation = 1;
		
		population[i]->fitness = calculate_fitness(population[i]);
	}
	
	return 0;
}

int initialize_genes(char* g)
{
	int i;

	for(i=0; i<GENE_SIZE; i++)
	{
		g[i] = i + 1; /* skip 0 */
	}

	return 0;
}

int cross_over(ind* p1, ind* p2, ind* offspring)
{
	int i, j;
	int r = (rand() % (GENE_SIZE - 1)) + 1; /* dont allow 0 or GENE_SIZE */

	memset(offspring, 0, sizeof(ind));

	offspring->p1_gen = p1->generation;
	offspring->p2_gen = p2->generation;

	/* copy first part */
	for(i=0; i<r; i++)
	{
		offspring->genes[i] = p1->genes[i];
	}

	/* copy second part */
	j = r;
	for(i=r; i<GENE_SIZE;)
	{
		/* skip existing elements */
		if(!exist_in_array(offspring->genes, p2->genes[j]))
		{
			offspring->genes[i] = p2->genes[j];
			i++;
		}

		j = (j + 1) % GENE_SIZE; /* start from beginning if necessary */
	}
	
	offspring->fitness = calculate_fitness(offspring);

	return 0;
}

int mutate(ind* i)
{
	int r1 = rand() % GENE_SIZE;
	int	r2 = rand() % GENE_SIZE;
	int tmp;

	i->mutated = 1;

	tmp = i->genes[r1];
	i->genes[r1] = i->genes[r2];
	i->genes[r2] = tmp;

	return 0;
}

int sort_population(ind** p, int size)
{
	int i, j;
	ind* tmp;

	/* insertion sort */
	for(i=1; i<size; i++)
	{
		j = i-1;
		tmp = p[i];

		while(j>=0 && p[i]->fitness < p[j]->fitness)
		{
			p[j+1] = p[j];
			j--;	
		}

		p[j+1] = tmp;
	}

	return 0;
}



int choose_subpopulation()
{
	int i, j, found;
	int r;

	memset(sub_population, 0, SUB_POPULATION_SIZE*sizeof(ind*));

	for(i=0; i<SUB_POPULATION_SIZE;)
	{
		found = 0;

		r = rand() % POPULATION_SIZE;

		/* dont get the same parents twice */
		for (j=0; j<i; j++)
		{
			if (population[r] == sub_population[j])
			{
				found = 1;
				break;
			}
		}

		if (!found)
		{
			sub_population[i] = population[r];
			i++;
		}
	}

	sort_population(sub_population, SUB_POPULATION_SIZE);

	return 0;
}

int calculate_fitness(ind* p)
{
	int i, j, col_diff, row_diff;
	int score = 0;

	/* 
		due to configuration queens are guaranteed not to check 
		for rows and columns, only possibility is diagonal
		when a queen checks we increase the score.
		lower is better!!!
	*/

	for(i=0; i<GENE_SIZE; i++)
	{
		for(j=0; j<GENE_SIZE; j++)
		{
			if (i==j)
				continue; /* dont check with same queen */				

			/*
				if the absolute difference in row id and column id is same, 
				the queens are on the same diagonal line
			*/
			row_diff = i-j;
			col_diff = p->genes[i] - p->genes[j];
			if (row_diff == col_diff || row_diff == col_diff * -1) /* multiply with -1 to check negative results */
				score++;
		}
	}

	p->fitness = score;

	return score;
}

int randomize_array(char* a)
{
	int i, r1, r2;
	char tmp;

	for(i=0; i<100; i++)
	{
		r1 = rand() % GENE_SIZE;
		r2 = rand() % GENE_SIZE;

		tmp = a[r1];
		a[r1] = a[r2];
		a[r2] = tmp;
	}

	return 0;
}

int exist_in_array(char *a, char c)
{
	int i;

	for(i=0; i<GENE_SIZE; i++)
	{
		if (c == a[i])
			return 1;
	}

	return 0;
}

int print_individual(ind* p)
{
	int i,j;

	printf("individual generation %d\n", p->generation);
	printf("Fitness: %d\n", p->fitness);
	printf("Parents: %d, %d\n", p->p1_gen, p->p2_gen);
	printf("Mutated: %d\n", p->mutated);
	printf("Individual genes: ");

	for(i=0; i<GENE_SIZE; i++)
	{
		printf("%d ", p->genes[i]);
	}
	printf("\n");

	for (i=0; i<GENE_SIZE; i++)
	{
		for (j=0; j<GENE_SIZE; j++)
		{
			if (p->genes[j] == i + 1)
				printf(" Q ");
			else
				printf(" _ ");
		}
		printf("\n");
	}

	return 0;
}

int main(void)
{
	int i;
	ind child;

	srand(time(NULL));

	initialize_population();

	sort_population(population, POPULATION_SIZE);

	for(i=0; i<MAX_STEPS && population[0]->fitness != 0; i++)
	{
		/* chose 5 random potantial parents */
		choose_subpopulation();

		cross_over(sub_population[0], sub_population[1], &child);
		child.generation = i;

		if ((rand() % 100) < MUTATION_PROBABILTY)
			mutate(&child);

		child.fitness = calculate_fitness(&child);

		/* replace new child with the worst */
		memcpy(population[POPULATION_SIZE-1], &child, sizeof(ind));

		/* rearrange population so the best/worst can be found in one step */
		sort_population(population, POPULATION_SIZE);
	}

	printf("############ Result ############\n");

	print_individual(population[0]);

	return EXIT_SUCCESS;
}