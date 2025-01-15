#include<bits/stdc++.h>
using namespace std;
// IMPLEMENTATION OF STACK USING ARRAY 
class StackArray{
    private:
        int *arr;
        int top;
        int size;
    public:
        StackArray(int s){
            arr = new int[s];
            top = -1;
            size = s;
        }
    //PUSHING VALUE INTO STACK 
    void push(int value){
        if(top==size-1){
            cout << "Stack is full, cannot push more elements" << "\n";
            return;
        }else{
            top++;
            arr[top]=value;
            cout << "Pushed the element into stack" << "\n";
            return;
        }
    }
    // POPPING AN ELEMENT FROMTHE STOC
    void pop(){
        if(top==-1){
            cout << "Stack is already empty, cannot remove any element" << "\n";
            return;
        }else{
            top--;
            cout << "Removed the element from the stack" <<"\n";
        }
    }
    // RETURN THE TOP ELEMENT IN THE STACK 
    int topElement(){
        if(top==-1){
            cout << "Stack is empty, no element to return" <<" \n";
            return -1;
        }else{
            return arr[top];
        }
    }
    // SIZE OF THE STACK 
    int sizeOfStack(){
        return top+1;
    }
    // IS STACK EMPTY 
    bool isEmpty(){
        if(top==-1){
            return true;
        }else{
            return false;
        }
    }
};
// REVERSE A STRING USING STACK
string reverseString(string s){
    stack<char>st;
    for(int i=0;i<s.size();i++){
        char character = s[i];
        st.push(character);
    }
    int index=0;
    while(st.empty()==false){
        char character = st.top();
        st.pop();
        s[index]=character;index++;
    }
    return s;
}
// INSERT X AT THE BOTTOM OF THE STACK
stack<int>insertAtBottom(stack<int>&st,int X){
    stack<int>temp;
    while(st.empty()==false){
        int topElement = st.top();st.pop();
        temp.push(topElement);
    }
    st.push(X);
    while(temp.empty()==false){
        int topElement = temp.top();temp.pop();
        st.push(topElement);
    }
    return st;
}
// MAKE THE ARRAY BEAUTIFUL 
vector<int>makeBeautiful(vector<int>&arr){
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        int element = arr[i];
        if(st.empty()==true){
            st.push(element);
        }
        if(element>=0){
            if(st.top()>=0){
                st.push(element);
            }else{
                st.pop();
            }
        }else{
            if(st.top()<0){
                st.push(element);
            }else{
                st.pop();
            }
        }
    }
    vector<int>ans(st.size(),-1);
    int index=st.size()-1;
    while(st.empty()==false){
        ans[index]=st.top();st.pop();
        index--;
    }
    return arr;
}
// STRING MANIPULATION 
vector<string>stringManipulation(vector<string>&arr){
    stack<string>st;
    for(int i=0;i<arr.size();i++){
        string s=arr[i];
        if(st.empty()==true){
            st.push(s);
        }
        if(st.top()==s){
            st.pop();
        }else{
            st.push(s);
        }
    }
    int index=st.size()-1;
    vector<string>ans(st.size(),"");
    while(st.empty()==false){
        ans[index]=st.top();st.pop();
        index--;
    }
    return ans;
}
// CHECK FOR VALID PARENTHESIS 
bool isValid(string parenthesis){
    stack<char>st;
    for(int i=0;i<parenthesis.size();i++){
        char character = parenthesis[i];
        if(character=='('){
            st.push(character);
        }else{
            if(st.empty()==true){
                return false;
            }else{
                st.pop();
            }
        }
    }
    if(st.size()==0){
        return true;
    }
    return false;
}
// CHECK FOR VALID PARENTHESIS 
bool isValid(string parenthesis){
    stack<char>st;
    int count=0;
    for(int i=0;i<parenthesis.size();i++){
        char character = parenthesis[i];
        if(character=='('){
            count++;
        }
        else{
            if(count==0){
                return false;
            }else{
                count--;
            }
        }
    }
    if(count==0){
        return true;
    }else{
        return false;
    }
}
// MINIUM ADDITIONS TO MAKE THE STRING VALID PARENTHESIS 
int minAdditions(string parenthesis){
    stack<char>st;
    int additions=0;
    for(int i=0;i<parenthesis.size();i++){
        char character = parenthesis[i];
        if(character=='('){
            st.push(character);
        }else{
            if(st.size()==0){
                additions++;
            }else{
                st.pop();
            }
        }
    }
    return st.size()+additions;
}
// CHECK FOR VALID PARENTHESIS WITH DIFFERENT CHARACTERS
bool checkParenthesis(string parenthesis){
    stack<char>st;
    for(int i=0;i<parenthesis.size();i++){
        char character = parenthesis[i];
        if(character=='(' || character=='{' || character=='['){
            st.push(character);
        }else{
            if(st.size()==0){
                return false;
            }
            if(character==')'){
                if(st.top()!='('){
                    return false;
                }else{
                    st.pop();
                }
            }
            else if(character=='}'){
                if(st.top()!='{'){
                    return false;
                }else{
                    st.pop();
                }
            }else{
                if(st.top()!=']'){
                    return false;
                }else{
                    st.pop();
                }
            }
        }
    }
    if(st.size()==0){
        return false;
    }
    return true;
}
// CHECK IF STRINGS ARE EQUAL POST BACKSLAASH 
bool areEqual(string s1,string s2){
    stack<char>st;
    stack<char>st2;
    for(int i=0;i<s1.size();i++){
        char character = s1[i];
        if(character!='#'){
            st.push(character);
        }else{
            st.pop();
        }
    }
    for(int i=0;i<s2.size();i++){
        char character = s2[i];
        if(character!='#'){
            st.push(character);
        }else{
            st.pop();
        }
    }
    if(st.size()!=st2.size()){
        return false;
    }
    while(st.empty()==false){
        char topElement1=st.top();
        char topElement2=st2.top();
        if(topElement1!=topElement2){
            return false;
        }
        st.pop();st2.pop();
    }
    return true;
}
// PRINT THE BRACEKT NUMBER 
vector<int>printBracketNumber(string s){
    stack<int>st;
    vector<int>ans;
    int count=0;
    for(int i=0;i<s.size();i++){
        char character = s[i];
        if(character=='('){
            count++;
            st.push(count);
            ans.push_back(count);
        }
        else if(character==')'){
            ans.push_back(st.top());
            st.pop();
        }
    }
    return ans;
}
// GET MINIMUM AT POP
vector<int>getMin(vector<int>&arr){
    stack<int>st;
    stack<int>minSt;
    minSt.push(INT_MAX);
    for(int i=0;i<arr.size();i++){
        int element = arr[i];
        st.push(element);
        minSt.push(min(minSt.top(),element));
    }
    vector<int>ans;
    while(st.empty()==false){
        ans.push_back(minSt.top());
        st.pop();minSt.pop();
    }
    return ans;
}
// NEXT GREATER ELEMENT BRUTE FORCE WAY 
vector<int>nextGreater(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[j] > arr[i]){
                ans[i]=arr[j];
                break;
            }
        }
    }
    return ans;
}
// NEXT GREATER ELEMENT OPTIMIES USING STACK 
vector<int>nextGreater(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        while(st.empty()==false && arr[st.top()] < arr[i]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
}
// NEXT SMALLER ELEMENT BRUTE FORCE 
vector<int>nextSmaller(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        while(st.empty()==false && arr[st.top()] > arr[i]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
// SMALLER NUMBER ON LEFT 
vector<int>smallerOnLeft(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    for(int i=0;i<arr.size();i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j] < arr[i]){
                ans.push_back(arr[j]);
                break;
            }
        }
    }
    return ans;
}
// SMALLER NUMBER ON LEFT OPTIMISED 
vector<int>smallerOnLeft(vector<int>&arr){
   vector<int>ans(arr.size(),-1);
   stack<int>st;
   for(int i=0;i<arr.size();i++){
    while(st.empty()==false && arr[st.top()]>=arr[i]){
        st.pop();
    }
    if(st.empty()==false){
        ans[i]=arr[st.top()];
    }
    st.push(i);
   } 
}
// GREATER NUMBER ON LEFT 
vector<int>greaterOnLeft(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    for(int i=0;i<arr.size();i++){
        for(int j=i-1;j>=0;j++){
            if(arr[j] > arr[i]){
                ans[i] =arr[j];
                break;
            }
        }
    }
    return ans;
}
// GREATER NUMBER ON LEFT OPTIMISED WAY 
vector<int>greaterOnLeft(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        while(st.empty()==false && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.empty()==false){
            ans[i]=arr[st.top()];
        }
        st.push(i);
    }
    return ans;
}
// NEXT GREATER ELEMENT IN CIRCULAR WAY 
vector<int>nextGreaterCircular(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    stack<int>st;
    for(int i=0;i<2*arr.size();i++){
        int num = arr[i%arr.size()];
        while(st.empty()==false && arr[st.top()]<num){
            ans[st.top()] = num;
            st.pop();
        }
        if(i<arr.size()){
            st.push(i);
        }
    }
}
// STOCK SPAN PROBLEM
vector<int>stockSpan(vector<int>&prices){
    vector<int>ans(prices.size());
    for(int i=0;i<prices.size();i++){
        for(int j=i-1;j>=0;j--){
            if(prices[j]<=prices[i]){
                ans[i]++;
            }
            else{
                break;
            }
        }
    }
    return ans;
}
// STOCK SPAN PROBLEM USING 
vector<int>stockSpan(vector<int>&arr){
    vector<int>span(arr.size());
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        while(st.empty()==false && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.empty()==true){
            span[i]=i+1;
        }else{
            span[i]=i-st.top();
        }
        st.push(i);
    }
    return span;
}
// CELEBRITY PROBLEM BRUTE FORCE
bool check(int person,vector<vector<int>>&M){
    bool validPersonRow=true;
    bool validPersonCol=true;
    for(int i=0;i<M.size();i++){
        if(i!=person && M[person][i]==1){
            validPersonRow=false;
            break;
        }
    }
    for(int i=0;i<M.size();i++){
        if(i!=person && M[i][person]==1){
            validPersonCol=false;
            break;
        }
    }
    if(validPersonCol==true && validPersonRow==true){
        return true;
    }else{
        return false;
    }
}
int celebrity(vector<vector<int>>&M,int n){
    for(int i=0;i<n;i++){
        bool ans=check(i,M);
        if(ans==true){
            return true;
        }
    }
    return false;
}
// CELEBRITY PROBLEM GRAPH BASED APPROACH 
int celebrity(vector<vector<int>>&M,int n){
    vector<int>inDegree(n,0);
    vector<int>outDegree(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            inDegree[j]++;
            outDegree[i]++;
        }
    }
    for(int i=0;i<outDegree.size();i++){
        if(inDegree[i]==n-1 && outDegree[i]==0){
            return i;
        }
    }
    return -1;
}
// CELEBRITY PROBLEM STACK BASED APPROACH 
int celebrity(vector<vector<int>>&M,int n){
    stack<int>st;
    for(int i=0;i<n;i++){
        st.push(i);
    }
    while(st.empty()==false){
        int a=st.top();st.pop();
        int b=st.top();st.pop();
        if(M[a][b]==1){
            st.push(b);
        }else{
            st.push(a);
        }
    }
    int candidate = st.top();
    for(int i=0;i<n;i++){
        if(i!=candidate && M[candidate][i]==1){
            return -1;
        }
    }
    return candidate;
}
// LARGEST RECTANGLE IN HISTOGRAM 
int largestRectangle(vector<int>&heights){
    int maxArea=INT_MIN;
    for(int i=0;i<heights.size();i++){
        int  minHeight = heights[i];
        for(int j=i;j<heights.size();j++){
            minHeight = min(minHeight,heights[j]);
            int width = j-i+1;
            int area = minHeight*width;
            maxArea = max(maxArea,area);
        }
    }
    return maxArea;
}
// LARGEST RECTANGLE IN HISTOGRAM OPTIMISED WAY 
vector<int>nextSmallestElement(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        while(st.empty()==false && arr[st.top()]>arr[i]){
            ans[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
vector<int>smallestOnLeft(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        while(st.empty()==false && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(st.empty()==false){
            ans[i]=arr[st.top()];
        }
        st.push(i);
    }
    return ans;
}
int largestRectangle(vector<int>&heights,int n){
    vector<int>nextSmalletRight = nextSmallestElement(heights);
    vector<int>nextSmallestLeft = smallestOnLeft(heights);
    int maxArea=0;
    for(int i=0;i<heights.size();i++){
        int width = nextSmalletRight[i] - nextSmallestLeft[i];
        int area = heights[i]*width;
        maxArea = max(area,maxArea);
    }
    return maxArea;
}
// LONGEST VALID PARENTHESIS 
bool checkSub(string substring){
    int open=0;
    for(int i=0;i<substring.size();i++){
        char character = substring[i];
        if(character=='('){
            open++;
        }else{
            if(open==0){
                return false;
            }
            open--;
        }
    }
    if(open==0){return true;}else{
        return false;
    }
}
int longestValidParenthesis(string s){
    int maxLen=0;
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<=s.size();j++){
            string substring = s.substr(i,j-i);
            if(checkSub(substring)==true){
                maxLen = max(maxLen,j-i);
            }
        }
    }
    return maxLen;
}
// lONGEST VALID PARENTHESIS 
int longestValidParenthesis(string s){
    int maxlen=0;
    stack<int>st;
    for(int i=0;i<s.size();i++){
        char character = s[i];
        if(character=='('){
            st.push(i);
        }else{
            st.pop();
            if(st.size()==0){
                st.push(i);
            }else{
                maxlen = max(maxlen,i-st.top());
            }
        }
    }
    return maxlen;
}