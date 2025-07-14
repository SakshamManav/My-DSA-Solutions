#include <bits/stdc++.h>
using namespace std;

int main(){
    //  <<<<<-----Pair--->>>>
    // When we have to store data in pairs and it can be of any data type and different data type
    // pair<int, string> p = {1,"saksham"};
    // cout<<p.first<<" and "<<p.second<<endl;
    
    // // It is used to store pairs in pairs
    // pair<int, pair<int, string>> s = {1, {2, "Manav"}};
    // cout<<s.first<<" "<<s.second.first<<" "<<s.second.second<<endl;

    // // Pair's array

    // pair<int, int> arr[] = {{1,2}, {3,4}, {5,6}};
    // cout<<arr[0].first<<" "<<arr[1].second<<" " << arr[2].first;
    // --------------------------------------------------------------------

    // Vectors---->>>>>

    // vector<int> v = {1,23,4};
    // v.push_back(1); // it adds the value to last 
    // v.emplace_back(2);  // and it also do the same thing but It is faster and if we inserting the value in pair we don't have to explicitly denote the {} 
    
    // vector<pair<int, int>> p;
    // p.push_back({1,2});
    // p.emplace_back(1,2);
    // // cout<<p[1];
    // for (int i = 0; i < p.size(); i++)
    // {
    //     cout<<p[i].first<<p[i].second;
        
    // }
    // cout<<p.size();

    // vector<int> v(5, 100);
   
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i];
    // }
    // vector <int> v = {1,2,3,4};
    // vector<int>:: iterator it = v.begin();
    // cout<<*(it)<<" ";
    // it++;

    // To print vector using iterator

    // for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
    //     cout<<*(it);
    // }

    // for(auto it = v.begin(); it != v.end(); it++){ // c++ automaticaly understand that it have to use "vector<int>::iterator" inplace of auto
    //     cout<<*(it);
    // }
    
    // for (auto it:v)
    // {
    //    cout<<it<<" ";
    // }
    
    // To erase a element from vector
    // v.erase(v.begin()+1, v.begin()+3);   // v.erase(start, end) erase start to before end
    // for (auto it:v)
    // {
    //    cout<<it<<" ";
    // }

    // To insert element at any index in vector

    // v.insert(v.begin(), 300);
    // v.insert(v.begin()+4, 3, 100 );
    // for (auto it:v)
    // {
    //    cout<<it<<" ";
    // }

//   🧠 Real-life Analogy:
// Think of a vector like a row of seats in a theater — you can jump directly to seat 20 (v[20]), but if you want to insert a new chair in the middle, you must shift all seats.

// A list is like a train of compartments — you can't jump to the 20th instantly, but it's easy to add or remove a compartment in between.
    // list---------->>>>
    // list<int> ls;
    // ls.push_back(10);
    // ls.push_back(20);
    // ls.push_back(30);
    // for( auto it: ls){
    //     cout<<it;
    // }

    // dequeue is also same like these

    // Stack --->>>>
    // stack is LIFO (last in first out)
    // stack<int> st;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);
    // st.push(5);

    // cout<<st.top();
    // cout<<st.size();

    // st.pop();
    // cout<<st.top();
    // stack<int> stt;
    // stt.swap(st);
    // cout<<stt.top();

    // stt.empty();
    // cout<<stt.top();



    // queue ---->>> // FIFO (First in first out )

    // queue<int> q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    
    // cout<<q.back();

    // Priority queue is same as queue but in this greatest number will be remain at top in any order you put the numbers in queue (asc to desc from top to bottom) but we can reverse it(desc to asc).


    // Set ---- >>>>  sorted and can only store a occurence of a number only one time
    // set<int> st;
    // st.insert(1);
    // st.insert(2);
    // st.insert(44);
    // st.insert(3);

    // auto it = st.find(44);
    // cout<<*(it);
    
    // auto itn = st.find(3);
    // st.erase(itn);
    // cout<<*(itn);

    


    // Multiset ----- >>>>>> multiset is same as set but can store more  occurence of a number more than one time and it is also sorted

    // unordered_Set is also same as set but not store values sorted 

    map<int, string> mp;
    mp.insert({3, "Saksham"});
    mp.insert({2, "Manav"});\
    mp[1] = "Pandey"; // we can define it just like array
    // for(auto val: mp){
    //     cout<<val.first<<" : "<<val.second << endl;
    // }
    cout<<mp[2];

    // multimap is also like multiset but it is a map not set
    // unordered map is also like unorderset but it is a map not set

}