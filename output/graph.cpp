#include <iostream>
using namespace std;

struct simpul
{
    simpul *left;
    int INFO;
    simpul *right;
};

// Declaration
typedef struct simpul simpul;
simpul *P, *FIRST, *LAST, *PVertex, *PEdge, *Q, *R, *S;
simpul *pointS[5];

int main()
{
    int A[5][5] = {{0, 5, 0, 2, 0},
                   {6, 0, 0, 3, 0},
                   {0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0},
                   {9, 0, 12, 7, 14}};
    char NmS[6] = "ABCDE";
    int I, J;

    // Initialize the first vertex
    P = new simpul;
    P->INFO = NmS[0];
    FIRST = P;
    LAST = P;
    P->left = NULL;
    P->right = NULL;
    pointS[0] = P;
    cout << P->INFO << endl;
    cout << "Address: " << pointS[0] << endl;

    // Initialize the remaining vertices
    for (I = 1; I < 5; I++)
    {
        P = new simpul;
        P->INFO = NmS[I];
        LAST->left = P;
        LAST = LAST->left;
        P->left = NULL;
        P->right = NULL;
        pointS[I] = P;
        cout << P->INFO << endl;
        cout << "Address: " << pointS[I] << endl;
    }

    // Print the graph
    Q = FIRST;
    for (I = 0; I < 5; I++)
    {
        R = Q;
        cout << "Vertex: " << Q->INFO << endl;
        for (J = 0; J < 5; J++)
        {
            if (A[I][J] != 0)
            {
                P = new simpul;
                P->INFO = A[I][J];
                R->right = P;
                P->left = pointS[J];
                cout << "Connected to: " << P->left->INFO << endl;
                cout << "Weight: " << P->INFO << endl;
                P->right = NULL;
                R = P;
            }
        }
        cout << endl;
        Q = Q->left;
    }

    return 0;
}