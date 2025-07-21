#include <bits/stdc++.h>
using namespace std;
// Contest ques no 1
// class Solution
// {
// public:
//     bool isPrime(int n)
//     {
//         if (n == 0 || n == 1)
//         {
//             return false;
//         }
//         for (int i = 2; i <= sqrt(n); i++)
//         {
//             if (n % i == 0)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
//     long long splitArray(vector<int> &nums)
//     {
//         vector<int> A;
//         vector<int> B;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (isPrime(i))
//             {
//                 A.push_back(nums[i]);
//             }
//             else
//             {
//                 B.push_back(nums[i]);
//             }
//         }
//         long sumA = 0;
//         long sumB = 0;
//         for(int i=0; i<A.size(); i++){
//             sumA += A[i];
//         }
//         for(int i=0; i<B.size(); i++){
//             sumB += B[i];
//         }

//         cout<<sumA<<" "<<sumB;
//         long ans = abs(sumA-sumB);
//         return ans;
//     }
// };

// sunday contest ques 1

// class Solution
// {
// public:
//     int count(int n){
//          if (n == 0) return 1;
//     int count = 0;
//     while (n != 0) {
//         n = n / 10;
//         count++;
//     }
//     return count;
//     }
//     bool checkDivisibility(int n){

//         string s = to_string(n);
// // if(s.length() <= 1){
// //     return true;
// // }
//         int sum = 0;
//         int prod=1;
//         int digita ;
//         for (int i = 0; i < s.length(); i++)
//         {
//             int digit = s[i] - '0';
//             sum = sum + digit;
//             prod = prod * digit;
//         }
//         if(n % (sum+prod) == 0){
//             return true;
//         }
//         return false;
//     }

// };


// Unable to do this ques
// class Solution {
// public:
//     int countTrapezoids(vector<vector<int>>& points) {
//         int count = 0;
//         int xaxis = 0;
//         for(int i=0; i<points.size(); i++){ 
//             for (int j = 0; j < points[j].size(); j++)
//             {
//                 for(int k = 1; i<points.size(); i++){
//                     if(points[i][1] == points[k][1]){
//                         xaxis++; 
//                         break;
//                     }
//                 }
//             }
//         }
        
//         if(xaxis > 3){
//              return xaxis -3;
//         }
//         return 0;
       
//     }
// };
// int main()
// {
//     Solution sol;
//     // vector<vector<int>> nums = {{1,0},{2,0},{3,0},{2,2},{3,2}};
//     vector<vector<int>> nums = {{-99,-79}, {30, -60}, {-70, -60}, {61, 50}};
//     int ans = sol.countTrapezoids(nums);
//     cout << ans;
// }