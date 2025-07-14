#include <bits/stdc++.h>
using namespace std;
 void Frequency(int arr[], int n){
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
        map[arr[i]]++;

    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;
    // Traverse through map to find the elements.
    for (auto it : map) {
        int count = it.second;
        int element = it.first;

        if (count > maxFreq) {
            maxEle = element;
            maxFreq = count;
        }
        if (count < minFreq) {
            minEle = element;
            minFreq = count;
        }
    }

    cout << "The highest frequency element is: " << maxEle << "\n";
    cout << "The lowest frequency element is: " << minEle << "\n";
}
int main(){
//   int n;
//   cout<<"Enter the size of array"<<endl;
//   cin>>n;
//   int arr[n];
//   for (int i = 0; i < n; i++)
//   {
//     cin>>arr[i];
//   }

//   int hash[13] = {0};

//   for(int i = 0; i< n; i++){
//     hash[arr[i]] += 1;
//   }
  
//   for (int i = 0; i < 13; i++)
//   {
//     cout<<hash[i]-'a';
//   }
  
//   int abcd = 'a';
//   cout<<abcd;
//   cout<<('a' - 'z');

    //  // Character hashing 
    // below is not the exact answer but i tried it doing it 
    // int n;
    // cout<<"Enter the size of character array!"<<endl;
    // cin>>n;
    // char arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<"Enter the "<<i+1<<" character : ";
    //     cin>>arr[i];
    //     arr[i] = arr[i] - 'a';
    // }
    // // let say there will be only small characters and biggest will be the z

    // // for z we have to make the hash array of size 26
    // int hash[26] = {0};

    // for (int i = 0; i < n; i++)
    // {
    //     hash[arr[i]]++;
    // }
    // for (int i = 0; i < 26; i++)
    // {
    //     
    //     cout<<hash[i];
    // }
    

    // character hashing (actual)

    // string s;
    // cin>>s;

    // int hash[256] = {0}; // as there are 256 ascii values of characters

    // for (int i = 0; i < s.size(); i++)
    // {
    //     hash[s[i]-'a']++;
    // }
    
    // int q;
    // cin>>q;
    // while (q--)
    // {
    //     char c;
    //     cin>>c;
    //     cout<<hash[c-'a'];
    // }
    
    
//   int n;
//   cout<<"Enter the size of array"<<endl;
//   cin>>n;
//   int arr[n]; // 1,2,3,4,1,2
//   for (int i = 0; i < n; i++)
//   {
//     cin>>arr[i];
//   }
//   map<int, int> mpp;
//   int count = 0;
//   for (int i = 0; i < n; i++)
//   {
//     mpp[arr[i]]++; 
//   }
//   for(auto it: mpp){
//     cout<<it.first<<" - "<<it.second<<endl;
//   }

//  problem 1 - Problem statement: Given an array, we have found the number of occurrences of each element in the array.
    // method - 1
    // int arr[] = {10,5,10,15,10,5};
    // int arrSize = sizeof(arr) / sizeof(arr[0]);
    // unordered_map<int, int> mpp;
    // for (int i = 0; i < arrSize; i++)
    // {
    //     mpp[arr[i]]++;
    // }
    // for(auto it: mpp){
    //     cout<<it.first<<" - "<<it.second<<endl;
    // }
    
    // method - 2
    // int arr[] = {10,5,10,15,10,5};
    // int arrsize = sizeof(arr)/sizeof(int);
    // int hash[16] = {0};
    // for (int i = 0; i < arrsize; i++)
    // {
    //     hash[arr[i]]++;
    // }
    // int maxn = arr[0];

    // for (int i = 0; i < 16; i++)
    // {
    //     // if(hash[i] != 0){
    //     //     cout<<i<<" occurs "<<hash[i]<<" times."<<endl;
    //     // }
    //     maxn = max(hash[i], hash[i+1]);
    // }

  


    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Frequency(arr, n);
    return 0;

    
    
}
