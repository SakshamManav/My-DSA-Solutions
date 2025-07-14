#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// selection sort
// int main() {
//     // Your code here
//     int arr[] = {23,452,45,32,2,0,12};
//     int sizeOfArr = sizeof(arr)/sizeof(int);
//     // cout<<sizeOfArr;
//     int sortedArr[sizeOfArr] = {0};

//     for (int i = 0; i < sizeOfArr ; i++)
//     {
//         int minN = arr[i];
//         for (int j = i+1; j < sizeOfArr; j++)
//         {
//             if(arr[i]>arr[j]){
//                 swap(arr[i], arr[j]);
//             }
//         }
        
        
//     }
//     for (int i = 0; i < sizeOfArr; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
    
    
//     return 0;
// }

// Actual selection sorting
// int main() {
//     int arr[] = {23,452,45,32,2,0,12};
//     int sizeOfArr = sizeof(arr)/sizeof(int);

//     for (int i = 0; i < sizeOfArr ; i++)
//     {
//         // int minN = arr[i];
//         int minIndex = i;
//         for (int j = i+1; j < sizeOfArr; j++)
//         {
            
//             if(arr[j]<arr[minIndex]){
//                 minIndex = j;
//             }
//         }
//         if(minIndex != i){
//             swap(arr[i], arr[minIndex]);
//         }
        
//     }
//     for (int i = 0; i < sizeOfArr; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
    
    
//     return 0;
// }

// Bubble sort

// int main(){
//     int arr[] = {23,452,45,32,2,0,12};
//     int arrSize = sizeof(arr)/sizeof(int);
//     int count = 0;
//     for (int i = 0; i < arrSize; i++)
//     {
//         for (int j = 0; j < arrSize-1; j++)
//         {
//              if(arr[j]>arr[j+1]){
//             swap(arr[j], arr[j+1]);
//         }   
//         }
        
       
//     }
//     for (int i = 0; i < arrSize; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<"\n"<<count;
    
// }

// Insertion Sort

// int main(){
//     vector <int> arr = {23,452,45,32,2,0,12};
    
//     for (int i = 0; i < arr.size()-1; i++)
//     {
  
//         if(arr[i]>arr[i+1]){
//             for (int j = i+1; j > 0; j--){
//                 if(arr[j]<arr[j-1]){
                   
//                     swap(arr[j], arr[j-1]);
                
//                 }
//             }
//         }
//     }
//     for (int i = 0; i < arr.size(); i++)
//     {
//         cout<<arr[i]<<" ";
//     }

// ---->>>>> actual One <<<<<------------
    // vector <int> arr = {23,452,45,32,2,0,12};
    // for (int i = 1; i < arr.size(); i++)
    // {
    //     int j = i;
    //     while (j>0 && arr[j]<arr[j-1])
    //     {
    //         int temp;
    //         // temp = arr[j];
    //         // arr[j] = arr[j-1];
    //         // arr[j-1] = temp;
    //        swap(arr[j], arr[j-1]);
    //         j--;
    //     }
    // }
    //  for (int i = 0; i < arr.size(); i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
// }


//  MERGE SORT

// void merging_sorted_arrays(vector<int> &arr, int low, int mid, int high){
//     vector <int> temp;

//     int i = low;
//         int j = mid+1;
//     while (i <= mid && j <= high)
//     {
        
//         if(arr[i] <= arr[j]){
//             temp.push_back(arr[i]);
//             i++;
//         }
//         else{
//             temp.push_back(arr[j]);
//             j++;
//         }
//     }
    
//     while (i <= mid) {
//         temp.push_back(arr[i]);
//         i++;
//     }

//     while (j <= high) {
//         temp.push_back(arr[j]);
//         j++;
//     }
//    for (int k = 0; k < temp.size(); k++) {
//         arr[low + k] = temp[k];
//     }


// }
// void splitting_array(vector <int> &arr, int low, int high){
//     if(low >= high){
//         return;
//     }
//     int mid = (low+high)/2;
   
//     splitting_array(arr, low, mid);
//     splitting_array(arr, mid +1, high);
//     merging_sorted_arrays(arr, low, mid, high);
// }
// int main(){
//     vector <int> arr = {23,452,45,32,2,0,12};
//     splitting_array(arr, 0, arr.size()-1);
//     cout << "Sorted array: ";
//     for (int x : arr)
//         cout << x << " ";
//     cout << endl;

//     return 0;
    
// }
// int fibonacci(int n){
//     if(n==1 || n==0){
//         return 1;
//     }
//     return (n * fibonacci(n-1));
// }
// int main(){
//     cout<<fibonacci(0);
// }

// class Solution {
// public:
// void merging_sorted_arrays(vector<int>& arr, int low, int mid, int high ){
//     vector <int> temp;
//     int left = low;
//     int right = mid+1;

//     while(left <= mid && right <= high){
//         if(arr[left]<= arr[right]){
//            temp.push_back(arr[left]);
//             left ++;
//         }
//         else{
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }
//       while (left <= mid) {
//             temp.push_back(arr[left]);
//             left++;
//         }

//         while (right <= high) {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     for(int i =0; i< temp.size(); i++){
//         arr[low + i] = temp[i];
//     }
// }
// void splitting_array(vector<int> &arr, int low, int high){
//     if(low>= high){
//         return;
//     }
//    int mid = (low+high)/2;
//     splitting_array(arr, low, mid);
//     splitting_array(arr, mid +1, high);

//     merging_sorted_arrays(arr, low, mid, high);
// }
// vector<int> merge_sort(vector<int>& nums) {
//         splitting_array(nums, 0, nums.size()-1);
//         return nums;
//     }
// };

// int main(){
//     Solution obj;
//     vector<int> arr = {23,452,45,32,2,0,12};
//     vector<int> ans = obj.merge_sort(arr);
//     for(auto it: ans){
//         cout<<it<<" ";
//     }
// }

// Quick Sort

int find(vector <int> & arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i<= high-1)
        {
            i++;
        }
        while (arr[j] > pivot && i>=low+1)
        {
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void quick_sort(vector<int> & arr, int low, int high){
    if(low < high){
        int partition = find(arr, low, high);
        quick_sort(arr, low, partition-1);
        quick_sort(arr, partition + 1, high);
    }
}


int main(){
    vector<int> arr ={23,452,45,32,2,0,12};
    quick_sort(arr,0, arr.size()-1);
    for(auto it : arr){
        cout<< it << " ";
    }
}