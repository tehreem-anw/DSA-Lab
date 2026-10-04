#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList{
    Node* head;
    Node* tail;
    public:
    LinkedList(){
        head = tail = NULL;
    }
    void push_back(int x){
        Node* newNode = new Node(x);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << "[" << temp->data << "]->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void reverseList(){
        tail = head;
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main() {
    LinkedList list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);

    cout << "Original List:" << endl;
    list.print();

    list.reverseList();

    cout << "\nReversed List:" << endl;
    list.print();

    return 0;
}
