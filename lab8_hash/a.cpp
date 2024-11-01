#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

long long mod = 1e9 + 7;
long long p = 11;

string get_hash(string s) {
    long long h = 0;
    for (long long i = s.size() - 1; i >= 0; i--) {
        h = (h * p % mod + (s[i] - 47)) % mod;
    }
    return to_string(h);
}

int main(){
    int a, c = 0; cin >> a;
    pair <string, string> n[2 * a];
    set <string> hashes;
    for(int i = 0; i < 2*a; i++){
        string s; cin >> s;
        n[i].first = s;
        n[i].second = get_hash(s);
        hashes.insert(s);
    }
    
    for(int i = 0; i < 2*a; i++){
        set<string> :: iterator it = hashes.find(n[i].second);
        if(it != hashes.end()){
            cout << "Hash of string \"" + n[i].first + "\" is " + n[i].second << endl;
            c++;
        }
        if(c == a){
            break;
        }
    }
}