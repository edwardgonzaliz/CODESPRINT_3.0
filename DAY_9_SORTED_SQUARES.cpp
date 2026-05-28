#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

vector<int> sqrSort(vector<int>& nums){
  vector<int> res;
  int N = nums.size();
  int low = 0, high = N - 1;

  while(low <= high){
    int sqr1 = pow(nums[low], 2);
    int sqr2 = pow(nums[high], 2);

    if(sqr1 >= sqr2){
      res.push_back(sqr1);
      low++;
    }
    else{
      res.push_back(sqr2);
      high--;
    }
  }

  reverse(res.begin(), res.end());

  return res;
}
int main(){
  int N;
  cin>>N;

  vector<int> arr(N);

  for(int i=0; i<N; i++){
    cin>>arr[i];
  }

  vector<int> ans = sqrSort(arr);

  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }

  cout<<endl;

  return 0;
}