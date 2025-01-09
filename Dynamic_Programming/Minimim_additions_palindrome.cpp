#include<bits/stdc++.h>
using namespace std;

// MINIMIUM ADDITION TO STRING TO MAKE IT PALINDROMIC RECURSIVE 
int minAdditionsRecursion(string s,int left,int right){
    if(left>right){
        return 0;
    }
    if(left==right){
        return 0;
    }
    if(left==right-1){
        if(s[left]==s[right]){
            return 0;
        }
        else{
            return 1;
        }
    }
    if(s[left]==s[right]){
        return minAdditionsRecursion(s,left+1,right-1);
    }
    else{
        int insertAtEnd = 1+minAdditionsRecursion(s,left+1,right);
        int insertAtStart = 1+minAdditionsRecursion(s,left,right-1);
        return min(insertAtEnd,insertAtStart);
    }
}
int minAdditions(string s){
    int ans=minAdditionsRecursion(s,0,s.size()-1);
    return ans;
}
// MINIMUM ADDITION TO STRING TO MAKE IT PALINDROMIC TOP DOWN 
int minAdditionsTopDown(string s,int left,int right,vector<vector<int>>&dp){
    if(left>right){
        return 0;
    }
    if(left==right){
        return 0;
    }
    if(left==right-1){
        if(s[left]==s[right]){
            return 0;
        }
        else{
            return 1;
        }
    }
    if(dp[left][right]!=-1){
        return dp[left][right];
    }
    if(s[left]==s[right]){
        dp[left][right]=minAdditionsTopDown(s,left+1,right-1,dp);
    }
    else{
        int insertAtEnd = 1+minAdditionsTopDown(s,left+1,right,dp);
        int insertAtStart =1+ minAdditionsTopDown(s,left,right-1,dp);
        dp[left][right]=min(insertAtEnd,insertAtStart);
    }
    return dp[left][right];
}
int minAddtions(string s){
    vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
    int ans=minAdditionsTopDown(s,0,s.size()-1,dp);
    return ans;
}
// MINIMUM ADDITIONS TO STRING TO MAKE IT PALINDROMIC BOTTOM UP 
int minAdditions(string s){
    vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,0));
    for(int length = 2 ;length<=s.size();length++){
        for(int l=0;l<=s.size()-length;l++){
            int r = l+length-1;
            if(s[l]==s[r]){
                dp[l][r] = dp[l+1][r+1];
            }
            else{
                int insertAtStart = 1+dp[l][r-1];
                int insertAtEnd = 1+dp[l-1][r];
                dp[l][r] = min(insertAtEnd,insertAtStart);
            }
        }
    }
    return dp[0][s.size()-1];
}