#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void splitting_array(vector<int> &nums, int low, int high){
        if(low >= high) return;

        int mid = (low + high) / 2;

        // Print current split
        cout << "Splitting: [";
        for(int i=low;i<=high;i++) cout << nums[i] << (i==high? "":",");
        cout << "] into [";
        for(int i=low;i<=mid;i++) cout << nums[i] << (i==mid? "":",");
        cout << "] and [";
        for(int i=mid+1;i<=high;i++) cout << nums[i] << (i==high? "":",");
        cout << "]" << endl;

        // recursive calls
        splitting_array(nums, low, mid);    // left half ✅
        splitting_array(nums, mid+1, high); // right half ✅
    }

    vector<int> mergeSort(vector<int> nums){
        int low = 0, high = nums.size()-1;
        splitting_array(nums, low, high);
        return nums; // just returning unchanged nums for now
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,1,2,5,7,4,5};
    vector<int> ans = sol.mergeSort(nums);
}
