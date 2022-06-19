// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int S[], int m, int n) {

        // code here.
        
        long long dp[m+1][n+1];  // table
        
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0)                          // ar=0 sum= something
                    dp[i][j]=0;
                    
                if(j==0)                          
                    dp[i][j]=1;               // ar=0  sum =0   { }  =1
            }
        }
        
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(S[i-1]<=j)     //  array ele < sum
                
                    dp[i][j]= dp[i][j-S[i-1]] + dp[i-1][j];  //include
                    
                else  //  big num than sum avail , just exclude
                    dp[i][j]= dp[i-1][j]; //exclude
            }
        }
        
        return dp[m][n];
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends