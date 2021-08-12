#include <bits/stdc++.h>
using namespace std;

// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Input: x = 2.00000, n = 10
// Output: 1024.00000

double myPow(double x, int n)
{

    double ans = 1.0;
    long long nn = n;

    if (nn < 0)       // -ve power edge case
        nn = -1 * nn; // take case of over flow

    while (nn > 0)
    {
        if (nn % 2 == 0)
        {
            x = x * x;
            nn = nn / 2;
        }
        else
        {
            ans = ans * x;
            nn--;
        }
    }
    if (n < 0)
        ans = (double)1.0 / (double)ans; // take case of type casting
    return ans;
}