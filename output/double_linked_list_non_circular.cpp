#include <iostream>
using namespace std;

typedef struct TNode
{
    int data;
    TNode *next;
    TNode *prev;
};
TNode *head;

void init()
{
    head = NULL;
}
int isEmpty()
{
    if (head == NULL)
        return 1;
    else
        return 0;
}
void tampil()
{
    TNode *bantu;
    bantu = head;
    if (isEmpty() == 0)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << endl;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
        cout << "Masih Kosong" << endl;
}
void insertDepan(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    baru->prev = NULL;
    if (isEmpty() == 1)
    {
        head = baru;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    cout << "Data Masuk" << endl;
}
void insertBelakang(int databaru)
{
    TNode *baru, *bantu;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    baru->prev = NULL;
    if (isEmpty() == 1)
    {
        head = baru;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        bantu = head;
        while (bantu->next != NULL)
        {
            bantu = bantu->next;
        }
        bantu->next = baru;
        baru->prev = bantu;
    }
    cout << "Data masuk " << endl;
}
void hapusDepan()
{
    TNode *hapus;
    int d;
    if (isEmpty() == 0)
    {
        if (head->next != NULL)
        {
            hapus = head;
            d = hapus->data;
            head = head->next;
            head->prev = NULL;
            delete hapus;
        }
        else
        {
            d = head->data;
            head = NULL;
        }
        cout << d << " Terhapus" << endl;
    }
    else
        cout << "Masih Kosong" << endl;
}
void hapusBelakang()
{
    TNode *hapus;
    int d;
    if (isEmpty() == 0)
    {
        if (head->next != NULL)
        {
            hapus = head;
            while (hapus->next != NULL)
            {
                hapus = hapus->next;
            }
            d = hapus->data;
            hapus->prev->next = NULL;
            delete hapus;
        }
        else
        {
            d = head->data;
            head = NULL;
        }
        cout << d << " terhapus\n";
    }
    else
        cout << "Masih kosong\n";
}
void clear()
{
    TNode *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = NULL;
}
int main()
{
    init();
}