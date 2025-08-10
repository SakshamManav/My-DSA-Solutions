#include <bits/stdc++.h>
using namespace std;

// Finding Sqrt of a number using Binary Search

// int floorSqrt(int n) {
//     int low = 1, high = n;
//     //Binary search on the answers:
//     while (low <= high) {
//         long long mid = (low + high) / 2;
//         long long val = mid * mid;
//         if (val <= (long long)(n)) {
//             //eliminate the left half:
//             low = mid + 1;
//         }
//         else {
//             //eliminate the right half:
//             high = mid - 1;
//         }
//     }
//     return high;
// }

// int main()
// {
//     int n = 28;
//     int ans = floorSqrt(n);
//     cout << "The floor of square root of " << n
//          << " is: " << ans << "\n";
//     return 0;
// }

// Nth Root of a Number using Binary Search

// class Solution {
//   public:
//     int nthRoot(int n, int m) {
//         int low = 1, high = m;
//         int ans = 1;
//         if(m == 1){
//             return 1;
//         }
//         while(low <= high){
//             int mid = low + (high -low)/2;
//             if(pow(mid, n) == m){
//                 return mid;
//             }
//             else if(pow(mid, n) > m){
//                 high = mid-1;
//             }
//             else{
//                 low = mid+1;
//             }
//         }
//         return -1;
//     }
// };

// KOKO eat bananas

// too bad solution

// class Solution
// {
// public:
//     int minEatingSpeed(vector<int> &piles, int h)
//     {
//         int count = 0;
//         int i = 0;
//         int min_num = INT_MIN;
//         for (int i = 0; i < piles.size(); i++)
//         {
//             min_num = min(piles[i], min_num);
//         }
//         // cout<<min_num;
//         while (count != h)
//         {
//             count = 0;
//             for (int j = 0; j < piles.size(); j++)
//             {

//                 if (min_num >= piles[j])
//                 {
//                     count++;
//                 }
//                 else
//                 {
//                     int cur_num = piles[j];
//                     while (cur_num > 0)
//                     {
//                         cur_num = cur_num - min_num;
//                         count++;
//                     }
//                 }
//             }
//             min_num++;
//         }

//         return min_num-1;
//     }
// };

// Better

// we know that our answer will always lies inside the range of 1, max_element

// class Solution
// {
// public:
//     int calculatehrs(vector<int> piles, int hourly)
//     {
//         int cur_hour = 0;
//         for (int i = 0; i < piles.size(); i++)
//         {
//             cur_hour += ceil((double)piles[i] / hourly);
//         }
//         return cur_hour;
//     }
//     int minEatingSpeed(vector<int> &piles, int h)
//     {
//         // finding max
//         int maxi = INT_MIN;
//         for (int i = 0; i < piles.size(); i++)
//         {
//             maxi = max(maxi, piles[i]);
//         }
//         cout << "max" << maxi << endl;

//         // finding minimum answer
//         for (int i = 1; i <= maxi; i++)
//         {
//             int ans = calculatehrs(piles, i);
//             if (ans <= h)
//             {
//                 return i;
//             }
//         }
//     }
// };

// optimal solution using binary search

// class Solution {
// public:
//     int calculatehrs(vector<int> piles, int hourly)
//     {
//         int cur_hour = 0;
//         for (int i = 0; i < piles.size(); i++)
//         {
//             cur_hour += ceil((double)piles[i] / hourly);
//         }
//         return cur_hour;
//     }
//     int minEatingSpeed(vector<int>& piles, int h) {
//        int maxi = INT_MIN;
//        for (int i = 0; i < piles.size(); i++)
//        {
//         maxi = max(maxi, piles[i]);
//        }

//        int low = 0, high = maxi;

//        while (low<= high)
//        {
//         int mid = low + (high-low)/2;
//         int ans = calculatehrs(piles, mid);

//         if(ans <= h){
//             return mid;
//              high = mid-1;
//         }
//         else if(ans > h){
//            low = mid +1;
//         }
//        }

//     }
// };

// int main()
// {
//     // cout<<pow(6,0.5);
//     Solution sol;
//     vector<int> nums = {30, 11, 23, 4, 20};
//     int ans = sol.minEatingSpeed(nums, 6);
//     cout << ans;
// }

// Minimum days to make M bouquets
// Example 1:
// Input Format: N = 8, arr[] = {7, 7, 7, 7, 13, 11, 12, 7}, m = 2, k = 3
// Result: 12
// Explanation: On the 12th the first 4 flowers and the last 3 flowers would have already bloomed. So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers. z

// Brute force
// class Solution
// {
// public:
//     int minDays(vector<int> &bloomDay, int m, int k)
//     {
//         int maxi = INT_MIN;
//         int mini = INT_MAX;
//         for (int i = 0; i < bloomDay.size(); i++)
//         {
//             maxi = max(bloomDay[i], maxi);
//             mini = min(bloomDay[i], mini);
//         }

//         for (int i = mini; i <= maxi; i++)
//         {
//             int count = 0;
//             int days = 0;
//             for (int j = 0; j < bloomDay.size(); j++)
//             {
//                 if (bloomDay[j] <= i)
//                 {
//                     count++;
//                 }
//                 else
//                 {
//                     days += count / k;
//                     count = 0;
//                 }
//             }

//             days += count / k;

//             // Check >= instead of ==
//             if (days >= m)
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };


// Optimal solution using Binary Search
// class Solution
// {
// public:
//     int minDays(vector<int> &bloomDay, int m, int k)
//     {
//         int maxi = INT_MIN;
//         int mini = INT_MAX;
//         if((long long)m*k > bloomDay.size()) return -1;
//         for (int i = 0; i < bloomDay.size(); i++)
//         {
//             maxi = max(bloomDay[i], maxi);
//             mini = min(bloomDay[i], mini);
//         }

//         int low = mini, high = maxi;

//         while (low <= high)
//         {
//             int mid = low + (high - low)/2;
//             int days = 0;
//             int count = 0;
//             for (int i = 0; i < bloomDay.size(); i++)
//             {
//                  if (bloomDay[i] <= mid)
//                 {
//                     count++;
//                 }
//                 else
//                 {
//                     days += count / k;
//                     count = 0;
//                 }
//             }
//            days += count / k;
//             if(days >= m){
//                 high = mid-1;
//             }
//             else{
//                 low = mid+1;
//             }
//         }
//         return low;
//     }
// };

// int main()
// {
//     Solution sol;
//     vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
//     int m = 2, k = 3;
//     int ans = sol.minDays(arr, m, k);
//     cout << ans;
// }

// Find the Smallest Divisor Given a Threshold

// Example 1:
// Input Format: N = 5, arr[] = {1,2,3,4,5}, limit = 8
// Result: 3
// Explanation: We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor. 
// The sum is 9(1 + 1 + 2 + 2 + 3)  if we choose 2 as a divisor. Upon dividing all the elements of the array by 3, we get 1,1,1,2,2 respectively. Now, their sum is equal to 7 <= 8 i.e. the threshold value. So, 3 is the minimum possible answer.



//Brute force
// class Solution {
//   public:
//     int smallestDivisor(vector<int>& nums, int k) {
//         int maxi = INT_MIN;
//         for(int i =0; i<nums.size(); i++){
//             maxi = max(maxi, nums[i]);
//         }
        
//         for(int i =1; i<= maxi; i++){
//             int sum = 0;
//             for(int j=0; j<nums.size(); j++){
//                 sum += ceil((double)nums[j]/i);
//             }
//             if(sum <= k){
//                 return i;
//             }
//         }
//         return -1;
        
//     }
// };

// Optimal solution using binary search

// class Solution {
//   public:
//     int smallestDivisor(vector<int>& nums, int k) {
//         int maxi = INT_MIN;
//         for(int i =0; i<nums.size(); i++){
//             maxi = max(maxi, nums[i]);
//         }
//         int low = 1, high = maxi;
//         int ans = 0;
//         while(low <= high){
//             int sum = 0;
        
//             int mid = low + (high - low)/2;
            
//             for(int j=0; j<nums.size(); j++){
//                 sum += ceil((double)nums[j]/mid);
//             }
//             if(sum <= k){
//                 ans = mid;
//                 high = mid-1;
//                 // return i;
//             }else{
//                 low = mid+1;
//             }
//         }
//         return ans;
        
//     }
// };


// Capacity to ship packages in D days

// Brute force

// class Solution {
// public:
//     int shipWithinDays(vector<int>& nums, int days) {
//         int first = INT_MIN;
//         int last =0;
//         for(int i=0; i<nums.size(); i++){
//             first = max(first, nums[i]);
//             last += nums[i];
//         }
//         int count =1;
//         for(int i = first; i<= last; i++){
//             int cur_sum = 0;
//             for(int j=0; j<nums.size(); j++){
//                 cur_sum += nums[j];
//                 if(cur_sum > i){
//                     count ++;
//                     cur_sum = nums[j];
//                 }
//             }
//             if(count <= days){
//                 return i;
//             }
//             count = 1;
//         }
//         return -1;
//     }
// };


// Optimal solution -- binary search
// class Solution {
// public:
//     int shipWithinDays(vector<int>& nums, int days) {
//         int low = INT_MIN;
//         int high =0;
//         for(int i=0; i<nums.size(); i++){
//             low = max(low, nums[i]);
//             high += nums[i];
//         }
//         int count =1;
//         int ans = 0;
//         while(low <= high){
//             int mid = low +(high - low)/2;
//             int cur_sum = 0;

//             for(int i=0; i<nums.size(); i++){
//                 cur_sum += nums[i];
//                 if(cur_sum > mid){
//                     count ++;
//                     cur_sum = nums[i];
//                 }
//             }
//             if(count <= days){
//                 ans = mid;
//                 high = mid-1;
//             }else{
//                 low = mid+1;
//             }
//             count = 1;
//         }
//         return ans;
//     }
// };
