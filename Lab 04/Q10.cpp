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
    void removeCycle(){
        if(head == NULL || head->next == NULL){
            return;
        }
        Node* slow = head;
        Node* fast = head;
        bool hasCycle = false;
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                hasCycle = true;
                break;
            }
        }
        if(!hasCycle){return;}
        slow = head;
        if(slow == fast){
            while(fast->next != slow){
                fast = fast->next;
            }
            fast->next = NULL;
            tail = fast;
            return;
        }
        Node* prev = NULL;
        while (slow != fast){
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = NULL;
        tail = prev;
    }
    Node* getNodeAt(int index) {
        Node* temp = head;
        for (int i = 1; i < index && temp != NULL; i++) {
            temp = temp->next;
        }
        return temp;
    }
};

int main() {
    LinkedList list;

    // Create list: [1]->[2]->[3]->[4]->[5]->[6]->NULL
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);

    Node* node6 = list.getNodeAt(6);
    Node* node3 = list.getNodeAt(3);
    node6->next = node3; 

    cout << "Cycle created: [6] points to [3]" << endl;

    // Remove cycle
    list.removeCycle();

    cout << "Repaired list:" << endl;
    list.print();

    return 0;
}
