#include<cstdint>
#include<iostream>
#include<vector>
using namespace std;

struct Node{
  int data;

  Node* nextprev_ptr;
};

class XORLL{
private:
  Node* head;
  Node* tail;

  Node* XOR(Node* a, Node* b);

public:

  XORLL();

  void insertAtEnd(int data);

  void traverseLtoR();
};

XORLL::XORLL(){

  head = tail = nullptr;
}

Node* XORLL::XOR(Node* a, Node* b){

  return (Node*)(uintptr_t(a) ^ uintptr_t(b));
}

void XORLL::insertAtEnd(int data){

  Node* newNode = new Node();
  newNode->data = data;
  newNode->nextprev_ptr = tail;

  if(tail){
    tail->nextprev_ptr = XOR(XOR(tail->nextprev_ptr, 
                                 nullptr), newNode);
  }
  else{
    head = newNode;
  }

  tail = newNode;
}

void XORLL::traverseLtoR(){
  Node* curr = head;
  Node* prev = nullptr;

  while(curr != nullptr){
    cout<<curr->data<<" ";
    Node* next = XOR(prev, curr->nextprev_ptr);
    prev = curr;
    curr = next;
  }
  cout<<endl;
}
int main(){
  int N;
  cin>>N;

  vector<int> arr(N);
  for(int i=0; i<N; i++){
    cin>>arr[i];
  }

  XORLL list;

  for(int i=0; i<N; i++){
    list.insertAtEnd(arr[i]);
  }

  list.traverseLtoR();

  return 0;
}