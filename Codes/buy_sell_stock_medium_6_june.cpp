#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int mx = prices.back();
    int ans = 0;
    for (int i = prices.size() - 2; i >= 0; i--)
    {
        if (prices[i] >= mx)
        {
            mx = prices[i];
        }
        else
        {
            ans = max(ans, mx - prices[i]);
        }
    }
    return ans;
}