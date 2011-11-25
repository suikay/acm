#include <string.h>
#include <stdio.h>
#include <iostream>
//using namespace std;

int left[510], right[510], s[1100], *swp;
bool in[1100], t[1100];

void swap(int *a, int *b)
{
    int *c;
    c = a;
    a = b;
    b = c;
}

int
main(int argc, char *argv[])
{
    int m, n, k;
    bool inequal;
    char ch;

    inequal = false;
    scanf("%d%d", &m, &n);
    memset(t, false, sizeof(t));
    memset(s, 0, sizeof(s));

    while(n--)
    {
        memset(in, false, sizeof(in));
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &left[i]);
            in[left[i]] = true;
        }
        for (int i = 0; i < k; i++) {
            scanf("%d", &right[i]);
            in[right[i]] = true;
        }
        std::cin >> ch;
        if (ch == '<' || ch == '>') {
            inequal = true;
            if (ch == '>') 
                swap(left,right);
            for (int i = 1 ; i <= m; i++)
                if (!in[i]) 
                    t[i] = true;
            for (int i = 0; i < k; i++)
                if (!t[left[i]])
                    if (s[left[i]] > 0)
                        t[left[i]] = true; 
                    else if (s[left[i]] == 0)
                        s[left[i]] = -1;
            for (int i = 0; i < k; i++)
                if (!t[right[i]])
                    if (s[right[i]] < 0)
                        t[left[i]] = true;
                    else if (s[right[i]] == 0)
                        s[right[i]] = 1;
        } else {
            for (int i = 1; i <= m; i++)
                if (in[i])
                    t[i] = true;
        }
    }
    int res = -1;
    if (inequal) {
        for (int i = 1; i <= m; i++)
            if (!t[i] && s[i] != 0)
                if (res == -1)
                    res = i;
                else
                    res = -2;
    } else {
        for (int i = 1; i <= m; i++)
            if (!t[i])
                if (res == -1)
                    res = i;
                else
                    res = -2;
    }
    printf("%d\n",(res > 0)?res:0);

    return 0;
}
