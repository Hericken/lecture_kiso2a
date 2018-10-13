#include <stdio.h>
#include <malloc.h>
#include "../PLIB.h"
#define N 6
static int w[N][N] =
    {{0,1,0,1,1,0},
     {1,0,1,0,1,0},
     {0,1,0,0,1,0},
     {1,0,0,0,1,1},
     {1,1,1,1,0,1},
     {0,0,0,1,1,0}};
static char V[N+1] = "S12345";
static int start = 0;
static int end = 5;

int main(void)
{
    int i, n, visit[N];

    printf("/*** (112項)chap-6-4-2グラフの探索(幅優先) ***\n");
    queuehead = queuetail = 0;

    for (i = 0; i < N; i++) visit[i] = 0;
    
    visit[start] = 1;
    Enqueue(start);
    while (queuehead != queuetail) {
        n = Dequeue();
        printf("%c\n", V[n]);
        printf("Visit: %c(%d)\n", V[n], n);
        if (end == n) {
            printf("*** solved *** Goal = %c(%d)\n*/\n", V[n], n);
            return 0;
        } else {
            for (i = 0; i < N; i++)
                if (!visit[i] && w[n][i]) {
                    visit[i] = 1;
                    Enqueue(i);
                }
        }
    }
    printf("\n*/\n");
}

