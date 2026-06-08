#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    Node(int data){
      this->data = data;
      next = nullptr;
    }
};

Node* getIntersectionNode(Node* head1, Node* head2){
  if(!head1 || !head2) return nullptr;

  Node* p1 = head1;
  Node* p2 = head2;

  while(p1 != p2){
    p1 = (p1 == nullptr)? head2 : p1->next;
    p2 = (p2 == nullptr)? head1 : p2->next;
  }

  return p1;
}

int main(){
  int N;
  cin>>N;

  vector<int> a(N);
  for(int i=0; i<N; i++) cin>> a[i];

  int M;
  cin>>M;

  vector<int> b(M);
  for(int i=0; i<M; i++) cin>>b[i];

  int X;
  cin>>X;

  unordered_map<int, Node*> mp;

  Node* head1 = nullptr;
  Node* tail1 = nullptr;

  for(int x: a){
    Node* node = new Node(x);

    if(!head1){
      head1 = tail1 = node;
    }else{
      tail1->next = node;
      tail1 = node;
    }

    mp[x] = node;
  }

  Node* head2 = nullptr;
  Node* tail2 = nullptr;

  bool intersected = false;

  for(int x: b){
    if(x != -1 && x == X){
      if(!head2) head2 = mp[x];
      else
        tail2->next = mp[x];

      intersected = true;
      break;
    }

    Node* node = new Node(x);

    if(!head2){
      head2 = tail2 = node;
    }else{
      tail2->next = node;
      tail2 = node;
    }
  }

  Node* intersection = getIntersectionNode(head1, head2);

  if(intersection)
    cout<<intersection->data;
  else
    cout<<-1;
  
  return 0;
}