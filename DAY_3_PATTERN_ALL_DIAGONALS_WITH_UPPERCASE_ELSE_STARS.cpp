#include<iostream>
using namespace std;

int main(){
  int N;
  cin>>N;

  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      if(i == j){
        cout<<(char)(i+64)<<" ";
      }
      else if(j == N+1-i){
        cout<<(char)(i+64)<<" ";
      }
      else{
        cout<<'*'<<" ";
      }
    }
    cout<<endl;
  }

  return 0;
}