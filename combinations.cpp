/*
nCr :
Input : n (n<=1000)

q queries(q<=1e7)
each query has two integers a and b
print otutput (aCb)
*/

#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int dp[MAX][MAX]; // matrix to be used for bottom up approach
int save[MAX][MAX]; // matrix to be used for top down approach

void bottomUp(int n){  //time complexity for this approach is O(n^2)
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
}

int topDown(int i,int j){
    if(i<0 || j<0)
        return 0;
    if(save[i][j]!=0)
        return save[i][j];
    
    save[i][j] = topDown(i-1,j-1) + topDown(i-1,j);

    return save[i][j];
}

int main(){
    int n; cin >> n ;
    //intializing the dp array for bottom up approach
    // also same 'iniatialization' is done for the save array
    // save array is used in the top down fashion
    for(int i=0;i<=n;i++){
        dp[i][0] = dp[i][i]= 1;
        
        save[i][0] = save[i][i] = 1;
    } 
    bottomUp(n); // calling the bootom up helper function to fill the dp array
    
    for(int i=n;i>=1;i--)
        topDown(n,i); // i and j values passed are both n and n


    int queries; cin >> queries;
    while(queries--){
        int a,b; cin >> a >> b;
        cout << "value from bottom up approach is:" << dp[a][b] << endl;
        cout << "value from top down approach is:" << save[a][b] << endl;
    }

    return 0;
}
