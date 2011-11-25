#include <stdio.h>
#include <string.h>

const int M = 17;
const int N = 301;
int U[M*N], D[M*N], L[M*N], R[M*N], C[M*N];
// record the last element of each column
int last[N], S[N];

void cover(int c)
{
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    for (int i = D[c]; i != c; i = D[i])
    {
        for (int j = R[i]; j != i; j = R[j])
        {
            U[D[j]] = U[j];
            D[U[j]] = D[j];
            S[C[j]]--;
        }
    }
}

void uncover(int c)
{
    for (int i = U[c]; i != c; i = U[i])
    {
        for (int j = L[i]; j != i; j = L[j])
        {
            S[C[j]] ++;
            U[D[j]] = j; 
            D[U[j]] = j;
        }
    }
    L[R[c]] = c;
    R[L[c]] = c;
}

bool search(int k)
{
    if (R[0] == 0)
        return true;
    int c, j, r, s, t;
    s = 0x3fffffff;
    for (t = R[0]; t != 0; t = R[t])
        if (S[t] < s) {
            s = S[t];
            c = t;
        }
    cover(c);
    r = D[c];
    for (r = D[c]; r != c; r = D[r])
    {
        for (j = R[r]; j != r; j = R[j])
        {
            cover(C[j]);
            j = R[j];
        }
        if (search(k+1))
            return true;
        for (j = L[r]; j != r; j = L[j])
        {
           uncover(C[j]);
           j = L[j];
        }
    }
    uncover(c);

    return false;
}

bool input()
{
    memset(S, 0, sizeof(S));
    R[0] = 1;
    // record the head and tail of each row;
    int m, n;
    int head, tail;
    if (scanf("%d%d", &m, &n) != 2)
        return false;
    for (int i = 1; i <= n; i++)
    {
        L[i] = i-1;
        R[i-1] = i;
        last[i] = i;
    }
    L[0] = n;
    R[n] = 0;
    int tmp, k = n+1;
    for (int i = 1; i <= m; i++) {
        head = tail = 0;
        for (int j = 1; j <= n; j++, k++)
        {
            scanf("%d", &tmp);
            if (!tmp)
                continue;
            C[k] = j;
            S[j]++;
            if (!head) {
                head = tail = k;
            } else {
                L[k] = tail;
                R[tail] = k;
                tail = k;
            }
            D[last[j]] = k;
            U[k] = last[j];
            last[j] = k;
        }
        if (head) {
            R[tail] = head;
            L[head] = tail;
        }
    }
    for (int i = 1; i <= n; i++) {
        U[i] = last[i];
        D[last[i]] = i;
    }

    return true;
}

int main()
{
    while (input())
    {
        if (search(0))
            puts("Yes, I found it");
        else
            puts("It is impossible");
    }
}
