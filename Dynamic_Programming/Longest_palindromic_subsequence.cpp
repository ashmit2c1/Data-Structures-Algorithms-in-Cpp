#include<bits/stdc++.h>
using namespace std;

// LONGEST PALINDROMIC SUBSEQUENCE RECURSIVE CODE
int recursiveFunction(string s,int start,int end){
    if(start==end){
        return 1;
    }
    if(start>end){
        return 0;
    }
    if(s[start]==s[end]){
        return 2+recursiveFunction(s,start+1,end-1);
    }else{
        int option1 = recursiveFunction(s,start+1,end);
        int option2 = recursiveFunction(s,start,end-1);
        return max(option1,option2);
    }
}
int findLPS(string s){
    int ans=recursiveFunction(s,0,s.size()-1);
    return ans;
}
// LONGEST PALINDROMIC SUBSTRING TOP DOWN CODE
int topDownFunction(string s,int start,int end,vector<vector<int>>&dp){
    if(start==end){
        return 1;
    }
    if(start>end){
        return 0;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    if(s[start]==s[end]){
        dp[start][end]=2+topDownFunction(s,start+1,end-1,dp);
    }else{
        int option1 = topDownFunction(s,start+1,end,dp);
        int option2 = topDownFunction(s,start,end-1,dp);
        dp[start][end]=max(option1,option2);
    }
    return dp[start][end];
}
int findLPS(string s){
    vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
    int ans=topDownFunction(s,0,s.size()-1,dp);
    return ans;
}
// LONGEST PALINDROMIC SUBSEQUENCE BOTTOM UP CODE 
int findLPS(string s){
    vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
    for(int i=0;i<s.size();i++){
        dp[i][i]=1;
    }
    for(int len=2;len<=s.size();len++){
        for(int start=0;start<s.size()-len;start++){
            int end = start+len-1;
            if(s[start]==s[end]){
                dp[start][end]=2+dp[start+1][end-1];
            }else{
                dp[start][end] = max(dp[start][end-1],dp[start+1][end]);
            }
        }
    }
    return dp[0][s.size()-1];
}

// LONGEST PALINDROMIC SUBSTRING 
vector<string> findSubstrings(string s) {
    vector<string> ans;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans.push_back(s.substr(i, j - i));
        }
    }
    return ans;
}
bool isPalindrome(string s){
    int start=0;
    int end=s.size()-1;
    while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
vector<string>findPalindromes(vector<string>&substrings){
    vector<string>ans;
    for(int i=0;i<substrings.size();i++){
        string temp=substrings[i];
        if(isPalindrome(temp)==true){
            ans.push_back(temp);
        }
    }
    return ans;
}
int longestPalindromicSubstring(string s){
    vector<string>substrings=findSubstrings(s);
    vector<string>palindromes=findPalindromes(substrings);
    int maxlen=INT_MIN;
    string palstring;
    for(int i=0;i<palindromes.size();i++){
        string pal = palindromes[i];
        int len = pal.size();
        if(len>maxlen){
            palstring=pal;
            maxlen=len;
        }
    }
    return maxlen;
}