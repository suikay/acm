#include <stdio.h>
#include <string.h>

bool less[26][26], less_b[26][26];
int cnt[26], cnt_b[26];

int is_topo()
{
}

int main()
{
    int n, m;
    char x, y, foo;
    int fault, right, add, add_should_be;

    while (scanf("%d%d", &n, &m) && n)
    {
        foo = getchar();
        memset(less, 0, sizeof(less));
        memset(cnt, 0, sizeof(cnt));
        fault = right = add = 0;
        add_should_be = n*(n-1)/2;
        for (int i = 0; i < m; ++i)
        {
            scanf("%c%c%c", &x, &foo, &y);
            scanf("%c", &foo);
            x -= 'A'; 
            y -= 'A';
            if (less[y][x])
                fault = i+1;
            if (less[x][y])
                continue;
            less[x][y] = true;
            cnt[y]++;
            add++;
            for (int j = 0; j < m; ++j)
            {
                if (less[y][j])
                {
                    if(!less[x][j])
                    {
                        less[x][j] = true;
                        cnt[j]++;
                        add++;
                    }
                    if (less[j][x])
                    {
                        fault = i+1;
                    }
                }
                if (less[j][x])
                {
                    if (!less[j][y])
                    {
                        less[j][y] = true;
                        cnt[y]++;
                        add++;
                    }
                    if (less[y][j])
                    {
                        fault = i+1;
                    }
                }
            }
            if (add == add_should_be)
                right = i+1;
        }
        if (fault)
        {
            printf("Inconsistency found after %d relations.\n",
                    fault);
            continue;
        }
        if (!right)
        {
            printf("Sorted sequence cannot be determined.\n");
            continue;
        }
        printf("Sorted sequence determined after %d relations: ", right);
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; k++)
                if (cnt[k] == j)
                    printf("%c", 'A'+k);
        puts("");
    }

    return 0;
}
