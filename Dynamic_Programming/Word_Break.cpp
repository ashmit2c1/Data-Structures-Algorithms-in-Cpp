#include<bits/stdc++.h>
using namespace std;
// WORD BREAK 
bool recursivefunction(string s,unordered_set<string>&st,int index){
    if(index==s.size()){
        return true;
    }
    for(int end=index+1;end<s.size();end++){
        string sub = s.substr(index,end-index);
        if(st.find(sub)!=st.end()){
            if(recursivefunction(s,st,end)==true){
                return true;
            }
        }
    }
    return false;
}
bool canBreak(string s,vector<string>&dict){
    unordered_set<string>st;
    for(int i=0;i<dict.size();i++){
        st.insert(dict[i]);
    }
    bool ans=recursivefunction(s,st,0);
    return ans;
}
// WORD BREAK WITH MEMOISATION 
bool topdownfunction(string s,unordered_set<string>&st,int index,vector<int>&dp){
    if(index==s.size()){
        return true;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    for(int end=index+1;end<s.size();end++){
        string sub = s.substr(index,end-index);
        if(st.find(sub)!=st.end()){
            if(topdownfunction(s,st,end,dp)==true){
                dp[index]=true;
                return true;
            }
        }
    }
    dp[index]=false;
    return false;
}
bool canBreak(string s,vector<string>&dict){
    unordered_set<string>st;
    vector<int>dp(s.size()+1,-1);
    for(int i=0;i<dict.size();i++){
        st.insert(dict[i]);
    }
    bool ans=topdownfunction(s,st,0,dp);
    return ans;
}