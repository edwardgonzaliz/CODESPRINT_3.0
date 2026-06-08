#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValidTriplet(vector<int>& nums, int K){
  int n = nums.size();

  sort(nums.begin(), nums.end());
  for(int i=0; i<n-2; i++){
    int left = i + 1;
    int right = nums.size() - 1;

    while(left < right){
      long long int total = nums[i] + nums[left] + nums[right];

      if(total == K){
        return true;
      }
      else if(total < K){
        left++;
      }
      else{
        right--;
      }
    }
  }

  return false;
}

int main(){
  int N;
  cin>>N;

  vector<int> arr(N);

  for(int i=0; i<N; i++){
    cin>>arr[i];
  }

  int K;
  cin>>K;
  
  if(isValidTriplet(arr, K)){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }

  return 0;
}