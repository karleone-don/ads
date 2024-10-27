#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin>>t;
    string alp = "abcdefghijklmnopqrstuvwxyz";
    map<char, bool> mp;
    for(int i = 0; i<26; i++){
        mp[alp[i]] = false;
    }

    for(int i=0; i<t; i++){
        string n; cin >> n;
        mp[n[0]] = true;
    }
    int c = 0;
    for (int i=0; i<26; i++){
        if(mp[alp[i]]){
            cout<<alp[i];
        } else {
            cout<<'.';
        }
        c++;
        if(c%6==0) cout<<endl;
    }
}