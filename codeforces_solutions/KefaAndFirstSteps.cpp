#include <iostream>
#include <vector>
int main()
{
    int n;
    std::cin>>n;
    std::vector<int> a = std::vector<int>(n);
    for(int j = 0;j<n;++j)
    {
        std::cin>>a[j];
    }
    int i = 0;
    int m = 1;
    int k = 1;
    while(i<a.size()-1)
    {
        if(a[i]<=a[i+1])
        {
            k++;
        }
        else
        {
            if(k>m)
                m=k;
            k=1;
        }
        i++;
    }
    if(k>m)
        m=k;
    std::cout<<m;
}