#include<bits/stdc++.h>
using namespace std;

// GENERATE ALL THE SUBSETS OF AN ARRAY ( ARRAY MAY CONTAIN DUPLICATE ELEMENTS )
void genSubsets(int index,vector<int>&arr,vector<vector<int>>&ans,vector<int>&current){
    ans.push_back(current);
    for(int i=index;i<arr.size();i++){
        current.push_back(arr[i]);
        genSubsets(i+1,arr,ans,current);
        current.pop_back();
    }
}
vector<vector<int>>subsets(vector<int>&arr){
    vector<vector<int>>ans;
    vector<int>current;
    genSubsets(0,arr,ans,current);
    return ans;
}
// GENERATE ALL THE SUBSETS OF AN ARRAY ( SUBSETS SHOULD NOT HAVE DUPLICATE ELEMENTS )
void genSubets2(int index,vector<int>&arr,vector<vector<int>>&ans,vector<int>current){
    ans.push_back(current);
    for(int i=index;i<arr.size();i++){
        if(i>index && arr[i-1]==arr[i]){continue;}
        current.push_back(arr[i]);
        genSubets2(i+1,arr,ans,current);
        current.pop_back();
    }
}
vector<vector<int>>subsets2(vector<int>&arr){
    vector<vector<int>>ans;
    vector<int>current;
    sort(arr.begin(),arr.end());
    genSubets2(0,arr,ans,current);
    return ans;
}
// FIND A TO POWER B 
// iterative method to find A to power B
int findAPowerB(int a,int b){
    int ans=1;
    for(int i=1;i<=b;i++){
        ans*=a;
    }
    return a;
}
// recursive method 
int solveFunction(int a,int b){
    if(b==1){return a;}
    return a*solveFunction(a,b-1);
}
int calc(int a,int b){
    int ans=solveFunction(a,b);
    return ans;
}
// most optimised method O(logN) time complexity 
int optimisedSolution(int a,int b){
    if(b==1){
        return a;
    }
    int ans=solveFunction(a,b/2);
    ans*=ans;
    if(b%2==0){
        return ans;
    }
    else{
        return ans*a;
    }
}
// GENERATE BINARY STRINGS 
string genBin(int n){
    if(n==0){
        return "0";
    }
    string ans=genBin(n/2);
    if(n%2==1){
        ans+="1";
    }
    else{
        ans+="0";
    }
}
string generateBinary(int n){
    string ans=genBin(n);
    return ans;
}
// GENERATE BINARY STRINGS WITHOUT AJDACENT ZEROSE
void genString(vector<string>&ans,string current,int n){
    if(current.size()==n){
        ans.push_back(current);
        return;
    }
    genString(ans,current+"1",n);
    if(current.empty()==true || current.back()!='0'){
        genString(ans,current+"0",n);
    }
}
vector<string>genBinStrings(int n){
    vector<string>ans;
    genString(ans,"",n);
    return ans;
}
// GIVEN A MATRIX FIND THE MAX PATH SUM 
int findMaxHelper(int i,int j,vector<vector<int>>&matrix){
    if(i<0 || j<0){
        return INT_MIN;
    }
    if(i==0 && j==0){
        return matrix[0][0];
    }
    int fromTop=findMaxHelper(i-1,j,matrix);
    int fromLeft=findMaxHelper(i,j-1,matrix);
    return matrix[i][j] + max(fromTop,fromLeft);

}
int findMaxPath(vector<vector<int>>&matrix){
    int n=matrix.size();int m=matrix[0].size();
    int ans=findMaxHelper(n-1,m-1,matrix);
    return ans;
}
// GIVEN A MATRIX FIND THE MIN PATH SUM 
int findMinHelper(int i,int j,vector<vector<int>>&matrix){
    if(i<0 || j<0){
        return INT_MAX;
    }
    if(i==0 && j==0){
        return matrix[0][0];
    }
    int fromTop=findMinHelper(i-1,j,matrix);
    int fromLeft=findMinHelper(i,j-1,matrix);
    return matrix[i][j]+min(fromTop,fromLeft);
}
int findMinPath(vector<vector<int>>&matrix){
    int n=matrix.size();int m=matrix[0].size();
    int ans=findMinHelper(n-1,m-1,matrix);
    return ans;
}
// WORD SEARCH
bool solveFunction(vector<vector<char>>&board,int i,int j,int index,string word){
    if(index==word.size()){
        return true;
    }
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size()){
        return false;
    }
    if(board[i][j]!=word[index]){
        return false;
    }
    char temp = board[i][j];
    board[i][j]='#';
    bool case1=solveFunction(board,i+1,j,index+1,word);
    bool case2=solveFunction(board,i,j+1,index+1,word);
    bool case3=solveFunction(board,i-1,j,index+1,word);
    bool case4 = solveFunction(board,i,j-1,index+1,word);
    board[i][j]=temp;
    bool ans = case1  || case2 || case3 ||case4;
    return ans;

}
bool exist(vector<vector<char>>&board,string word){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(solveFunction(board,i,j,0,word)==true){
                return true;
            }
        }
    }
    return false;
}
// COMBINATION SUM 1 
void combinationSum1Helper(vector<vector<int>>&ans,vector<int>&current,int index,vector<int>&arr,int target){
    if(target==0){
        ans.push_back(current);
        return;
    }
    if(target<0){
        return;
    }
    for(int i=index;i<arr.size();i++){
        current.push_back(arr[i]);
        combinationSum1Helper(ans,current,i,arr,target-arr[i]);
        current.pop_back();
    }
}
vector<vector<int>>combinationSum1(vector<int>&arr,int target){
    int n=arr.size();
    vector<vector<int>>ans;
    vector<int>current;
    combinationSum1Helper(ans,current,0,arr,target);
    return ans;
}
// COMBINATION SUM 2 
void combinationSum2Helper(vector<vector<int>>&ans,vector<int>&arr,int target,int index,vector<int>&current){
    if(target==0){
        ans.push_back(current);
        return;
    }
    if(target<0){
        return;
    }
    for(int i=index;i<arr.size();i++){
        if(i>index && arr[i]==arr[i-1]){
            continue;
        }
        current.push_back(arr[i]);
        combinationSum2Helper(ans,arr,target-arr[i],i+1,current);
        current.pop_back();
    }
}
vector<vector<int>>combinationSum2(vector<int>&arr,int target){
    vector<vector<int>>ans;
    vector<int>current;
    sort(arr.begin(),arr.end());
    combinationSum2Helper(ans,arr,target,0,current);
    return ans;
}
// UNIQUE PATHS ( WITHOUT OBSTACLES )
int countPaths(int i,int j,int m,int n){
    if(i>=m || j>=n){
        return 0;
    }
    if(i==m-1 && j==n-1){
        return 1;
    }
    int rightpath=countPaths(i,j+1,m,n);
    int leftpath=countPaths(i+1,j,m,n);
    return rightpath+leftpath;
}
int uniquePaths(int m,int n){
    int ans=countPaths(0,0,m,n);
    return ans;
}
// UNIQUE PATHS ( WITH OBSTACLES)