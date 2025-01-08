#include<bits/stdc++.h>
using namespace std;
// SCRAMBLED STRINGS RECURSIVE METHOD
bool isScramble(string s1,string s2){
    if(s1==s2){
        return true;
    }
    if(s1.size() !=s2.size()){
        return false;
    }
    string sorteds1=s1;
    string sorteds2=s2;
    sort(sorteds1.begin(),sorteds1.end());
    sort(sorteds2.begin(),sorteds2.end());
    if(sorteds1!=sorteds2){
        return false;
    }
    int n=s1.size();
    for(int i=1;i<s1.size();i++){
        bool caseWithoutSwapping = isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i));
        bool caseWithSwapping = isScramble(s1.substr(i),s1.substr(0,n-i)) && isScramble(s1.substr(0,i),s2.substr(n-i));
        if(caseWithSwapping==true || caseWithoutSwapping==true){
            return true;
        }
    }
    return false;
}

// SCRAMBLED STRINGS TOP DOWN APPROACH 
bool isScrambled(string s1, string s2, int i, int j, vector<vector<vector<int>>>& dp, int len) {
    if (dp[i][j][len] != -1) {
        return dp[i][j][len];
    }
    
    if (s1.substr(i, len) == s2.substr(j, len)) {
        dp[i][j][len] = true;
        return true;
    }
    
    string sorted_s1 = s1.substr(i, len);
    string sorted_s2 = s2.substr(j, len);
    sort(sorted_s1.begin(), sorted_s1.end());
    sort(sorted_s2.begin(), sorted_s2.end());
    
    if (sorted_s1 != sorted_s2) {
        dp[i][j][len] = false;
        return false;
    }
    
    for (int k = 1; k < len; ++k) {
        if ((isScrambled(s1, s2, i, j, dp, k) && 
             isScrambled(s1, s2, i + k, j + k, dp, len - k)) ||
            (isScrambled(s1, s2, i, j + len - k, dp, k) && 
             isScrambled(s1, s2, i + k, j, dp, len - k))) {
            dp[i][j][len] = true;
            return true;
        }
    }

    dp[i][j][len] = false;
    return false;
}