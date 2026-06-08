#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
  string jewels, stones;
  cin>>jewels;
  cin>>stones;
  unordered_map<char, int> um;

    for(char& c: jewels){
      for(char& x: stones){
        if(c == x){
          um[c]++;
        }
      }
    }

  int sum = 0;
  for(auto& it: um){
    sum += it.second;
  }

  cout<<sum<<endl;

  return 0;
}