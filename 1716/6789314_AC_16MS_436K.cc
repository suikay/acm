#include <stdio.h>
#include <algorithm>
using namespace std;
struct interval
{
    int start,end;
    bool operator<(const interval &i) const {
        if(end == i.end)
            return start < i.start;
        return end < i.end;
    }
};
int want[10010];
interval inter[10010];
int main(int argc, const char *argv[])
{
    int n,ptr,now,l,r,res;
    scanf("%d",&n);
    res = 0;
    for(int i = 0; i < n; i++)
        scanf("%d%d",&inter[i].start,&inter[i].end);
    sort(inter,inter+n);
    for(int i = 0; i < 10001; i++)
        want[i] = 2;
    ptr = 0;
    while(ptr < n)
    {
        if(want[ptr] == 1) {
            res++;
            l = inter[ptr].start;
            r = inter[ptr].end;
            now = ptr+1;
            while(now < n && !((inter[now].start > inter[ptr].end) ||
                (inter[now].end < inter[ptr].start))) {
                want[now]--;
                inter[now].start = r + 1;
                now++;
            }
        } else if(want[ptr] == 2) {
            res += 2;
            l = inter[ptr].start;
            r = inter[ptr].end;
            now = ptr + 1;
            while(now < n && inter[now].start <= r) {
                if(inter[now].start == r)
                {
                    want[now]--;
                    inter[now].start = r + 1;
                } else {
                    l = max(l,inter[now].start);
                    r = min(r,inter[now].end);
                    want[now] = 0;
                }
                now++;
            }
        }
        ptr++;
    }
    printf("%d\n",res);
    
    return 0;
}
