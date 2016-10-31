#include <stdio.h>

#define WHITE 0
#define GRAY  1
#define BLACK 2

#define N 6

int DFS(int s);
int dfs_visit(int u);
int print_step();

int adj[N][N] = {
                    {1,1,1,1,1,1},
                    {1,1,1,1,1,1},
                    {1,1,1,1,1,1},
                    {1,1,1,1,1,1},
                    {1,1,1,1,1,1}
                };

int d[N];
int f[N];
int pred[N];
int colour[N];
int time;

int main()
{
    DFS(2);
    
    print_step();
    return 0;
}

int DFS(int s)
{
    int i;
    
    for (i=0; i<N; i++)
    {
        colour[i] = WHITE;
        pred[i]   = -1;
    }
    
    time = 0;

    for(i=0; i<N; i++)
    {   
        if((adj[s][i] == 1) && (colour[i] == WHITE))
        {
            dfs_visit(i);
        }
    }

    return 0;
}

int dfs_visit(int u)
{
    int i;

    printf("\nVisiting node %d", u);
    print_step();

    colour[u] = GRAY;
    time++;

    d[u] = time;

    for(i=0; i<N; i++)
    {   
        if((adj[u][i] == 1) && (colour[i] == WHITE))
        {
            pred[i] = u;
            dfs_visit(i);
        }
    }

    colour[u] = BLACK;
    time++;
    f[u] = time;

    return 0;
}

int print_step()
{
    int i;
    
    printf("\n\ncolours: ");
    for(i=0; i<N; i++)
    {
        printf("%3d ", colour[i]);
    }    

    printf("\nd:       ");
    for(i=0; i<N; i++)
    {
        printf("%3d ", d[i]);
    }    

    printf("\nf:       ");
    for(i=0; i<N; i++)
    {
        printf("%3d ", f[i]);
    }    

    printf("\npred:    ");
    for(i=0; i<N; i++)
    {
        printf("%3d ", pred[i]);
    }

    printf("\n");

    return 0;
}