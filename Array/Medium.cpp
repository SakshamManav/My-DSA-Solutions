#include<bits/stdc++.h>
using namespace std;


// 01) Two Sum
// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Time - O(n^2) space - O(1)

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {    
//         for(int i = 0; i<nums.size()-1; i++){
//             for(int j = i+1; j<nums.size(); j++){
//                 if(nums[i] + nums[j] == target){
//                     return {i,j};
//                 }
//             }
//         }
//         return {-1, -1};
//     }
// };


// Solution using hashmap,  time taken - O(n logn) this time is good for given question
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {    
        unordered_map<int, int> mpp;
        for(int i =0; i<nums.size(); i++){
            int num = nums[i];
            int anotherNo = target-num;
            if(mpp.find(anotherNo) != mpp.end()){
                return {i, mpp[anotherNo]};
            }
    mpp[num] = i;
        }
        return {-1,-1};
    }
};
int main(){
    vector<int> nums = {2,7,11,15};
    int target = 13;
    Solution sol;
    vector<int>result = sol.twoSum(nums, target);

    for(auto it:result){
        cout<<"indices : "<< " ";
        cout<<it<<" ";
    }
}