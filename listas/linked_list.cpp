#include <iostream>
#include <sstream>

using namespace std;

struct Node 
{
    int value;
    Node* nextPtr;
    Node* prevPtr;

    Node(int value = 0, Node* nextPtr = nullptr, Node* prevPtr = nullptr) :
    value(value), nextPtr(nextPtr), prevPtr(prevPtr)
    { }

};

struct LinkedList 
{
    Node* headPtr;
    Node* tailPtr;

    LinkedList() 
    {
        this->headPtr = new Node();
        this->tailPtr = new Node();

        this->headPtr->nextPtr = this->tailPtr;
        this->tailPtr->prevPtr = this->headPtr;
    }

    ~LinkedList() 
    {
        Node* node = this->headPtr;
        while (node != nullptr)
        {
            Node* next = node->nextPtr;
            delete node;
            node = next;
        }
    }

    bool isEmpty()
    {
        return this->headPtr->nextPtr == this->tailPtr;
    }

    void insert_after(Node* node, int value)
    {
        Node* newElement = new Node(value, node->nextPtr, node);
        node->nextPtr->prevPtr = newElement;
        node->nextPtr = newElement;
    }

    void insert_after_step_by_step(Node* node, int value)
    {
        Node* newElement = new Node(value);
        newElement->nextPtr = node->nextPtr;
        newElement->prevPtr = node;
        node->nextPtr->prevPtr = newElement;
        node->nextPtr = newElement;
    }

    void push_front(int value)
    {
        Node* newElement = new Node(value, this->headPtr->nextPtr, this->headPtr);
        this->headPtr->nextPtr->prevPtr = newElement;
        this->headPtr->nextPtr = newElement;
    }

    void push_front_step_by_step(int value)
    {
        Node* newElement = new Node(value);

        newElement->nextPtr = this->headPtr->nextPtr;
        this->headPtr->nextPtr->prevPtr = newElement;
        this->headPtr->nextPtr = newElement;
        newElement->prevPtr = this->headPtr;
    }

    void push_front_with_insert_after(int value)
    {
        insert_after(this->headPtr, value);
    }

    void push_back(int value)
    {
        Node* newElement = new Node(value, this->tailPtr, this->tailPtr->prevPtr);
        this->tailPtr->prevPtr->nextPtr = newElement;
        this->tailPtr->prevPtr = newElement;
    }

    void push_back_with_insert_after(int value)
    {
        insert_after(this->tailPtr->prevPtr, value);
    }

    void push_back_step_by_step(int value)
    {
        Node* newElement = new Node(value);
        newElement->prevPtr = this->tailPtr->prevPtr;
        this->tailPtr->prevPtr->nextPtr = newElement;
        this->tailPtr->prevPtr = newElement;
        newElement->nextPtr = this->tailPtr;
    }

    void erase(Node* node)
    {
        node->prevPtr->nextPtr = node->nextPtr;
        node->nextPtr->prevPtr = node->prevPtr;
        delete node;
    }

    void pop_back()
    {
        if (!this->isEmpty())
            erase(this->tailPtr->prevPtr);
    }

    void pop_front()
    {
        if (!this->isEmpty())
            erase(this->headPtr->nextPtr);
    }

    string toString()
    {
        stringstream ss;
        ss << "[ ";
        for (auto node = this->headPtr->nextPtr; node != this->tailPtr; node = node->nextPtr)
            ss << node->value << " ";
        ss << "]\n";
        return ss.str();
    }

};

int main()
{
    LinkedList list;
    list.push_front_with_insert_after(1);
    list.push_front_with_insert_after(2);
    list.push_front_with_insert_after(3);
    list.push_back_with_insert_after(1);

    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    cout << list.toString();

    LinkedList list2;
    list2.push_back(1);
    list2.push_back(2);
    list2.push_back(3);

    cout << list2.toString();

    return 0;
}