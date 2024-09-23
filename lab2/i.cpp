#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    string a, b;
    deque<string> n;
    while(true){
        cin >> a;
        if(a == "exit"){
            break;
        }
        if(a == "add_front"){
            cin >> b;
            n.push_front(b);
            cout << "ok";
        }
        else if(a == "add_back"){
            cin >> b;
            n.push_back(b);
            cout << "ok";
        }
        else if(a == "clear"){
            n.clear();
            cout << "ok";
        }
        else{
            if(n.empty()){
                cout << "error";
            }
            else if(a == "erase_front"){
                cout << n.front();
                n.pop_front();
            }
            else if(a == "erase_back"){
                cout << n.back();
                n.pop_back();
            }
            else if(a == "front"){
                cout << n.front();
            }
            else if(a == "back"){
                cout << n.back();
            }
        }
        cout << endl;
    }
    cout << "goodbye";
}