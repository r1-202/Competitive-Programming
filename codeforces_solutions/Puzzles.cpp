#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
    int n,m;
    int i;
    int min;
    std::cin>>n>>m;
    std::vector<int> a(m);
    for(i=0;i<m;i++)
    {
        std::cin>>a[i];
    }
    std::sort(a.begin(),a.end());
    min = a[m-1]-a[0];
    for(i=0;i<=m-n;i++)
    {
        if(a[i+n-1]-a[i]<min)
            min = a[i+n-1]-a[i];
    }
    std::cout<<min;
}