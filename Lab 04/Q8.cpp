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

        int countThrees(int x){
            int match = 0;
            cout << "All triplets checked: " << endl;
            for(Node* first = head; first != NULL && first->next != NULL && first->next->next; first = first->next){
                for(Node* second = first->next; second != NULL && second->next != NULL; second = second->next){
                    for(Node* third = second->next; third != NULL; third = third->next){
                        int sum = first->data + second->data + third->data;
                        cout << "(" << first->data << ", " << second->data << ", " << third->data << ")" << " = " << sum << " ";
                        if(sum == x) {
                            cout << "✓" << endl;
                            match++;
                        }
                        else{
                            cout << "✗" << endl;
                        }
                    }
                }
            }
            cout << "Matching: " << match << endl;
            return match;
        }
};

int main() {
    DoublyList dll;

    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.push_back(4);
    dll.push_back(5);

    int X = 6;

    cout << "Input List:" << endl;
    dll.print();
    cout << endl;

    dll.countThrees(X);

    return 0;
}
