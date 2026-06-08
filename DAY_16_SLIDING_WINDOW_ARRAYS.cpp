#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N, K, X;
  cin>>N>>K>>X;

  vector<int> arr(N);
  for(int i=0; i<N; i++){
    cin>>arr[i];
  }

  long long windSum = 0;
  int zeroCount = 0;

  for(int i=0; i<K; i++){
    windSum += arr[i];
    if(arr[i] == 0) zeroCount++;
  }

  if(windSum >= X && zeroCount == 0){
    cout<<"YES"<<endl;
    return 0;
  }

  zeroCount = 0;
  
  for(int i=K; i<N; i++){
    windSum += arr[i];
    if(arr[i] == 0) zeroCount++;

    windSum -= arr[i - K];
    if(arr[i - K] == 0) zeroCount--;

    if(windSum >= X && zeroCount == 0){
      cout<<"YES"<<endl;
      return 0;
    }
  }

  cout<<"NO"<<endl;

  return 0;
}