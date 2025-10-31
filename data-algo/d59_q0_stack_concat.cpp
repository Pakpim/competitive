#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void stack_concat(stack<int> &s1, stack<int> &s2){
    // write your code only in this function
    stack<int> t1,t2;
    while (!s1.empty()) {
        int v=s1.top(); s1.pop();
        t1.emplace(v);
    }
    while (!s2.empty()){
        int v=s2.top(); s2.pop();
        t2.emplace(v);
    }
    while (!t2.empty()){
        int v=t2.top(); t2.pop();
        s1.emplace(v);
    }
    while (!t1.empty()){
        int v=t1.top(); t1.pop();
        s1.emplace(v);
    }
}

int main(){
    // read input
    int n, m;
    int c;
    cin >> n >> m;
    stack<int> s1, s2;
    for (int i = 0; i < n; i++){
        cin >> c;
        s1.push(c);
    }
    for (int i = 0; i < m; i++){
        cin >> c;
        s2.push(c);
    }
    // call the function
    stack_concat(s1, s2);
    // display content of the stack
    cout << "S1 has " << s1.size() << endl;
    while (!s1.empty()){
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
    // display content of the stack
    cout << "S2 has " << s2.size() << endl;
    while (!s2.empty()){
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;
}