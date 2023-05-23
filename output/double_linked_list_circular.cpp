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
int searchList(TNode *start, int search)
{
    // Declare the temp variable
    TNode *temp = start;

    // Declare other control variable for the searching
    int count = 0, flag = 0, value;

    // If start is NULL return -1
    if (temp == NULL)
        return -1;
    else
    {
        // Move the temp pointer until, temp->next doesn't move start address (Circular Fashion)
        while (temp->next != start)
        {
            // Increment count for location
            count++;
            // If it is found raise the flag and break the loop
            if (temp->data == search)
            {
                flag = 1;
                count--;
                break;
            }
            // Increment temp pointer
            temp = temp->next;
        }
        // Check whether last element in the list content the value if contain, raise a flag and increment count
        if (temp->data == search)
        {
            count++;
            flag = 1;
        }

        // If flag is true, then element found, else not
        if (flag == 1)
            cout << "\n"
                 << search << " found at location " << count << endl;
        else
            cout << "\n"
                 << search << " not found" << endl;
    }
    return 0;
}

int main()
{
    init();
    int program = 1;
    int angka, setelah_angka;

    while (program)
    {
        cout << "\n=================================" << endl;
        cout << "   Double Linked List Circular" << endl;
        cout << "=================================" << endl
             << endl;
        ;
        cout << "Apa Yang Ingin Kamu Lakukan ?" << endl;
        cout << "1. Menampilkan Isi List " << endl;
        cout << "2. Memasukkan Elemen di awal list " << endl;
        cout << "3. Memasukkan Elemen di akhir list" << endl;
        cout << "4. Menghapus Elemen di awal list" << endl;
        cout << "5. Menghapus Elemen di akhir list" << endl;
        cout << "6. Menghapus Seluruh Elemen di list" << endl;
        cout << "7. Mencari Elemen di dalam list" << endl;
        cout << "8. Keluar Dari Program" << endl;
        cout << "Pilihan : ";
        cin >> program;

        switch (program)
        {
        case 1:
            tampil();
            break;
        case 2:
            cout << "Ketik Angka Yang Ingin Dimasukkan di List : ";
            cin >> angka;
            insertDepan(angka);
            break;
        case 3:
            cout << "Ketik Angka Yang ingin dimasukkan di List : ";
            cin >> angka;
            insertBelakang(angka);
            break;
        case 4:
            hapusDepan();
            break;
        case 5:
            hapusBelakang();
            break;
        case 6:
            clear();
            break;
        case 7:
            cout << "masukkang value yang ingin kamu cari :";
            cin >> angka;
            searchList(head, angka);
            break;
        case 8:
            return 0;
        default:
            cout << "Masukkan angka yang sesuai di menu !!";
            break;
        }
    }
    return 0;
}