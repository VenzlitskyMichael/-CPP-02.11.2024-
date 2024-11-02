#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class ForwardList {
private:
    Node* head;
public:
    ForwardList() : head(nullptr) {}
    void ins(int data) {
        Node* nNode = new Node(data);
        nNode->next = head;
        head = nNode;
    }
    void ins(Node* prNode, int data) {
        if (prNode == nullptr) {
            cout << "last yzel ne moschet but nullptr." << endl;
            return;
        }
        Node* nNode = new Node(data);
        nNode->next = prNode->next;
        prNode->next = nNode;
    }
    void clear() {
        Node* cur = head;
        while (cur != nullptr) {
            Node* nNode = cur->next;
            delete cur;
            cur = nNode;
        }
        head = nullptr;
    }
    ~ForwardList() {
        clear();
    }
    void pL() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
    Node* gHead() const {
        return head;
    }
};

int main() {
    ForwardList list;
    list.ins(10); 
    list.ins(20); 
    list.ins(30); 
    Node* second = list.gHead()->next; 
    list.ins(second, 15); 
    list.pL(); 
    list.clear();     
    return 0;
}
