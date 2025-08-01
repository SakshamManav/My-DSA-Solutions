#include <bits/stdc++.h>
using namespace std;

// Pascal's tree solution - Solved by me in one go

// int main()
// {
//     int k = 7;
//     vector<vector<int>> ans(k);
//     for (int i = 0; i < k; i++)
//     {
//         ans[i] = vector<int>(i + 1, 1);
//     }

//     for (int i = 2; i < k; i++)
//     {
//         ans.push_back(vector<int>(i+1, 1));
//         for (int j = 0; j < i-1; j++)
//         {
//             ans[i][j+1] = ans[i-1][j] + ans[i-1][j+1];
//         }
//     }
//     for (auto it : ans)
//     {
//         for (auto val : it)
//         {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
// }

// Majority Element 2

// Brute force
// class Solution
// {
// public:
//     vector<int> majorityElementTwo(vector<int> &nums)
//     {
//         int count;
//         vector<int> ans;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             count = 0;
//             for (int j = 0; j < nums.size(); j++)
//             {
//                 if (nums[i] == nums[j])
//                 {
//                     count++;
//                 }
//             }
//             if (count > nums.size() / 3)
//             {
//                 int present = false;
//                 for (int k = 0; k < ans.size(); k++)
//                 {
//                     if (ans[k] == nums[i])
//                     {
//                         present = true; break;
//                     }
//                 }
//                 if (!present)
//                 {
//                     ans.push_back(nums[i]);
//                 }
//             }
//         }
//         return ans;
//     }
// };

// int main()
// {

//     vector<int> nums = {1, 2, 3, 1, 2, 1};
//     Solution sol;
//     vector<int> ans = sol.majorityElementTwo(nums);

//     for (int it : ans)
//     {
//         cout << it << " ";
//     }
// }

// using hashing
// class Solution {
// public:
//     vector<int> majorityElementTwo(vector<int>& nums) {
//         int count = 0;
//         unordered_map<int, int> mpp;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             mpp[nums[i]]++;
//         }
//         vector<int> ans;
//         for(auto it:mpp){
//             if(it.second > nums.size()/3){
//                 ans.push_back(it.first);
//             }
//         }
//         return ans;
//     }
// };

// Optimal solution -- Extended version of Moore Voting algorithm
//  class Solution {
//  public:
//      vector<int> majorityElement(vector<int>& nums) {
//          int count1 = 0, count2 = 0;
//          int elem1 = INT_MIN, elem2 = INT_MIN;

//         // First pass: Find two candidates
//         for (int num : nums) {
//             if (num == elem1) {
//                 count1++;
//             } else if (num == elem2) {
//                 count2++;
//             } else if (count1 == 0 && num != elem2) {
//                 elem1 = num;
//                 count1 = 1;
//             } else if (count2 == 0 && num != elem1) {
//                 elem2 = num;
//                 count2 = 1;
//             } else {
//                 count1--;
//                 count2--;
//             }
//         }

//         count1 = 0;
//         count2 = 0;
//         for (int num : nums) {
//             if (num == elem1) count1++;
//             else if (num == elem2) count2++;
//         }

//         vector<int> ans;
//         if (count1 > nums.size() / 3) ans.push_back(elem1);
//         if (count2 > nums.size() / 3) ans.push_back(elem2);

//         sort(ans.begin(), ans.end());
//         return ans;
//     }
// };

// int main(){
//     vector<int> nums = {3,2,3};
//     Solution sol;
//     vector<int> ans = sol.majorityElement(nums);

//     for (int it : ans)
//     {
//         cout << it << " ";
//     }
// }

// Three Sum

// Brute Force approach

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>> st;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             for(int j = i+1; j<nums.size(); j++){
//                 for(int k =j+1; k<nums.size(); k++ ){
//                     if(nums[i]+nums[j]+nums[k] == 0){
//                         vector<int> vt = {nums[i], nums[j], nums[k]};
//                         sort(vt.begin(), vt.end());
//                         st.insert(vt);
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin(), st.end());
//         return ans;
//     }
// };

// Better approach

// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         set<vector<int>> st;

//         for (int i = 0; i < nums.size(); i++)
//         {
//             set<int> hashset;
//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 int elem = -(nums[i]+nums[j]);
//                 if(hashset.find(elem)!= hashset.end()){
//                     vector<int> vt = {nums[i], nums[j], elem};
//                     sort(vt.begin(), vt.end());
//                     st.insert(vt);
//                 }
//                 hashset.insert(nums[j]);
//             }
//         }
//         vector<vector<int>> ans(st.begin(), st.end());
//         return ans;
//     }
// };

// Optimal solution

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if(i>0 && nums[i] == nums[i-1]) continue;
//             int j =i+1; int k =nums.size()-1;
//             while (j<k)
//             {
//                 if(nums[i]+nums[j]+nums[k] == 0){
//                     ans.push_back({nums[i], nums[j], nums[k]});
//                     j++, k--;
//                     while(j<k && nums[j] == nums[j-1])j++;
//                     while(j<k && nums[k] == nums[k+1])k--;
//                 }else if(nums[i]+nums[j]+nums[k] > 0){
//                     k--;
//                 }
//                 else if(nums[i]+nums[j]+nums[k] < 0){
//                     j++;
//                 }
//             }
//         }
//         return ans;

//     }
// };

// int main()
// {
//     vector<int> nums = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
//     Solution sol;
//     vector<vector<int>> ans = sol.threeSum(nums);
//     for (auto it : ans)
//     {
//         for (auto val : it)
//         {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
// }

// Brute Force
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         set<vector<int>> st;
//         if(nums.size() < 4){
//             return {};
//         }
//         if(nums.size() == 4){
//             if(nums[0]+nums[1]+nums[2]+nums[3] == target){
//                 vector<int> vt = {nums[0], nums[1], nums[2], nums[3]};
//                 sort(vt.begin(), vt.end());
//                 st.insert(vt);
//             }
//             vector<vector<int>> ans(st.begin(), st.end());
//             return ans;
//         }
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i + 1; j < nums.size(); j++) {
//                 for (int k = j + 1; k < nums.size(); k++) {
//                     for (int l = k + 1; l < nums.size(); l++) {
//                         long long sum = nums[i] +nums[j];
//                         sum+= nums[k];
//                         sum+= nums[l];
//                         if (sum == target) {
//                             vector<int> vt = {nums[i], nums[j], nums[k],
//                                               nums[l]};
//                             sort(vt.begin(), vt.end());
//                             st.insert(vt);
//                         }
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin(), st.end());
//         return ans;
//     }
// };

// Better solution same as three sum

// class Solution
// {
// public:
//     vector<vector<int>> fourSum(vector<int> &nums, int target)
//     {
//         set<vector<int>> st;
//         if (nums.size() < 4)
//         {
//             return {};
//         }
//         if (nums.size() == 4)
//         {
//             if (nums[0] + nums[1] + nums[2] + nums[3] == target)
//             {
//                 vector<int> vt = {nums[0], nums[1], nums[2], nums[3]};
//                 sort(vt.begin(), vt.end());
//                 st.insert(vt);
//             }
//             vector<vector<int>> ans(st.begin(), st.end());
//             return ans;
//         }

//         for (int i = 0; i < nums.size(); i++)
//         {

//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 set<int> hashst;
//                 for (int k = j + 1; k < nums.size(); k++)
//                 {
//                     long long sum = nums[i] + nums[j];
//                     sum += nums[k];
//                     int fourth = target - sum;
//                     if (hashst.find(fourth) != hashst.end())
//                     {
//                         vector<int> vt = {nums[i], nums[j], nums[k], fourth};
//                         sort(vt.begin(), vt.end());
//                         st.insert(vt);
//                     }
//                     hashst.insert(nums[k]);
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin(), st.end());
//         return ans;
//     }
// };
// class Solution
// {
// public:
//     vector<vector<int>> fourSum(vector<int> &nums, int target)
//     {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         if (nums.size() < 4)
//         {
//             return ans;
//         }
//         if (nums.size() == 4)
//         {
//             long long sum = nums[0] + nums[1] + nums[2] + nums[3];
//             if(sum == target){
//                 ans.push_back({nums[0], nums[1], nums[2], nums[3]});
//             }
//             return ans;
//         }
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (i > 0 && nums[i - 1] == nums[i])
//                 continue;
//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 if (j > i + 1 && nums[j - 1] == nums[j])
//                     continue;
//                 int k = j + 1, l = nums.size() - 1;
//                 while (k < l)
//                 {
//                     long long sum = nums[i] + nums[j] + nums[k] + nums[l];
//                     if (sum == target)
//                     {
//                         ans.push_back({nums[i], nums[j], nums[k], nums[l]});
//                         k++, l--;
//                         while (k < l && nums[k] == nums[k - 1])
//                             k++;
//                         while (k < l && nums[l] == nums[l + 1])
//                             l--;
//                     }
//                     else if (sum > target)
//                     {
//                         l--;
//                     }
//                     else
//                     {
//                         k++;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };
// int main()
// {
//     Solution sol;
//     vector<int> nums = {1, 0, 0, 0};
//     int target = 0;
//     vector<vector<int>> ans = sol.fourSum(nums, target);
//     for (auto it : ans)
//     {
//         for (auto val : it)
//         {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
// }

// Longest subarray with 0 sum

// class Solution
// {
// public:
//     int maxLength(vector<int> &arr)
//     {
//         int count = 0;
//         for (int i = 0; i < arr.size(); i++)
//         {

//             int sum = arr[i];
//             for (int j = i + 1; j < arr.size(); j++)
//             {
//                 sum += arr[j];
//                 int cur_count = 0;

//                 if (sum == 0)
//                 {
//                     cur_count = j - i + 1;
//                 }

//                 count = max(count, cur_count);
//             }
//         }
//         if (count == 0)
//         {
//             for (int i = 0; i < arr.size(); i++)
//             {
//                 if (arr[i] == 0)
//                 {
//                     count = 1;
//                 }
//             }
//         }

//         return count;
//     }
// };

// optimal solution
// class Solution
// {
// public:
//     int maxLength(vector<int> &arr)
//     {
//         unordered_map<int, int> hashmpp;
//         int sum = 0;
//         int max_len = 0;

//         for (int i = 0; i < arr.size(); i++)
//         {
//             sum += arr[i];
//             if (sum == 0){
//                 max_len = i+1;
//             }
//             else{
//                 if(hashmpp.find(sum) != hashmpp.end()){
//                     max_len = max(max_len, i- hashmpp[sum]);
//                 }
//                 else{
//                     hashmpp[sum] = i;
//                 }
//             }
//         }
//         return max_len;
//     }
// };

// 07) Merge overlapping Subintervals

// class Solution
// {
// public:
//     vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
//     {
//         vector<vector<int>> ans;
//         sort(arr.begin(), arr.end());
//         for (int i = 0; i < arr.size(); i++)
//         {
//             if(ans.empty() || ans.back()[1] < arr[i][0]){
//                 ans.push_back(arr[i]);
//             }
//             else{
//                 ans.back()[1] = max(arr[i][1], ans.back()[1]);
//             }
//         }
//         return ans;
//     }
// };

// int main()
// {
//     Solution sol;
//     vector<vector<int>> nums = {{1, 3},{2, 4},{6, 8},{9, 10}};
//     vector<vector<int>> ans = sol.mergeOverlap(nums);
//     for (auto it : ans)
//     {
//         for (auto val : it)
//         {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
// }

// class Solution
// {
// public:
//     void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
//     {
//         for (int i = m; i < nums1.size(); i++)
//         {
//             nums1[i] = nums2[i - n];
//         }
//         sort(nums1.begin(), nums1.end());
//     }
// };

// Merge two sorted arrays without extra space

// VAriant 1
// IN this solution we have to return both array in sorted order without changing their sizes like in this example
//  nums1 = {1, 4, 8, 10}, nums2 = {2, 3, 9};
// 1 2 3 4
// 8 9 10
// class Solution{
// public:
//     void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
//     {
//         vector<int> combined;
//         for (int i = 0; i < m; i++)
//         {
//             combined.push_back(nums1[i]);
//         }
//         for (int i = 0; i < n; i++)
//         {
//             combined.push_back(nums2[i]);
//         }
//         sort(combined.begin(), combined.end());
//         int j = 0;
//         for (int i =0; i<combined.size(); i++){
//             if(i<m){
//                 // nums1[i] = combined[i];
//                 nums1[i] = combined[i];
//             }
//             else{
//                 nums2[j] = combined[i];
//                 j++;
//             }
//         }

//     }
// };
// Variant 2 when we have to return the both array combined in first array and also sorted
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         for (int i = 0; i < n; i++)
//         {
//             nums1.push_back(nums2[i]);
//         }
//         sort(nums1.begin(), nums1.end());
//     }
// };

// Variant 3: When in first array already zero are given in place of second array elements -- leetcode variant
// class Solution
// {
// public:
//     void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             nums1[m + i] = nums2[i];
//         }
//         sort(nums1.begin(), nums1.end());
//     }
// };

// int main()
// {
//     Solution sol;
//     vector<int> nums1 = {1, 4, 8, 10, 0, 0, 0}, nums2 = {2, 3, 9};
//     int m = 4, n = 3;
//     sol.merge(nums1, m, nums2, n);

//     for (auto it : nums1)
//     {
//         cout << it << " ";
//     }
//     // cout << endl;
//     // for (auto it : nums2)
//     // {
//     //     cout << it << " ";
//     // }
// }

// Maximum product subarray

// Brute Force
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         if(nums.size() == 1){
//             return nums[0];
//         }
//         int max_prod = INT_MIN;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int prod = nums[i];
//             max_prod = max(max_prod, prod);
//             for (int j = i+1; j < nums.size(); j++)
//             {
//                 prod *= nums[j];
//                 max_prod = max(max_prod, prod);
//             }

//         }

//         return max_prod;
//     }
// };

// optimal approach
// class Solution
// {
// public:
//     int maxProduct(vector<int> &nums)
//     {
//         int max_prod = INT_MIN;
//         int suf = 1, pre = 1;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (pre == 0)
//                 pre = 1;
//             if (suf == 0)
//                 suf = 1;
//             pre *= nums[i];
//             suf *= nums[nums.size() - i - 1];\

//             max_prod = max(max_prod, max(pre, suf));
//         }
//         return max_prod;
//     }
// };

// Find the repeating and missing number

// better solution

// class Solution {
//   public:
//     vector<int> findTwoElement(vector<int>& arr) {
//         map<int, int> mpp;
//         int sum = 0;
//         int maxi = arr[0];
//         for (int i = 0; i < arr.size(); i++)
//         {
//             maxi = max(maxi, arr[i]);
//             mpp[arr[i]]++;
//         }

//         int missing ;
//         int total_sum = 0;
//         for (int i = 1; i <= maxi; i++)
//         {
//             total_sum += i;
//         }

//         int repeating;
//         for(auto it:mpp){
//             sum += it.first;
//             if(it.second != 1){
//                 repeating = it.first;
//             }
//         }
//         if( total_sum-sum == 0){
//             missing = arr.size();
//         }
//         else{
//             missing = total_sum-sum ;
//         }
//         return {repeating, missing };
//     }
// };

// optimal soltution (using maths - using two equations)

// class Solution {
//   public:
//     vector<int> findTwoElement(vector<int>& arr) {
//         int n = arr.size();
//         long long Sn,S2n;
//         Sn = (n*(n+1))/2;
//         S2n = ((n*(n+1))*(2*n+1))/6;
//         long long s =0, s2 = 0;
//         for (int i = 0; i < arr.size(); i++)
//         {
//             s+= arr[i];
//             s2+= arr[i]*arr[i];
//         }
//         long long val1 = s - Sn;
//         long long val2 = s2 - S2n;
//         val2 = val2/val1;
//         long long x = (val1 + val2)/2; // repeating
//         long long y = x - val1;  // missing

//         return {(int)x,(int)y};
//     }
// };

class Solution
{
public:
    long long int numberOfInversions(vector<int> nums)
    {
        long long count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if(nums[j]<nums[i]){
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5,3,2,1,4};
    long long ans = sol.numberOfInversions(nums);
    cout << ans;
}