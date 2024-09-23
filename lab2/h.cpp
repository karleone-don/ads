#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

Node* insert(Node* head, Node* node, int p) {
    if (p == 0) {
        node->next = head;
        return node;
    }

    Node* current = head;
    for (int i = 0; i < p-1; i++) {
        current = current->next;
    }

    node->next = current->next;
    current->next = node;

    return head;
}

Node* remove(Node* head, int p) {
    if (p == 0) {
        Node* current = head;
        head = head->next;
        delete current;
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;
    
    for (int i = 1; i < p; i++) {
        slow = slow->next;
        fast = fast->next;
    }

    Node* toDelete = slow->next;
    slow->next = toDelete->next;
    delete toDelete;
    
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    Node* current = head;
    int index = 0;
    int value;
    
    while (current != nullptr) {
        if (index == p1) {
            value = current->val; // Возвращаем значение узла на позиции p
        }
        current = current->next;
        index++;
    }
    head = remove(head, p1);
    head = insert(head, new Node(value), p2);

    return head;
}
 
Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* current = head;
    while(current){
        Node* next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node; 
    }
    return prev;
}
 
void print(Node* head){
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl; 
}

Node* cyclic_left(Node* head, int x){
    if(x == 0) return head;
    Node* new_head = head;
    for(int i = 0; i < x-1; i++){
        new_head = new_head->next;
    }
    Node* new_head_next = new_head->next;
    new_head->next = nullptr;
    Node* old_tail = new_head_next;
    while (old_tail->next)
    {
        old_tail = old_tail->next;
    }
    old_tail->next = head;
    return new_head_next;
}
 
Node* cyclic_right(Node* head, int x){
    if(x == 0) return head;
    int count = 0;
    Node* new_head = head;
    while(new_head){
        count += 1;
        new_head = new_head->next;
    }
    head = cyclic_left(head, count-x);
    return head;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}