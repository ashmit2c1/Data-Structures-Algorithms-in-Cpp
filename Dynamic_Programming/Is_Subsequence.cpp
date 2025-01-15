#include<bits/stdc++.h>
using namespace std;
// CHECK IF S1 IS SUBSEQUENCE OF S2 USING TWO POINTERS 
bool isSubsequence(string s1,string s2){
    int i=0;
    int j=0;
    while(i<s1.size() && j<s2.size()){
        if(s1[i]==s2[j]){
            i++;j++;
        }else{
            j++;
        }
    }
    if(i!=s1.size()){
        return false;
    }
    return true;
}
// CHECK IF S1 IS A SUBSEQUENCE USING RECURSION 
bool recursiveFunction(string s1,string s2,int n,int m){
    if(n==0){
        return true;
    }
    if(m==0){
        return false;
    }
    if(s1[n-1]==s2[m-1]){
        return recursiveFunction(s1,s2,n-1,m-1);
    }
    else{
        return recursiveFunction(s1,s2,n,m-1);
    }
}
bool isSubsequence(string s1,string s2){
    bool ans=recursiveFunction(s1,s2,s1.size(),s2.size());
    return ans;
}
// CHECK IF S1 IS A SUBSEQUENCE USING TOP DOWN APPROACH 
int topDownFunction(string s1,string s2,int n,int m,vector<vector<int>>dp){
    if(n==0){
        return 1;
    }
    if(m==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(s1[n-1]==s2[m-1]){
        dp[n][m]=topDownFunction(s1,s2,n-1,m-1,dp);
    }else{
        dp[n][m]=topDownFunction(s1,s2,n,m-1,dp);
    }
    return dp[n][m];

}
bool isSubsequence(string s1,string s2){
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
    int ans=topDownFunction(s1,s2,s1.size(),s2.size(),dp);
    if(ans==1){
        return true;
    }else{
        return false;
    }
}
// BOTTOM UP CODE 
bool isSubsequence(string s1,string s2){
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
    for(int i=0;i<=s1.size();i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=s2.size();i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    if(dp[s1.size()-1][s2.size()-1]==1){
        return true;
    }else{
        return false;
    }
    
}