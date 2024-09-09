#include <iostream>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;
    int a;
    a = s.size();
    stack<char> n;
    for(int i = 0; i < a; i++){
        if(!n.empty() and n.top() == s[i]){
            n.pop();
        }
        else{
            n.push(s[i]);
        }
    }
    if(n.empty()){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}

//Dmitro genyi