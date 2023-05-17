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
struct Node *insertAtEnd(struct Node *last, int new_data) {
    if(last != NULL) {
        return insertInEmpty(last, new_data);
    }

    struct Node *temp = new Node;

    temp -> data = new_data;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;

    return last;
}

struct Node *insertAfter(struct Node *last, int new_data, int after_item) {
    if (last == NULL) {
        return NULL;
    }

    struct Node *temp, *p;
    p = last -> next;

    do {
        if (p -> data == after_item) {
            temp = new Node;
            temp -> data = new_data;
            temp -> next = p -> next;
            p -> next = temp;

            if (p == last) {
                last = temp;
                return last;
            }
        } else if (p == last && p -> data != after_item) {
            cout << "The Node With Data " << after_item << "is not present in the list"
            return last; 
        }
        p = p -> next;
    }while (p != last -> next);
}
void showList(struct Node *last) {
    struct Node *p;

    if (last == NULL){
        cout << "The list is empty" << endl;
        return;
    }

    p = last -> next;

    do{
        cout << p -> data << "==>";
        p = p -> next;
    } while(p != last -> next);

    if (p == last -> next) {
        cout << p -> data;
        cout << "\n\n";
    }
}

void deleteNode(Node** head, int key) {
    // jika list kosong maka return
    if (head == NULL) {
        return;
    }

    // jika list hanya berisi satu Node
    if ((*head) -> data == key && (*head) -> next == *head) {
        free(*head);
        *head = NULL;
    }

    Node *last = *head, *d;

    // Jika key adalah head
    if ((*head) -> next == key) {
        while (last -> next != *head) { // mencari last node pada list
            last = last -> next;

            // menunjuk last node ke ke akhir node head atau second node
            last -> next = (*head) -> next;
            free(*head);
            *head = last -> next;
        }
        //mencapai bgaian akhir node
        while (last -> next != *head && last -> next -> data != key) {
            last = last -> next;
        }
    // menunjukan list setelah menghapus node
    if (last -> next -> data == key) {
        d = last -> next;
        last -> next = d -> next;

        cout << "Node dengan data " << key << " dihapus dari list" << endl;
        free(d);
        cout << "\nSLLC setelah penghapusan " << key << " beranggotakan : ";
        showList(last);
    }
    }
}