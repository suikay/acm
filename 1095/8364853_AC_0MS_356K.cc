#include <stdio.h>
const int sz = 20;
int arr[sz], sum[sz];

int go(int x)
{
    if (x == 1)
    {
        putchar('X');
        return 0;
    }
    int i, j = 0;

    // 找到节点数
    for (i = 1; i < sz; ++i)
        if (sum[i] >= x)
            break;
    x -= sum[i-1]; // 将要得到的树是所有节点数为i的第x棵树
    // 得到左右节点总和
    --i;

    // 将树分为左右子树
    // 遍历左子树的节点数
    for (j = 0; j <= i; ++j)
    {
        // 左子树节点数为j时

        if (x > arr[j]*arr[i-j])
        {
            // 仍左子树节点数为j的最大序号仍然比x小
            x -= arr[j]*arr[i-j];
            continue;
        }

        // 确定左子树的节点数为j
        if (j) {
            printf("(");
            // 左子树的偏移量：
            // 节点数小于j的树的总和 + 1(基本偏移量) + "右子树的进位"
            go(sum[j-1]+1+(x-1)/arr[i-j]);
            printf(")");
        }
        printf("X");
        if (j < i) {
            printf("(");
            // 右子树的偏移量：
            // 节点数小于(i-j)的树的总和 + 1(基本偏移量) + "进位后右子树的剩余偏移"
            go(sum[i-1-j]+1+(x-1)%arr[i-j]);
            printf(")");
        }
        return 0;
    }

    return 1;
}

int main()
{
    int k, n;
    arr[0] = arr[1] = 1;
    sum[1] = 1;
    for (int i = 2; i < sz; ++i)
    {
        k = i-1;
        for (int j = 0; j <= k; ++j)
            arr[i] += arr[j]*arr[k-j];
        sum[i] = sum[i-1] + arr[i];
    }
    while (scanf("%d", &n) && n)
    {
        go(n);
        puts("");
    }

    return 0;
}
