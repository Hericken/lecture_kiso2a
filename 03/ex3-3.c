#include <stdio.h>
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
    int i, j, n, x, visit[N], cost[N][N], reach_cost[N] = {0};

    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) {
            if (!w[i][j]) x = 0;
            else {
                printf("%c - %c間のコスト > ", V[i], V[j]);
                scanf("%d", &x);
            }
            cost[i][j] = cost[j][j] = x;
        }
    }

    printf("/*** (112項)chap-6-4-2グラフの探索(幅優先) ***\n");
    queuehead = queuetail = 0;
    for (i = 0; i < N; i++) visit[i] = 0;
    visit[start] = 1;
    Enqueue(start);
    while (queuehead != queuetail) {
        for (i = 0; i < N; i++) {
            if (!visit[i]) break;
        }
        if (i == N) {
            printf("point cost\n");
            for (i = 0; i < N; i++)
                printf("%5c %4d\n", V[i], reach_cost[i]);
            return 0;
        }
        n = Dequeue();
        for (i = 0; i < N; i++)
            if (!visit[i] && w[n][i]) {
                visit[i] = 1;
                reach_cost[i] = reach_cost[n] + cost[n][i];
                Enqueue(i);
            }
    }
    printf("\n*/\n");
}

