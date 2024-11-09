#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>

#define ll long long
using namespace std;

void solve_case()
{
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> x[i];
  }
  sort(x.begin(),x.end());
  if(n==5)
  {
    double left = (double)(x[n-1]+x[n-2])/2.0-(double)(x[2]+x[0])/2.0;
    double right = (double)(x[n-1]+x[n-3])/2.0-(double)(x[1]+x[0])/2.0;
    cout<<max(left,right)<<'\n';
    return;
  }
  cout<<(double)(x[n-1]+x[n-2])/2.0-(double)(x[1]+x[0])/2.0<<'\n';
}

void main_()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i)
  {
    std::cout << "Case #" << i + 1 << ": ";
    solve_case();
  }
}
static void run_with_stack_size(void (*func)(void), size_t stsize)
{
  char *stack, *send;
  stack = (char *)malloc(stsize);
  send = stack + stsize - 16;
  send = (char *)((uintptr_t)send / 16 * 16);
  asm volatile(
      "mov %%rsp, (%0)\n"
      "mov %0, %%rsp\n"
      :
      : "r"(send));
  func();
  asm volatile("mov (%0), %%rsp\n" : : "r"(send));
  free(stack);
}
int main()
{
  run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
  return 0;
}