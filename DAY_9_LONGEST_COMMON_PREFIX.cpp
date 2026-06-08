#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& arr){

  int minLen = arr[0].size();

  for(string& str: arr){
    minLen = min(minLen, (int)str.size());
  }

  string res;

  for(int i=0; i<minLen; i++){
    char ch = arr[0][i];

    for(string& str: arr){
      if(str[i] != ch){
        return res;
      }
    }

    res.push_back(ch);
  }

  return res;
}

int main(){
  int N;
  cin>>N;

  vector<string> arr(N);

  for(int i=0; i<N; i++){
    cin>>arr[i];
  }

  cout<<longestCommonPrefix(arr);

  return 0;
}