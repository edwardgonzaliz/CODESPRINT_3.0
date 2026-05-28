#include<iostream>
#include<string>
// #include<vector>
#include<algorithm>
#include<cctype>
using namespace std;

int main(){
  string s;
  getline(cin, s);
  
  // vector<pair<char, int>> letters(26);
  transform(s.begin(), s.end(), s.begin(), [](unsigned char c){return tolower(c); });
  // for(int i=0; i<26; i++){
  //   char ch = (char)(97 + i);
  //   letters[ch] = 0;
  // }

  int word_cnt = 0;
  bool sameWord = false;

  for(char ch: s){
    if(isalnum(ch)){
      if(!sameWord){
        sameWord = true;
        word_cnt++;
      }
    }
    else{
      sameWord = false;
    }
  }

  int vow_cnt = 0;
  int const_cnt = 0;
  for(char ch: s){
    int asc = (int)ch;
    if(asc >= 97 && asc <= 122){
      if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        vow_cnt++;
      }
      else{
        const_cnt++;
      }
    }
    else{
      continue;
    }
  }

  cout<<"Total Vowels: "<<vow_cnt<<endl;
  cout<<"Total Consonants: "<<const_cnt<<endl;
  cout<<"Total Words: "<<word_cnt<<endl;

  return 0;
}