#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
  int N;
  cin>>N;

  vector<int> arr(N);
  for(int i=0; i<N; i++){
    cin>>arr[i];
  }

  sort(arr.begin(), arr.end());

  int maxminVal = INT_MIN;

  int left = 0, right = N - 1;
  while(left < right){
    int currSum = 0;
    currSum += arr[left] + arr[right];
    maxminVal = max(currSum, maxminVal);
    left++;
    right--;
  }

  cout<<maxminVal<<endl;

  return 0;
}