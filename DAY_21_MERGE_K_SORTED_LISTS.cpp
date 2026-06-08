#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
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

class Compare{
public:
  bool operator()(Node* a, Node* b){
    return a->data > b->data;
  }
};

Node* mergeKLinkedLists(vector<Node*>& arr){
  priority_queue<Node*, vector<Node*>, Compare> pq;

  for(Node* head: arr){
    if(head != nullptr){
      pq.push(head);
    }
  }

  Node* dummy = new Node(-1);
  Node* temp = dummy;

  while(!pq.empty()){
    Node* top = pq.top();
    pq.pop();

    temp->next = top;
    temp = top;

    if(top->next != nullptr){
      pq.push(top->next);
    }
  }

  return dummy->next;
}

void printLists(Node* head){
  while(head != nullptr){
    cout<<head->data;
    if(head->next) cout<<" ";
    head = head->next;
  }
  cout<<endl;
}

int main(){
  int N;
  cin>>N;
  cin.ignore();

  vector<Node*> arr(N, nullptr);

  for(int i=0; i<N; i++){
    string line;
    getline(cin, line);

    if(line.empty()) continue;

    stringstream ss(line);
    int value;

    Node* head = nullptr;
    Node* tail = nullptr;

    while(ss >> value){
      Node* newNode = new Node(value);

      if(head == nullptr){
        head = newNode;
        tail = newNode;
      }
      else{
        tail->next = newNode;
        tail = newNode;
      }
    }

    arr[i] = head;
  }

  Node* mergedHead = mergeKLinkedLists(arr);
  printLists(mergedHead);

  return 0;
}