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

// 07) Rearrange Array Elements by Sign
// Example :

// Input:
// arr[] = {1,2,-4,-5}, N = 4
// Output:
// 1 -4 2 -5

// Explanation:

// Positive elements = 1,2
// Negative elements = -4,-5
// To maintain relative ordering, 1 must occur before 2, and -4 must occur before -5.
// vector<int> alternateNumbers(vector<int>&a) {
//     int count1 = 0;
//     int count2 = 0;
//     vector<int> b(a.size()/2);
//     vector<int> c(a.size()/2);
//     for(int i = 0; i<a.size(); i++){
//         if(a[i]<0){
//             b[count1] = a[i];
//             count1++;
//         }
//         else{
//             c[count2] = a[i];
//             count2++;
//         }
//     }
//     count1 = 0, count2 = 0;

//     for (int i = 0; i < a.size(); i++)
//     {
//         if(i%2==0){
//             a[i] = c[count2];
//             count2++;
//         }
//         else{
//             a[i] = b[count1];
//             count1++;
//         }
//     }

//     return a;
// }

// When order does not matter
// vector<int> alternateNumbers(vector<int>&nums) {
//     int pos_idx = 0;
//     int neg_idx = 1;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if(nums[i] >= 0 && pos_idx < nums.size()){
//             swap(nums[i], nums[pos_idx]);
//             pos_idx+=2;
//         }
//         else if(nums[i]<0 && neg_idx < nums.size()){
//             swap(nums[i], nums[neg_idx]);
//             neg_idx+=2;
//         }
//     }
//     return nums;

// }
// int main(){
//     vector<int> a = {1,2,-4,-5,3,-6};
//     vector<int>ans;
//     ans = alternateNumbers(a);
//     for(auto it:ans){
//         cout<<it;
//     }
// }

// // 08) Next permutation   ---- >>> did not complete
// // Example :

// // Input format: Arr[] = {1,3,2}
// // Output: Arr[] = {2,1,3}
// // Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {

//     }
// };

// int main(){
//     vector<int> nums = {1,3,2};
//     Solution sol;
//     sol.nextPermutation(nums);
// }

// 09) Leader in Array

// Example 1:
// Input:
//  arr = [4, 7, 1, 0]
// Output:
//  7 1 0
// Explanation:
//  Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side

// int main(){
//     vector<int> nums = {61, 61, 17};
//     int largest = nums[nums.size()-1];
//     vector<int> ans;
//     ans.push_back(largest);
//     for (int i = nums.size()-2; i >= 0; i--)
//     {
//         if(nums[i] >= largest){
//             largest = nums[i];
//             ans.push_back(largest);
//         }
//     }
//     reverse(ans.begin(), ans.end());
//     for(auto it: ans){
//         cout<<it<<" ";
//     }
// }

// 10) Longest Consecutive Sequence in an Array
// Example 1:

// Input: [100, 200, 1, 3, 2, 4]

// Output: 4

// Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

// int main(){
//     vector<int> nums = {1,0,1,2};
//     int count = 0;
//     int curr_count = 0;
//     sort(nums.begin(), nums.end());
//     for (int i = 1; i < nums.size(); i++)
//     {
//         if(nums[i] ==  nums[i-1]+1){
//             curr_count++;
//         }
//         else if(nums[i] == nums[i-1]){

//         } else{
//             curr_count = 0;
//         }
//         count = max(count, curr_count);
//     }
//     cout<<"Count  = "<<count+1;
// }

//  taking same or more time as prev
// int main()
// {
//     vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6};
//     set<int> st;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         st.insert(nums[i]);
//     }
//     int count = 0;
//     int curr_count = 0;
//     for(auto it:st){
//         cout<<it<<" ";
//     }
//     cout<<endl;
//     for (auto it = st.begin(); it != st.end(); ++it)
//     {
//         if(next(it) != st.end() && *next(it) == *it + 1){
//             curr_count++;
//         }
//         else{
//             curr_count = 0;
//         }
//         count = max(curr_count, count);
//     }
//    cout<<count+1;
// // }
// --->>> Did not understand it at all
// int main(){
//     vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6};
//     if(nums.size()<1){
//         cout<<0;
//     }
//     int count = 0;
//     unordered_set<int> st;
//     for(int i = 0; i<nums.size(); i++){
//         st.insert(nums[i]);
//     }
//     for(int it:st){
//         if(st.find(it-1) == st.end()){
//             int cnt = 1;
//             int x =it;
//             while (st.find(x+1) != st.end())
//             {
//                 x =  x+1;
//                 cnt++;
//             }
//         count = max(count, cnt);
//         }
//     }
// }

// 11) Set Matrix Zero

// Examples 1:
// Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.

// this is so bad solution done by me On^4
// int main()
// {
//     vector<vector<int>> mat = {{1,1,1}, {1,0,1}, {1,1,1}};
//     vector<pair<int, int>> p;

//     for (int i = 0; i < mat.size(); i++)
//     {
//         for (int j = 0; j < mat[i].size(); j++)
//         {
//             cout << mat[i][j] << " ";
//             if (mat[i][j] == 0)
//             {
//                 p.push_back({i, j});
//             }
//         }
//         cout << endl;
//     }
//     for (auto it : p)
//     {
//         cout << it.first << " " << it.second << endl;
//         for (int i = 0; i < mat.size(); i++)
//         {
//             for (int j = 0; j < mat[i].size(); j++)
//             {
//                 if (i == it.first && j == it.second)
//                 {
//                     int k =0;
//                     while (k<mat[i].size())
//                     {
//                         mat[i][k] = 0;
//                         k++;
//                     }
//                     k=0;
//                     while (k<mat.size())
//                     {
//                         mat[k][j] = 0;
//                         k++;
//                     }
//                 }
//             }
//         }
//     }
//     for (int i = 0; i < mat.size(); i++)
//     {
//         for (int j = 0; j < mat[i].size(); j++)
//         {
//             cout << mat[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// better than before On^3
// int main()
// {
//     vector<vector<int>> mat = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
//     for (int i = 0; i < mat.size(); i++)
//     {
//         for (int j = 0; j < mat[i].size(); j++)
//         {

//             if (mat[i][j] == 0)
//             {
//                 int k = 0;
//                 while (k < mat[i].size())
//                 {
//                     mat[i][k] = -1;
//                     k++;
//                 }
//                 k = 0;
//                 while (k < mat.size())
//                 {
//                     mat[k][j] = -1;
//                     k++;
//                 }
//             }
//         }
//     }

//     for (int i = 0; i < mat.size(); i++)
//     {
//         for (int j = 0; j < mat[i].size(); j++)
//         {
//             if(mat[i][j] == -1){
//                 mat[i][j] = 0;
//             }
//             cout << mat[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// better than before

// int main(){
//      vector<vector<int>> mat = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
//      vector<int> col(mat[0].size());
//      vector<int> row(mat.size());
//     for (int i = 0; i < mat.size(); i++)
//     {
//         for (int j = 0; j < mat[i].size(); j++)
//         {

//             if (mat[i][j] == 0)
//             {
//                row[i] = 1;
//                col[j] = 1;
//             }
//         }
//     }
//     for (int i = 0; i < mat.size(); i++)
//     {
//         for (int j = 0; j < mat[i].size(); j++)
//         {
//             if(col[j] == 1 || row[i] ==1){
//                 mat[i][j] = 0;
//             }
//             cout << mat[i][j] << " ";
//         }
//         cout << endl;
//     }

// }

// Best approach
// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

//     // int row[n] = {0}; --> matrix[..][0]
//     // int col[m] = {0}; --> matrix[0][..]

//     int col0 = 1;
//     // step 1: Traverse the matrix and
//     // mark 1st row & col accordingly:
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] == 0) {
//                 // mark i-th row:
//                 matrix[i][0] = 0;

//                 // mark j-th column:
//                 if (j != 0)
//                     matrix[0][j] = 0;
//                 else
//                     col0 = 0;
//             }
//         }
//     }

//     // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
//     for (int i = 1; i < n; i++) {
//         for (int j = 1; j < m; j++) {
//             if (matrix[i][j] != 0) {
//                 // check for col & row:
//                 if (matrix[i][0] == 0 || matrix[0][j] == 0) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }

//     //step 3: Finally mark the 1st col & then 1st row:
//     if (matrix[0][0] == 0) {
//         for (int j = 0; j < m; j++) {
//             matrix[0][j] = 0;
//         }
//     }
//     if (col0 == 0) {
//         for (int i = 0; i < n; i++) {
//             matrix[i][0] = 0;
//         }
//     }

//     return matrix;
// }

// int main()
// {
//     vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
//     int n = matrix.size();
//     int m = matrix[0].size();
//     vector<vector<int>> ans = zeroMatrix(matrix, n, m);

//     cout << "The Final matrix is: n";
//     for (auto it : ans) {
//         for (auto ele : it) {
//             cout << ele << " ";
//         }
//         cout << "n";
//     }
//     return 0;
// }

// Rotate matrix by 90 degree
// Brute force approach
// int main(){

//     vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
//     vector<vector<int>> ans_mat = matrix;

//     for (int i =0; i < matrix.size(); i++)
//     {
//        for (int j = matrix[i].size()-1; j >=0; j--)
//        {
//             cout<<ans_mat[j][i]<<" ";
//        }
//        cout<<endl;

//     }

// }
// better approach with time of O(n²) and space of	O(1)
// int main(){
//     vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
//     for (int i = 0; i < matrix.size(); i++)
//     {
//         for (int j = i+1; j < matrix.size(); j++)
//         {
//            if(i == j){

//            }
//            else{
//             swap(matrix[i][j], matrix[j][i]);
//            }

//         }

//     }

//     for (int i = 0; i < matrix.size(); i++)
//     {
//         reverse(matrix[i].begin(), matrix[i].end());
//     }
//     for (int i = 0; i < matrix.size(); i++)
//     {
//         for (int j = 0; j < matrix.size(); j++)
//         {
//             cout<<matrix[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

// Spiral Traversal of Matrix
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   vector<int> ans;
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;

        while (left <= right && top <= bottom) {
            // Traverse top row
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;

            // Traverse right column
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;

            // Traverse bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;                                                                   

            }

            // Traverse left column
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }
    
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

// Example 1:
// Input Format: N = 3, k = 5, array[] = {2,3,5}
// Result: 2
// Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

// Example 2:
// Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
// Result: 3
// Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.

// int main()
// {
//     vector<int> nums = {1, 2, 3};
//     int act_count = 0;
//     int k = 3;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         int sum = 0;
//         int count = 0;
//         for (int j = i; j < nums.size(); j++)
//         {
//           sum += nums[j];
//           if(sum == k){
//             act_count = max(act_count, j-i+1);
//           }
//         }
//     }
//     cout<<act_count;
// }