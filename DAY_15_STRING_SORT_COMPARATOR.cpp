#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int vowelCnt(string &s){
  int cnt = 0;
  for(char c : s){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
      cnt++;
    }
  }
  return cnt;
}

int main(){
  int N;
  cin>>N;

  vector<string> arr(N);
  for(int i=0; i<N; i++){
    cin>>arr[i];
  }

  auto compare = [&](string &a, string &b){
    int totalvowela = vowelCnt(a);
    int totalvowelb = vowelCnt(b);

    if(totalvowela != totalvowelb){
      return totalvowela > totalvowelb;
    }

    if(a.size() != b.size()){
      return a.size() < b.size();
    }

    return a < b;
  };

  sort(arr.begin(), arr.end(), compare);

  for(int i=0; i<N; i++){
    cout<<arr[i]<<endl;
  }

  return 0;
}