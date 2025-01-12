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