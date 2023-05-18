#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *insertInEmpty(struct Node *last, int new_data) {
    if (last != NULL) {
        return last;
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
    if (last != NULL) {
        return insertInEmpty(last, new_data);
    }

    struct Node* temp = new Node;
    temp->data = new_data;
    temp->next = last->next;
    last->next = temp;
    last = temp; // Update last to the newly inserted node

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
            cout << "The Node With Data " << after_item << "is not present in the list";
            return last; 
        }
        p = p -> next;
    }while (p != last -> next);
    return last;
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
    if ((*head)->next->data == key) {
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
    } else {
        cout << "Node dengan data "<< key << " tidak ditemukan dalam list" << endl;
    }
    }
}

bool findElement(struct Node *head, int key) {
    if (head == NULL) {
        return false; // List is empty
    }

    Node* current = head;

    do {
        if (current->data == key) {
            return true; // Key found
        }
        current = current->next;
    } while (current != head);

    return false; // Key not found
}


// Main Program

int main() {
    struct Node *last = NULL;

    int program = 1;
    int angka, setelah_angka;

    while (program) {
        cout << "=================================" << endl;
        cout << "   Single Linked List Circular" << endl;
        cout << "=================================" << endl << endl;;
        cout << "Apa Yang Ingin Kamu Lakukan ?" << endl;
        cout << "1. Menampilkan Isi List " << endl;
        cout << "2. Memasukkan Elemen ke dalam List yang kosong " << endl;
        cout << "3. Memasukkan Elemenn ke awal List " << endl;
        cout << "4. Memasukkan Elemen ke Akhir List" << endl;
        cout << "5. Memasukkan Elemen Setelah Elemen tertentu " << endl;
        cout << "6. Menghapus Node " << endl;
        cout << "7. Keluar Dari Program" << endl;
        cin >> program;

        switch (program)
        {
        case 1:
            showList(last);
            break;
        case 2:
            cout << "Ketik Angka Yang Ingin Dimasukkan di List : ";
            cin >> angka;
            last = insertInEmpty(last,angka);
            break;
        case 3:
            cout << "Ketik Angka Yang ingin dimasukkan di List : ";
            cin >> angka;
            last = insertAtBegin(last, angka);
            break;
        case 4:
            cout << "Ketik angka yang ingin dimasukkan di list : ";
            cin >> angka;
            last = insertAtEnd(last, angka);
            break;
        case 5:
            cout << "Ketik angka yang ingin dimasukkan di dalam list : ";
            cin >> angka;
            cout << "Ketik angka di dalam list untuk menyisipkan elemen : ";
            cin >> setelah_angka;
            last = insertAfter(last, angka, setelah_angka);
            break;
        case 6:
            cout << "Ketik angka yang akan dihapus : ";
            cin >> angka;
            deleteNode(&last, angka);
            break;
        default:
            cout << "Masukkan angka yang sesuai di menu !!";
            break;
        }
    }

    last = insertInEmpty(last, 30);
    last = insertAtBegin(last, 20);
    last = insertAtBegin(last, 120);
    last = insertAtEnd(last, 99);
    last = insertAtEnd(last, 10);
    last = insertAfter(last, 50, 30);

    showList(last);
}