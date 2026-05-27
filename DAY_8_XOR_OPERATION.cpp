#include<iostream>
using namespace std;

int main(){
  int N;
  cin>>N;

  int arr[N];
  for(int i=0; i<N; i++){
    cin>>arr[i];
  }

  int x = arr[0];
  for(int i=1; i<N; i++){
    x = x ^ arr[i];
  }

  if(!x){
    cout<<"BALANCED"<<endl;
  }
  else{
    cout<<"UNBALANCED"<<endl;
  }

  return 0;
}