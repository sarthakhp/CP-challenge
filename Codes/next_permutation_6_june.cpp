#include <bits/stdc++.h>
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    if (permutation.size() == 0)
    {
        return permutation;
    }
    //  Write your code here.
    vector<int> ans;
    for (int i = permutation.size() - 2; i >= 0; i--)
    {
        if (permutation[i] < permutation[i + 1])
        {
            vector<int> v;
            int found = -1;
            for (int j = permutation.size() - 1; j > i; j--)
            {
                if (permutation[j] > permutation[i] && found == -1)
                {
                    found = permutation[j];
                    v.push_back(permutation[i]);
                }
                else
                {
                    v.push_back(permutation[j]);
                }
            }
            for (int j = 0; j < i; j++)
            {
                ans.push_back(permutation[j]);
            }
            ans.push_back(found);
            for (int i = 0; i < v.size(); i++)
            {
                ans.push_back(v[i]);
            }
            return ans;
        }
    }
    reverse(permutation.begin(), permutation.end());
    return permutation;
}