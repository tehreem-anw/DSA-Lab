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
    void middle(){
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* fast = head;
        Node* slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle Box = [" << slow->data << "]" << endl;
    }
};

int main() {
    LinkedList list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);

    cout << "List:" << endl;
    list.print();

    list.middle();

    return 0;
}
