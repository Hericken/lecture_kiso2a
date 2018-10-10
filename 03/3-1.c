#include <stdio.h>
#include "../PLIB.h"

int main(void)
{
    int ope, x, dq;

    queuehead = 0;
    queuetail = 0;

    do {
        printf("エンキュー:0 デキュー:1 終了:2 >");
        scanf("%d", &ope);
        if (ope == 0) {
            printf("整数値のデータ> ");
            scanf("%d", &x);
            Enqueue(x);
        } else if (ope == 1) {
            dq = Dequeue();
            if (dq != -1) printf("out %d\n", dq);
        }
    } while (ope != 2);

    return 0;
}
