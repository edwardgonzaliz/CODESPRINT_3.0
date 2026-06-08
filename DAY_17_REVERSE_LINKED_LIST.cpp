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
  int n = arr.size();
  if(n == 0) return nullptr;

  Node* head = new Node(arr[0]);
  Node* temp = head;
  
  for(int i=1; i<n; i++){
    Node* newNode = new Node(arr[i]);
    temp->next = newNode;
    temp = newNode;
  }

  return head;
}

Node* reverseNode(Node* head){
  Node* prev = nullptr;
  Node* curr = head;

  while(curr != nullptr){
    Node* newNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = newNode;
  }

  return prev;
}
void printArray(Node* head){
  Node* temp = head;

  while(temp != nullptr){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  
}
int main(){
  int N;
  cin>>N;

  vector<int> arr(N);
  for(int i=0; i<N; i++){
    cin>>arr[i];
  }

  Node* head = insertNode(arr);

  head = reverseNode(head);

  printArray(head);

  return 0;
}