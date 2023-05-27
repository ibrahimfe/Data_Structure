#include <iostream>
// #include <queue>
using namespace std;

typedef struct myTree Tree;

struct myTree
{
    int data;
    Tree *left;
    Tree *right;
};

void init()
{
    Tree *pohon = NULL;
}
void clear()
{
    Tree *pohon = NULL;
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
void deleteNode(Tree *node)
{
    // Check if the node is null
    if (node == NULL)
    {
        return;
    }
    // If the node is a leaf node, simply free it
    if (node->left == NULL && node->right == NULL)
    {
        free(node);
        return;
    }
    // If the node has only one child, replace it with the child
    if (node->left == NULL)
    {
        node->right->parent = node->parent;
        node->parent->left = node->right;
    }
    else if (node->right == NULL)
    {
        node->left->parent = node->parent;
        node->parent->right = node->left;
    }
    else
    {
        // If the node has two children, find the inorder successor and replace the node with it
        Tree *successor = node->right;
        while (successor->left != NULL)
        {
            successor = successor->left;
        }

        // Replace the node with the successor
        node->data = successor->data;
        deleteNode(successor);
    }
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
// void LevelOrder(Tree *root)
// {
//     queue<int> queue;
//     Enqueue(queue, root);
//     while (isEmpty(queue) != 1)
//     {
//         Tree n = GetQueue(); // visit
//         print(n->data);
//         if (n->left != NULL)
//             Enqueue(n->left); // Enqueue if exists
//         if (n->right != NULL)
//             Enqueue(n->right); // Enqueue if exists
//         Dequeue(queue);        // out
//     }
// }

// void Dequeue(Queue *queue)
// {
//     Tree *node = queue->front;
//     queue->front = queue->front->next;
//     delete node;
// }

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
void printCari(int angka, Tree *pohon)
{
    Tree *node = cari(pohon, angka);
    if (node != NULL)
    {
        cout << "Angka Ditemukan!!" << endl;
    }
    else
    {
        cout << "Angka Tidak Ditemukan!!" << endl;
    }
}

void printMin(Tree *pohon)
{
    Tree *minNode = FindMin(pohon);
    cout << "Nilai Minimum dari sebuah tree adalah : " << minNode->data << endl;
}
int main()
{
    Tree *pohon;
    init();
    Tree *t = FindMin(pohon);
    int pilihan, angka;

    while (true)
    {
        cout << "\n=======================================" << endl;
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
        cout << "12. Keluar Dari Program"

            cout
             << "Masukkann pilihan kamu : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            if (isEmpty(pohon))
            {
                cout << "List Kosong" << endl;
            }
            else
            {
                cout << "List tidak kosong" << endl;
            }
            break;
        case 2:
            cout << "Masukkan angka yang ingin ditambahkan : " << endl;
            cin >> angka;
            tambah(&pohon, angka);
            break;
        case 3:
            preOrder(pohon);
            break;
        case 4:
            inOrder(pohon);
            break;
        case 5:
            postOrder(pohon);
            break;
        case 6:
            cout << "Still in Progress";
            break;
        case 7:
            cout << "Masukkan angka yang ingin dicari : " << endl;
            cin >> angka;
            printCari(angka, pohon);
            break;
        case 8:
            cout << "Banyaknya Nodes didalam Tree adalah : " << count(pohon) << endl;
            break;
        case 9:
            cout << "Tinggi dari Tree adalah : " << height(pohon) << endl;
            break;
        case 10:
            printMin(pohon);
            break;
        case 11:
            leaf(pohon);
            break;
        case 12:
            return 0;
        default:
            cout << endl
                 << "Tolong Masukkan Angka angka yang sesuai!!" << endl;
            break;
        }
    }
}