#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *insertInEmpty(struct Node *last, int new_data) {
    if (last != NULL) {
        return last
    }

    struct Node *temp = new Node;

    temp -> data = new_data;
    last = temp;

    last -> next = last;
    return last;
}

struct Node *insertAtBegin(struct Node *last, int new_data) {
    if (last == NULL){
        return insertInEmpty(last, new_data);
    }

    struct Node *temp = new Node;

    temp -> data = new_data;
    temp -> next = last -> next;
    last -> next = temp;

    return last;
}