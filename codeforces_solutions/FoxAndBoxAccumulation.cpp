#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x[101];
    int stacks[102]={0};
    for(int i=1;i<=n;++i)cin>>x[i];
    sort(x+1,x+n+1);
    for(int i = 1;i<=n;++i)
    {
        int j = 1;
        while(stacks[j]>x[i])
        {
            j++;
        }
        stacks[j]++;
    }
    int s=1;
    while(stacks[s]>0)
    {
        s++;
    }
    cout<<s-1;
    return 0;
}