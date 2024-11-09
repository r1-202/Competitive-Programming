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

int gcd(int a, int b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    return gcd(b, a % b);
}

void solve_case()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < a.size(); ++i)
    {
        cin >> a[i];
    }
    vector<int> b(n - 1);
    for (int i = 0; i < b.size(); ++i)
    {
        b[i] = gcd(a[i], a[i + 1]);
    }
    int m = -1;
    for (int i = 0; i < b.size() - 1; ++i)
    {
        if (b[i] > b[i + 1])
        {
            if (m != -1)
            {
                cout << "no\n";
                return;
            }
            m = i;
            i += 3;
        }
    }
    for (int r = m; r <= m + 2; ++r)
    {
        bool works = true;
        vector<int> c;
        vector<int> cd;
        int l = max(r - 5, 0);
        int h = min(r + 5, n - 1);
        int i = l;
        while (i <= h)
        {
            if (i != r)
                c.push_back(a[i]);
            ++i;
        }
        for (int j = 0; j < c.size() - 1; ++j)
        {
            cd.push_back(gcd(c[j], c[j + 1]));
        }
        for (int j = 0; j < cd.size() - 1; ++j)
        {
            if (cd[j] > cd[j + 1])
            {
                works = false;
                break;
            }
        }
        if (works)
        {
            cout << "yes\n";
            return;
        }
    }
    cout << "no\n";
}