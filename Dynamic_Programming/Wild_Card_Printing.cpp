#include<bits/stdc++.h>
using namespace std;

// RECURSIVE CODE 
bool isMatchHelper(string s,string p,int i,int j){
    if(i<0 && j<0){
        return true;
    }
    if(j<0){
        return false;
    }
    if(i<0){
        for(int k=0;k<=j;k++){
            if(p[k]!='*'){
                return false;
            }
        }
        return true;
    }
    if(s[i]==p[j] || p[j]=='?'){
        return isMatchHelper(s,p,i-1,j-1);
    }
    if(p[j]=='*'){
        bool case1=isMatchHelper(s,p,i-1,j);
        bool case2=isMatchHelper(s,p,i,j-1);
        return case1||case2;
    }
    return false;
}

bool isMatch(string s,string p){
    return isMatchHelper(s,p,s.size()-1,p.size()-1);
}
// TOP DOWN CODE 
bool isMatchTopDown(string s, string p, int i, int j, vector<vector<int>>& dp) {
    if (i < 0 && j < 0) {
        return true;
    }
    if (j < 0) {
        return false;
    }
    if (i < 0) {
        for (int k = 0; k <= j; k++) {
            if (p[k] != '*') {
                return false;
            }
        }
        return true;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (s[i] == p[j] || p[j] == '?') {
        dp[i][j] = isMatchTopDown(s, p, i - 1, j - 1, dp);
    } else if (p[j] == '*') {
        bool case1 = isMatchTopDown(s, p, i - 1, j, dp);
        bool case2 = isMatchTopDown(s, p, i, j - 1, dp);
        dp[i][j] = case1 || case2;
    } else {
        dp[i][j] = false;
    }
    return dp[i][j];
}

bool isMatch(string s, string p) {
    vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
    return isMatchTopDown(s, p, s.size() - 1, p.size() - 1, dp);
}
// BOTTOM UP CODE 

bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }
    return dp[n][m];
}
