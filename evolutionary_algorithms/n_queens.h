#ifndef _N_QUEENS_H_
#define _N_QUEENS_H_

#define GENE_SIZE			8
#define POPULATION_SIZE 	10
#define SUB_POPULATION_SIZE 5
#define MAX_STEPS			10000
#define MUTATION_PROBABILTY	70

typedef struct individual
{
	char genes[GENE_SIZE];
	int  fitness;
	int  generation;
	int  p1_gen;
	int  p2_gen;
	int  mutated;
} ind;

int initialize_population();
int initialize_genes(char* g);
int cross_over();
int mutate(ind* i);
int sort_population(ind** p, int size);
int choose_subpopulation();
int calculate_fitness(ind* i);
int randomize_array(char* a);
int exist_in_array(char *a, char c);
int print_individual(ind* i);

#endif /* _N_QUEENS_H_ */