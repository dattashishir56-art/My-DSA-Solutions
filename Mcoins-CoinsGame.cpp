#include<iostream>
#include<vector>
using namespace std;
int win(int n,int k,int l){
    if(n==1||n==k||n==l) return 1;
    if(n==0||n<0) return 0;
    return win(n-1,k,l)||win(n-k,k,l)||win(n-l,k,l);
}
int main(){
    int k,l,m;
    cin>>k>>l>>m;
    vector<int> dp(m+1,0);
    dp[1]=dp[k]=dp[l]=1;
    for(int i=2;i<m;i++){
        if(i==k||i==l) continue;
        dp[i]=!(dp[i-1]&&(i-k>=1)?dp[i-k]:1&&(i-l>=1)?dp[i-l]:1);
    }
    int x;
    for(int i=0;i<m;i++){
        cin>>x;
    if(dp[x]==1) cout<<"A";
    else cout<<"B";
    }
    
}