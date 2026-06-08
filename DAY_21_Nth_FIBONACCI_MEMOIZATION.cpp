#include<iostream>
#include<vector>
using namespace std;

int nthFibonacciUtil(int n, vector<int>& dp){

  if(n <= 1){
    return n;
  }

  if(dp[n] != -1){
    return dp[n];
  }

  dp[n] = nthFibonacciUtil(n - 1, dp)
          +nthFibonacciUtil(n - 2, dp);

  return dp[n];
}

int nthFibonacci(int n){
  vector<int> dp(n + 1, -1);

  return nthFibonacciUtil(n, dp);
}

int main(){
  int N;
  cin>>N;
  int res = nthFibonacci(N);
  cout<<res<<endl;

  return 0;
}