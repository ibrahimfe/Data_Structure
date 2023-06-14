#include <iostream>
using namespace std;

typedef struct Customer
{
    int ticketnumber;
    Customer *next;
    Customer *prev;
};

// Function to create a new Customer
Customer *createNode(int ticketnumber)
{
    Customer *newCustomer = new Customer;
    newCustomer->ticketnumber = ticketnumber;
    newCustomer->next = nullptr;
    newCustomer->prev = nullptr;
    return newCustomer;
}

// Function to insert a new Customer at the rear of the queue
Customer *enqueue(Customer *rear, int ticketnumber)
{
    Customer *newCustomer = createNode(ticketnumber);

    if (rear == nullptr)
    {
        rear = newCustomer;
        rear->next = rear;
        rear->prev = rear;
    }
    else
    {
        newCustomer->next = rear->next;
        newCustomer->prev = rear;
        rear->next->prev = newCustomer;
        rear->next = newCustomer;
        rear = newCustomer;
    }

    return rear;
}

// Function to remove a Customer from the front of the queue
Customer *dequeue(Customer *rear)
{
    if (rear == nullptr)
    {
        cout << "Queue is empty" << endl;
        return nullptr;
    }

    Customer *front = rear->next;

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
void displayQueue(Customer *rear)
{
    if (rear == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Customer *temp = rear->next;

    do
    {
        cout << temp->ticketnumber << " ";
        temp = temp->next;
    } while (temp != rear->next);

    cout << endl;
}

int main()
{
    Customer *rear = nullptr;

    rear = enqueue(rear, 1);
    rear = enqueue(rear, 2);
    rear = enqueue(rear, 3);
    rear = enqueue(rear, 4);
    rear = enqueue(rear, 5);
    rear = enqueue(rear, 6);

    cout << "\nAntrian saat ini : ";
    displayQueue(rear);

    rear = dequeue(rear);
    cout << "\nNomor urut 1 telah keluar, Update Antrian : ";
    displayQueue(rear);

    rear = enqueue(rear, 7);
    rear = enqueue(rear, 8);
    cout << "\nAda Antrian baru yang masuk, Update Antrian : ";
    displayQueue(rear);

    rear = dequeue(rear);
    rear = dequeue(rear);
    rear = dequeue(rear);
    cout << "\nNomor urut 2, 3, 4 telah keluar, Update Antrian : ";
    displayQueue(rear);

    rear = enqueue(rear, 9);
    rear = dequeue(rear);
    cout << "\nNomor uurut 5 telah keluar dan ada antrian baru yang masuk, Update Antrian : ";
    displayQueue(rear);
    return 0;
}