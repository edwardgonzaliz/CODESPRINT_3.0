#include<iostream>
#include<vector>
using namespace std;

void sortClubs(vector<int>& nums){
  int st = 0, mid = 0, end = nums.size() - 1;
  
 while(mid <= end){
   if(nums[mid] == 0){
     swap(nums[st], nums[mid]);
     st++;
     mid++;
   }
   else if(nums[mid] == 1){
     mid++;
   }
   else{
     swap(nums[mid], nums[end]);
     end--;
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

  sortClubs(arr);

  for(int i=0; i<N; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  return 0;
}