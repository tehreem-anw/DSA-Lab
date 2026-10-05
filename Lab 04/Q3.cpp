
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
    Node* head;
    public:
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
    Node* reverse(Node* nodeHead){
        Node* curr = nodeHead;
        Node* next = NULL;
        Node* prev = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(){
        if(head == NULL || head->next == NULL){
            return true;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* p1 = head;
        Node* p2 = reverse(slow);
        bool result = true;
        while(p2 != NULL){
            if(p1->data != p2->data){
                result = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        slow->next = reverse(reverse(slow));
        return result;
    }
};
int main() {
    // Test Case 1: Palindrome
    LinkedList list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(2);
    list1.push_back(1);

    cout << "List 1: ";
    list1.print();
    if (list1.isPalindrome()) {
        cout << "Result: Is a Palindrome!" << endl;
    } else {
        cout << "Result: Not a Palindrome." << endl;
    }

    cout << endl;

    // Test Case 2: Not Palindrome
    LinkedList list2;
    list2.push_back(1);
    list2.push_back(2);
    list2.push_back(3);
    list2.push_back(4);
    list2.push_back(5);

    cout << "List 2: ";
    list2.print();
    if (list2.isPalindrome()) {
        cout << "Result: Is a Palindrome!" << endl;
    } else {
        cout << "Result: Not a Palindrome." << endl;
    }

    return 0;
}
