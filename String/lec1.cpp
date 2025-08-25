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
// class Solution
// {
// public:
//     string longestCommonPrefix(vector<string> &strs)
//     {
//         int max_idx = INT_MAX;
//         for (int i = 0; i < strs.size(); i++)
//         {
//             max_idx = min(max_idx, (int)strs[i].size());
//         }
//         if(max_idx == 0){
//             return "";
//         }

//         string ans = strs[0].substr(0, max_idx);

//         int cur_idx = 0;
//         int j = 0;
//         int check = max_idx;

//         while (j < max_idx)
//         {
//             bool is_true = true;
//             for (int i = 0; i < strs.size(); i++)
//             {
//                 if(i == strs.size()-1 && strs[i].substr(0, ans.size()) == ans) {
//                     return ans;
//                 }
//                 if (strs[i].substr(0, ans.size()) != ans){
//                     ans.resize(ans.size()-1);
//                     is_true = false;
//                     break;
//                 }
//             }
//             // cout<<ans<<" ";
//             if(is_true){
//                 return ans;
//             }
//         j++;
//         }
//         return "";
//     }
// };

// int main()
// {
//     vector<string> str = {"flower","flow","flight"};
//     Solution sol;
//     cout<<sol.longestCommonPrefix(str);
// }

// rotate string

// brute force - tle
// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         int n = s.size();
//         if(s == goal){
//             return true;
//         }
//         // int check_ans = "";
//         for(int i=1; i<s.size(); i++){
//             int d = i % s.size();
//             string substring = s.substr(n - d) + s.substr(0, n - d);
//             if(substring == goal){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// Optimal
//  class Solution {
//  public:
//      bool rotateString(string s, string goal) {
//         if (s.size() != goal.size()) return false;
//          string doubled = s + s;
//          return doubled.find(goal) != string::npos;
//      }
//  };

// Valid anagram

// taking extra space, we can also do it by using sorting
// class Solution
// {
// public:
//     bool isAnagram(string s, string t)
//     {
//         unordered_map<char, int> mp;
//         if (s.size() != t.size())
//         {
//             return false;
//         }
//         for (int i = 0; i < s.size(); i++)
//         {
//             mp[s[i]]++;
//         }
//         for (int i = 0; i < s.size(); i++)
//         {
//             if(mp[t[i]] > 0){
//                 mp[t[i]]--;
//             }else{
//                 return false;
//             }
//         }
//         return true;

//     }
// };

// int main()
// {
//     Solution sol;
//     string s = "anagram", t = "nagarmm";
//     cout << sol.isAnagram(s, t);
// }
// class Solution
// {
// public:
//  static bool cmp(pair<char, int> a, pair<char, int> b)
//         {
//             return a.second > b.second;
//         }
//     string frequencySort(string s)
//     {
//         unordered_map<char, int> mp;
//         for (int i = 0; i < s.size(); i++)
//         {
//             mp[s[i]]++;
//         }
//         vector<pair<char, int>> vc;
//         for (auto &p : mp)
//             vc.push_back(p);

//         sort(vc.begin(), vc.end(), cmp);

//         string result = "";

//         for (auto &p : vc)
//             result.append(p.second, p.first);

//         return result;
//     }
// };

// Roman to integer

// this solution will work but we are doing some hardcore checks
// class Solution
// {
// public:
//     int romanToInt(string s)
//     {
//         unordered_map<char, int> mp = {
//             {'I', 1},
//             {'V', 5},
//             {'X', 10},
//             {'L', 50},
//             {'C', 100},
//             {'D', 500},
//             {'M', 1000}};
//             int ans = 0;
//         for (int i = 0; i < s.size()-1; i++)
//         {
//             if((s[i] == 'I' && s[i+1] == 'V') || (s[i] == 'I' && s[i+1] == 'X')){
//                 ans += mp[s[i+1]] - mp[s[i]];
//                 i++;
//             }
//             else if((s[i] == 'X' && s[i+1] == 'L') || (s[i] == 'X' && s[i+1] == 'C')){
//                 ans += mp[s[i+1]] - mp[s[i]];
//                 i++;
//             }
//             else if((s[i] == 'C' && s[i+1] == 'D') || (s[i] == 'C' && s[i+1] == 'M')){
//                 ans += mp[s[i+1]] - mp[s[i]];
//                 i++;
//             }
//             else{
//                 ans += mp[s[i]];
//             }
//         }

//         return ans;
//     }
// };

// in this we are not doing hardcore checks

// class Solution {
// public:
//     int romanToInt(string &s) {
//         unordered_map<char, int> mp = {
//             {'I', 1},
//             {'V', 5},
//             {'X', 10},
//             {'L', 50},
//             {'C', 100},
//             {'D', 500},
//             {'M', 1000}
//         };

//         int ans = 0;
//         for (int i = 0; i < s.size(); i++) {
//             if (i + 1 < s.size() && mp[s[i]] < mp[s[i + 1]]) {
//                 ans -= mp[s[i]];
//             } else {
//                 ans += mp[s[i]];
//             }
//         }
//         return ans;
//     }
// };

// int main()
// {
//     string str = "MCMXCIV";

//     Solution sol;
//     cout << sol.romanToInt(str);
// }

// String to integer

// this solution is not working--- >>>
// class Solution {
// public:
//     int myAtoi(string s) {
//         int i = 0;
//         for (i = 0; i < s.size(); i++) {
//             if (s[i] != ' ') {
//                 break;
//             }
//         }
//         string ans = "";
//         int sign_count = 0;
//         if((s[i] >= 'a' && s[i] < 'z') || (s[i] >= 'A' && s[i] < 'Z')){
//             return 0;
//         }
//         // cout<<i;
//         for (int j = i; j < s.size(); j++) {
//             if ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z')) {
//                 break;
//             } else if (((s[j] == '+' || s[j] == '-') && (sign_count > 0)) ||
//                        (s[j] == ' ' || s[j] == '.')) {
//                 break;
//             }else if(((s[j] == '+' || s[j] == '-') && (sign_count == 0))){
//                 ans += s[j];
//             }
//             else{
//                 ans += s[j];
//             }
//         }
//         if(ans.size() == 0){
//             return 0;
//         }
//         if((ans.size() == 1) && (ans[0] == '+' || ans[0] == '-')) return 0;
//         if(stoi(ans) < pow(-2, 31)) return pow(-2,31);
//         if(stoi(ans) > (pow(2, 31)-1)) return pow(2, 31)-1;

//         return stoi(ans);

//     }
// };

// optimal solution

// class Solution {
// public:
//     int myAtoi(string s) {
//         int i = 0;
//         // 1. Skip leading spaces
//         while (i < s.size() && s[i] == ' ') i++;

//         // 2. Handle sign
//         int sign = 1;
//         if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
//             if (s[i] == '-') sign = -1;
//             i++;
//         }

//         // 3. Parse digits
//         long long num = 0;
//         while (i < s.size() && isdigit(s[i])) {
//             num = num * 10 + (s[i] - '0');

//             // 4. Clamp if out of range
//             if (sign * num <= INT_MIN) return INT_MIN;
//             if (sign * num >= INT_MAX) return INT_MAX;

//             i++;
//         }

//         return (int)(sign * num);
//     }
// };
// int main(){
//     Solution sol;
//     cout<<sol.myAtoi("-");
// }

// longest palindrome substring

// Not working for even substrings -- >>
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         string ans = "";
//         string left_part = "";
//         string right_part = "";

//         for(int i=1; i<s.size(); i++){
//             string temp = "";
//             left_part = "";
//             right_part = "";
//             int low = i-1, high = i+1;
//             while(low >= 0 && high <= s.size()-1){
//                 if(s[low] == s[high]){
//                     left_part += s[low];
//                     right_part += s[high];
//                     temp = left_part + s[i] + right_part;
//                     if(ans.size() < temp.size()){
//                         ans = temp;
//                     }
//                     low--, high++;
//                 }else{
//                     break;
//                 }
//             }
//         }
//         // cout<<ans;
//         return ans;
//     }
// };

// class Solution {
// public:
//     void expand(string &s, int left, int right, int &start, int &maxLen) {
//         while (left >= 0 && right < s.size() && s[left] == s[right]) {
//             if (right - left + 1 > maxLen) {
//                 start = left;
//                 maxLen = right - left + 1;
//             }
//             left--;
//             right++;
//         }
//     }

//     string longestPalindrome(string s) {
//         if (s.empty()) return "";
//         int start = 0, maxLen = 1;

//         for (int i = 0; i < s.size(); i++) {
//             expand(s, i, i, start, maxLen);     // odd length
//             expand(s, i, i + 1, start, maxLen); // even length
//         }

//         return s.substr(start, maxLen);
//     }
// };

// int main(){
//     Solution sol;
//     cout<<sol.longestPalindrome("babad");
// }

// Sum of beauty of all substrings


// Not optimal
// class Solution
// {
// public:
//     int beautySum(string s)
//     {
//         int n = s.size();
//         int sum = 0;
       
//         for (int i = 0; i < n; i++) {
//         unordered_map<char, int> mp;
//         for (int j = i; j < n; j++) {
//             mp[s[j]]++;

//             int high = 0, low = INT_MAX;
//             for (auto &it : mp) {
//                 high = max(high, it.second);
//                 low = min(low, it.second);
//             }
//             sum += (high - low);
//         }
//     }

//         return sum;
//     }
// };


// Opimal
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        vector<int> freq(26, 0);

        for (int j = i; j < n; j++) {
            freq[s[j] - 'a']++;

            int high = 0, low = INT_MAX;
            for (int f : freq) {
                if (f > 0) {
                    high = max(high, f);
                    low = min(low, f);
                }
            }

            sum += (high - low);
        }
    }

    return sum;
    }
};
int main()
{
    Solution sol;
    sol.beautySum("aabcbaa");
}