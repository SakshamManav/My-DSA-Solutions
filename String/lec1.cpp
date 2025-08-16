#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool isAlphaNumeric(char s){
//         if( (s<='9' && s>='0') || (tolower(s)<='z' && tolower(s)>='a') ){
//             return true;
//         }
//             return false;
        
//     }
//     bool isPalindrome(string s) {
//         // for(char &ch: s){
//         //     ch = tolower(ch);
//         // }

//         int st =0, end = s.length()-1;
//         while(st <= end){
//             if(!isAlphaNumeric(s[st])){ st++; continue;}
//             if(!isAlphaNumeric(s[end])) {end--; continue;
// }
//             if(tolower(s[st]) != tolower(s[end])){
//                 return false;
//             }
//             st++, end--;
//         }
//         return true;
        
//     }
// };

// int main(){
//     Solution sol;
//     string s = "Racecar";
//     cout<<sol.isPalindrome(s);
// }

class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.find(part) != string::npos )
        {
            int idx = s.find(part);
            s.erase(idx, part.length());
        }
        return s;
    }
};

int main(){
    string s = "axxxxyyyyb", part = "xy";
    Solution sol;
    string ans = sol.removeOccurrences(s, part);
    cout<<ans;
    // cout<<s.find(part);
}