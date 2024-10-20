#include <iostream>
#include <string>

using namespace std;

string heapify(string S, int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && S[l] > S[largest]){
        largest = l;
    }
    if(r < n && S[r] > S[largest]){
        largest = r;
    }

    if(largest != i){
        swap(S[i], S[largest]);
        S = heapify(S, n, largest);
    }
    return S;
}

string heapSort(string S, int n){
    for(int i = n/2 - 1; i >= 0; i--){
        S = heapify(S, n, i);
    }

    for(int i = n-1; i >= 0; i--){
        swap(S[0], S[i]);
        S = heapify(S, i, 0);
    }
    return S;
}

int main(){
    string s; cin >> s;
    int n = s.size();
    s = heapSort(s, n);
    cout << s;
}