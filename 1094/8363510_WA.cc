#include <stdio.h>
#include <string.h>

bool less[26][26], less_b[26][26];
int cnt[26], cnt_b[26];

int n, m;
int is_topo()
{
    memcpy(less_b, less, sizeof(less));
    memcpy(cnt_b, cnt, sizeof(cnt));
    int good = 0, multi = 0, v;
    int i;
    for (i = 0; i < n; i++)
    {
        v = -1;
        for (int j = 0; j < n; j++)
            if (cnt_b[j] == 0) 
            {
                if (v != -1)
                {
                    multi = 1;
                    continue;
                }
                v = j;
            }
        if (v == -1)
            break;
        for (int k = 0; k < n; k++)
            if (less_b[v][k])
                cnt_b[k]--;
        cnt_b[v]--;
    }
    if (i < n)
        return 1;
    return 2*multi;
}

int main()
{
    char x, y, foo;
    int fault, right, tmp;

    while (scanf("%d%d", &n, &m) && n)
    {
        foo = getchar();
        memset(less, 0, sizeof(less));
        memset(cnt, 0, sizeof(cnt));
        fault = right = 0;
        for (int i = 0; i < m; ++i)
        {
            scanf("%c%c%c", &x, &foo, &y);
            scanf("%c", &foo);
            if (fault)
                continue;
            x -= 'A'; 
            y -= 'A';
            if (less[x][y])
                continue;
            less[x][y] = true;
            cnt[y]++;
            tmp = is_topo();
            switch (tmp)
            {
                case 0:
                    if (!right) right = i+1;
                    break;
                case 1:
                    if (!fault) fault = i+1;
                    break;
            }
        }
        if (fault && (!right || right > fault))
        {
            printf("Inconsistency found after %d relations.\n", fault);
            continue;
        }
        if (right)
        {
            printf("Sorted sequence determined after %d relations: ", right);
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; k++)
                    if (cnt[k] == j)
                        printf("%c", 'A'+k);
            puts(".");
            continue;
        }
        printf("Sorted sequence cannot be determined.\n");
    }

    return 0;
}
