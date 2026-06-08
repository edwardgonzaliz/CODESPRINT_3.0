#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* next;
    Node(int data){
      this->data = data;
    }
};

bool detectLoop(Node* head){
  Node* slow = head;
  Node* fast = head;
  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) return true;
  }

  return false;
}

int main(){
  int N;
  cin>>N;

  vector<int> arr(N);
  for(int i=0; i<N; i++) cin>>arr[i];

  int POS;
  cin>>POS;

  if(N == 0){
    cout<<"NO\n";
    return 0;
  }
  
  vector<Node*> nodes;

  Node* head = new Node(arr[0]);
  nodes.push_back(head);

  Node* curr = head;

  for(int i=1; i<N; i++){
    Node* temp = new Node(arr[i]);
    curr->next = temp;
    curr = temp;
    nodes.push_back(temp);
  }

  if(POS != -1){
    curr->next = nodes[POS];
  }

  if(detectLoop(head)) cout<<"YES\n";
  else cout<<"NO\n";

  return 0;
}