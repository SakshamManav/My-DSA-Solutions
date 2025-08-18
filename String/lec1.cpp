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
//             if(!isalnum(s[st])){ st++; continue;}
//             if(!isalnum(s[end])) {end--; continue;
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

// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
        
//         while(s.find(part) != string::npos )
//         {
//             int idx = s.find(part);
//             s.erase(idx, part.length());
//         }
//         return s;
//     }
// };

// Remove parenthesis 
// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//       int counter = 0;
//       string ans;
//       for(int i=0; i<s.size(); i++){
//         if(s[i] == ')') counter--;
//         if(counter != 0) ans.push_back(s[i]);
//         if(s[i] =='(') counter++;
//       }
//       return ans;
//     }
// };

// int main(){
//     Solution sol;
//     string s = "(()())(())(()(()))";
//     sol.removeOuterParentheses(s);
// }


// brute force

class Solution {
public:
    string reverseWords(string s) {
        if(s[0] == ' ') { s.erase(0, 1);};
        if(s[s.size()-1] == ' '){s.erase(s.size()-1, 1);}
        string a = "";
        string cur = "";
        for(int i=s.length()-1; i>=0; i--){
            if(s[i] == ' '){
                
                reverse(cur.begin() , cur.end());
                a = a+cur+" ";
                
                cur = "";
            }else{
                cur.push_back(s[i]);
            }

        }
        string start_word = "";
        cur = "";
        bool is_space = false;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                is_space = true;
                break; 
            }else{
                cur.push_back(s[i]);
            }
        }
        if(is_space){
            return a + cur;
        }
          return cur;   
    }
};

int main(){
    Solution sol;
    string s = "the sky is blue";
    sol.reverseWords(s);
}