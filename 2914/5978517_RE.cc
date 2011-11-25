#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define CLEAN(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int N = 110;
const int INF = 0x3fffffff;
bool in[N], valid[N];
int net[N][N];

int MinimumCutPhase(int s, int t, int &lastS, int &lastT) {
    int lastmax, _max, maxV;
    static int sum[N];
    CLEAN(in, false);
    CLEAN(sum, 0);
    while (true) {
        _max = -1;
        for (int i = s; i <= t; i++)
            if (valid[i] && !in[i] && _max < sum[i]) {
                _max = sum[i];
                maxV = i;
            }
        if(_max == -1)
            return lastmax;
        in[maxV] = true;
        for (int i = s; i <= t; i++)
            if (valid[i] && !in[i])
                sum[i] += net[i][maxV];
        lastS = lastT;
        lastT = maxV;
        lastmax = _max;
    }
}

void Merge(int s, int t, int lastS, int lastT) {
    valid[lastT] = false;
    for (int i = s; i <= t; i++)
        if (valid[i]) {
            net[i][lastS] += net[i][lastT];
            net[lastS][i] += net[lastT][i];
        }
}

int MinimumCut(int s, int t) {
    int lastS, lastT;
    int _min = INF;
    CLEAN(valid, true);
    for (int i = s; i < t; i++) {
        _min = min(_min, MinimumCutPhase(s, t, lastS, lastT));
        Merge(s, t, lastS, lastT);
    }
    return _min;
}

int n, m;
bool input() {
    int u, v, w;
    if (scanf("%d%d", &n, &m) != 2)
        return false;
    CLEAN(net, 0);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        net[u][v] += w;
        net[v][u] += w;
    }
    return true;
}

int main() {
    while (input())
        printf("%d\n", MinimumCut(0, n-1));
    return true;
}

