#include <bits/stdc++.h>
using namespace std;

// 01) ---->>> Find the largest Number----->>>>>>>>>
// Example :
// Input: arr[] = {2,5,1,3,0};
// Output: 5
// Explanation: 5 is the largest element in the array.

// int main(){
// vector<int> arr = {101,2,5,1,3,7,8,9,0};
// 1st method - linear search
// int largest = arr[0];
// for (int i = 0; i < arr.size(); i++)
// {
//     if(arr[i]>largest){
//         largest = arr[i];
//     }
// }
// cout<<largest<<" is the largest number in the given array"<<endl;

// 2nd method - by sorting
// vector<int> arr = {101,2,5,1,3,7,8,9,0};
// sort(arr.begin(), arr.end());

// for (int i = 0; i < arr.size(); i++)
// {
//     int min_index = i;
//     for (int j = i+1; j < arr.size(); j++)
//     {
//         if(arr[min_index] > arr[j]){
//             min_index = j;
//         }
//     }
//     if(min_index != i){
//         swap(arr[min_index], arr[i]);
//     }
// }
//     for(auto it: arr){
//         cout<<it<< " ";
//     }
//     cout<<"\n"<<arr[arr.size()-1]<<" is the largest number of given array"<<endl;
// }

// 02)  --->>> Find Second Smallest and Second Largest Element in an array without sorting --->>>>
// Example :
// Input: [1,2,4,7,7,5]
// Output: Second Smallest : 2
// 	Second Largest : 5
// Explanation: The elements are as follows 1,2,4,5,7,7 and hence second largest of these is 5 and second smallest is 2

// int main(){
//     vector<int> arr ={1,2,4,7,7,5};
//     int smallest_elem = arr[0];
//     int largest_elem = arr[0];

//     for (int i = 0; i < arr.size()-1; i++)
//     {
//        smallest_elem =  min(arr[i], smallest_elem );
//        largest_elem = max(arr[i], largest_elem);
//     }

//     cout<<"smallest_elem : "<<smallest_elem<< " largest_elem : "<< largest_elem<<endl;

//     int second_smallest_elem=INT_MAX;
//     int second_largest_elem=INT_MIN;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if(arr[i]>second_largest_elem && arr[i]!= largest_elem){
//             second_largest_elem = arr[i];
//         }
//         if(arr[i]<second_smallest_elem && arr[i] != smallest_elem){
//             second_smallest_elem = arr[i];
//         }
//     }

// ------------------------------------------------------------------------
// My attempt -- it is working but time complexity is high and we can also find it using sort but we dont have to do that as mentioned
// for (int i = 0; i < arr.size(); i++)
// {
//     if(arr[i]>smallest_elem){
//         second_smallest_elem = arr[i];
//         for (int j = 0; j < arr.size(); j++)
//         {
//             if(arr[j] == smallest_elem){
//                 continue;
//             }
//             else if(arr[j]<second_smallest_elem){
//                 second_smallest_elem = arr[j];
//             }
//         }
//     }
//     if(arr[i]<largest_elem){
//         second_largest_elem = arr[i];
//         for (int j = 0; j < arr.size(); j++)
//         {
//             if(arr[j] == largest_elem){
//                 continue;
//             }
//             else if(arr[j]>second_largest_elem){
//                 second_largest_elem = arr[j];
//             }
//         }
//     }

// }
//------------------------------------------------------------------

//     cout<<"second_smallest_elem : "<<second_smallest_elem<<" second_largest_elem : "<< second_largest_elem;

// }
// most optimal solution of second problem
// #include<bits/stdc++.h>
// using namespace std;
// int secondSmallest(int arr[],int n)
// {
//     if(n<2)
//         return -1;
//     int small = INT_MAX;
//     int second_small = INT_MAX;
//     int i;
//     for(i = 0; i < n; i++)
//     {
//        if(arr[i] < small)
//        {
//           second_small = small;
//           small = arr[i];
//        }
//        else if(arr[i] < second_small && arr[i] != small)
//        {
//           second_small = arr[i];
//        }
//     }
//    return second_small;
// }
// int secondLargest(int arr[],int n)
// {
// 	if(n<2)
// 	return -1;
//     int large=INT_MIN,second_large=INT_MIN;
//     int i;
//     for (i = 0; i < n; i++)
//     {
//         if (arr[i] > large)
//         {
//             second_large = large;
//             large = arr[i];
//         }

//         else if (arr[i] > second_large && arr[i] != large)
//         {
//             second_large = arr[i];
//         }
//     }
//     return second_large;
// }

// int main() {
//     int arr[]={1,2,4,7,7,5};
//     int n=sizeof(arr)/sizeof(arr[0]);
//         int sS=secondSmallest(arr,n);
//         int sL=secondLargest(arr,n);
//     cout<<"Second smallest is "<<sS<<endl;
//     cout<<"Second largest is "<<sL<<endl;
//     return 0;
// }

// 03) ---->>>> Check if given array is sorted or not
// Example:
// Input: N = 5, array[] = {1,2,3,4,5}
// Output: True.
// Explanation: The given array is sorted i.e Every element in the array is smaller than or equals to its next values, So the answer is True.

// int main(){
//     vector <int> arr =  {10};
//     int isSorted = true;
//     if(arr.size() >1){
// if(arr[0]<=arr[1]){
//             int num = arr[0];
//     for (int i = 1; i < arr.size(); i++)
//     {
//         if(num <= arr[i]){
//             isSorted = true;
//             num = arr[i];
//         }else{
//             isSorted = false;
//             break;
//         }
//     }
// } else if(arr[0]>=arr[1]){
//      int num = arr[0];
//     for (int i = 1; i < arr.size(); i++)
//     {
//         if(num >= arr[i]){
//             isSorted = true;
//             num = arr[i];
//         }else{
//             isSorted = false;
//             break;
//         }
//     }
// }
//     if(isSorted){
//         cout<<"Yes given array is sorted"<<endl;
//     }
//     else{
//         cout<<"Given array is not sorted"<<endl;
//     }
//     }
//     else{
//         cout<<"Yes given array is sorted"<<endl;
//     }
// }

// 04) Check if array is sorted and rotated
// Example 1:
// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].
// int main(){
//     vector<int> arr = {2,1,3,4};
//     int drop = 0;
//     bool isSorted = true;
//     int it=0;
//     for (it = 0; it < arr.size(); it++)
//     {
//         if(arr[it]<=arr[it+1] && it != arr.size()-1){
//             isSorted = true;
//         }
//         else if(arr[it]>arr[it+1] && it != arr.size()-1){
//             isSorted = true;
//             break;
//         }
//     }
//     // cout<<it;
//     for (int i = it+1; i < arr.size(); i++)
//     {
//         if(arr[i]<= arr[i+1] && i != arr.size()-1){
//             isSorted = true;
//         }else if(i == arr.size()-1 && arr[i] <= arr[0]){
//             isSorted = true;
//         }
//         else{
//             isSorted = false;
//             break;
//         }
//     }

//     cout<<isSorted;
// }

// 05) Remove Duplicates in-place from Sorted Array
// Example 1:
// Input: arr[1,1,2,2,2,3,3]
// Output: arr[1,2,3,_,_,_,_]
// Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the beginning of the array.

// int main(){

// My solution ---- >>> taking too much time - On^2
//    vector <int>  arr = {0,1,1,1,1,1,1,2,2,2,3,3};
//    for (int i = 0; i < arr.size()-1; i++)
//    {
//     for (int j = arr.size()-1; j > i; j--)
//     {
//         if(arr[i]==arr[j]){
//            arr.erase(arr.begin() + j);
//         }
//     }
//    }
//    for(auto it:arr){
//     cout<<it<<" ";
//    }
// vector <int>  arr = {0,0,0,1,1,1,1,1,1,2,2,2,3,3};
// My solution again but it is better solution than previous one or i say optimal solution
// vector <int> arr = {1, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6};
//     vector <int> arr = {1,2,3,4,5};
//     bool isSorted = true;
//     // int num = arr[0];
//     int index = 1;
//     for (int i = 1; i < arr.size(); i++)
//     {
//         if(arr[i] != arr[index-1]){
//             // swap(arr[index], arr[i]);
//             // num = arr[index];
//             arr[index] = arr[i];
//             index ++;
//         }
//     }
//     // cout<<"index = "<<index<<endl;
//     for(auto it:arr){
//         cout<<it<<" ";
//     }

// }

// 06) ---- >>>>  Left Rotate the Array by One
// Example 1:
// Input: N = 5, array[] = {1,2,3,4,5}
// Output: 2,3,4,5,1
// Explanation:
// Since all the elements in array will be shifted
// toward left by one so ‘2’ will now become the
// first index and and ‘1’ which was present at
// first index will be shifted at last.


// int main()
// {
    // Brute force approach
    // vector<int> arr = {1,2,3,4,5,6,7};
    // int k = 3;
    // string direction = "right";

    // int i = 0;
    // if (arr.size() > 1 && direction == "left") // when we have to shift the elements in left side by k position
    // {
    //     while (i < k)
    //     {
    //         int first_elem = arr[0];
    //         for (int i = 0; i < arr.size()-1; i++)
    //         {
    //             arr[i] = arr[i + 1];
    //         }
    //         arr[arr.size() - 1] = first_elem;
    //         i++;
    //     }
    // }
    // else if(arr.size() > 1 && direction == "right"){  // when we have to shift the elements in right side by k position
    //     while (i < k)
    //     {
    //         int last_elem = arr[arr.size()-1];
    //         for (int i = arr.size()-1; i > 0; i--)
    //         {
    //             arr[i] = arr[i-1];
    //         }
    //         arr[0] = last_elem;
    //         i++;
    //     }
    // }

    // IN this it only takes One loop so time complexity is lesser than but using much space
    // vector<int> arr = {1,2,3,4,5,6,7};
    // int k =3;
    // int t = k % nums.size(); { for k > arr.size() we are using this}

    // vector <int> temp(arr.size());
    // for (int i = arr.size()-1; i >= 0; i--)
    // {
    //     int j = i-k;
    //     if(j>=0){
    //         temp[i] = arr[j];
    //     }
    //     else if(j<0){
    //         j = (arr.size())+j;
    //         temp[i] = arr[j];
    //     }

    // }
    
    // swap(arr, temp);
    // for(auto it:arr){
    //     cout<<it<<" ";
    // }

    // Optimal Solution
    
    // for left rotate
    // vector<int> arr = {1,2,3,4,5,6,7};
    // int k =3;
    
    // reverse(arr.begin(), arr.begin()+k);
    // reverse(arr.begin() + k, arr.end());
    // reverse(arr.begin(), arr.end());
    //  for(auto it:arr){
    //     cout<<it<<" ";
    // }

    // // for right rotate
    // vector<int> nums = {1,2,3,4,5,6,7};
    // int k =8;
    //     k = k % nums.size();
    //     reverse(nums.begin(), nums.end() - k);
    //     reverse(nums.end() - k, nums.end());
    //     reverse(nums.begin(), nums.end());
    //   for(auto it:nums){
    //     cout<<it<<" ";
    // }
// }

// 07) Move all Zeros to the end of the array

// Example :
// Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
// Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
// Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order


// int main(){
    // Not optimal solution - using On^2 time
    // vector<int> nums = { 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1};
    // for(int i = nums.size()-1; i>=0; i--){
    //         if(nums[i] == 0){
    //             nums.push_back(nums[i]);
    //             nums.erase(nums.begin() + i);
    //         }
    //     }

    // Optimal Solution
    // vector<int> nums = { 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1};
    // int j = -1;
    // for (int i = 0; i < nums.size() ; i++)
    // {
    //     if(nums[i] == 0){
    //         j = i; // Here we found the first instance or place of first zero in the array in left to right direction
    //         break;
    //     }
    // }
    // if(j == -1){
    //     return -1;
    // }
    // else{
    //     for (int i = j+1; i < nums.size(); i++)
    // {
    //     if(nums[i] != 0){
    //         swap(nums[i], nums[j]);
    //         j++;
    //     }
    // }
    // }
    
    // for(auto it: nums){
    //     cout<<it<<" ";
    // }
    

    // }
//  08) Find the Union of Two Sorted Arrays
// Example :
// Input:
// n = 5,m = 5.
// arr1[] = {1,2,3,4,5}  
// arr2[] = {2,3,4,4,5}
// Output:
//  {1,2,3,4,5}

// Explanation: 
// Common Elements in arr1 and arr2  are:  2,3,4,5
// Distnict Elements in arr1 are : 1
// Distnict Elemennts in arr2 are : No distinct elements.
// Union of arr1 and arr2 is {1,2,3,4,5} 
    
    // int main(){
    //     int arr1[] = {1,2,4,5};  
    //     int arr2[] = {7};
    //     int n = 4, m= 1;
    //    set <int> s;
    //    for (int i = 0; i < n; i++)
    //    {
    //     s.insert(arr1[i]);
    //    }
       
    //     for (int i = 0; i < m; i++)
    //     {
    //         s.insert(arr2[i]);
    //     }
        
    //     for(auto it:s){
    //         cout<<it;
    //     }
    // }


// 09) Find the missing number.
// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
// Example :
// Input Format: N = 5, array[] = {0,1,2,4,5}
// Result: 3
// Explanation: In the given array, number 3 is missing. So, 3 is the answer.

int main(){
    // Solved by me - takes much time and space
    // vector <int> nums = {0,1,2,3,5};
    // bool yes_is_present;
    // int ans;
    //     for(int i =0; i< nums.size(); i++){
    //         yes_is_present = false;
    //         for(int j=0; j< nums.size(); j++){
    //             if(i == nums[j]){
    //                 yes_is_present = true;
    //                 break;
    //             }
               
    //         }
    //         if(!yes_is_present){
    //             ans = i;
    //             break;
    //         }
        
    // }
    // // int ans;
    // cout << ans<< " is the missing number"<<endl;

    // Better than previous one - also done by me
    // sort(nums.begin(), nums.end());
    //     int ans;
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (i != nums[i]) {
    //             return i;
    //         }
    //     }
    //     return nums.size();

    // Another Solution --
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//        int actual_sum = 0, actual_sum2 = 0;
//        for(int i = 0; i<=nums.size(); i++){
//         actual_sum += i;
//        }
//        for(int i=0; i< nums.size(); i++){
//         actual_sum2 += nums[i];
//        }
//        return actual_sum - actual_sum2;
//     }
// };


// Another Solution 
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//             unordered_map<int ,int> mp;
//             for(int i =0; i< nums.size(); i++){
//                 mp[nums[i]] = 1;
//             }
//             for(int i =0; i<nums.size(); i++){
//                 if(mp[i] != 1){
//                     return i;
//                 }
//             }
//             return nums.size();
//     }
// };


//     This problem can be solved by 3 methods:
// 1.Hashing
// 2.Sum Formula

// Bit manupulation i.e using XOR.
// Lets dicuss this method that which is more effiecient and why it has to be used:-

// HASHING :- In this Method, We can iterate over all the element upto the n and compare it with the present element by creating the hash map of (n+1).
// Time Complexity = O(n)
// Space complexity =O(n)
// Issue :- Though it is taking the space complexity of N, So we move on to the next Method.
// Sum Formula :- In this we us e the sum formula i.e;
// Sn = (N+1)/2 & Sum of all the array(Sa[]).
// And after this we subtract the (Sn-Sa[]) to find the Missing Number.
// Time Complexity = O(n)
// Space complexity =O(1)
// Issue :- It can cause the Overflow issue because in this we are adding the element, So if the array element is very large then it can cause Integer Overflow.
// To handle out this Overflow we can use the Next Method which is XOR Bit Manipulation.

// XOR Bit Manipulation :- In this we take the XOR of given array and the first n natural number.
// Time Complexity = O(n)
// Space complexity =O(1)
// No Overflow.
// Hope you find this useful.
}