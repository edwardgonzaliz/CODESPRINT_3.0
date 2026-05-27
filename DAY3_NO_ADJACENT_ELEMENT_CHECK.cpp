#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> arr){
  int n = arr.size();

  for(int i=0; i<n-1; i++){
    if(arr[i] == arr[i+1]){
      return false;
    }
  }

  return true;
}
int main(){
  int N;
  cin>>N;
  vector<int> arr(N);
  for(int i=0; i<N; i++){
    cin>>arr[i];
  }

  bool k = isValid(arr);

  if(k){
    cout<<"VALID"<<endl;
  }
  else{
    cout<<"INVALID"<<endl;
  }
}