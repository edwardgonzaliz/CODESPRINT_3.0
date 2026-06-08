#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Node{
  public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key, int value){
      this->key = key;
      this->value = value;
      prev = next = nullptr;
    }
};
class LRUCache{
private:
  int capacity;

  unordered_map<int, Node*> mp;

  Node* head; 
  Node* tail;

  void removeNode(Node* node){
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void insertAtFront(Node* node){
    node->next = head->next;
    node->prev = head;

    head->next->prev = node;
    head->next = node;
  }
public:
  
  LRUCache(int capacity){
    this->capacity = capacity;

    head = new Node(-1, -1);
    tail = new Node(-1, -1);

    head->next = tail;
    tail->prev = head;
  }

  int get(int key){
    if(mp.find(key) == mp.end())
      return -1;

    Node* node = mp[key];

    removeNode(node);
    insertAtFront(node);

    return node->value;
  }

  void put(int key, int value){
    if(mp.find(key) != mp.end()){

      Node* node = mp[key];
      node->value = value;

      removeNode(node);
      insertAtFront(node);

      return;
    }

    if(mp.size() == capacity){
      Node* lru = tail->prev;

      removeNode(lru);

      mp.erase(lru->key);

      delete lru;
    }

    Node* newNode = new Node(key, value);

    insertAtFront(newNode);

    mp[key] = newNode;
  }
};

int main(){
  int capacity;
  cin>>capacity;

  int Q;
  cin>>Q;

  LRUCache cache(capacity);

  vector<int> res;

  while(Q--){

    string op;
    cin>>op;

    if(op == "PUT"){
      int key, value;
      cin>>key>>value;

      cache.put(key, value);
    }
    else if(op == "GET"){
      int key;

      cin>>key;

      res.push_back(cache.get(key));
    }
  }

  for(int x: res){
    cout<<x<<endl;
  }
  
  return 0;
}