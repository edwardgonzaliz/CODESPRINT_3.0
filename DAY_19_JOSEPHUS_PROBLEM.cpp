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

Node* tail = nullptr;

Node* insertNode(vector<int>& arr){
  Node* head = new Node(arr[0]);
  Node* prev = head;
  if(arr.size() == 1){
    head->next = head;
    tail = head->next;
  }

  for(int i=1; i<arr.size(); i++){
    Node* curr = new Node(arr[i]);
    if(i == arr.size() - 1){
      prev->next = curr;
      prev = curr;
      prev->next = head;
      tail = prev;
    }
    else{
      prev->next = curr;
      prev = curr;
    }
  }

  return head;
}

Node* removeKthPerson(Node* head, int& K){
  Node* prev = head;
  Node* temp = head;

  while(temp->next != temp){
    int K1 = K;
    while(K1 > 1){
      prev = temp;
      temp = temp->next;
      K1--;
    }

    Node* curr = temp->next;
    if(temp == head){
      head = curr;
    }
    else if(temp == tail){
      tail = prev;
    }
    prev->next = curr;

    delete temp;

    temp = curr;
  }
  
  return temp;
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

  Node* res = removeKthPerson(head, K);

  cout<<res->data<<endl;

  return 0;
}