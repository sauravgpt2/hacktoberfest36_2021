#include<bits/stdc++.h>
using namespace std;

class LRUCache {
  class DNode {
  public:
    int val, key;
    DNode* prev, * next;
    DNode(int key = 0, int val = 0) {
      this->val = val;
      prev = next = nullptr;
      this->key = key;
    }
  };

  void deleteNode(DNode* node) {
    auto delPrev = node->prev;
    auto delNext = node->next;
    delPrev->next = delNext;
    delNext->prev = delPrev;
    node->prev = nullptr;
    node->next = nullptr;
    delete node;
  }

  void insertNode(DNode* node) {
    auto tmp = head->next;
    node->next = tmp;
    node->prev = head;
    head->next = node;
    tmp->prev = node;
  }

  DNode* head, * tail;
  unordered_map<int, DNode*> M;
  int cap;

public:
  LRUCache(int size = 100) {
    cap = size;
    head = new DNode(-1);
    tail = new DNode(-1);
    head->next = tail;
    tail->prev = head;
  }

  void put(int key, int val) {
    if (M.count(key)) {
      auto existingNode = M[key];
      M.erase(key);
      deleteNode(existingNode);
    }
    else if (cap == M.size()) {
      M.erase(tail->prev->key);
      deleteNode(tail->prev);
    }

    insertNode(new DNode(key, val));
    M[key] = head->next;
  }

  int get(int key) {
    if (M.count(key)) {
      auto existingNode = M[key];
      int res = existingNode->val;
      M.erase(key);
      deleteNode(existingNode);
      insertNode(existingNode);
      M[key] = head->next;
      return res;
    }

    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  LRUCache L(2);

  L.put(1, 1);
  L.put(2, 2);
  cout << L.get(1) << endl;
  L.put(3, 3);
  cout << L.get(2) << endl;
  L.put(4, 4);
  cout << L.get(1) << endl;
  cout << L.get(3) << endl;
  cout << L.get(4) << endl;

  return 0;
}