#include <bits/stdc++.h>
using namespace std;

// Remove outermost Paranthesis

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

// Remove all occurences of a substring

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

// REverse words in string

// brute force

// class Solution {
// public:
//     string reverseWords(string s) {
//         stack<string> st;
//         s+= " ";
//         string str;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if(s[i] == ' '){
//                 st.push(str);
//                 str = ' ';
//             }else{
//                 str += s[i];
//             }
//         }
//         string ans = "";

//         while (st.size() != 1)
//         {
//             ans += st.top() + " ";
//             st.pop();
//         }
//         ans += st.top();
//         return ans;
//     }
// };

// Optimal
// class Solution {
// public:
//     string reverseWords(string s) {
//         int left = 0, right = s.length()-1;
//         string temp = "";
//         string ans = "";
//         while (left <= right)
//         {
//             char ch = s[left];
//             if(ch != ' '){
//                 temp += ch;
//             }else if(ch == ' '){
//                 if(ans != ""){
//                     ans = temp + " " + ans;
//                 }else{
//                     ans = temp;
//                 }
//                 temp = "";
//             }
//             left ++;
//         }

//         if(temp != ""){
//             if (ans!="") ans = temp + " " + ans;
//         else ans = temp;
//         }
//         return ans;
//     }
// };

// int main(){
//     Solution sol;
//     string s = "the sky is blue";
//     sol.reverseWords(s);
// }


// Longest Common Prefix (done by myself without any help)


// our answer string size will always from zero to smallest string in the vector.
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int max_idx = INT_MAX;
        for (int i = 0; i < strs.size(); i++)
        {
            max_idx = min(max_idx, (int)strs[i].size());
        }
        if(max_idx == 0){
            return "";
        }
        
        
        string ans = strs[0].substr(0, max_idx);
        
        int cur_idx = 0;
        int j = 0;
        int check = max_idx;
        
        while (j < max_idx)
        {
            bool is_true = true;
            for (int i = 0; i < strs.size(); i++)
            {
                if(i == strs.size()-1 && strs[i].substr(0, ans.size()) == ans) {
                    return ans;
                }
                if (strs[i].substr(0, ans.size()) != ans){
                    ans.resize(ans.size()-1);
                    is_true = false;
                    break;
                }
            }
            // cout<<ans<<" ";
            if(is_true){
                return ans;
            }
        j++;
        }
        return "";
    }
};

int main()
{
    vector<string> str = {"flower","flow","flight"};
    Solution sol;
    cout<<sol.longestCommonPrefix(str);
}