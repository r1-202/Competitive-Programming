#include <iostream>
#include <vector>
using namespace std;
void getMaxScore(vector<int> p, vector<int> a, int current_step, int max_step, int position,int current_score,
 int& max_score);
int main()
{
    int t,n,k,P_B,P_S;
    vector<int> p;
    vector<int> a;
    int i;
    int m_B,m_S;


    //cin>>t;
    //for(int tt=0;tt<t;++t)
    //{
    cin>>n>>k>>P_B>>P_S;
    p = vector<int>(n);
    for(i=0;i<n;++i)
    {
        cin>>p[i];
    }
    a = vector<int>(n);
    for(i=0;i<n;++i)
    {
        cin>>a[i];
    }
    m_S = m_B =0;
    getMaxScore(p,a,0,k,P_B-1,0,m_B);
    getMaxScore(p,a,0,k,P_S-1,0,m_S);
    if(m_S>m_B)
        cout<<"Sasha"<<endl;
    else if(m_S<m_B)
        cout<<"Bodya"<<endl;
    else 
        cout<<"Draw";
    //}
    return 1;
}

void getMaxScore(vector<int> p, vector<int> a, int current_step, int max_step, int position,int current_score,
 int& max_score)
{
    if(current_step==max_step)
    {
        if(current_score>max_score)
            max_score = current_score;
    }
    else
    {
        getMaxScore(p,a,current_step+1,max_step,position,current_score+a[position],max_score);
        getMaxScore(p,a,current_step+1,max_step,p[position]-1,current_score+a[position],max_score);
    }
}