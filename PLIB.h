#include <stdio.h>

void printsort(int *data, int n, int k) {
    int i;
    printf("\n%2d回目のスキャン結果:", k);
    for (i = 0; i < n; i++) printf("%d ", data[i]);
}

void printheap(int *heap, int n)
{
    int i;

    printf("heap(n=%02d):", n);
    for (i = 1; i <= n; i++) printf("%2d ", heap[i]);
    printf("\n");
}

#define Q_SIZE 10000
static int queue[Q_SIZE];
static int queuehead;
static int queuetail;

void Enqueue(int x)
{
    queuetail = (queuetail + 1) % Q_SIZE;
    printf("Enqueue:%d(queuehead = %d, queuetail = %d)\n", x, queuehead, queuetail);
    queue[queuetail] = x;
    if (queuehead == queuetail) {
        printf("Error: Overflow\n");
        return;
    }
}

int Dequeue()
{
    if (queuehead == queuetail) {
        printf("Error: Underflow\n");
        return -1;
    }
    queuehead = (queuehead + 1) % Q_SIZE;
    return queue[queuehead];
}
