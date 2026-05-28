#include<iostream>
#include<vector>
#include<string>
using namespace std;

//INPUT:
// N = 7

// pizzapalace

// pizzahub

// pizzaworld

// burgervilla

// pizzacity

// pastahouse

// pizzaexpress

// search prefix = pizza

//OUTPUT:

// pizzacity

// pizzaexpress

// pizzahub

// pizzapalace

// pizzaworld

// Explanation:

// 1. All restaurant names starting with "pizza" are selected.

// 2. After sorting them lexicographically, the matching names are printed in dictionary order.
void merge(vector<string>& s, int start, int mid, int end){

  int n1 = mid - start + 1;
  int n2 = end - mid;

  vector<string> leftHalf(n1);
  vector<string> rightHalf(n2);

  for(int i=0; i<n1; i++){
    leftHalf[i] = s[start + i];
  }
  for(int i=0; i<n2; i++){
    rightHalf[i] = s[mid + 1 + i];
  }

  int i = 0, j = 0, k = start;

  while(i < n1 && j < n2){
    if(leftHalf[i] < rightHalf[j]){
      s[k++] = leftHalf[i];
      i++;
    }
    else{
      s[k++] = rightHalf[j];
      j++;
    }
  }

  while(i < n1){
    s[k++] = leftHalf[i];
    i++;
  }

  while(j < n2){
    s[k++] = rightHalf[j];
    j++;
  }
}
void mergeSort(vector<string>&s, int start, int end){
  if(start < end){
    int mid = start + (end - start) / 2;

    mergeSort(s, start, mid);
    mergeSort(s, mid+1, end);

    merge(s, start, mid, end);
  }
}
vector<string> lexicoSort(vector<string>& s){
  mergeSort(s, 0, s.size()-1);

  return s;
}
vector<string> prefixMatch(vector<string>& s, string& key){
  int len = key.size();
  int n = s.size();

  vector<string> res;
  for(int i=0; i<n; i++){
      if(s[i].size() >= len){
        string matchFound = s[i].substr(0, len);
  
        if(matchFound == key){
          res.push_back(s[i]);
        }
      }
    }

  if(res.size() == 0){
    res.push_back(" ");
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

  string key;
  cin>>key;
  
  vector<string> s = lexicoSort(arr);
  
  vector<string> ans = prefixMatch(s, key);

  if(ans.size() == 1 && ans[0] == " "){
    cout<<"-1"<<endl;
  }
  else{
    for(int i=0 ; i<ans.size(); i++){
      cout<<ans[i]<<endl;
    }
  }

  return 0;
}