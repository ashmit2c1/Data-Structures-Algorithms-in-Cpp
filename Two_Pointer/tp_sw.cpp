#include<bits/stdc++.h>
using namespace std;
// MERGE ARRAYS
vector<int>mergeArrays(vector<int>&arr1,vector<int>&arr2){
    vector<int>ans;
    int i=0;
    int j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }else{
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while(i<arr1.size()){
        ans.push_back(arr1[i]);
        i++;
    }
    while(j<arr2.size()){
        ans.push_back(arr2[j]);
        j++;
    }
    return ans;
}
// NUMBER OF SMALLER 
vector<int>numSmall(vector<int>&arr1,vector<int>&arr2){
    vector<int>ans;
    for(int i=0;i<arr2.size();i++){
        int element = arr2[i];
        int index = lower_bound(arr1.begin(),arr1.end(),element) - arr1.begin();
        ans.push_back(index);
    }
    return ans;
}
// NUMBER OF SMALLER USING TWO POINTER SOLUTION 
vector<int>numLarger(vector<int>&arr1,vector<int>&arr2){
    int i=0;int j=0;
    vector<int>ans;
    while(j<arr2.size()){
        while(i<arr1.size() && arr1[i] < arr2[j]){
            i++;
        }
        ans.push_back(i);
        j++;
    }
    return ans;
}
// NUMBER OF EQUAL  ( find the pairs in two arrays where a[i]=b[j])
int numEqual(vector<int>&arr1,vector<int>&arr2){
    unordered_map<int,int>mp1,mp2;
    for(int i=0;i<arr1.size();i++){
        mp1[arr1[i]]++;
    }
    for(int i=0;i<arr2.size();i++){
        mp2[arr2[i]]++;
    }
    int cnt=0;
    for(auto it=mp1.begin();it!=mp1.end();it++){
        int element = it->first;
        if(mp2.find(element)!=mp2.end()){
            cnt+=(it->second)*(mp2[element]);
        }
    }
    return cnt;
}
// NUMBER OF EQUAL ( find the pairs in two arrays where arr[i]==brr[j] )
int numEqual(vector<int>&arr1,vector<int>&arr2){
    int cnt=0;
    int i=0;
    int j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]==arr2[j]){
            cnt++;
            i++;
            j++;
        }
        if(arr1[i]<arr2[j]){
            i++;
        }else{
            j++;
        }
    }
    return cnt;
}
// SEGMENT WITH SMALL SUM ( find the max len of subarray with sum less than or equal to s )
vector<vector<int>>findSubarrays(vector<int>&arr){
    vector<vector<int>>ans;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            vector<int>subarray;
            for(int k=i;k<=j;k++){
                subarray.push_back(arr[k]);
            }
            ans.push_back(subarray);
        }
    }
    return ans;
}
vector<int>findLen(vector<vector<int>>&arr,int s){
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        vector<int>check=arr[i];
        int sum=0;
        for(int j=0;j<check.size();j++){
            sum+=check[j];
        }
        if(sum<=s){
            ans.push_back(check.size());
        }
    }
    return ans;
}
int findLen(vector<int>&arr,int s){
    vector<vector<int>>allsubarrays=findSubarrays(arr);
    vector<int>lenwithsumS=findLen(allsubarrays,s);
    sort(lenwithsumS.begin(),lenwithsumS.end());
    return lenwithsumS[lenwithsumS.size()-1];

}
// SEGMENT WITH SMALL SUM ( find the max len of subarray with sum less than or equal to s ) USING TWO POINTER
int findLen(vector<int>&arr,int s){
    int left=0;
    int right=0;
    int sum=0;
    int maxlen = INT_MIN;
    while(right<arr.size()){
        sum+=arr[right];
        if(sum>s){
            sum-=arr[left];
            left++;
        }
        if(sum<=s){
            maxlen=max(maxlen,right-left+1);
        }
        right++;
    }
    return maxlen;
}
// SEGMENT WITH BIG SUN ( find the shortest length of the sub-array with sum greater than or equal to ) bRUTE FORCE
vector<vector<int>>findSubarrays(vector<int>&arr){
    vector<vector<int>>ans;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            vector<int>subarray;
            for(int k=i;k<=j;k++){
                subarray.push_back(arr[k]);
            }
            ans.push_back(subarray);
        }
    }
    return ans;
}
vector<int>findLen(vector<vector<int>>&arr,int s){
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        vector<int>check=arr[i];
        int sum=0;
        for(int j=0;j<check.size();j++){
            sum+=check[j];
        }
        if(sum>=s){
            ans.push_back(check.size());
        }
    }
    return ans;
}
int findLen(vector<int>&arr,int s){
    vector<vector<int>>allsubarrays=findSubarrays(arr);
    vector<int>lenwithsumS=findLen(allsubarrays,s);
    sort(lenwithsumS.begin(),lenwithsumS.end());
    return lenwithsumS[0];

}
// SEGMENT WITH BIG SUN ( find the shortest length of the sub-array with sum greater than or equal to ) TWO POINTER TECHNIQUE 
int findlen(vector<int>&arr,int s){
    int minlen=INT_MAX;
    int left=0;
    int sum=0;
    for(int right=0;right<arr.size();right++){
        sum+=arr[right];
        while(sum>=s){
            minlen=min(minlen,right-left+1);
            sum-=arr[left];
            left++;
        }
    }
    if(minlen==INT_MAX){
        return -1;
    }else{
        return minlen;
    }
}
// NUMBER OF SEGMENTS WITH SMALL SUM 
vector<vector<int>>findsubarrays(vector<int>&arr){
    vector<vector<int>>ans;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            vector<int>subarray;
            for(int k=i;k<=j;k++){
                subarray.push_back(arr[k]);
            }
            ans.push_back(subarray);
        }
    }
    return ans;
}
int findarrays(vector<vector<int>>&subarrays,int s){
    int cnt=0;
    for(int i=0;i<subarrays.size();i++){
        vector<int>check=subarrays[i];
        int sum=0;
        for(int j=0;j<check.size();j++){
            sum+=check[j];
        }
        if(sum<=s){
            cnt++;
        }
    }
    return cnt;
}
int findCount(vector<int>&arr,int s){
    vector<vector<int>>subarrays=findsubarrays(arr);
    int count = findarrays(subarrays,s);
    return count;
}
// NUMBER OF SEGMENTS WITH SMALL SUM USING TWO POINTER TECHNIQUE 
int findCount(vector<int>&arr,int target){
    int right=0;
    int left=0;
    int sum=0;
    int cnt=0;
    while(right<arr.size()){
        sum+=arr[right];
        while(sum>target){
            sum-=arr[left];
            left++;
        }
        if(sum<=target){
            cnt+=(right-left+1);
        }
        right++;
    }
    return cnt;
}
// NUMBER OF SEGMENTS WITH BIG SUM BRUTE FORCE
vector<vector<int>>findsubarrays(vector<int>&arr){
    vector<vector<int>>ans;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            vector<int>subarray;
            for(int k=i;k<=j;k++){
                subarray.push_back(arr[k]);
            }
            ans.push_back(subarray);
        }
    }
    return ans;
}
int findarrays(vector<vector<int>>&subarrays,int s){
    int cnt=0;
    for(int i=0;i<subarrays.size();i++){
        vector<int>check=subarrays[i];
        int sum=0;
        for(int j=0;j<check.size();j++){
            sum+=check[j];
        }
        if(sum>=s){
            cnt++;
        }
    }
    return cnt;
}
// NUMBER OF SEGMENTS WITH WITH BIG SUM TWO POINTER TECHNIQUE 
int findSeg(vector<int>&arr,int s){
    int sum=0;
    int left=0;
    int right=0;
    int cnt=0;
    while(right<arr.size()){
        sum+=arr[right];
        while(sum>=s){
            cnt+=(arr.size()-right);
            sum-=arr[left];
            left++;
        }
        right++;
    }
}
// SEGMENTS WITH SMALL SET 
vector<vector<int>>findsubarrays(vector<int>&arr){
    vector<vector<int>>ans;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            vector<int>subarray;
            for(int k=i;k<=j;k++){
                subarray.push_back(arr[k]);
            }
            ans.push_back(subarray);
        }
    }
    return ans;
}
int findCount(vector<vector<int>>arr, int k){
    int count=0;
    for(int i=0;i<arr.size();i++){
        vector<int>check=arr[i];
        set<int>st;
        for(int j=0;j<check.size();j++){
            st.insert(check[j]);
        }
        if(st.size()<=k){
            count++;
        }
    }
    return count;
}
int findSmall(vector<int>&arr,int k){
    vector<vector<int>>subarrays=findsubarrays(arr);
    int count = findCount(subarrays,k);
    return count;
}
// SEGMENTS WITH SMALL SET 
int findSmall(vector<int>&arr,int k){
    int left=0;
    int right=0;
    unordered_map<int,int>mp;
    int cnt=0;
    while(right<arr.size()){
        mp[arr[right]]++;
        while(mp.size()>k){
            mp[arr[left]]--;
            if(mp[arr[left]]==0){
                mp.erase(arr[left]);
            }
            left++;
        }
        cnt+=(right-left+1);
        right++;
    }
    return cnt;
}
// FIND THE SEGMENTS WITH SMALL SPREAD ( DIFFERENCE BETWEEN THE MAX AND MIN ELEMENT IN THE SEGMENT IS ATMOST K)
vector<vector<int>>findsubarrays(vector<int>&arr){
    vector<vector<int>>ans;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            vector<int>subarray;
            for(int k=i;k<=j;k++){
                subarray.push_back(arr[k]);
            }
            ans.push_back(subarray);
        }
    }
    return ans;
}
int findCount(vector<vector<int>>arr, int k){
    int count=0;
    for(int i=0;i<arr.size();i++){
        vector<int>check=arr[i];
        sort(check.begin(),check.end());
        int diff = abs(check[check.size()-1]-check[0]);
        if(diff<=k){
            count++;
        }
    }
    return count;
}
int findSpread(vector<int>&arr,int k){
    vector<vector<int>>subarrays=findsubarrays(arr);
    int count = findCount(subarrays,k);
    return count;
}
// FIND THE SEGMENTS WITH SMALL SPREAD ( DIFFERENCE BETWEEN THE MAX AND MIN ELEMENT IN THE SEGMENT IS ATMOST K)
int findSpread(vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;
    multiset<int> window;

    int left = 0;
    for (int right = 0; right < n; right++) {
        window.insert(arr[right]); 
        while (*window.rbegin() - *window.begin() > k) {
            window.erase(window.find(arr[left])); 
            left++; 
        }
        count += right - left + 1;
    }
    return count;
}