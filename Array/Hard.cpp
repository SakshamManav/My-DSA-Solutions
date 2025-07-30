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

class Solution
{
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
    {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            if(ans.empty() || ans.back()[1] < arr[i][0]){
                ans.push_back(arr[i]);
            }   
            else{
                ans.back()[1] = max(arr[i][1], ans.back()[1]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> nums = {{1, 3},{2, 4},{6, 8},{9, 10}};
    vector<vector<int>> ans = sol.mergeOverlap(nums);
    for (auto it : ans)
    {
        for (auto val : it)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}
