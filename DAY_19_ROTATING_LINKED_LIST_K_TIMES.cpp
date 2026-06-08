#include<iostream>
#include<vector>
using namespace std;

class Node{
  public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
      this->data = data;
      prev = next = nullptr;
    }
};

Node* tail = nullptr;

Node* insertNode(vector<int>& arr){
  Node* head = new Node(arr[0]);
  Node* curr = head;

  for(int i=1; i<arr.size(); i++){
    Node* newNode = new Node(arr[i]);
    curr->next = newNode;
    newNode->prev = curr;
    curr = newNode;
  }

  tail = curr;
  return head;
}

Node* kRotations(Node* head, int K){
  if(!head || !head->next || K == 0){
    return head;
  }

  int len = 1;
  Node* temp = head;

  while(temp->next){
    len++;
    temp = temp->next;
  }

  K = K % len;

  if(K == 0){
    return head;
  }

  Node* newtail = tail;

  for(int i=0; i<K; i++){
    newtail = newtail->prev;
  }

  Node* newhead = newtail->next;

  tail->next = head;
  head->prev = tail;

  newtail->next = nullptr;
  newhead->prev = nullptr;

  return newhead;
}
void printDLL(Node* head){
  Node* temp = head;

  while(temp != nullptr){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

int main(){
  int N, K;
  cin>>N>>K;

  vector<int> arr(N);
  for(int i=0; i<N; i++){
    cin>>arr[i];
  }

  Node* head = insertNode(arr);

  head = kRotations(head, K);

  printDLL(head);

  return 0;
}