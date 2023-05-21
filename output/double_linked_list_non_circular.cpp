#include <iostream>
using namespace std;

struct TNode
{
    int data;
    TNode *next;
    TNode *prev;
};

TNode *head;

void init()
{
    head = new TNode;
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
}

bool isEmpty()
{
    return head->next == NULL;
}

void tampil()
{
    if (isEmpty())
    {
        cout << "Masih Kosong" << endl;
        return;
    }

    TNode *bantu = head->next;
    while (bantu != NULL)
    {
        cout << bantu->data << endl;
        bantu = bantu->next;
    }
    cout << endl;
}

void insertDepan(int databaru)
{
    TNode *baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    baru->prev = NULL;

    if (isEmpty())
    {
        head->next = baru;
        baru->prev = head;
    }
    else
    {
        baru->next = head->next;
        head->next->prev = baru;
        head->next = baru;
        baru->prev = head;
    }

    head->data++;
    cout << "Data Masuk" << endl;
}

void insertBelakang(int databaru)
{
    TNode *baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    baru->prev = NULL;

    if (isEmpty())
    {
        head->next = baru;
        baru->prev = head;
    }
    else
    {
        TNode *bantu = head->next;
        while (bantu->next != NULL)
        {
            bantu = bantu->next;
        }
        bantu->next = baru;
        baru->prev = bantu;
    }

    head->data++;
    cout << "Data masuk" << endl;
}

void hapusDepan()
{
    if (isEmpty())
    {
        cout << "Masih Kosong" << endl;
        return;
    }

    TNode *hapus = head->next;
    int d = hapus->data;
    head->next = hapus->next;
    if (hapus->next != NULL)
    {
        hapus->next->prev = head;
    }
    delete hapus;

    head->data--;
    cout << d << " Terhapus" << endl;
}

void hapusBelakang()
{
    if (isEmpty())
    {
        cout << "Masih Kosong" << endl;
        return;
    }

    TNode *hapus = head->next;
    while (hapus->next != NULL)
    {
        hapus = hapus->next;
    }

    int d = hapus->data;
    hapus->prev->next = NULL;
    delete hapus;

    head->data--;
    cout << d << " Terhapus" << endl;
}
void updateNode(TNode *head, int position, int newData)
{
    TNode *temp = head;
    int count = 1;
    while (temp != nullptr && count < position)
    {
        temp = temp->next;
        count++;
    }
    if (temp != nullptr)
    {
        temp->data = newData;
    }
    else
    {
        cout << "Invalid position!" << std::endl;
    }
}
void displayReverse(TNode *head)
{
    if (head == nullptr)
    {
        return;
    }
    TNode *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    cout << "List in reverse order: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void clear()
{
    TNode *bantu = head->next;
    while (bantu != NULL)
    {
        TNode *hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head->next = NULL;
    head->data = 0;
}
int countElements(TNode *head)
{
    TNode *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    init();
    insertDepan(10);
    insertBelakang(9);
    tampil();
    cout << "Panjang List adalah " << countElements(head) << endl;

    return 0;
}
