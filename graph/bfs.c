#include <stdio.h>
#include <string.h>

#define N 6

#define WHITE 0
#define GRAY  1
#define BLACK 2

int init_queue();
int enqueue(int i);
int dequeue();
int is_queue_empty();
int BFS(int s);
int print_step();

int adj[N][N] = {
                    {1,1,1,1,1,1},
                    {1,1,1,1,1,1},
                    {1,1,1,1,1,1},
                    {1,1,1,1,1,1},
                    {1,1,1,1,1,1}
                };
int q[N];
int f,r;

int colour[N];
int dist[N];
int pred[N];


int main()
{
    init_queue();
    BFS(2);
    
    print_step();
    return 0;
}

int BFS(int s)
{
    int i;
    int u;
    
    for (i=0; i<N; i++)
    {
        colour[i] = WHITE;
        dist[i]   = -1;
        pred[i]   = -1; 
    }
    
    colour[s] = GRAY;
    dist[s] = 0;
    pred[s] = -1;
    
    enqueue(s);
    
    while(!is_queue_empty())
    {
        print_step();
        
        u = dequeue();
        for(i=0; i<N; i++)
        {   
            if((adj[s][i] == 1) && (colour[i] == WHITE))
            {
                printf("\nprocessing node %d\n", i);
                
                colour[i] = GRAY;
                dist[i] = dist[u] + 1;
                pred[i] = u;
                
                enqueue(i);    
            }
        }
        
        colour[u] = BLACK;
    }
    
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

    printf("\ndist:    ");
    for(i=0; i<N; i++)
    {
        printf("%3d ", dist[i]);
    }    

    printf("\npred:    ");
    for(i=0; i<N; i++)
    {
        printf("%3d ", pred[i]);
    }    

    printf("\n");

    return 0;
}

int init_queue()
{
    memset(q, 0, sizeof(int)*N);
    f = 0;
    r = 0;

    return 0;
}

int enqueue(int i)
{
    q[r++] = i;

    return i;
}

int dequeue()
{
    return q[f++];
}

int is_queue_empty()
{
    return r==f;    
}
