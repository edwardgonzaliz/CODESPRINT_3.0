#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;
  cin>>N;

  vector<vector<int>> arr(N, vector<int>(N));
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin>>arr[i][j];
    }
  }

int sum1 = 0, sum2 = 0;
  
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(i == j){
        sum1 += arr[i][j];
      }

      if(i + j == N-1){
        sum2 += arr[i][j];
      }
    }
  }

  if(sum1 == sum2){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }

  return 0;
}