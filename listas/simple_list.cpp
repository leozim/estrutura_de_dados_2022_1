#include <iostream>
#include <sstream>

using namespace std;

struct Node
{
    int value;
    Node* nextPtr;

    Node(int value = 0, Node* nextPtr = nullptr) :
    value(value), nextPtr(nextPtr)
    { }

};

struct LinkedList
{
    Node* head { nullptr };

    LinkedList()
    { }

    ~LinkedList()
    {
        Node* node = this->head;
        while (node != nullptr)
        {
            Node* next = node->nextPtr;
            delete node;
            node = next;
        }
    }

    bool isEmpty()
    {
        return this->head == nullptr;
    }

    void push_back(int value)
    {
        Node* newElement = new Node(value);

        if ( isEmpty() )
        {
            this->head = newElement;
            return;
        }

        Node* lastElement = this->head;
        while (lastElement->nextPtr != nullptr)
        {
            lastElement = lastElement->nextPtr;
        }

        lastElement->nextPtr = newElement;

    }

    void push_front(int value)
    {
        Node* newElement = new Node(value);

        if ( isEmpty() )
        {
            this->head = newElement;
            return;
        }

        newElement->nextPtr = this->head;
        this->head = newElement;

    }

    void pop_back()
    {
        if (isEmpty())
            return;
        
        if (this->head->nextPtr == nullptr)
        {
            delete this->head;
            this->head = nullptr;
            return;
        }

        Node* node = this->head;
        while (node->nextPtr->nextPtr != nullptr)
        {
            node = node->nextPtr;
        }

        delete node->nextPtr;
        node->nextPtr = nullptr;

    }

    void pop_front()
    {
        if ( isEmpty() )
            return;
        
        Node* node = this->head;
        this->head = this->head->nextPtr;
        delete node;
    }

    string toString()
    {
        stringstream ss;
        ss << "[ ";
        for (auto node = this->head; node != nullptr && node->value != 0; node = node->nextPtr)
            ss << node->value << " ";
        ss << "]\n";

        return ss.str();
    }

    /* RECURSSION  */

    Node * __push_back(Node * node, int value) {
        if (node == nullptr)
            return new Node(value);
        node->nextPtr = __push_back(node->nextPtr, value);
        return node;
    }

    void push_back_rec(int value) {
        head = __push_back(head, value);
    }
    
    Node * __pop_back(Node * node) {
        if (node->nextPtr == nullptr) {
            delete node;
            return nullptr;
        }
        node->nextPtr = __pop_back(node->nextPtr);
        return node;
    }

    void pop_back_rec() {
        head = __pop_back(head);
    }

};


int main()
{
    LinkedList list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_back(4);
    list.pop_back();
    cout << list.toString();

    LinkedList list2;
    list2.push_back(1);
    list2.push_back(2);
    list2.push_back(3);
    list2.pop_front();
    cout << list2.toString();

    return 0;
}