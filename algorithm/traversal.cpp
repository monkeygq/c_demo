#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct node {
  int var;
  struct node *left;
  struct node *right;
};

void midorder(struct node *root) {
  struct node *n = root;
  stack<struct node*> s;
  while(!s.empty() || n) {
    while(n) {
      s.push(n);
      n = n->left;
    }
    if(!s.empty()) {
      n = s.top();
      s.pop();
      cout << n->var << endl;
      n = n->right;
    }
  }
}

void postorder(struct node *root) {
  struct node *n = root;
  stack<struct node*> s1;
  stack<int> s2;
  int flag;
  while(!s1.empty() || n) {
    while (n) {
      s1.push(n);
      s2.push(0);
      n = n->left;
    }
    n = s1.top();
    s1.pop();
    flag = s2.top();
    s2.pop();
    if (flag == 0) {
      s1.push(n);
      s2.push(1);
      n = n->right;
    } else {
      cout << n->var << endl;
      n = NULL;
    }
  }
}

int main() {
  struct node n[7];
  int i;
  for(i = 0; i < 7; i++) {
    n[i].var = i;
    n[i].left = NULL;
    n[i].right = NULL;
  }
  n[0].left = &n[1];
  n[0].right = &n[2];
  n[1].left = &n[3];
  n[1].right = &n[4];
  n[4].left = &n[5];
  n[4].right = &n[6];
  midorder(&n[0]);
  postorder(&n[0]);
  return 0;
}
