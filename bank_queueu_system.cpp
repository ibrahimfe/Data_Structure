#include <iostream>
using namespace std;

typedef struct TNode
{
    int data;
    TNode *next;
    TNode *prev;
};

// Function to create a new TNode
TNode *createNode(int data)
{
    TNode *newNode = new TNode();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Function to insert a new TNode at the rear of the queue
TNode *enqueue(TNode *rear, int data)
{
    TNode *newNode = createNode(data);

    if (rear == nullptr)
    {
        rear = newNode;
        rear->next = rear;
        rear->prev = rear;
    }
    else
    {
        newNode->next = rear->next;
        newNode->prev = rear;
        rear->next->prev = newNode;
        rear->next = newNode;
        rear = newNode;
    }

    return rear;
}

// Function to remove a TNode from the front of the queue
TNode *dequeue(TNode *rear)
{
    if (rear == nullptr)
    {
        cout << "Queue is empty" << endl;
        return nullptr;
    }

    TNode *front = rear->next;

    if (rear == front)
    {
        rear = nullptr;
    }
    else
    {
        rear->next = front->next;
        front->next->prev = rear;
    }

    delete front;

    return rear;
}

// Function to display the queue
void displayQueue(TNode *rear)
{
    if (rear == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    TNode *temp = rear->next;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != rear->next);

    cout << endl;
}

int main()
{
    TNode *rear = nullptr;

    rear = enqueue(rear, 1);
    rear = enqueue(rear, 2);
    rear = enqueue(rear, 3);

    displayQueue(rear);

    rear = dequeue(rear);

    displayQueue(rear);

    rear = enqueue(rear, 4);

    displayQueue(rear);

    return 0;
}