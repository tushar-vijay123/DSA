#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int data = this -> data;
        if(this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
        }
        cout<<"Memory freed for node with data: "<<data<<endl;
    }
};

void insertAtHead(Node* &head, int d)
{
    // creating new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d)
{
    // creating new node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d)
{
    // inserting at 1st position(head)
    if(position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1)
    {
        temp = temp -> next;
        cnt++;
    }

    // inserting at last position(tail)
    if(temp -> next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating new node
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(Node* &head, Node* &tail, int position)
{
    // deleting first node
    if(position == 1)
    {
        Node* temp = head;
        head = head -> next;
        // memory free for current node
        temp -> next = NULL; // respective of our destructor call
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

        prev -> next = curr -> next;
        // memory free for current node
        curr -> next = NULL;
        delete curr;

        if(prev -> next == NULL)
        {
            tail = prev;
        }
    }
}

void print(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main()
{
    // created a node
    Node* node1 = new Node(10); // created in heap
    // cout<<node1 -> data<<endl;
    // cout<<node1 -> next<<endl;

    // Head and Tail node pointed
    Node* head = node1;
    Node* tail = node1;
    print(head);

    // insertAtHead(head, 12);
    // print(head);

    // insertAtHead(head, 15);
    // print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(head, tail, 4, 22);
    print(head);

    cout<<"Head -> "<<head -> data<<endl;
    cout<<"Tail -> "<<tail -> data<<endl;

    deleteNode(head, tail, 4);
    print(head);

    cout<<"Head -> "<<head -> data<<endl;
    cout<<"Tail -> "<<tail -> data<<endl;

    return 0;
}
