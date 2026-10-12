#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    void push_back(int x) {
        Node* newNode = new Node(x);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << "[" << temp->data << "]->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

Node* oddEven(Node* nodeHead){
    if(nodeHead == NULL || nodeHead->next == NULL){
        return nodeHead;
    }
    Node oddDummy(0);
    Node evenDummy(0);
    Node* oddTail = &oddDummy;
    Node* evenTail = &evenDummy;
    Node* curr = nodeHead;
    while (curr != NULL){
        if((curr->data % 2) != 0){
            oddTail->next = curr;
            oddTail = curr;
        }
        else{
            evenTail->next = curr;
            evenTail = curr;
        }
        curr = curr->next;
    }
    evenTail->next = NULL;
    oddTail->next = evenDummy.next;
    return oddDummy.next;
}

void printUpdated(Node* nodeHead){
    Node* temp = nodeHead;
    while(temp != NULL){
        cout << "[" << temp->data << "]" << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    LinkedList list;

    list.push_back(2);
    list.push_back(1);
    list.push_back(3);
    list.push_back(5);
    list.push_back(6);
    list.push_back(4);
    list.push_back(7);

    cout << "Original List: ";
    list.print();

    // Perform segregation
    Node* rearrangedHead = oddEven(list.head);

    cout << "\nRearranged List (Odd values first, then Even values):" << endl;
    printUpdated(rearrangedHead);

    return 0;
}
