#include<iostream>
#include<algorithm>
using namespace std;

string reverse(string s){
  int n = s.length();

  string ans = "";

  reverse(s.begin(), s.end());

  for(int i=0; i<n; i++){

    string word ="";

    while(i < n && s[i] != ' '){
      word += s[i];
      i++;
    }

    reverse(word.begin(), word.end());

    if(word.length()) ans += " " + word;
  }

  return ans.substr(1);
}

int main(){
  string s;

  getline(cin, s);

  string res = reverse(s);

  cout<<res<<endl;

  return 0;
}