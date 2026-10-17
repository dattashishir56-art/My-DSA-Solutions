#include<bits/stdc++.h>
using namespace std;
vector<int> get_digit(int n){// TC=log n
    vector<int> x;
    while(n>0){
        if(n%10!=0) x.push_back(n%10);
        n=n/10;
    }
    return x;
}
int f(int n){//recurtion
    if(n==0) return 0;//TC~O(nlog(n))
    if(n<=9) return 1;//SC=O(n)
    vector<int> d=get_digit( n);
    int result=INT_MAX;
    for(int i=0;i<d.size();i++){
     result=min(result,f(n-d[i]));
    }
    return 1+ result;
}

int f(int n,vector<int>& dp){//Memoization Method
    if(n==0) return 0;//TC~O(nlog(n))
    if(n<=9) return 1;//SC=O(n)
    if(dp[n]!=-1) return dp[n];
    vector<int> d=get_digit( n);
    int result=INT_MAX;
    for(int i=0;i<d.size();i++){
     result=min(result,f(n-d[i],dp));
    }
    return dp[n]= 1+ result;
}

int main(){
   int n;
   cin>>n;
   vector<int> dp(n+100,-1);
   //Tabulation Mathod
   dp[0]=0;
   for(int i=1;i<=9;i++){
    dp[i]=1;
   }
   for(int i=10;i<=n;i++){// Overall TC=O(n.log(n));(n for i=10 to n loop and log(n) for calculating digits)
   vector<int> digit=get_digit(i);// SC=O(n);(for the vector)
   int result=INT_MAX;
   for(int j=0;j<digit.size();j++){
      result=min(result,dp[i-digit[j]]);
   }
   dp[i]=1+result;
   }
   cout<<dp[n]<<endl;
}