#include<bits/stdc++.h>
using namespace std;

// IMPLEMENTING STACK USING ARRAY 
class StackUsingArray{
    private:
        int *arr;
        int top;
        int size;

    public:
        StackUsingArray(int s){
            size=s;
            top=-1;
            arr = new int[s];
        }
        // PUSH OPERATION IN STACK 
        void push(int value){
            if(top==size-1){
                cout << "Stack is already full" << "\n";
                return;
            }
            else{
                arr[top]=value;
                top++;
                cout << "Push the value in stack" << "\n";
                return;
            }
        }
        // POP OPERATION IN STACK 
        void pop(){
            if(top==-1){
                cout << "Stack underflow, nothing to pop" << "\n";
                return;
            }
            else{
                top--;
                cout << "Removed the element from stack" << "\n";
            }
        }
        // TOP ELEMENT IN STACK
        int topElement(){
            if(top==-1){
                cout << "Stack is empty" << "\n";
                return -1;
            }
            else{
                return arr[top];
            }
        }
        // IS EMPTY 
        bool isEmpty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }
        // SIZE OF THE STACK 
        int sizeOfStack(){
            return top+1;
        }
};
// REVERSE A STRING USING STACK 
string reverseUsingStack(string s){
    stack<char>st;
    for(int i=0;i<s.size();i++){
        char character = s[i];
        st.push(character);
    }
    int index=0;
    while(st.empty()==false){
        char character = st.top();
        st.pop();
        s[index]=character;
        index++;
    }
    return s;
}
// INSERT X AT THE BOTTOM OF THE STACK 
stack<int>insertAtBottom(stack<int>&st,int X){
    stack<int>temp;
    while(st.empty()==false){
        int topElement = st.top();
        st.pop();
        temp.push(topElement);
    }
    st.push(X);
    while(temp.empty()==false){
        int topElement = temp.top();
        temp.pop();
        st.push(topElement);
    }
    return st;
}
// MAKE THE ARRAY BEATIFUL 
vector<int>makeArray(vector<int>&arr){
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        if(st.empty()==true){
            st.push(arr[i]);
        }
        else if(arr[i]>=0){
            if(st.top()>=0){
                st.push(arr[i]);
            }
            else{
                st.pop();
            }
        }
        else{
            if(st.top()<0){
                st.push(arr[i]);
            }
            else{
                st.pop();
            }
        }
    }
    int index=st.size()-1;
    vector<int>ans;
    while(st.empty()==false){
        int topElement = st.top();
        ans[index]=topElement;
        index--;
    }
    return ans;
}
// STRING MANIPULATION 
vector<string>stringManipulation(vector<string>&stringVector){
    stack<string>st;
    for(int i=0;i<stringVector.size();i++){
        string s = stringVector[i];
        if(st.empty()==true){
            st.push(s);
        }
        else if(s==st.top()){
            st.pop();
        }
        else{
            st.push(s);
        }
    }
    vector<string>ans;
    int index=st.size()-1;
    while(st.empty()==false){
        string topString = st.top();
        ans[index]=topString;
        st.pop();
        index--;
    }
    return ans;
}
// CHECK FOR PARENTHESIS 
bool isValid(string parenthesis){
    stack<char>st;
    for(int i=0;i<parenthesis.size();i++){
        char ch = parenthesis[i];
        if(ch=='('){
            st.push(ch);
        }
        else{
            if(st.size()==0){
                return false;
            }
            else{
                st.pop();
            }
        }
    }
    if(st.size()==0){
        return true;
    }
    else{
        return false;
    }
}
// SOLVING WITHOUT STACK 
bool isValid2(string parenthesis){
    int left=0;
    for(int i=0;i<parenthesis.size();i++){
        char ch = parenthesis[i];
        if(ch=='('){
            left++;
        }
        else{
            if(left==0){
                return false;
            }
            else{
                left--;
            }
        }
    }
    if(left==0){
        return true;
    }
    else{
        return false;
    }
}
// MINIMUM NUMBER OF ADDITIONS TO MAKE THE PARENTHESIS VALID
int minAdditions(string parenthesis){
    int additions=0;
    stack<char>st;
    for(int i=0;i<parenthesis.size();i++){
        char character = parenthesis[i];
        if(character=='('){
            st.push(character);
        }
        else{
            if(st.size()==0){
                additions++;
            }
            else{
                st.pop();
            }
        }
    }
    return additions+st.size();
}
// VALID PARENTHESIS WITH DIFFERENT CHARACTERS
bool checkForValid2(string &s){
    int n = s.size();
    stack<char> st;
    for(int i = 0; i<n ; i++){
        char ch = s[i];
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else{
            if(st.empty()==true){
                return false;
            }
            else if(ch==')'){
                if(st.top()!='('){
                    return false;
                }
                else{
                    st.pop();
                }
            }
            else if(ch=='}'){
                if(st.top()!='{'){
                    return false;
                }
                else{
                    st.top();
                }
            }
            else{
                if(st.top()!='['){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
    }
    if(st.size()==0){
        return true;
    }
    else{
        return false;
    }
}
// CHECK IF THE GIVEN STRINGS ARE EQUAL POST BACKSLASH
bool equalOrNot(string s1,string s2){
    stack<char>st1,st2;
    for(int i=0;i<s1.size();i++){
        char character = s1[i];
        if(character!='#'){
            st1.push(character);
        }
        else{
            st1.pop();
        }
    }
    for(int i=0;i<s2.size();i++){
        char character = s2[i];
        if(character!='#'){
            st2.push(character);
        }else{
            st2.pop();
        }
    }
    while(st1.empty()==false && st2.empty()==false){
        char firstTop = st1.top();
        char secondTop = st2.top();
        st1.pop();st2.pop();
        if(firstTop!=secondTop){
            return false;
        }
    }
    return true;
}
// PRINT BRACKET NUMBER 
vector<int>printBracketNumber(string s){
    stack<int>st;
    vector<int>ans;
    int count=0;
    for(int i=0;i<s.size();i++){
        char character = s[i];
        if(character == '('){
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
vector<int>findMinAtPop(vector<int>&arr){
    stack<int>st,minStack;
    minStack.push(INT_MAX);
    for(int i=0;i<arr.size();i++){
        int element = arr[i];
        st.push(element);
        minStack.push(min(minStack.top(),element));
    }
    vector<int>ans;
    while(st.empty()==false){
        ans.push_back(minStack.top());
        st.pop();minStack.pop();
    }
    return ans;
}
// NEXT GREATER  ELEMENT BRUTE FORCE WAY TO SOLVE 
vector<int>nextGreaterElement(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();i++){
            if(arr[i]<arr[j]){
                ans[i]=arr[j];
                break;
            }
        }
    }
    return ans;
}
// NEXT GREATER ELEMENT OPTIMISED WAY TO SOLVE 
vector<int>nextGreaterElement(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        if(st.empty()==true){
            st.push(i);
        }
        else{
            while(st.empty()==false && arr[st.top()] < arr[i]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
    }
    return ans;
}
// NEXT SMALLER ELEMENT BRUTE FORCE WAY 
vector<int>nextSmallerElement(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i] > arr[j]){
                ans.push_back(arr[j]);
                break;
            }
        }
    }
    return ans;
}
// NEXT SMALLER ELEMENT OPTIMISED WAY 
vector<int>nextSmallerElement(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        while(st.empty()==false && arr[i] < arr[st.top()]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
// SMALLER NUMBER ON LEFT BRUTE FORCE WAY 
vector<int>smallerOnLeft(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    for(int i=0;i<arr.size();i++){
        for(int j=i-1;j>=0;j++){
            if(arr[i]>arr[j]){
                ans[i]=arr[j];
                break;
            }
        }
    }
    return ans;
}
// SMALLER NUMBER ON LEFT OPTIMISED WAY 
vector<int>smallerOnLeft(vector<int>&arr){
    stack<int>st;
    vector<int>ans(arr.size(),-1);
    for(int i=0;i<arr.size();i++){
        while(st.empty()==false && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()==false){
            ans[i]=arr[st.top()];
        }
        st.push(i);
    }
    return ans;
}
// GREATER NUMBER ON LEFT BRUTE FORCE
vector<int>greaterOnLeft(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    for(int i=0;i<arr.size();i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j] > arr[i]){
                ans.push_back(arr[j]);
                break;
            }
        }
    }
    return ans;
}
// GREATER NUMBER ON LEFT OPTIMISED WAY 
vector<int>greaterOnLeft(vector<int>&arr){
    int n=arr.size();
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
// NEXT GREATER ELEMENT IN A CIRCULAR ARRAY 
vector<int>nextGreaterElement(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    stack<int>st;
    for(int i=0;i<2*arr.size();i++){
        int num = arr[i%arr.size()];
        while(st.empty()==false && arr[st.top()] < num){
            ans[st.top()]=num;
            st.pop();
        }
        if(i<arr.size()){
            st.push(i);
        }
    }
    return ans;
}
// STOCK SPAN PROBLEM BRUTE FORCE 
vector<int>stockSpanBruteForce(vector<int>&arr){
    vector<int>span(arr.size(),1);
    for(int i=0;i<arr.size();i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j] <=arr[i]){
                span[i]++;
            }
            else{
                break;
            }
        }
    }
    return span;
}
// STOCK SPAN OPTIMISED WAY 
vector<int>stockSpan(vector<int>&prices){
    vector<int>span(prices.size());
    stack<int>st;
    for(int i=0;i<prices.size();i++){
        while(st.empty()==false && prices[st.top()]<=prices[i]){
            st.pop();
        }
        if(st.empty()==false){
            span[i]=i+1;
        }
        else{
            span[i]=i-st.top();
        }
        st.push(i);
    }
    return span;
}
// CELEBRITY PROBLEM BRUTE FORCE WAY 1 
bool checkForPerson(int person,vector<vector<int>>&M){
    bool validPersonOnRow=true;
    bool validPersonOnColumn=true;
    for(int i=0;i<M.size();i++){
        if(i!=person && M[person][i]==1){
            validPersonOnRow=false;
            break;
        }
    }
    for(int i=0;i<M.size();i++){
        if(i!=person && M[i][person]==0){
            validPersonOnColumn=false;
            break;
        }
    }
    if(validPersonOnColumn==true && validPersonOnRow==true){
        return true;
    }
    else{
        return false;
    }
}
int celebrity(vector<vector<int>>&M,int n){
    for(int i=0;i<n;i++){
        bool ans = checkForPerson(i,M);
        if(ans==true){
            return i;
        }
    }
    return -1;
}
// CELEBRITY PROBLEM GRAPH BASED APPROACH 
int celebrity(vector<vector<int>>&M,int n){
    vector<int>inDegree(M.size(),0);
    vector<int>outDegree(M.size(),0);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(M[i][j]==1){
                inDegree[j]++;
                outDegree[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
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
    while(st.size()>1){
        int a=st.top();st.pop();
        int b=st.top();st.pop();
        if(M[a][b]==1){
            st.push(b);
        }
        else{
            st.push(a);
        }
    }
    int candiateCelebrity = st.top();
    for(int i=0;i<n;i++){
        if(i!=candiateCelebrity && M[i][candiateCelebrity]==0){
            return -1;
        }
    }
    return candiateCelebrity;
}
// LARGEST RECTANGLE IN HISTOGRAM BRUTE FORCE WAY 
int largestRectangle(vector<int>&heights){
    int n=heights.size();
    int maxArea=INT_MIN;
    for(int i=0;i<heights.size();i++){
        int minHeight = heights[i];
        for(int j=i;j<heights.size();j++){
            minHeight = min(minHeight,heights[j]);
            int width = j-i+1;
            int area = minHeight*width;
            maxArea = max(maxArea,area);
        }
    }
    return maxArea;
}
// LARGEST RECTANLGE IN HISTOGRAM OPTIMISED WAY 
vector<int> nextSmallerElement(int arr[], int n) {
    vector<int> ans(n, n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
vector<int> smallestOnLeft(int arr[], int n) {
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
int getMaxArea(int arr[], int n) {
    vector<int> nextSmallestRight = nextSmallerElement(arr, n);
    vector<int> nextSmallestLeft = smallestOnLeft(arr, n);
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = nextSmallestRight[i] - nextSmallestLeft[i] - 1;
        int area = arr[i] * width;
        maxArea = max(area, maxArea);
    }
    return maxArea;
}
// LONGEST LENGTH VALID PARENTHESIS BRUTE FORCE WAY 
bool isValid(string s){
    int balance=0;
    for(int i=0;i<s.size();i++){
        char character = s[i];
        if(character=='('){
            balance++;
        }
        else{
            balance--;
            if(balance<0){
                return false;
            }
        }
    }
    if(balance==0){
        return true;
    }
    return false;
}
int longestValidParenthesis(string s){
    int maxlen=0;
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            string substring = s.substr(i,j-i);
            bool check = isValid(s);
            if(check==true){
                maxlen = max(maxlen,j-i);
            }
        }
    }
    return maxlen;
}
// LONGEST LENGTH IN VALID PARENTHESIS OPTIMISED WAY 
int longestValidParenthesis(string s){
    stack<int>st;
    st.push(-1);
    int maxlen=0;
    for(int i=0;i<s.size();i++){
        char character = s[i];
        if(character=='('){
            st.push(i);
        }
        else{
            st.pop();
            if(st.size()==0){
                st.push(i);
            }else{
                maxlen=max(maxlen,i-st.top());
            }
        }
    }
    return maxlen;
}