#include <iostream>
using namespace std;
 int main()
 {
    int n,k,nr_learned;
    int a[100];
    bool learned[100]={false};
    cin>>n>>k;
    for(int i=0;i<n;++i) cin>>a[i];
    while(k>0)
    {
       
    }
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if( learned[i]) count++;
    }
    cout<<count<<endl;
    for(int i=0;i<n;i++)
    {
        if(learned[i]) cout<<i+1<<" ";
    }

 }