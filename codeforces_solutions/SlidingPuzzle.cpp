#include <iostream>

int main() {
    
    std::string A,B,A1,A2,B1,B2;
    char c;
    int i,j;
    std::cout<<"input:";
    std::cin>>A1>>A2>>B1>>B2;
    
    c=A2[1];A2[1]=A2[0];A2[0]=c;
    c=B2[1];B2[1]=B2[0];B2[0]=c;

    A = A1+A2;
    B = B1+B2;

    for(i =0;i<A.size();++i)
    {
        if (A[i]=='X')
            break;
    }
    if(i!=A.size())
        A.erase(i,1);
    for(i =0;i<B.size();++i)
    {
        if (B[i]=='X')
            break;
    }
    if(i!=B.size())
       B.erase(i,1);
            std::cout<<std::endl<<A<<std::endl<<B;
    A = A+A;
    for(i=0;i<A.size();++i)
    {
        if(B[0]==A[i])
        {
            for(j=1;j<B.size();++j)
            {
                if(B[j]!=A[i+j])
                    break;
            }
            if(j==B.size())
                break;
        }
    }
    if(i==A.size())
        std::cout<<"NO";
    else
        std::cout<<"YES";
    return 0;
}