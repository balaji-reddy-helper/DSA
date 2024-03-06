/*
Given an array a of n positive integers. The task is to find the maximum of j - i subjected to the constraint of a[i] < a[j] and i < j.

Input:
n = 2
a[] = {1, 10}
Output:
1
Explanation:
a[0] < a[1] so (j-i) is 1-0 = 1.

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        vector<int>v;
        v.push_back(n-1);
        for(int i=n-2;i>=0;i--){
            if(a[i]>a[v.back()])v.push_back(i);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            while( v.size()>0 && a[i]<=a[v.back()]){
                ans=max(ans,v.back()-i);
                v.pop_back();
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends
