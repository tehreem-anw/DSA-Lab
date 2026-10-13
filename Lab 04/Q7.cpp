#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int val){
            data = val;
            next = prev = NULL;
        }
};

class DoublyList{
    Node* head;
    Node* tail;
    public:
        DoublyList(){
            head = tail = NULL;
        }

        void push_back(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = tail = newNode;
                return;
            }
            tail->next = newNode;
            newNode->prev = tail;
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

        void removeDupes(){
            if(head == NULL || head->next == NULL){
                return;
            }
            Node* curr = head;
            while(curr->next != NULL){
                if(curr->data == curr->next->data){
                    Node* dupe = curr->next;
                    curr->next = dupe->next;
                    if(dupe->next != NULL){
                        dupe->next->prev = curr;
                    }
                    else{
                        tail = curr;
                    }
                    delete dupe;
                }
                else{
                    curr = curr->next;
                }
            }
        }
};

int main() {
    DoublyList dll;

    dll.push_back(1);
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.push_back(3);
    dll.push_back(3);
    dll.push_back(4);

    cout << "Original List (Forward): " << endl;
    dll.print();

    dll.removeDupes();

    cout << "\nCleaned List: " << endl;
    dll.print();

    return 0;
}
