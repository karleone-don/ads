#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

struct Heap{ // min heap
    ll *a;
    ll capacity;
    ll size;

    Heap(ll x){
        this->a = new ll[x];
        this->capacity = x;
        this->size = 0;
    }

    ll parent(ll i){
        return (i-1) / 2;
    }
    ll left(ll i){
        return i*2 + 1;
    }
    ll right(ll i){
        return i*2 + 2;
    }

    void HeapDown(ll i){
        ll l = left(i);
        ll r = right(i);
        ll min = i;

        if(l < size && a[min] > a[l]){
            min = l;
        }
        if(r < size && a[min] > a[r]){
            min = r;
        }

        if(min != i){
            swap(a[min], a[i]);
            HeapDown(min);
        }
    }
    void HeapUp(ll i){
        if(i > 0){
            ll p = parent(i);
            if(a[p] > a[i]){
                swap(a[i], a[p]);
                HeapUp(p);
            }
        }
    }

    void add(ll x){
        if(size < capacity){
            a[size] = x;
            size++;
            HeapUp(size-1);
        }
        else if(x > a[0]){
            a[0] = x;
            HeapDown(0);
        }
    }

    ll sume(ll i){
        if(i < this->size){
            ll sum = a[i];
            sum += sume(left(i));
            sum += sume(right(i));
            return sum;
        }
        return 0;
    }
};

int main(){
    ll a, b; cin >> a >> b;
    Heap h(b);
    for(int i = 0; i < a; i++){
        string s; cin >> s;
        if(s == "print"){
            cout << h.sume(0) << endl;
        }
        else if(s == "insert"){
            ll x; cin >> x;
            h.add(x);
        }
    }
}