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
  ll N;
  cin >> N;
  vector<ll> A(N), B(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> A[i];
    cin >> B[i];
  }
  vector<double> As(N), Bs(N);
  for (int i = 0; i < N; ++i)
  {
    As[i] = (double)A[i] / (double)(i + 1);
    Bs[i] = (double)B[i] / (double)(i + 1);
  }
  double maxA = As[0];
  for (int i = 0; i < N; ++i)
  {
    maxA = max(maxA, As[i]);
  }
  double minB = Bs[0];
  for (int i = 0; i < N; ++i)
  {
    minB = min(minB, Bs[i]);
  }
  if (maxA > minB)
    cout << -1 << '\n';
  else
    cout << 1.0 / minB << '\n';
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