// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing
// a different day in the future to sell that stock.

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Keep track using min and profit


#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = INT_MIN;
        int minSoFar = INT_MAX; 

        for(int i=0; i<n; i++) {

            minSoFar = min(minSoFar, prices[i]);
            int profit = prices[i]-minSoFar;
            ans = max(ans, profit);
            
        }
        return ans;
    }

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
}