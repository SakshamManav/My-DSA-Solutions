#include <bits/stdc++.h>
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
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> mpp;
//         for(int i =0; i<nums.size(); i++){
//             int num = nums[i];
//             int anotherNo = target-num;
//             if(mpp.find(anotherNo) != mpp.end()){
//                 return {i, mpp[anotherNo]};
//             }
//     mpp[num] = i;
//         }
//         return {-1,-1};
//     }
// };

// We can also do it by sorting the array and use two pointers approach but it might get be difficult to get the actual index as array is sorted so number at their actual; index has changed their indexes

// int main(){
//     vector<int> nums = {2,7,11,15};
//     int target = 13;
//     Solution sol;
//     vector<int>result = sol.twoSum(nums, target);

//     for(auto it:result){
//         cout<<"indices : "<< " ";
//         cout<<it<<" ";
//     }
// }

// Sort an array of 0s, 1s and 2s without using inbult sort function
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Input: nums = [2,0,1]
// Output: [0,1,2]

// Input: nums = [0]
// Output: [0]

int main()
{
    // Brute force approach
    // vector<int> nums = {0,1,2};
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     int smallest_no_index = i;
    //    for (int j = i+1; j < nums.size(); j++)
    //    {
    //         if(nums[smallest_no_index] > nums[j]){
    //             smallest_no_index = j;
    //         }
    //    }
    //    if(smallest_no_index != i){
    //     swap(nums[i], nums[smallest_no_index]);
    //    }

    // }
    // time - O(n) but taking 2pass and we have to done it in single pass
    // vector<int> nums = {2, 0, 2, 1, 1, 0, 0, 1, 1, 2};

    // int count_0 = 0, count_1 = 0, count_2 = 0;

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums[i] == 0)
    //     {
    //         count_0++;
    //     }
    //     if (nums[i] == 1)
    //     {
    //         count_1++;
    //     }
    //     if (nums[i] == 2)
    //     {
    //         count_2++;
    //     }
    // }

    // for (int i = 0; i < count_0; i++)
    // {
    //     nums[i] = 0;
    // }
    // for (int i = count_0; i < count_0 + count_1; i++)
    // {
    //     nums[i] = 1;
    // }
    // for (int i = count_0 + count_1; i < nums.size(); i++)
    // {
    //     nums[i] = 2;
    // }

    // Most optimal solution - Dutch National Flag algorithm
    vector<int> nums = {2, 0, 2, 1, 1, 0, 0, 1, 1, 2};
    int mid = 0, high = nums.size()-1, low = 0;
    while(mid <= high)
    {
        if(nums[mid] == 0){
            swap(nums[mid], nums[low]);
            mid++, low++;
        }
        else if(nums[mid] == 1){
            mid ++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    
    for (auto it : nums)
    {
        cout << it << " ";
    }
}
