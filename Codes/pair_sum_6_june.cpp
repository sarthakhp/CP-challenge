#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    sort(arr.begin(), arr.end());
    int p1 = 0, p2 = arr.size()-1;
    vector<vector<int>> ans;
    while(p1 < p2){
        int op2 = p2;
        while (p1 < p2){
            if (arr[p1] + arr[p2] == s){
                ans.push_back({arr[p1], arr[p2]});
                p2--;
            }
            else{
                break;
            }
        }
        p2 = op2;
        if (p1 >= p2){
            break;
        }
        
        if (arr[p1] + arr[p2] > s){
            p2--;
        }
        else if (arr[p1] + arr[p2] <= s){
            p1++;
        }
    }
    return ans;
}