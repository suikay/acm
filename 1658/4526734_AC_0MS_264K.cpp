#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int j = 0; j < n; j++) {
    int data[4];
    for(int i = 0; i < 4; i++)
        cin >> data[i];
    for(int i = 0; i < 4; i++)
        cout << data[i] << " ";
    if((data[1]-data[0])==(data[2]-data[1])&&(data[2]-data[1])==(data[3]-data[2]))
        cout << data[3]*2-data[2]<<endl;
    else
        cout << data[3]*data[3]/data[2]<<endl;

    }
        return 0;
}
