#include<iostream>
#include<vector>
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

Node* insertNode(vector<int>& arr){
  if(arr.empty()) return nullptr;
  Node* head = new Node(arr[0]);
  Node* tail = head;

  for(int i=1; i<arr.size(); i++){
    tail->next = new Node(arr[i]);
    tail = tail->next;
  }

  return head;
}

Node* removeKthFromEnd(Node* head, int K){
  Node* fast = head;
  Node* slow = head;

  for(int i=0; i<K; i++){
    fast = fast->next;
  }

  if(fast == nullptr){
    Node* temp = head;
    head = head->next;
    delete temp;
    return temp;
  }

  while(fast->next != nullptr){
    fast = fast->next;
    slow = slow->next;
  }

  Node* target = slow->next;
  slow->next = target->next;
  delete target;

  return head;
}

void printList(Node* head){
  while(head != nullptr){
    cout<<head->data<<" ";
    head = head->next;
  }
}

int main(){
  int N;
  cin>>N;
  vector<int> arr(N);
  for(int i=0; i<N; i++){
    cin>>arr[i];
  }
  int K;
  cin>>K;

  Node* head = insertNode(arr);
  head = removeKthFromEnd(head, K);
  printList(head);

  return 0;
}