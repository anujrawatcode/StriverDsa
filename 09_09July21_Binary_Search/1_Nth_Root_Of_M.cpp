#include <bits/stdc++.h>
using namespace std;

double multiply(double number, int n)
{
    double ans = 1.0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * number;
    }
    return ans;
}
double rootNth(int N, int M)
{
    double l = 1;
    double h = M;

    while ((h - l) > 0.0000001)
    {
        double mid = (l + h) / 2.0;

        if (multiply(mid, N) == M)
            return mid;
        if (multiply(mid, N) > M)
            h = mid;
        if (multiply(mid, N) < M)
            l = mid;
    }
    return l;
}

int main()
{
    cout << rootNth(3, 27);
}