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

Node* merge(Node* head1, Node* head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    if(head1->data <= head2->data){
        head1->next = merge(head1->next, head2);
        return head1;
    }
    else{
        head2->next = merge(head1, head2->next);
        return head2;
    }
}

void printMerged(Node* nodeHead){
    Node* temp = nodeHead;
    while(temp != NULL){
        cout << "[" << temp->data << "]" << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    LinkedList list1;
    list1.push_back(1);
    list1.push_back(3);
    list1.push_back(5);
    list1.push_back(7);

    LinkedList list2;
    list2.push_back(2);
    list2.push_back(4);
    list2.push_back(6);
    list2.push_back(8);

    cout << "Chain A: ";
    list1.print();

    cout << "Chain B: ";
    list2.print();

    Node* mergedHead = merge(list1.head, list2.head);

    cout << "\nMerged List (Recursive): ";
    printMerged(mergedHead);

    return 0;
}
