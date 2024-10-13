#include <iostream>
#include <algorithm>

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

    void HeapUp(ll i){
        if(i > 0){
            ll p = parent(i);
            if(a[p] > a[i]){
                swap(a[p], a[i]);
                HeapUp(p);
            }
        }
    }
    void HeapDown(ll i){
        ll l = left(i);
        ll r = right(i);
        ll min = i;

        if(l < size && a[l] < a[min]){
            min = l;
        }
        if(r < size && a[r] < a[min]){
            min = r;
        }

        if(min != i){
            swap(a[min], a[i]);
            HeapDown(min);
        }
    }

    void add(ll x){
        a[size] = x;
        size++;
        HeapUp(size-1);
    }

    void cut_min(){
        a[0] = a[size-1];
        size = max(ll(0), size-1);
        HeapDown(0);
    }
};

int main(){
    ll a, b; cin >> a >> b;
    Heap h(a);

    for(int i = 0; i < a; i++){
        ll x; cin >> x;
        h.add(x);
    }

    ll count = 0;
    while(h.a[0] < b && h.size > 1){
        ll x = h.a[0];
        h.cut_min();
        x += 2 * h.a[0];
        h.cut_min();
        h.add(x);
        count++;
    }
    if(h.a[0] > b){
        cout << count;
    }
    else{
        cout << -1;
    }
}