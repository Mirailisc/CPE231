#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main() {
  vector <int> vec;
  
  // Queue
  queue<int> que;
  
  que.push(4);
  que.push(3);

  cout << que.front() << endl;

  que.pop();

  que.empty();

  que.size();
  
  // Stack
  stack<int> st;

  st.push(10);
  st.push(20);

  cout << st.top() << endl;

  st.pop();

  st.empty();

  st.size();
  
  st.slice();

  // Priority Queue
  priority_queue<int> pq;

  pq.push(0);
  pq.push(90);
  pq.push(100);
  pq.push(-6);
  pq.push(1);


  cout << pq.top() << endl;
  
  pq.pop();
  
  pq.empty();

  return 0;
}
