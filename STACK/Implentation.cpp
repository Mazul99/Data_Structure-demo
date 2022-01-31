//This will be the implementation of a basic Stack
//And it also contains an example on how to use it
//Valid Parenthesis
 #include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

template <class T>
class Node {
    private:
        T data;
        
    public:
        Node <T> * next;
        Node<T> (T data);
        T getData() const;
};

template <class T>
Node<T> :: Node(T dat) : data(dat), next(nullptr) {};
template <class T>
inline T Node<T> :: getData () const{ return data; }

template <class S>
class Stack{
    private:
        Node <S> *front;
        int Size;
    public:
        Stack<S> ();
        int getSize()const;
        void Push(S data);
        bool Empty() const;
        void Print() const;
        void Pop ();
        S Front () const;
        void Erase ();
};
//Constructor of the class
template<class S>
Stack<S>:: Stack() : Size (0), front (nullptr) {};
//Function to know the size of the Stack
template <class S>
inline int Stack<S>:: getSize() const { return Size;}
//Function to know if the stack is empty
template <class S>
bool Stack <S> :: Empty() const { return front == nullptr;}
//Function to insert an element in the stack
template <class S>
void Stack<S> :: Push(S data){
    Node <S> * newNode = new Node<S> (data);
    if(Empty())
        front = newNode;
    else{
        Node <S> *auxNode = front;
        front = newNode;
        newNode->next = auxNode;
    }
    Size ++;
}
//Function to pop an element from the stack
template <class S> 
void Stack <S> :: Pop(){
    if(Empty())
        cout << "Impossible to pop an element from an empty Stack " << endl;
    else{
        Node<S> *auxNode = front;
        front = front-> next;
        free (auxNode);
    }
    Size --;
}
//Function that returns the element on the front of the stack
template <class S>
S Stack <S> :: Front () const {
    if(front == nullptr) cout << "Error, there are no elements in the stack";
    return front->getData();
}
//Function to Print in the elements of the stack
template <class S>
void Stack<S> :: Print()const{
    Node<S> * Aux = front;
    while (Aux != nullptr){
        cout << Aux-> getData() << " ";
        Aux =  Aux-> next;
    }
}
//Function to erase all elements in the Stack
template <class S>
void Stack <S> :: Erase(){
    while(!Empty())
        Pop();
}
bool isValid (const string &s){
    Stack <char> St;
    int j,cont =0 ;
    if(s.length() & 1) return false;
    for(int i = 0; i < s.length(); i ++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') St.Push(s[i]);
        else{
            if(St.Empty()) return false;
            if(s[i] == ')' && St.Front() != '(' ) return false;
            if(s[i] == '}' && St.Front() != '{') return false;
            if(s[i] == ']' && St.Front() != '[') return false;
            St.Pop();
        }
    }
    return St.Empty();
}

int main() {
    string s;
    cin >> s;
    cout << isValid (s);
    return 0;
}
