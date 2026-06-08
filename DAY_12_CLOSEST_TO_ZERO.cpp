#include<iostream>
#include<vector>
#include<cstdlib>
#include<climits>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<int> LH(n1), RH(n2);
  for(int i=0; i<n1; i++){
    LH[i] = arr[left + i];
  }
  for(int j=0; j<n2; j++){
    RH[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0, k = left;
  while(i < n1 && j < n2){
    if(LH[i] < RH[j]){
      arr[k++] = LH[i];
      i++;
    }
    else{
      arr[k++] = RH[j];
      j++;
    }
  }

  while(i < n1){
    arr[k++] = LH[i++];
  }

  while(j < n2){
    arr[k++] = RH[j++];
  }
}
void mergeSort(vector<int>& arr, int left, int right){
  if(left < right){
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}
pair<int, int> approxZeroSum(vector<int> arr, int left, int right){
  int minDiff = INT_MAX;
  pair<int, int> approxZeroPair;
  while(left < right){
    int sum = arr[right] + arr[left];
    int diff = abs(0 - sum);
    if(diff < minDiff){
      minDiff = diff;
      approxZeroPair = {arr[left], arr[right]};
    }
    else if(sum > 0){
      right--;
    }
    else{
      left++;
    }
  }

  return approxZeroPair;
}
int main(){
  int N;
  cin>>N;

  vector<int> arr(N);
  for(int i=0; i<N; i++){
    cin>>arr[i];
  }

  mergeSort(arr, 0, N - 1);

  pair<int, int> s = approxZeroSum(arr, 0, N - 1);

  cout<<s.first<<" "<<s.second<<endl;

  return 0;
}