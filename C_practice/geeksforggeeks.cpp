
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        // int c[][2];
        int count=0,c_del=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){//j=i+1
                // if(i==0){
                //     if(arr[j-1]>k){
                //         // int temp=arr[j];
                //         arr[j]=arr[n-c_del-1];
                //         c_del++;
                //     }
                //  }
                if(arr[i]+arr[j]==k){
                    // c[i][0]=i;
                    // c[i][1]=j;
                    count++;
                }
            }
            // if(i==0) n=n-c_del;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends