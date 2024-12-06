#include<bits/stdc++.h>
using namespace std;

//BINARY SEARCH CODE

int binarySearch(vector<int>&arr,int target){
    int start=0;
    int end=arr.size()-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(target>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}
// RECURSIVE BINARY SEARCH 
int recursiveBinarySearch(vector<int>&arr,int start,int end,int target){
    if(start>end){
        return -1;
    }
    int mid = start + (end-start)/2;
    if(arr[mid]==target){
        return mid;
    }
    if(target>arr[mid]){
        return recursiveBinarySearch(arr,mid+1,end,target);
    }
    else{
        return recursiveBinarySearch(arr,start,mid-1,target);
    }
}
// FIND THE SQUARE ROOT OF A NUMBER USING BINARY SEARCH
bool checkFunction(int mid, int n){
    if(mid<=n/mid){
        return true;
    }
    else{
        return false;
    }
}
int findSQRT(int n){
    int start=0;
    int end=n;
    int ans=-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(checkFunction(mid,n)==true){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans; 
}
// FIND THE FIRST AND LAST OCCURENCE OF EELEMENT 
vector<int>findFirstLast(vector<int>arr,int target){
    int start=0;
    int end=arr.size()-1;
    int first=-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(target=arr[mid]){
            first=mid;
            end=mid-1;
        }
        if(target>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    int second=-1;
    start=0;
    end=arr.size()-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(target==arr[mid]){
            second=mid;
            start=mid+1;
        }
        if(target>arr[mid]){
            start=mid+1;
        }
        if(target<arr[mid]){
            end=mid-1;
        }
    }
    vector<int>ans;
    ans.push_back(first);
    ans.push_back(second);
    return ans;
}

// FIND THE INDEX POSITION OF ELEMENT IN ARRAY 
int findPosition(vector<int>&arr,int element){
    int start=0;
    int end=arr.size()-1;
    int ans=arr.size();
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]>=element){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}
// CHECK WHEHTER AN ELEMENT IS PRESENT IN 2D MATRIX OR NOT 
bool checkForElement(vector<vector<int>>&matrix,int element){
    int rows=matrix.size();
    int cols=matrix[0].size();
    for(int i=0;i<rows;i++){
        int start=0;
        int end=cols-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(matrix[i][mid]==element){
                return true;
            }
            if(element > matrix[i][mid]){
                start=mid+1;
            }
            if(element < matrix[i][mid]){
                end=mid-1;
            }
        }
    }
    return false;
}
// FIND THE PEAK ELEMENT IN MOUTNAIN ARRAY 
int findPeak(vector<int>&arr){
    int start=0;
    int end=arr.size()-1;
    while(start<end){
        int mid = start + (end-start)/2;
        if(arr[mid] < arr[mid+1]){
            start=mid+1;
        }
        else{
            end=mid;
        }
    }
    return start;
}
// FIND THE KTH POSITIVE MISSING NUMBERS 
int findKthPositive(vector<int>&arr,int k){
    int start=0;
    int end=arr.size()-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        int missingNumber = arr[mid]-(mid+1);
        if(k>missingNumber){start=mid+1;}
        else{end=mid-1;}
    }
    return start+k;
}