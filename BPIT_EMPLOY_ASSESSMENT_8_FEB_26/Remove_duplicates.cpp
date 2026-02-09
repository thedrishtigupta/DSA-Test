/*
Remove duplicate elements while keeping the order of elements intact.

Example 1:

nums = [1,2,2,3,4,4,4,4]
ans = [1,2,3,4]

Example 2:
nums = [1,2,3,4]
ans = [1,2,3,4]
*/


#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<int> removeDuplicate(vector<int> nums) {
    unordered_set<int> s;
    vector<int> ans;

    for(int val : nums) {
        if(!s.count(val)) {
            ans.push_back(val);
            s.insert(val);
        }
    }
    return ans;
}
int main() {
    vector<int> nums = {1,2,2,3,4,4,4,4};

    vector<int> ans = removeDuplicate(nums);

    for(int val : ans) cout<<val<<" ";
    return 0;
}