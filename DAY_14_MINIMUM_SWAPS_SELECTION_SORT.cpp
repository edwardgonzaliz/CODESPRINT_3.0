#include<iostream>
using namespace std;

int swapped(int arr[], int n){

  int swap = 0;
  for(int i=0; i<n-1; i++){
    int min_idx = i;
    for(int j=i+1; j<n; ++j){
      if(arr[j] < arr[min_idx]){
        min_idx = j;
      }
    }
    if(arr[i] != arr[min_idx]){
      int temp = arr[i];
      arr[i] = arr[min_idx];
      arr[min_idx] = temp;
      swap++;
    }
  }
  return swap;
}

void printArray(int arr[], int n){
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main(){
  int N;
  cin>>N;

  int arr[N];
  for(int i=0; i<N; i++){
    cin>>arr[i];
  }

  int k = swapped(arr, N);
  printArray(arr, N);
  
  cout<<k<<endl;

  return 0;
}