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

  int left = 0, right = N - 1;
  int minScore = INT_MIN;
  while(left <= right){
    int num = min(arr[left], arr[right]);
    num *= (right - left);
    if(minScore < num){
      minScore = num;
    }
    left++;
    right--;
  }

  cout<<minScore<<endl;

  return 0;
}