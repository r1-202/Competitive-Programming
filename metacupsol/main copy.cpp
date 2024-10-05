#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <memory>

#define ll long long
using namespace std;

vector<ll> primes;
vector<bool> prime;

void getPrimes(int N, vector<ll> &primes, vector<bool> &prime)
{
  prime = vector<bool>(N + 1, true);
  primes = vector<ll>();
  for (int p = 2; p * p <= N; ++p)
  {
    if (prime[p])
    {
      for (int i = p * p; i <= N; i += p)
      {
        prime[i] = false;
      }
    }
  }
  for (int i = 2; i <= N; ++i)
  {
    if (prime[i])
      primes.push_back(i);
  }
  prime[0] = false;
  prime[1] = false;
}

void solve_case()
{
  ll N;
  cin >> N;
  if (N <= 4)
  {
    cout << "0\n";
    return;
  }
  ll c = 1;
  for (int i = 0; i < primes.size(); ++i)
  {
    if (primes[i] > N)
      break;
    if (prime[primes[i] + 2] && primes[i] + 2 <= N)
      ++c;
  }
  cout << c << '\n';
}

void main_()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  getPrimes(10000000, primes, prime);
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