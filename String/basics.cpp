#include<bits/stdc++.h>
using namespace std;

// int main(){
//     // char a[] = {'a','b','c','d', '\0'};
//     // // char str[] = "abcdefgh";
//     // char str[100];
//     // cin.getline(str, 100, '$');
//     // // for( char it:str){
//     // //     cout<<it<< "      ";
//     // // }
//     // cout<<str;
//     // cout<<strlen(str);


//     // string str;
//     // str = "ABcd";
//     // cout<<str;
//     // cout<<str.size();
//     // cin>>str;
//     // cout<<str;
//     // cin.ignore();
//     // getline(cin, str);
//     // cout<<str;


//     char str[] = {'a','b', 'd', 'f', '\0'};
//     int st =0, end = strlen(str)-1;
//     // cout<<str[st];
//     while (st <= end)
//     {
//         swap(str[st], str[end]);
//         st++, end--;
//     }
//     cout<<str;
// }


class Solution {
public:
    bool isAlphaNumeric(char s){
        if( (s<='9' && s>='0') || (tolower(s)<='z' && tolower(s)>='a') ){
            return true;
        }
            return false;
        
    }
    bool isPalindrome(string s) {
        // for(char &ch: s){
        //     ch = tolower(ch);
        // }

        int st =0, end = s.length()-1;
        while(st <= end){
            if(!isAlphaNumeric(s[st])){ st++; continue;}
            if(!isAlphaNumeric(s[end])) {end--; continue;
}
            if(tolower(s[st]) != tolower(s[end])){
                return false;
            }
            st++, end--;
        }
        return true;
        
    }
};

int main(){
    Solution sol;
    string s = "Racecar";
    cout<<sol.isPalindrome(s);
}