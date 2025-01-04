#include<bits/stdc++.h>
using namespace std;

// FIND THE SUM IN RANGE USING BRUTE FORCE
int calculate(vector<int>&arr,int leftindex,int rightindex){
    int sum=0;
    for(int i=leftindex;i<=rightindex;i++){
        sum+=arr[i];
    }
    return sum;
}
vector<int>findSum(vector<int>&arr,vector<pair<int,int>>&queries){
    vector<int>ans;
    for(int i=0;i<queries.size();i++){
        int leftindex = queries[i].first-1;
        int rightindex = queries[i].second-1;
        int answer = calculate(arr,leftindex,rightindex);
        ans.push_back(answer);
    }
    return ans;
}
// FIND THE SUM USING PREFIX ARRAY APPROACH
int calculateOptimised(int leftIndex,int rightIndex,vector<int>&arr){
    if(leftIndex==0){
        return arr[rightIndex];
    }
    else{
        return arr[rightIndex]-arr[leftIndex-1];
    }
}
vector<int>findSumOptimised(vector<int>&arr,vector<pair<int,int>>&queries){
    vector<int>ans;
    for(int i=1;i<arr.size()-1;i++){
        arr[i]+=arr[i-1];
    }
    for(int i=0;i<queries.size();i++){
        int leftindex=queries[i].first-1;
        int rightindex = queries[i].second-1;
        int answer = calculateOptimised(leftindex,rightindex,arr);
        ans.push_back(answer);
    }
    return ans;
}
// FIND THE NUMBER OF SUB-ARRAYS WITH THE GIVEN SUM TARGET 
int findSubarrays(vector<int>&arr,int target){
    int count=0;
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
            if(sum==target){
                count++;
            }
        }
    }
    return count;
}
// FIND THE NUMBER OF SUB-ARRAYS WITH THE GIVEN SUM TARGET OPTIMISED APPROACH 
int findSubarraysOptimised(vector<int>&arr,int target){
    unordered_map<int,int>mp;
    int currentSum=0;
    int count=0;
    for(int i=0;i<arr.size();i++){
        currentSum+=arr[i];
        if(currentSum==target){
            count++;
        }
        if(mp.find(currentSum-target)!=mp.end()){
            count+=mp[currentSum-target];
        }
        mp[currentSum]++;
    }
    return count;
}
// FIND THE INDEX AT WHICH THE SUFFIX AND PREFIX SUM ARE LEAST 
int findIndex(vector<int>&arr){
    vector<int>prefix=arr;
    vector<int>suffix=arr;
    for(int i=1;i<arr.size();i++){
        prefix[i]+=prefix[i-1];
    }
    for(int i=suffix.size()-2;i>=0;i--){
        suffix[i]+=suffix[i+1];
    }
    int minSum=INT_MAX;int index=-1;
    for(int i=0;i<arr.size();i++){
        int sum = prefix[i]+suffix[i];
        if(sum<minSum){
            minSum=sum;index=i;
        }
    }
    return index+1;
}
// FIND THE INDEX AT WHICH THE SUFFIX AND PREFIX ARRAY SUM IS MIN
int findIndexOptimised(vector<int>&arr){
    int minVal = INT_MAX;
    int minIndex=-1;
    for(int i=0;i<arr.size();i++){
        int val = arr[i];
        if(val<minVal){
            minVal=val;
            minIndex=i;
        }
    }
    return minIndex+1;
}
// FIND THE COUNT OF SUB-ARRAYS WHOSE SUM IS EQUAL TO LENGTH OF THE SUBARRAY 
int findCount(vector<int>&arr){
    int count=0;
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
            if(sum==(j-i+1)){
                count++;
            }
        }
    }
    return count;
}
// FIND THE COUNT OF SUBARRAYS WHOSE SUM IS EQUAL TO LENGTH OF THE SUBARRAY 
int findCountOptimised(vector<int>&arr){
    int currentSum=0;
    unordered_map<int,int>mp;
    mp[0]=1;int count=0;
    for(int i=0;i<arr.size();i++){
        currentSum+=arr[i];
        if(mp.find(currentSum-(i+1))!=mp.end()){
            count+=mp[currentSum-(i+1)];
        }
        mp[currentSum-(i+1)]++;
    }
    return count;
}
// FIND THE MAX GCD THAT CAN BE OBTAINED REMOVING ONE ELEMENT FROM THE ARRAY 
int calculateGCD(int a,int b){
    while(b!=0){
        int rem = a%b;
        a=b;b=rem;
    }
    return a;
}
int findGCD(vector<int>&arr){
    int ans=arr[0];
    for(int i=1;i<arr.size();i++){
        ans=calculateGCD(ans,arr[i]);
    }
    return ans;
}
int findMaxGCD(vector<int>&arr){
    int ans=INT_MIN;
    for(int i=0;i<arr.size();i++){
        vector<int>newArr;
        for(int j=0;j<arr.size();j++){
            if(i!=j){
                newArr.push_back(arr[j]);
            }
        }
        int gcd = findGCD(newArr);
        ans=max(ans,gcd);
    }
    return ans; 
}
// FIND THE MAX GCD THAT CAN BE OBTAINED BY REMOVING ONE ELEMENT FROM THE ARRAY OPTIMISED 
int calculateGCD(int a,int b){
    while(b!=0){
        int rem = a%b;
        a=b;b=rem;
    }
    return a;
}
int findMaxGCDOptimised(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return 0; // No element left if we remove one.

    vector<int> prefixGCD(n, 0), suffixGCD(n, 0);

    // Compute prefix GCD
    prefixGCD[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixGCD[i] = calculateGCD(prefixGCD[i - 1], arr[i]);
    }

    // Compute suffix GCD
    suffixGCD[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffixGCD[i] = calculateGCD(suffixGCD[i + 1], arr[i]);
    }

    // Calculate maximum GCD after removing one element
    int maxGCD = 0;
    for (int i = 0; i < n; i++) {
        int gcdExcludingCurrent;
        if (i == 0) {
            gcdExcludingCurrent = suffixGCD[1]; // No prefix for first element
        } else if (i == n - 1) {
            gcdExcludingCurrent = prefixGCD[n - 2]; // No suffix for last element
        } else {
            gcdExcludingCurrent = calculateGCD(prefixGCD[i - 1], suffixGCD[i + 1]);
        }
        maxGCD = max(maxGCD, gcdExcludingCurrent);
    }

    return maxGCD;
}
// FIND THE MAX LENGTH OF THE SUBARRAY WITH EQUAL 1 AND 0
int findMaxLength(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            arr[i]=-1;
        }
    }
    int len=INT_MIN;
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
            if(sum==0){
                len=max(len,j-i+1);
            }
        }
    }
    return len;
}
// FIND THE MAX LENGTH OF THE SUBARRAY WITH EQUAL 1 AND 0 OPTIMISED
int findMaxLenOptimised(vector<int>&arr){
    int maxLen=0;
    int prefixSum=0;
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            arr[i]=-1;
        }
        prefixSum+=arr[i];
        if(prefixSum==0){
            maxLen=max(maxLen,i+1);
        }
        if(mp.find(prefixSum)!=mp.end()){
            maxLen=max(maxLen,i-mp[prefixSum]);
        }
        mp[prefixSum]=i;
    }
    return maxLen;
}
// CREATE A 2D PREFIX ARRAY 
vector<vector<int>>createPrefix(vector<vector<int>>&matrix){
    vector<vector<int>>prefix(matrix.size(),vector<int>(matrix[0].size()));
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            prefix[i][j]=matrix[i][j];
            if(i>0){
                prefix[i][j]+=matrix[i-1][j];
            }
            else if(j>0){
                prefix[i][j]+=matrix[i][j-1];
            }
            else{
                prefix[i][j]-=matrix[i-1][j-1];
            }
        }
    }
    return prefix;
}
// PERFORMING QUERIES ON 2D PREFIX ARRAY 
int returnAnswer(vector<vector<int>>&points,vector<vector<int>>&prefix){
    int x1=points[0][0];
    int x2=points[1][0];
    int y1=points[0][1];
    int y2=points[1][1];
    int ans=prefix[x2][y2];
    if(x1>0){
        ans-=prefix[x1-1][y2];
    }
    if(y1>0){
        ans-=prefix[x2][y1-1];
    }
    if(x1>0 && y1>0){
        ans+=prefix[x1-1][y1-1];
    }
    return ans;
}
// FOREST QUERIES CSES
// GIVEN A MATRIX * REPRESENTS A TREE, IN ANY AREA GIVEN THROUGH QUERIES, FIND THE NUMBER OF TREES
int calculateFunction(vector<vector<int>>&matrix,int x1,int y1,int x2,int y2){
    int ans=matrix[x2][y2];
    if(x1>0){ans-=matrix[x1-1][y2];}
    if(y1>0){ans-=matrix[x2][y1-1];}
    if(x1>0 && y1>0){ans+=matrix[x1-1][y1-1];}
    return ans;
}
vector<int>solveFunction(vector<vector<int>>&prefixMatrix,vector<pair<pair<int,int>,pair<int,int>>>&queries){
    vector<int>ans;
    for(int i=0;i<queries.size();i++){
        int x1=queries[i].first.first-1;
        int y1=queries[i].first.second-1;
        int x2=queries[i].second.first-1;
        int y2=queries[i].second.second-1;
        int answer=calculateFunction(prefixMatrix,x1,y1,x2,y2);
        ans.push_back(answer);
    }
    return ans;
}

void solution(){
    int n;int q;
    cin >> n >> q;
    vector<vector<int>>matrix(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char a;cin >> a;
            if(a=='*'){matrix[i][j]=1;}
            else{matrix[i][j]=0;}
        }
    }
    vector<pair<pair<int,int>,pair<int,int>>>queries;
    for(int i=0;i<q;i++){
        int x1;int y1;int x2;int y2;
        cin >> x1 >> y1 >> x2 >> y2;
        queries.push_back({{x1,y1},{x2,y2}});
    }
    vector<vector<int>>prefixMatrix(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            prefixMatrix[i][j]=matrix[i][j];
            if(i>0){
                prefixMatrix[i][j]+=prefixMatrix[i-1][j];
            }
            if(j>0){
                prefixMatrix[i][j]+=prefixMatrix[i][j-1];
            }
            if(i>0 && j>0){
                prefixMatrix[i][j]-=prefixMatrix[i-1][j-1];
            }
        }
    }
    vector<int> ans=solveFunction(prefixMatrix,queries);
    for(int i=0;i<ans.size();i++){cout << ans[i] << "\n";}

}