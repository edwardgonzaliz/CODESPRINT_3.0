#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;
  cin>>N;

  vector<vector<int>> arr(N, vector<int> (N));
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin>>arr[i][j];
    }
  }

  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  
  vector<vector<char>> c(N, vector<char> (N));
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(arr[i][j]){
        c[i][j] = 'O';
      }
      else{
          bool gossip_check = false;
          for(int k=0; k<4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni>=0 && ni<N && nj>=0 && nj<N){
              if(arr[ni][nj] == 1){
                gossip_check = true;
                break;
              }
            }
          }
          if(gossip_check) c[i][j] = 'X';
          else c[i][j] = 'S';
      }
    }
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cout<<c[i][j];
      if(j != N-1) cout<<" ";
    }
    cout<<endl;
  }

  return 0;
}