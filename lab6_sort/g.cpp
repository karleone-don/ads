#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int a; cin >> a;
    map<string, string> reName;
    for(int i = 0; i < a; i++){
        bool find = false;
        string oldName, newName; cin >> oldName >> newName;
        for(auto it = reName.begin(); it != reName.end(); it++){
            if(it->second == oldName){
                reName[it->first] = newName;
                find = true;
                break;
            }
        }
        if(!find){
            reName[oldName] = newName;
        }
    }

    cout << reName.size() << endl;
    for(auto it = reName.begin(); it != reName.end(); it++){
        cout << it->first << ' ' << it->second << endl;
    }
}