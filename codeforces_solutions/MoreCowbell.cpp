#include <iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int s[100000];
    for(int i=0;i<n;i++) cin>>s[i];
    int size = s[n-1];
    while(n<2*k&&n>0)
    {
        k--;
        n--;
    }
    if(n==0)
    {
        cout<<size;
        return 0;
    }
    for(int i=0;i<k;++i)
    {
        if(s[i]+s[n-1-i]>size) size = s[i]+s[n-1-i];
    }
    cout<<size;
    return 0;
}