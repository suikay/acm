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
    int i, j, left = 0;
    for (i = 1; i < sz; ++i)
        if (sum[i] >= x)
            break;
    --i;
    x -= sum[i];
    for (j = 0; j <= i; ++j)
    {
        if (x > arr[j]*arr[i-j])
        {
            x -= arr[j]*arr[i-j];
            continue;
        }
        if (j) {
            printf("(");
            go(sum[j-1]+1+(x-1)/arr[i-j]);
            printf(")");
        }
        printf("X");
        if (j < i) {
            printf("(");
            go(sum[i-1-j]+1+(x-1)%arr[i-j]);
            printf(")");
        }
        return 0;
    }
    printf("(");
    go(j*arr[0]);
    printf(")");
    printf("X");

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
