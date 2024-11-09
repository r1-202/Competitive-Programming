#include <iostream>
int main()
{
    int a,b,s,p;
    std::cin>>a>>b;
    s=a;
    while(true)
    {
        p=0;
        while(a>=b)
        {
            a-=b;
            p++;
        }
        if(p==0)
            break;
        s+=p;
        a+=p;
    }
    std::cout<<s;
    return 0;
}