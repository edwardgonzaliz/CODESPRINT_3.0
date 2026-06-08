#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void merge(vector<pair<string, int>>& vec, int st, int mid, int end){
  int n1 = mid - st + 1;
  int n2 = end - mid;

  vector<pair<string, int>> left(n1), right(n2);
  
  for(int i=0; i<n1; i++){
    left[i] = {vec[st+i].first, vec[st+i].second};
  }
  for(int j=0; j<n2; j++){
    right[j] = {vec[mid+1+j].first, vec[mid+1+j].second};
  }

  int i = 0, j = 0;
  int k = st;

  while(i < n1 && j < n2){
    if(left[i].second <= right[j].second){
      vec[k] = left[i];
      i++;
    }
    else{
      vec[k] = right[j];
      j++;
    }
    k++;
  }

  while(i < n1){
    vec[k] = left[i];
    i++;
    k++;
  }

  while(j < n2){
    vec[k] = right[j];
    j++;
    k++;
  }
}
void mergeSort(vector<pair<string, int>>& vec, int st, int end){
  if(st < end){
    int mid = st + (end - st) / 2;

    mergeSort(vec, st, mid);
    mergeSort(vec, mid+1, end);

    merge(vec, st, mid, end);
  }
}
void sortScore(vector<pair<string, int>>& vec){
  int n = vec.size();
  mergeSort(vec, 0, n-1);

  for(int i=0; i<n; i++){
    cout<<vec[i].first<<" "<<vec[i].second<<endl;
  }
}

int main(){
  int N;
  cin>>N;

  vector<pair<string, int>> vec(N);
  for(int i=0; i<N; i++){
    cin>>vec[i].first>>vec[i].second;
  }

  sortScore(vec);

  return 0;
}