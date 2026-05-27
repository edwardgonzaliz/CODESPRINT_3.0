#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N, X;
  cin>>N>>X;

  vector<int> arr(N);
  for(int i=0; i<N; i++){
    cin>>arr[i];
  }

  int sum = 0;
  for(int i=0; i<N; i++){
    sum += arr[i];
    if(sum > X){
      cout<<i<<endl;
      break;
    }
  }

  if(sum <= X){
    cout<<-1<<endl;
  }

  return 0;
}