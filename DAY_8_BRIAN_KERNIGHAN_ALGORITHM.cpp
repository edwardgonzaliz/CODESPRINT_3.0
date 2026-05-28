#include<iostream>
#include<vector>
using namespace std;

//Brian Kernighan's algorithm
void setbitCount(vector<int>arr){
  int n = arr.size();

  for(int i=0; i<n; i++){
    
    unsigned int count = 0;
    int num = arr[i];
    while(num > 0){
      num &= (num - 1);
      count++;
    }

    if(count % 2 == 0){
      cout<<"SAFE"<<endl;
    }
    else{
      cout<<"ANSWER"<<endl;
    }
  }
}
int main(){
  int N;
  cin>>N;

  vector<int> arr(N);
  for(int i=0; i<N; i++){
    cin>>arr[i];
  }

  setbitCount(arr);

  return 0;
}