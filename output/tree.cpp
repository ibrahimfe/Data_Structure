#include <iostream>
using namespace std;

typedef struct Tree
{
    int data;
    Tree *left;
    Tree *right;
};

void init()
{
    pohon = NULL;
}
void clear()
{
    pohon = NULL;
}
int isEmpty(Tree *pohon)
{
    if (pohon == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void tambah(Tree **root, int databaru)
{
    if ((*root) == NULL)
    {
        Tree *baru;
        baru = new Tree;
        baru->data = databaru;
        baru->left = NULL;
        baru->right = NULL;
        (*root) = baru;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (databaru < (*root)->data)
        tambah(&(*root)->left, databaru);
    else if (databaru > (*root)->data)
        tambah(&(*root)->right, databaru);
    else if (databaru == (*root)->data)
        printf("Data sudah ada!");
}

void preOrder(Tree *root)
{
    if (root != NULL)
    {
        cout << root->data;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Tree *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data;
        inOrder(root->right);
    }
}
void postOrder(Tree *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data;
    }
}
void LevelOrder(Tree *root)
{
    Queue queue;
    Enqueue(queue, root);
    while (isEmpty(queue) != 1)
    {
        Tree n = GetQueue(); // visit
        print(n->data);
        if (n->left != NULL)
            Enqueue(n->left); // Enqueue if exists
        if (n->right != NULL)
            Enqueue(n->right); // Enqueue if exists
        Dequeue(queue);        // out
    }
}

Tree *cari(Tree *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (data < root->data)
        return (cari(root->left, data));
    else if (data > root->data)
        return (cari(root->right, data));
    else if (data == root->data)
        return root;
}

int count(Tree *root)
{
    if (root == NULL)
        return 0;
    return count(root->left) + count(root->right) + 1;
}

int height(Tree *root)
{
    if (root == NULL)
        return -1;
    int u = height(root->left), v = height(root->right);
    if (u > v)
        return u + 1;
    else
        return v + 1;
}
Tree *FindMin(Tree *root)
{
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    else
        return FindMin(root->left);
}

void leaf(Tree *root)
{
    if (root == NULL)
        printf("kosong!");
    if (root->left != NULL)
        leaf(root->left);
    if (root->right != NULL)
        leaf(root->right);
    if (root->right == NULL && root->left == NULL)
        printf("%d ", root->data);
}

int main()
{
    Tree *pohon;
    Tree *t = FindMin(pohon);
    int pilihan;

    while (true)
    {
        cout << "=======================================" << endl;
        cout << "                TREE                   " << endl;
        cout << "=======================================" << endl;
        cout << "1. Cek apakah tree kosong" << endl;
        cout << "2. Menambah Node pada Tree" << endl;
        cout << "3. Menampilkan data secara preOrder" << endl;
        cout << "4. Menampilkan data secara inOrder" << endl;
        cout << "5. Menampilkan data secara postOrder" << endl;
        cout << "6. Menampilkan data secara LevelOrder" << endl;
        cout << "7. Mencari Node didalam Tree" << endl;
        cout << "8. Menghitung node didalam tree" << endl;
        cout << "9. Menghitung tinggi dari Tree" << endl;
        cout << "10. Mencari Nilai Minimum didalam tree" << endl;
        cout << "11. Menampilkan daun di dalam tree" << endl;

        cout << "Masukkann pilihan kamu : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            if isEmpty ()
            {
                cout << "List Kosong" << endl;
            }
            else
            {
                cout << "List tidak kosong" << endl;
            }
            break;
        case 2:

        default:
            break;
        }
    }
}