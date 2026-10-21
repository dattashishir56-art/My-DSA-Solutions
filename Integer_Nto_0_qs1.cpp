#include<bits/stdc++.h>
using namespace std;

int f(int n){//recurtion
    if(n==1) return 0;
    if(n==2||n==3) return 1;
    
    return 1+min(f(n-1),min((n%2==0)?f(n/2):INT_MAX,(n%3==0)?f(n/3):INT_MAX));
}
int f(int n,vector<int>& dp){//Memoization Method
    if(n==1) return 0;//TC-O(n)
    if(n==2||n==3) return 1;//SC-O(2n)=O(n)
    if(dp[n]!=-1) return dp[n];
    return dp[n]=1+min(f(n-1,dp),min((n%2==0)?f(n/2,dp):INT_MAX,(n%3==0)?f(n/3,dp):INT_MAX));
}
int main(){

 int n;
 cin>>n;
 vector<int> dp(n+9,-1);
 //Tabulation Mathod
 dp[1]=0;//TC-O(n)
 dp[2]=dp[3]=1;//SC-O(n)
 for(int i=4;i<=n;i++){
    dp[i]=1+min(dp[i-1],min((i%2==0)?dp[i/2]:INT_MAX,(i%3==0)?dp[i/3]:INT_MAX));
 }
 cout<<dp[n]<<endl;
 return 0;
}