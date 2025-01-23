#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    private:
        vector<int>sumTree;
        vector<int>minTree;
        vector<int>maxTree;
        vector<int>arr;
        int n;
        // BUILDING THE SUM TREE 
        void buildSumTree(int node,int start,int end){
            if(start==end){
                sumTree[node]=arr[start];
            }else{
                int mid = start + (end-start)/2;
                int leftchild = 2*node+1;
                int rightchild =2*node+2;
                buildSumTree(leftchild,start,mid);
                buildSumTree(rightchild,mid+1,end);
                sumTree[node]=sumTree[leftchild]+sumTree[rightchild];
            }
        }
        // BUILD THE MIN TREE 
        void buildMinTree(int node,int start,int end){
            if(start==end){
                minTree[node]=arr[start];
            }else{
                int mid = start + (end-start)/2;
                int leftchild = 2*node+1;
                int rightchild = 2*node+2;
                buildMinTree(leftchild,start,mid);
                buildMinTree(rightchild,mid+1,end);
                minTree[node]=min(minTree[leftchild],minTree[rightchild]);
            }
        }
        // BUILD THE MAX TREE
        void buildMaxTree(int node,int start,int end){
            if(start==end){
                maxTree[node]=arr[start];
            }else{
                int mid = start + (end-start)/2;
                int leftchild = 2*node+1;
                int rightchild = 2*node+2;
                buildMaxTree(leftchild,start,mid);
                buildMaxTree(rightchild,mid+1,end);
                maxTree[node]=max(maxTree[leftchild],maxTree[rightchild]);
            }
        }
        // QUERY THE SUM 
        int querySum(int node,int start,int end,int L,int R){
            if(R<start || L>end){
                return 0;
            }
            if(L<=start && R>=end){
                return sumTree[node];
            }
            int mid = start + (end-start)/2;
            int leftchild = 2*node+1;
            int rightchild = 2*node+2;
            return querySum(leftchild,start,mid,L,R) + querySum(rightchild,mid+1,end,L,R);
        }
        // QUERY MIN 
        int queryMin(int node,int start,int end,int L,int R){
            if(R<start || L>end){
                return INT_MAX;
            }
            if(L<=start && R>=end){
                return minTree[node];
            }
            int mid = start + (end-start)/2;
            int leftchild = 2*node+1;
            int rightchild =2*node+2;
            return min(queryMin(leftchild,start,mid,L,R),queryMin(rightchild,mid+1,end,L,R));
        }
        // QUERY MAX 
        int queryMax(int node,int start,int end,int L,int R){
            if(R<start || L>end){
                return INT_MIN;
            }
            if(L<=start && R>=end){
                return maxTree[node];
            }
            int mid = start + (end-start)/2;
            int leftchild = 2*node+1;
            int rightchild = 2*node+2;
            return max(queryMax(leftchild,start,mid,L,R),queryMax(rightchild,mid+1,end,L,R));
        }
        // UPDATE SUM 
        void updateSum(int node,int start,int end,int index, int value){
            if(start==end){
                sumTree[node]=value;
            }else{
                int mid = start + (end-start)/2;
                int leftchild = 2*node+1;
                int rightchild = 2*node+2;
                if(index<=mid){
                    updateSum(leftchild,start,mid,index,value);
                }else{
                    updateSum(rightchild,mid+1,end,index,value);
                }
                sumTree[node]=sumTree[leftchild]+sumTree[rightchild];
            }
        }
        // UPDATE MAX
        void updateMax(int node,int start,int end,int index,int value){
            if(start==end){
                maxTree[node]=value;
            }else{
                int mid = start + (end-start)/2;
                int leftchild = 2*node+1;
                int rightchild = 2*node+2;
                if(index<=mid){
                    updateMax(leftchild,start,mid,index,value);
                }else{
                    updateMax(rightchild,mid+1,end,index,value);
                }
                maxTree[node]=max(maxTree[leftchild],maxTree[rightchild]);
            }
        }
        // UPDATE MIN 
        void updateMin(int node,int start,int end,int index,int value){
            if(start==end){
                minTree[node]=value;
            }else{
                int mid = start + (end-start)/2;
                int leftchild = 2*node+1;
                int rightchild = 2*node+2;
                if(index<=mid){
                    updateMin(leftchild,start,mid,index,value);
                }else{
                    updateMin(rightchild,mid+1,end,index,value);
                }
            }
        }
    
    public:
        SegmentTree(vector<int>&inputarr){
            n=inputarr.size();
            arr=inputarr;
            sumTree.resize(4*n,0);
            minTree.resize(4*n,INT_MAX);
            maxTree.resize(4*n,INT_MIN);
            buildSumTree(0,0,n-1);
            buildMinTree(0,0,n-1);
            buildMaxTree(0,0,n-1);
        }
        int rangeSum(int L,int R){
            return querySum(0,0,n-1,L,R);
        }
        int rangeMin(int L,int R){
            return queryMin(0,0,n-1,L,R);
        }
        int rangeMax(int L,int R){
            return queryMax(0,0,n-1,L,R);
        }
        void updateValue(int index,int value){
            updateSum(0,0,n-1,index,value);
            updateMin(0,0,n-1,index,value);
            updateMax(0,0,n-1,index,value);
        }

};

int main(){
    int n;cin >> n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;cin >> x;arr.push_back(x);
    }
    SegmentTree segTree(arr);
    cout << segTree.rangeSum(0,4) << "\n";
    cout << segTree.rangeMin(0,4) << "\n";
    cout << segTree.rangeMax(0,2) << "\n";
}