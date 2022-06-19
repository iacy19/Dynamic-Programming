
import java.io.*;
import java.util.*;

class Soln {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int Arr[] = new int[m];
            for (int i = 0; i < m; i++) Arr[i] = sc.nextInt();
            Solution ob = new Solution();

            System.out.println(ob.count(Arr, m, n));
        }
    }
}// } 

class Solution {

        
 public long count(int S[], int m, int n) 
 {
        // code here.
        long dp[] = new long[n+1];  // n= amount +1 size  ( dp table)
        
        dp[0]=1;    // if amount 0 than  print 1
        
        for(int i=0;i<m;i++)   // m = no of element
        {
            for(int j=S[i];j<dp.length;j++)   //  itr all elements
            {
                dp[j]+=dp[j-S[i]];  //  j = amount - s[ele] , add it to dp[j]
            }
        }
        return dp[n];  
    }
    
    
    }
    