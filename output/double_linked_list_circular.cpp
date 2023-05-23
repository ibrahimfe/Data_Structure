#include <iostream>
using namespace std;

typedef struct TNode
{
    int data;
    TNode *next;
    TNode *prev;
};
TNode *head, *tail;
void init()
{
    head = NULL;
    tail = NULL;
}
int isEmpty()
{
    if (tail == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void insertDepan(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = baru;
    baru->prev = baru;
    if (isEmpty() == 1)
    {
        head = baru;
        tail = baru;
        head->next = head;
        head->prev = head;
        tail->next = tail;
        tail->prev = tail;
    }
    else
    {
        baru->next = head;
        head->prev = baru;
        head = baru;
        head->prev = tail;
        tail->next = head;
    }
    cout << "Data masuk\n";
}
void insertBelakang(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = baru;
    baru->prev = baru;
    if (isEmpty() == 1)
    {
        head = baru;
        tail = baru;
        head->next = head;
        head->prev = head;
        tail->next = tail;
        tail->prev = tail;
    }
    else
    {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }
    cout << "Data masuk\n";
}
void tampil()
{
    TNode *bantu;
    bantu = head;
    if (isEmpty() == 0)
    {
        do
        {
            cout << bantu->data << " ";
            bantu = bantu->next;
        } while (bantu != tail->next);
        cout << endl;
    }
    else
        cout << "Masih kosong\n";
}
void hapusDepan()
{
    TNode *hapus;
    int d;
    if (isEmpty() == 0)
    {
        if (head != tail)
        {
            hapus = head;
            d = hapus->data;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete hapus;
        }
        else
        {
            d = head->data;
            head = NULL;
            tail = NULL;
        }
        cout << d << " terhapus\n";
    }
    else
        cout << "Masih kosong\n";
}
void hapusBelakang()
{
    TNode *hapus;
    int d;
    if (isEmpty() == 0)
    {
        if (head != tail)
        {
            hapus = tail;
            d = hapus->data;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete hapus;
        }
        else
        {
            d = head->data;
            head = NULL;
            tail = NULL;
        }
        cout << d << " terhapus\n";
    }
    else
        cout << "Masih kosong\n";
}
void clear()
{
    TNode *bantu, *hapus;
    if (isEmpty() == 0)
    {
        bantu = head;
        while (bantu->next != head)
        {
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
        head = NULL;
    }
}

int main()
{
    init();
    insertDepan(10);
    insertBelakang(20);
    tampil();
}