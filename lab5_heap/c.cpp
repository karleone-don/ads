#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

struct Heap{ // max heap
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
            if(a[i] > a[p]){
                swap(a[i], a[p]);
                HeapUp(p);
            }
        }
    }

    void HeapDown(ll i){
        ll l = left(i);
        ll r = right(i);
        ll max = i;

        if(l < this->size && a[l] > a[max]){
            max = l;
        }
        if(r < this->size && a[r] > a[max]){
            max = r;
        }

        if(max != i){
            swap(a[max], a[i]);
            HeapDown(max);
        }
    }

    void add(ll x){
        a[size] = x;
        size++;
        HeapUp(size-1);
    }

    void cute_max(){ // uwu
        a[0] = a[size-1];
        size = max((ll)0, size - 1);
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
    ll sum = 0;
    for(int i = 0; i < b; i++){
        ll x = h.a[0];
        h.cute_max();
        if(x == 0){
            break;
        }
        sum += x;
        x--;
        h.add(x);
    }
    cout << sum;
}