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

// 02) Sort an array of 0s, 1s and 2s without using inbult sort function
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Input: nums = [2,0,1]
// Output: [0,1,2]

// Input: nums = [0]
// Output: [0]

// int main()
// {
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
//     vector<int> nums = {2, 0, 2, 1, 1, 0, 0, 1, 1, 2};
//     int mid = 0, high = nums.size()-1, low = 0;
//     while(mid <= high)
//     {
//         if(nums[mid] == 0){
//             swap(nums[mid], nums[low]);
//             mid++, low++;
//         }
//         else if(nums[mid] == 1){
//             mid ++;
//         }
//         else{
//             swap(nums[mid], nums[high]);
//             high--;
//         }
//     }

//     for (auto it : nums)
//     {
//         cout << it << " ";
//     }
// }

// 03) Find the Majority Element that occurs more than N/2 times
// Example :
// Input Format: N = 3, nums[] = {3,2,3}
// Result: 3
// Explanation: When we just count the occurrences of each number and compare with half of the size of the array, you will get 3 for the above solution.

//  Time Complexity:
// O(n) for iterating over nums

// O(n log n) for inserting into a map<int, int> (because map is a Red-Black Tree)
// ➡️ So total time complexity = O(n log n)

// ✅ Space Complexity:
// You're using a map<int, int> mpp to store the frequency of elements.
// In the worst case, all elements are distinct.
// So:
// Space complexity = O(n) (for the map)

// class Solution{
//     public:
//     int majority_elem(vector<int>nums){
//         map<int, int> mpp;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             mpp[nums[i]]++;
//         }
//         for(auto it : mpp){
//             if(it.second > (nums.size()/2)){
//                 return it.first;
//             }
//         }
//         return -1;

//     }
// };

// Optimal solution time - Moore’s Voting Algorithm:  O(n), space - O(1)
// class Solution
// {
// public:
//     int majorityElement(vector<int> nums)
//     {
//         int count = 0;
//         int elem = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (count == 0)
//             {
//                 elem = nums[i];
//                 count++;
//             }
//             else if (nums[i] == elem)
//             {
//                 count++;
//             }
//             else
//             {
//                 count--;
//             }
//         }
//         cout<<elem;
//         int newcount = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] == elem)
//             {
//                 newcount++;
//             }
//         }
//         if (newcount > (nums.size() / 2))
//         {
//             return elem;
//         }
//         return -1;
//     }
// };

// int main()
// {
//     vector<int> nums = {1, 1, 3, 4, 4, 4, 4, 4, 4, 2, 1};
//     Solution sol;
//     int ans = sol.majorityElement(nums);
//     cout << ans;
// }

// 04) Maximum Subarray Sum in an Array
// Example :

// Input: arr = [-2,1,-3,4,-1,2,1,-5,4] 

// Output: 6 

// Explanation: [4,-1,2,1] has the largest sum = 6. 

// Optimal SOlution - Kadane's Algorithm
// in this we are also finding the sub_array that sums up to the maximum sum but in ideal question we just have asked to find the max sum.
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int sum = 0;
//         int max_sum = INT_MIN;
//         int start = 0;
//         int ans_start = 0;
//         int ans_end = 0;
//         for(int i = 0; i<nums.size(); i++){
//             if(sum == 0){
//                 start = i;
//             }

//             sum += nums[i];
//             if(sum > max_sum){
//                 max_sum = sum;
//                 ans_start = start;
//                 ans_end = i;
//             }            
//             if(sum < 0){
//                 sum = 0;
//             }
//         }
//         for(int i=ans_start; i <= ans_end; i++){
//             cout<<nums[i]<<" ";
//         }
//         return max_sum;
//     }
// };

// int main(){
//     vector<int> nums = {5,4,-1,7,8};
//     Solution sol;
//     int ans = sol.maxSubArray(nums);
//     cout<<ans;
// }

//  06) Best time to buy and sell stock
// Example :
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and 
// sell on day 5 (price = 6), profit = 6-1 = 5.

// Note: That buying on day 2 and selling on day 1 
// is not allowed because you must buy before 
// you sell.

// Most optimal Solution
// class Solution{
//     public:
//         int maxProfit(vector<int>& prices) {
//         int max_profit = 0;
//         int best_buy = prices[0];

//         for (int i = 0; i < prices.size(); i++)
//         {
//             max_profit = max(max_profit, prices[i] -best_buy);
//             best_buy = min(best_buy, prices[i]);
//         }
//         return max_profit;
//     }
// };
// int main(){
//     vector<int>  nums = {2,4,1,20,50};
//     Solution sol;
//     int ans = sol.maxProfit(nums);
//     cout<<ans;
// }