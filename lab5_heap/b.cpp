#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

struct Heap // max heap
{
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

        if(l < this->size && a[max] < a[l]){
            max = l;
        }
        if(r < this->size && a[max] < a[r]){
            max = r;
        }

        if(max != i){
            swap(a[i], a[max]);
            HeapDown(max);
        }
    }

    void add(ll x){
        a[size] = x;
        size++;
        HeapUp(size - 1);
    }

    void cut_max(){
        a[0] = a[size - 1];
        size = max((ll)0, size - 1);
        HeapDown(0);
    }
};

int main() {
    ll a; cin >> a;
    Heap h(a);
    for(int i = 0; i < a; i++){
        ll b; cin >> b;
        h.add(b);
    }

    while (h.size != 1)
    {
        ll x = h.a[0];
        h.cut_max();
        ll y = h.a[0];
        h.cut_max();
        x -= y;
        h.add(x);
    }
    cout << h.a[0];
}