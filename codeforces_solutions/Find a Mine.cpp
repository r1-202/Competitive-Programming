#include <iostream>
#include <vector>
using namespace std;

void solve_case();
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t > 0)
  {
    solve_case();
    --t;
  }
}

struct point
{
  point() {}
  point(int x, int y) : x(x), y(y) {}
  int x;
  int y;
};

int query(int x, int y)
{
  cout << "? " << x << " " << y << '\n';
  cout.flush();
  int buffer;
  cin >> buffer;
  return buffer;
}

void solve_case()
{
  int n, m;
  cin >> n >> m;
  point p1, p2;
  int d1 = query(1, 1);
  if (d1 == 0)
  {
    cout << "! 1 1\n";
    cout.flush();
    return;
  }
  p1 = point(d1 + 1, 1);
  p2 = point(1, d1 + 1);
  int a1 = (p1.y - p2.y) / (p1.x - p2.x);
  int b1 = p1.y - a1 * p1.x;
  int d2 = query(n, m);
  if (d2 == 0)
  {
    cout << "! " << n << " " << m << '\n';
    cout.flush();
    return;
  }
  p1 = point(n - d2, m);
  p2 = point(n, m - d2);
  int a2 = (p1.y - p2.y) / (p1.x - p2.x);
  int b2 = p1.y - a2 * p1.x;
  int d3 = query(n, 1);
  if (d3 == 0)
  {
    cout << "! " << n << " 1" << '\n';
    cout.flush();
    return;
  }
  p1 = point(n, d3 + 1);
  p2 = point(n - d3, 1);
  int a3 = (p1.y - p2.y) / (p1.x - p2.x);
  int b3 = p1.y - a3 * p1.x;
  if ((b3 - b2) % (a2 - a3) == 0)
  {
    int x = (b3 - b2) / (a2 - a3);
    int y = a2 * x + b2;
    if (x <= n && x >= 1 && y <= m && y >= 1)
      if (query(x, y) == 0)
      {
        cout << "! " << x << " " << y << '\n';
        cout.flush();
        return;
      }
  }
  int x = (b3 - b1) / (a1 - a3);
  int y = a1 * x + b1;
  cout << "! " << x << " " << y << '\n';
  cout.flush();
}