#include<iostream>
#include<string>
using namespace std;

int main(){
  string s;
  getline(cin, s);

  int flagUp = 0, flagLow = 0, flagDig = 0;

  for(int i=0; i<s.size(); i++){
    if(s[i] >= 65 && s[i] <= 90){
      flagUp = 1;
    }
    else if(s[i] >= 97 && s[i] <= 122){
      flagLow = 1;
    }
    else if(s[i] >= 48 && s[i] <= 57){
      flagDig = 1;
    }

    if(flagUp && flagLow && flagDig){
      break;
    }
  }

  if(flagUp && flagLow && flagDig){
    cout<<"STRONG"<<endl;
  }
  else{
    cout<<"WEAK"<<endl;
  }

  return 0;
}