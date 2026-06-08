#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
  string S1, S2;
  getline(cin, S1);
  getline(cin, S2);

  if(S1.size() != S2.size()){
    cout<<"NO"<<endl;
  }
  else{
    unordered_map<char, int> um;
    for(auto& it: S1){
      um[it]++;
    }
  
    for(auto& it: S2){
      um[it]--;
    }
  
    int flag = 0;
    for(auto& it: um){
      if(it.second != 0){
        flag = 1;
        break;
      }
    }
  
    if(flag){
      cout<<"NO"<<endl;
    }
    else{
      cout<<"YES"<<endl;
    }
  }

  return 0;
}