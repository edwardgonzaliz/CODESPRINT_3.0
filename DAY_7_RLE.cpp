#include<iostream>
#include<string>
using namespace std;

int main(){
  string S;
  getline(cin, S);

  string encoded_str = "";
  int count = 1;
  
  for(int i=1; i<S.size(); i++){
    if(S[i] == S[i-1]){
      count += 1;
    }
    else{
      encoded_str += S[i-1] + to_string(count);
      count = 1;
    }
  }

  encoded_str += S[S.size()-1] + to_string(count);

  cout<<encoded_str<<endl;

  return 0;
}