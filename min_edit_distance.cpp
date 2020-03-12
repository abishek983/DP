/*
https://practice.geeksforgeeks.org/problems/edit-distance/0
https://www.geeksforgeeks.org/edit-distance-dp-5/
*/

#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int dp[MAX+1][MAX+1];  // this dp array is for top down approach

// Time and Space complexity is O(n*m)
int topDown(string s1,string s2,int n,int m){
    if(n==0 || m==0){
        dp[n][m] = m+n ;
        return dp[n][m];
    }    
    if(dp[n][m]!=-1)
        return dp[n][m];
    
    int ans = INT_MAX;
    if(s1[n-1]==s2[m-1]){
        dp[n][m] = topDown(s1,s2,n-1,m-1);
        return dp[n][m];
    }
    else
    {
        // adding a new character to string s1
        // adding a new character to s1 is equivalent to deleting
        // a character from s2
        ans = min(ans,1+topDown(s1,s2,n,m-1));
        
        // removing a character from s1
        ans = min(ans,1+topDown(s1,s2,n-1,m));

        // replacing a character 
        ans = min(ans , 1+topDown(s1,s2,n-1,m-1));

    }
    return (dp[n][m] = ans);
}

int minn(int a,int b,int c){
    return min(min(a,b),c);
}

// Time and Space complexity is O(n*m)
int bottomUp(string s1,string s2,int n,int m){
    //2d array to store the dp state
    int save[MAX+1][MAX+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            // no element in string s1 and s2 gows from '0' to m
            // thus adding elements to s1
            if(i==0)
                save[0][j] = j;
            // deleting elements from s1 as s1 grows but s2 is '0'
            if(j==0)
                save[i][0] = i;

            else if(s1[i-1]==s2[j-1]){
                save[i][j] = save[i-1][j-1]; 
            }
            else{
                save[i][j] = 1 + minn(save[i-1][j-1] , save[i-1][j] , save[i][j-1]);
            } 
        }
    }
    
    return save[n][m];
}

int main(){
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        for(int i=0;i<=MAX;i++)
            for(int j=0;j<=MAX;j++)
                dp[i][j] = -1;
        int n,m;
        cin >> n >> m;
        string s1,s2; cin >> s1 >> s2;
        topDown(s1,s2,n,m) ;
        cout << "Answer from the topDown approach : " << dp[n][m] << endl; 
        cout << "Answer from the bottomUp approach : " << bottomUp(s1,s2,n,m) << endl;
    }
}