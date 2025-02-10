#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;

// implementing stack using vector
// class Stack{
//     vector<int> v;

// public:
//     void push(int val){
//         v.push_back(val);
//         return;
//     }

//     void pop(){
//         v.pop_back();
//         return;
//     }

//     int top(){
//         return v[v.size() - 1];
//     }

//     bool empty(){
//         return v.size() == 0;
//     }
// };

// implementing stack using linked list
// class Stack{
//     list<int> ll;

// public:
//     void push(int val){
//         ll.push_front(val);
//         return;
//     }

//     void pop(){
//         ll.pop_front();
//         return;
//     }

//     int top(){
//         return ll.front();
//     }

//     bool empty(){
//         return ll.size() == 0;
//     }
// };

int main() {

    // Stack s;
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}
