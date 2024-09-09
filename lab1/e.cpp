#include <iostream>
#include <queue>

using namespace std;

//n - Boris
//k - Nursik
// cards of nursik always last

int main(){
    queue<int> n, k;
    int a, b = 0;
    for(int i = 0; i < 5; i++){
        cin >> a;
        n.push(a);
    }
    for(int i = 0; i < 5; i++){
        cin >> a;
        k.push(a);
    }
    while(n.size() > 0 and k.size() > 0 and b < 1000000){
        b++;
        if(n.front() == 0 and k.front() == 9){
            a = n.front();
            n.pop();
            n.push(a);
            a = k.front();
            k.pop();
            n.push(a);
        }
        else if(n.front() == 9 and k.front() == 0){
            a = n.front();
            n.pop();
            k.push(a);
            a = k.front();
            k.pop();
            k.push(a);
        }
        else if(n.front() > k.front()){
            a = n.front();
            n.pop();
            n.push(a);
            a = k.front();
            k.pop();
            n.push(a);
        }
        else{
            a = n.front();
            n.pop();
            k.push(a);
            a = k.front();
            k.pop();
            k.push(a);
        }
    }
    if(n.size() > 0){
        cout << "Boris " << b;
    }
    else{
        cout << "Nursik " << b;
    }
}