#include<iostream>
using namespace std;

int insertionSort(int arr[], int n){
  int shiftCnt = 0;
  
  for(int i=1; i<n; i++){
    int key = arr[i];
    int j = i - 1;

    while(j >= 0 && arr[j] > key){
      arr[j + 1] = arr[j];
      j = j - 1;
      shiftCnt++;
    }
    arr[j + 1] = key;
  }

  return shiftCnt;
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

  int shiftCnt = insertionSort(arr, N);
  printArray(arr, N);

  cout<<shiftCnt<<endl;

  return 0;
}