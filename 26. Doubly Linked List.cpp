#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    // destructor
    ~Node(){
        int d = this -> data;

        if(next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout<<"Node deleted with data "<<d<<endl;
    }
};

// prints the linked list
void print(Node* head){
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

// count the nodes in linked list
int getLength(Node* head){
    Node* temp = head;
    int len = 0;

    while(temp != NULL){
        len++;
        temp = temp -> next;
    }

    return len;
}

void insertAtHead(Node* &head, Node* &tail, int d){
    // if list is empty
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
    
}

void insertAtTail(Node* &tail, Node* &head, int d){
    // if list is empty
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> prev = tail;
        tail -> next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int d, int position){
    // insert at head
    if(position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    int cnt = 1;
    Node* temp = head;

    while(cnt < position - 1)
    {
        temp = temp -> next;
        cnt++;
    }

    // insert at tail
    if(temp ->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    // insert at any other position
    Node *nodeToInsert = new Node(d);
    
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    nodeToInsert -> prev = temp;
    temp -> next = nodeToInsert;
}

void deleteNode(Node* &head, Node* &tail, int position)
{
    // deleting first node
    if(position == 1)
    {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        // deleting last or middle node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

        if(prev -> next == NULL)
        {
            tail = prev;
        }
    }
}

int main(){

    // Node* node1 = new Node(10);
    // Node* head = node1;
    // Node* tail = node1;

    //print(head);
    //cout<<getLength(head)<<endl;

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 11);
    print(head);

    insertAtHead(head, tail, 13);
    print(head);

    insertAtHead(head, tail, 8);
    print(head);

    insertAtTail(tail, head, 25);
    print(head);

    insertAtPosition(head, tail, 100, 2);
    print(head);

    insertAtPosition(head, tail, 101, 1);
    print(head);

    insertAtPosition(head, tail, 102, 7);
    print(head);

    deleteNode(head, tail, 7);
    print(head);

    return 0;
}
