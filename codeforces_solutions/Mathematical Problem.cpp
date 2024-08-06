#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#define ll long long
using namespace std;

void solve_case();
void solve_all();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve_all();
    ll t;
    cin >> t;
    while (t > 0)
    {
        solve_case();
        --t;
    }
}

class BigNum
{
  public:
  BigNum(){}
  BigNum(vector<int> v)
  {
    digits=v;
  }
  BigNum lastTwo()
  {
    BigNum out;
    out.digits.push_back(digits[0]);
    for(int i=1;i<digits.size();++i)
    {
      if(digits[i]==6||digits[i]==9||digits[i]==1)
      {
        out.digits.push_back(0);
      }
      out.digits.push_back(digits[i]);
    }
    return out;
  }
  vector<int> digits;
  void print()
  {
    for(int i=0;i<digits.size();++i)
    {
      cout<<digits[i];
    }
    cout<<'\n';
  }
};

vector<vector<BigNum>> solution;
void solve_all()
{
  solution.push_back(vector<BigNum>());
  solution.push_back(vector<BigNum>({BigNum(vector<int>({1}))}));
  solution.push_back(vector<BigNum>());
  solution.push_back(vector<BigNum>({BigNum(vector<int>({1,9,6})),BigNum(vector<int>({9,6,1})),
                                      BigNum(vector<int>({1,6,9}))}));
  for(int i=4;i<=99;i+=2)
  {
    vector<BigNum> pb;
    for(int j=0;j<solution.back().size();++j)
    {
      pb.push_back(solution.back()[j]);
      pb.back().digits.push_back(0);
      pb.back().digits.push_back(0);
    }
    pb.push_back(solution.back()[solution.back().size()-2].lastTwo());
    pb.push_back(solution.back()[solution.back().size()-1].lastTwo());
    solution.push_back(vector<BigNum>());
    solution.push_back(pb);
  }
}
void solve_case()
{
  int n;
  cin>>n;
  for(int i=0;i<solution[n].size();++i)
  {
    solution[n][i].print();
  }
}