#include <bits/stdc++.h>
long long maxSubarraySum(int arr[], int n)
{
    vector<long long> v;
    long long total = 0;

    for (long long i = 0; i < n; i++)
    {
        total += arr[i];
        v.push_back(arr[i]);
    }
    /*
        Don't write main().
        Don't read input, it is passed as function argument.
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    vector<long long> lv;
    long long last = 0;
    lv.push_back(last);
    for (long long i = 0; i < v.size() - 1; i++)
    {
        last += v[i];
        lv.push_back(last);
    }
    vector<long long> rv;
    last = 0;
    rv.push_back(0);
    for (long long i = v.size() - 1; i >= 0; i--)
    {
        last += v[i];
        if (last < rv.back())
        {
            rv.push_back(last);
        }
        else
        {
            rv.push_back(rv.back());
        }
    }
    reverse(rv.begin(), rv.end());
    long long ans = INT_MIN;
    for (long long i = 0; i < lv.size(); i++)
    {
        ans = max(ans, total - lv[i] - rv[i]);
    }
    return ans;
}