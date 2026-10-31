#include<iostream>
using namespace std;
class Stack{
    int* arr;
    int size;
    int top;
    public:
    Stack(int s){
        size = s;
        arr = new int [size];
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    bool isEmpty(){
        return (top == -1);
    }
    bool isFull(){
        return top == size - 1;
    }
    void push(int x){
        if(isFull()){
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop(){
        if(isEmpty()){
            cout << "Stack Underflow!" << endl;
            return;
        }
        top--;
    }
    int getTop(){
        if(isEmpty()){
            cout << "Stack is Empty." << endl;
            return -1;
        }
        return arr[top];
    }
    void display(){
        if(isEmpty()){
            cout << "Stack is Empty." << endl;
            return;
        }
        cout << "---Remaining Operations---" << endl;
        for(int i = top; i>= 0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Stack s1(8);

    s1.push(12);
    cout << "[" << s1.getTop() << "]" << endl;
    s1.push(25);
    cout << "[" << s1.getTop() << "]" << endl;
    s1.push(17);
    cout << "[" << s1.getTop() << "]" << endl;
    s1.push(31);
    cout << "[" << s1.getTop() << "]" << endl;
    s1.push(44);
    cout << "[" << s1.getTop() << "]" << endl;
    s1.push(19);
    cout << "[" << s1.getTop() << "]" << endl;

    s1.pop();
    cout << "[" << s1.getTop() << "]" << endl;
    s1.pop();
    cout << "[" << s1.getTop() << "]" << endl;
    s1.pop();
    cout << "[" << s1.getTop() << "]" << endl;

    s1.push(52);
    cout << "[" << s1.getTop() << "]" << endl;

    s1.pop();
    cout << "[" << s1.getTop() << "]" << endl;
    s1.pop();
    cout << "[" << s1.getTop() << "]" << endl;

    s1.display();

    return 0;
}
