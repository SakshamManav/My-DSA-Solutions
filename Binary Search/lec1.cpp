#include <bits/stdc++.h>
using namespace std;

// Lower bound
// Given a sorted array of nums and an integer x, write a program to find the lower bound of x.
// The lower bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
// If no such index is found, return the size of the array.

// class Solution
// {
// public:
//     int lowerBound(vector<int> &nums, int x)
//     {
//         int high = nums.size() - 1, low = 0;

//         int index = INT_MAX;
//         while (low <= high)
//         {
//             int mid = (low + high) / 2;
//             if (nums[mid] >= x)
//             {
//                 index = min(index, mid);
//                 high = mid - 1;
//             }
//             else
//             {
//                 low = mid +1;
//             }
//         }
//         return index;
//     }
// };
// int main()
// {
//     Solution sol;
//     vector<int> nums = {1,2,2,3};
//     int x = 2;
//     int ans = sol.lowerBound(nums, x);
//     cout<<ans;
// }

// Upper Bound

// class Solution
// {
// public:
//     int upperBound(vector<int> &nums, int x)
//     {
//         int high = nums.size() - 1, low = 0;

//         int index = INT_MAX;
//         while (low <= high)
//         {
//             int mid = low + ((high-low)/2);
//             if (nums[mid] > x)
//             {
//                 index = min(index, mid);
//                 high = mid - 1;
//             }
//             else
//             {
//                 low = mid +1;
//             }
//         }
//         if(index == INT_MAX){
//             return nums.size();
//         }
//         return index;
//     }
// };
// int main()
// {
//     Solution sol;
//     vector<int> nums = {3,5,8,15,19};
//     int x = 9;
//     int ans = sol.upperBound(nums, x);
//     cout<<ans;
// }

// Search insert position
// Example 1:
// Input Format: arr[] = {1,2,4,7}, x = 6
// Result: 3
// Explanation: 6 is not present in the array. So, if we will insert 6 in the 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//        int high = nums.size()-1, low =0;
//        while(low <= high){
//         int mid = low + ((high-low)/2);
//         if(nums[mid] == target){
//             return mid;
//         }
//         else if(nums[mid] > target){
//             high = mid-1;
//         }else{
//             low = mid+1;
//         }
//        }
//        return low;
//     }
// };

// int main()
// {
//     Solution sol;
//     vector<int> nums = {3,5,8,15,19};
//     int x = 9;
//     int ans = sol.searchInsert(nums, x);
//     cout<<ans;
// }

// Floor and Ceil in Sorted Array
// Example 1:
// Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
// Result: 4 7
// Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

// pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
// {
//     int low = 0, high = n - 1;
//     while (low <= high)
//     {
//         int mid = low + ((high - low) / 2);
//         if (a[mid] == x)
//         {
//             // floor = mid;
//             // ceiling = mid;
//             pair<int, int> p = {a[mid], a[mid]};
//             return p;
//         }
//         else if (a[mid] > x)
//         {
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     if(high == -1){
//         return {high, a[low]};
//     } else if(low > a.size()){
//         return {a[high], low};
//     }
//     pair<int, int> p = {a[high], a[low]};
//     return p;
// }

// int main()
// {
//     vector<int> nums = {3, 4, 4, 7, 8, 10};
//     int x = 2;
//     pair<int, int> ans = getFloorAndCeil(nums, nums.size(), x);
    
// }

class Solution{
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int low =0, high = nums.size()-1;
        int first, last = -1;
        while (low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid] == target){
                if(nums[mid+1] != target){
                    last = mid;
                }
                if(nums[mid-1] != target){
                    first = mid;
                }
            }
        }
        
    }
};