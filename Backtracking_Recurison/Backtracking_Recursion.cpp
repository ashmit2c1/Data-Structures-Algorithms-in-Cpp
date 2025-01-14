#include<bits/stdc++.h>
using namespace std;
#define ret return
// FIND THE SUM OF FIRST N NATURAL NUMBERS 
int findSumRecursive(int n){
    if(n==0){
        return 0;
    }
    return n+findSumRecursive(n-1);
}
int findSum(int n){
    int ans=findSumRecursive(n);
    return ans;
}
// GIVEN AN INTEGER N FIND THE N FACTORIAL 
int findFactorialRecursive(int n){
    if(n==1){
        return 1;
    }
    return n*findFactorialRecursive(n-1);
}
int findFactorial(int n){
    int ans=findFactorialRecursive(n);
    return ans;
}
// FIND THE NTH FIBONACCI NUMBER 
int findFibRecursive(int n){
    if(n==0){return 0;}
    if(n==1){return 1;}
    return findFibRecursive(n-1)+findFibRecursive(n-2);
}
int findFib(int n){
    int ans=findFibRecursive(n);
    return ans;
}
// PATTERN PRINTING USING RECURSION 
// ****
// ***
// **
// * 
void printPatternRecursive(int n){
    if(n==0){
        return;
    }
    for(int i=0;i<0;i++){
        cout << "*";
    }
    cout << "\n";
    printPatternRecursive(n-1);
}
void printPattern(int n){
    printPatternRecursive(n);
}
// LINEAR SEARCH USING RECURSION ( FIND THE INDEX OF ELEMENT IN ARRAY )
int findElementRecursion(vector<int>&arr,int index,int element){
    if(index==arr.size()){
        return -1;
    }
    if(arr[index]==element){
        return index;
    }
    else{
        return findElementRecursion(arr,index+1,element);
    }
}
int findElement(vector<int>&arr,int element){
    int ans=findElementRecursion(arr,0,element);
    return ans;

}
// CHECK IF A GIVEN STRING IS PALINDROME OR NOT USING RECURSION
bool checkPalindromeRecursion(string s,int start,int end){
    if(start==end){return true;}
    if(s[start]!=s[end]){return false;}
    return checkPalindromeRecursion(s,start+1,end-1);
} 
bool checkPalindrome(string s){
    bool ans=checkPalindromeRecursion(s,0,s.size()-1);
    return ans;
}
// GENERATE ALL THE SUBSETS OF AN ARRAY 
void generateSubsets(vector<vector<int>>&ans,vector<int>&current,int index,vector<int>&arr){
    ans.push_back(current);
    for(int i=index;i<arr.size();i++){
        current.push_back(arr[i]);
        generateSubsets(ans,current,i+1,arr);
        current.pop_back();
    }
}
vector<vector<int>>subsets(vector<int>&arr){
    vector<vector<int>>ans;
    vector<int>current;
    generateSubsets(ans,current,0,arr);
    return ans;
}
// GENERATE ALL THE UNIQUE SUBESTS OF ARRAY 
void generateUniqueSubsets(vector<vector<int>>&ans,vector<int>&current,int index,vector<int>&arr){
    ans.push_back(current);
    for(int i=index;i<arr.size();i++){
        if(i>0 && arr[i]==arr[i-1]){
            continue;
        }
        current.push_back(arr[i]);
        generateUniqueSubsets(ans,current,i+1,arr);
        current.pop_back();
    }
}
vector<vector<int>>subsets2(vector<int>&arr){
    vector<vector<int>>ans;
    vector<int>current;
    sort(arr.begin(),arr.end());
    generateUniqueSubsets(ans,current,0,arr);
    return ans;
}
// FIND A TO POWER B IN O(N) TIME COMPLEXITY 
int findPowerRecursion1(int a,int b){
    if(b==1){
        return a;
    }
    return a*findPowerRecursion1(a,b-1);
}
// FIND A TO POWER B IN O(LOG N) TIME COMPLEXITY
int findPowerRecursion2(int a,int b){
    if(b==1){
        return a;
    }
    int ans=findPowerRecursion2(a,b/2);
    ans*=ans;
    if(b%2==0){return ans;}
    else{return ans*a;}
}
int findPower(int a,int b){
    int ans=findPowerRecursion1(a,b);
    return ans;
}
// GENERATE THE BINARY STRING FOR THE NUMBER N 
string generateBinary(int n){
    if(n==0){
        return "0";
    }
    string ans=generateBinary(n/2);
    if(n%2==0){ans+="0";}
    else{ans+="1";}
    return ans;
}
string binary(int n){
    string ans=generateBinary(n);
    return ans;
}
// GENERATE THE BINARY STRINGS WITHOUT ADJACENT ZEROES 
void generateString(vector<string>&ans,string current,int size){
    if(current.size()==size){
        ans.push_back(current);
    }
    generateString(ans,current+"1",size);
    if(current.empty()==true || current.back()!='0'){
        generateString(ans,current+"0",size);
    }

}
vector<string>generateBinaryStrings(int n){
    vector<string>ans;
    generateString(ans,"",n);
    return ans;
}
// GIVEN A MATRIX FIND THE MAX PATH SUM 
int findMaxPathRecursion(vector<vector<int>>&matrix,int i,int j){
    if(i<0 || j<0){return INT_MIN;}
    if(i==0 && j==0){return matrix[0][0];}
    int fromTop = findMaxPathRecursion(matrix,i-1,j);
    int fromLeft = findMaxPathRecursion(matrix,i,j-1);
    return matrix[i][j] + max(fromTop,fromLeft);
}
int findMaxPath(vector<vector<int>>&matrix){
    int rows=matrix.size();
    int cols=matrix[0].size();
    int ans=findMaxPathRecursion(matrix,rows-1,cols-1);
    return ans;
}
// GIVEN A MATRIX FIND THE MIN PATH SUM 
int findMinPathRecursion(vector<vector<int>>&matrix,int i,int j){
    if(i<0 || j<0){return INT_MAX;}
    if(i==0 || j==0){return matrix[0][0];}
    int fromTop = findMinPathRecursion(matrix,i-1,j);
    int fromLeft = findMinPathRecursion(matrix,i,j-1);
    return matrix[i][j] + min(fromTop,fromLeft);
}
int findMinPath(vector<vector<int>>&matrix){
    int rows=matrix.size();
    int cols=matrix.size();
    int ans=findMinPathRecursion(matrix,rows-1,cols-1);
    return ans;
}
// SUDOKU SOLVER 
bool isValid(int number,int row,int col,vector<vector<int>>&matrix){
    for(int i=0;i<9;i++){
        // checking in the column
        if(matrix[i][col]==number){return false;}
        // checking in the row 
        if(matrix[row][i]==number){return false;}
        // checking in the submatrix
        if(matrix[3*(row/3)+i/3][3*(col/3)+i%3]==number){return false;}
    }
    return true;
}
bool solveSudoku(vector<vector<int>>&matrix){
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            for(int number=1;number<=9;number++){
                if(isValid(number,row,col,matrix)==true){
                    matrix[row][col]=number;
                    if(solveSudoku(matrix)==true){
                        return true;
                    }
                    matrix[row][col]=0;
                }
            }
            return false;
        }
    }
    return true;
}
// COMBNIATION SUM 1 
void combinationSum1Recursion(vector<vector<int>>&ans,vector<int>&current,int index,int target,vector<int>&arr){
    if(target==0){
        ans.push_back(current);
        return;
    }
    if(target<0){
        return;
    }
    for(int i=index;i<arr.size();i++){
        current.push_back(arr[i]);
        combinationSum1Recursion(ans,current,i,target-arr[i],arr);
        current.pop_back();
    }
}
vector<vector<int>>combinationSum1(vector<int>&arr,int target){
    vector<vector<int>>ans;
    vector<int>current;
    combinationSum1Recursion(ans,current,0,target,arr);
    return ans;
}
// COMBINATION SUM 2 ( WE ONLY NEED UNIQUE COMBINATION )
void combinationSum2Recursion(vector<vector<int>>&ans,vector<int>&current,int index,vector<int>&arr,int target){
    if(target==0){
        ans.push_back(current);
        return;
    }
    if(target<0){
        return;
    }
    for(int i=index;i<arr.size();i++){
        if(i>index && arr[i-1]==arr[i]){
            continue;
        }
        current.push_back(arr[i]);
        combinationSum2Recursion(ans,current,i+1,arr,target-arr[i]);
        current.pop_back();
    }
}
vector<vector<int>>combinationSum2(vector<int>&arr,int target){
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    vector<int>current;
    combinationSum2Recursion(ans,current,0,arr,target);
    return ans;
}
// LETTER COMBINATIONS OF A PHONE NUNBER
void letterCombinationsRecursion(vector<string>&ans,string number,vector<string>&map,string current,int index){
    if(index==number.size()){
        ans.push_back(current);
    }
    string letter = map[number[index]-'0'];
    for(char character : letter){
        letterCombinationsRecursion(ans,number,map,current+character,index+1);
    }
}
vector<string>letterCombinations(string number){
    vector<string>ans;
    if(number.size()==0){
        return {};
    }
    vector<string>map={
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    letterCombinationsRecursion(ans,number,map,"",0);
    return ans;
}
// GENERATE ALL THE VALID PARENTHESIS 
void generateParenthesisRecursion(vector<string>&ans,string current,int open,int close){
    if(open==0 && close==0){
        ans.push_back(current);
        return;
    }
    if(open>0){
        generateParenthesisRecursion(ans,current+"(",open-1,close);
    }
    if(close>open){
        generateParenthesisRecursion(ans,current+")",open,close-1);
    }
}
vector<string>generateValidParenthesis(int n){
    vector<string>ans;
    generateParenthesisRecursion(ans,"",n,n);
    return ans;
}
// N QUEENS, PLACE N QUEENS ON BOARD IN SUCH A MANNER THAT THEY ARE NOT ATTACKING EACH OTHER 
bool isSafe(int row,int col,vector<string>&matrix,int n){
    int dupRow = row;
    int dupCol = col;
    while(row>=0 && col>=0){
        if(matrix[row][col]=='Q'){
            return false;
        }
        row--;col--;
    }
    row = dupRow;col=dupCol;
    while(col>=0){
        if(matrix[row][col]=='Q'){
            return false;
        }
        col--;
    }
    col = dupCol;
    while(row<n && col>=0){
        if(matrix[row][col]=='Q'){
            return false;
        }
        row++;col--;
    }
    return true;
}
void createQueenFormation(vector<vector<string>>&ans,vector<string>matrix,int col,int n){
    if(col==n){
        ans.push_back(matrix);
    }
    for(int row = 0; row<n;row++){
        if(isSafe(row,col,matrix,n)==true){
            matrix[row][col]='Q';
            createQueenFormation(ans,matrix,col+1,n);
            matrix[row][col]='.';
        }
    }
}
vector<vector<string>>NQueens(int n){
    vector<vector<string>>ans;
    vector<string>matrix(n);
    string s(n,'.');
    for(int i = 0; i<n ; i++){
        matrix[i]=s;
    }
    createQueenFormation(ans,matrix,0,n);
    return ans;
}
// UNIQUE PATH TO REACH THE DESTINATION FROM STARTING POINT 
int uniquePathsRecursion(int i,int j,int n,int m){
    if(i>=n || j>=m){return 0;}
    if(i==n-1 && j==m-1){return 1;}
    int goDown = uniquePathsRecursion(i+1,j,n,m);
    int goRight = uniquePathsRecursion(i,j+1,n,m);
    return goDown + goRight;
}
int uniquePaths(int n,int m){
    int ans=uniquePathsRecursion(0,0,n,m);
    return ans;
}
// UNIQUE PATHS 2 1 REPRESNTS AN OBSTACLE IN THE MATRIX
int uniquePaths2Recursion(vector<vector<int>>&matrix,int i,int j,int n,int m){
    if(i>=n || j>=m || matrix[i][j]==1){return 0;}
    if(i==n-1 && j==m-1){
        return 1;
    }
    int goDown = uniquePaths2Recursion(matrix,i+1,j,n,m);
    int goRight = uniquePaths2Recursion(matrix,i,j+1,n,m);
    return goDown + goRight;
}
int uniquePaths2(vector<vector<int>>&matrix){
    int r=matrix.size();
    int c=matrix[0].size();
    int ans=uniquePaths2Recursion(matrix,0,0,r,c);
    return ans;
}
// UNIQUE PATHS 3 HERE WE HAVE TO WALK OVER WALKABLE COMPONENT REPRESNTED BY 0 
int uniquePaths3Recursion(vector<vector<int>>&matrix,int i,int j,int remainingCells){
    if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]==-1){
        return 0;
    }
    if(matrix[i][j]==2){
        if(remainingCells==1){return 1;}
        else{return 0;}
    }
    int temp = matrix[i][j];
    remainingCells--;
    int goUp = uniquePaths3Recursion(matrix,i-1,j,remainingCells);
    int goDown = uniquePaths3Recursion(matrix,i+1,j,remainingCells);
    int goRight = uniquePaths3Recursion(matrix,i,j+1,remainingCells);
    int goLeft = uniquePaths3Recursion(matrix,i,j-1,remainingCells);
    int paths = goUp + goDown + goLeft + goRight;
    matrix[i][j]=temp;
    remainingCells++;
    return paths;
}
int uniquePaths3(vector<vector<int>>&matrix){
    int startX=0;
    int startY=0;
    int emptyCells=0;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==1){
                startX=i;startY=j;
            }
            if(matrix[i][j]!=1){emptyCells++;}
        }
    }
    int ans=uniquePaths3Recursion(matrix,startX,startY,emptyCells);
    return ans;
}
// PALINDROME PARTITION 
bool isPalindrome(string s,int start,int end){
    while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void partitionRecursion(int index,string s,vector<vector<string>>&ans,vector<string>&current){
    if(index==s.size()){
        ans.push_back(current);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(isPalindrome(s,index,i)==true){
            current.push_back(s.substr(index,i-index+1));
            partitionRecursion(i+1,s,ans,current);
            current.pop_back();
        }
    }
}
vector<vector<string>>partition(string s){
    vector<vector<string>>ans;
    vector<string>current;
    partitionRecursion(0,s,ans,current);
    return ans;
}
// WORD SEARCH
bool checkFunction(int i,int j,vector<vector<char>>&board,string word,int index){
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[index]){
        return false;
    }
    if(index==word.size()){
        return true;
    }
    char temp = board[i][j];
    board[i][j]='#';
    bool goUp = checkFunction(i-1,j,board,word,index+1);
    bool goDown = checkFunction(i+1,j,board,word,index+1);
    bool goLeft = checkFunction(i,j-1,board,word,index+1);
    bool goRight = checkFunction(i,j+1,board,word,index+1);
    board[i][j]=temp;
    return goUp || goDown || goRight || goLeft;
}
bool checkIfWordExists(vector<vector<char>>board,string word){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(checkFunction(i,j,board,word,0)==true){
                return true;
            }
        }
    }
    return false;
}
// GENERATE ALL THE PERMUTATION OF AN ARRAY 
void generatePermutation(vector<vector<int>>&ans,vector<int>&current,vector<int>&arr,vector<bool>&visited){
    if(current.size()==arr.size()){
        ans.push_back(current);
        return;
    }
    for(int i=0;i<arr.size();i++){
        if(visited[i]==true){
            continue;
        }
        visited[i]=true;
        current.push_back(arr[i]);
        generatePermutation(ans,current,arr,visited);
        visited[i]=false;
        current.pop_back();
    }
}
vector<vector<int>>permutations(vector<int>&arr){
    vector<vector<int>>ans;
    vector<int>current;
    vector<bool>visited(arr.size(),false);
    generatePermutation(ans,current,arr,visited);
    return ans;
}
// GENERATE UNIQUE PERMUTATIONS IN ARRAY 
void generatePermutations2(vector<vector<int>>&ans,vector<int>&current,vector<int>&arr,vector<bool>&visited){
    if(current.size()==0){
        ans.push_back(current);
        return;
    }
    for(int i=0;i<arr.size();i++){
        if(visited[i]==true){
            continue;
        }
        if(i>0 && arr[i]==arr[i-1] && visited[i]==true){
            continue;
        }
        visited[i]=true;
        current.push_back(arr[i]);
        generatePermutations2(ans,current,arr,visited);
        current.pop_back();
        visited[i]=false;
    }
}
vector<vector<int>>permutations2(vector<int>&arr){
    vector<vector<int>>ans;
    vector<int>current;
    vector<bool>visited(arr.size(),false);
    sort(arr.begin(),arr.end());
    generatePermutations2(ans,current,arr,visited);
    return ans;
}
// PASCAL'S TRIANGLE ELEMENT 
int fact(int n){
    if(n==1){
        return 1;
    }
    return n*fact(n-1);
}
int findElementAtPascal(int n,int m){
    int ans=fact(n) /(fact(m)*fact(n-m));
    return ans;
}
// RECURRING SUM OF DIGITS 
// WE HAVE A NUMBER AND WE HAVE TO KEEP ADDING THE DIGITS OF THE NUMBER TILL IT IS A SINGLE DIGIT NUMBER 
// this is also called CASTINGINT OUT NINES
int recurringSumRecursion(int n){
    if(n<10){
        return n;
    }
    if(n==0){
        return 0;
    }
    if(n%9==0){
        return 9;
    }
    else{
        return n%9;
    }
}
int recurringSum(int n){

    int ans=recurringSumRecursion(n);
    return ans;
}
// FIND THE GREATEST COMMONE DIVISOR OF TWO NUMBERS 
int gcdFunction(int a,int b){
    while(b!=0){
        int rem = a%b;
        a=b;
        b=rem;
    }
    return a;
}
int findGCD(int a,int b){
    int ans=gcdFunction(a,b);
    return ans;
}
// COLLATZ CONJECTURE 
// this is also known as the 3*N+1 problem 
int collatzFunction(int n){
    if(n==1){
        return 0;
    }
    if(n%2==0){
        return 1+collatzFunction(n/2);
    }
    else{
        return 1+collatzFunction(3*n+1);
    }
}
int collatzConjecture(int n){
    int ans=collatzFunction(n);
    return ans;
}
// FIND THE LONGEST PALINDROMIC SUBSEQUECEN 
int LPSRecursion(string s,int start,int end){
    if(start>end){
        return 0;
    }
    if(start==end){
        return 1;
    }
    if(s[start]==s[end]){
        return 2+LPSRecursion(s,start+1,end-1);
    }
    else{
        return max(LPSRecursion(s,start+1,end),LPSRecursion(s,start,end-1));
    }
}
int longestPalindromicSubsequence(string s){
    int ans=LPSRecursion(s,0,s.size()-1);
    return ans;
}

