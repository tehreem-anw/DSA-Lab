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

Node* intersection(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL){
        return NULL;
    }
    Node* h1 = head1;
    Node* h2 = head2;
    while (h1 != h2){
        if(h1 == NULL){
            h1 = head2;
        }
        else{
            h1 = h1->next;
        }
        if(h2 == NULL){
            h2 = head1;
        }
        else{
            h2 = h2->next;
        }
    }
    return h1;
}

void printInter(Node* nodeHead){
    Node* temp = nodeHead;
    while(temp != NULL){
        cout << "[" << temp->data << "]" << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    LinkedList common;
    common.push_back(8);
    common.push_back(4);
    common.push_back(5);

    LinkedList listA;
    listA.push_back(4);
    listA.push_back(1);

    Node* tempA = listA.head;
    while (tempA->next != NULL) {
        tempA = tempA->next;
    }
    tempA->next = common.head;

    LinkedList listB;
    listB.push_back(5);
    listB.push_back(6);
    listB.push_back(1);

    
    Node* tempB = listB.head;
    while (tempB->next != NULL) {
        tempB = tempB->next;
    }
    tempB->next = common.head;

    cout << "Chain A: ";
    listA.print();

    cout << "Chain B: ";
    listB.print();

    Node* interNode = intersection(listA.head, listB.head);

    if (interNode != NULL) {
        cout << "\nIntersection point: [" << interNode->data << "]" << endl;
    } else {
        cout << "\nNo Intersection Point found." << endl;
    }

    return 0;
}
