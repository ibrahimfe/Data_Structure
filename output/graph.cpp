#include <iostream>
using namespace std;

typedef struct typeS
{
    typeS *left;
    int INFO;
    typeS *right;
};
typedef struct typeS simpul;
simpul *P, *FIRST, *LAST, *PVertex, *PEdge, *Q, *R, *S;
simpul *pointS[5];

int main()
{
    int A[5][5] = {0, 5, 0, 2, 0, 6, 0, 3, 0, 0, 0, 0, 0, 0, 9, 0, 0, 12, 0, 7, 0, 14, 0, 0, 0};
    char NmS[6] = "ABCDE";
    int I, J;

    I = 0;
    J = 0;
    P = new simpul;
    P->INFO = NmS[0];
    FIRST = P;
    LAST = P;
    P->left = NULL;
    P->right = NULL;
    pointS[0] = P;
    cout << P->INFO << endl;
    cout << "Alamat : " << pointS[0];

    for (I = 1; I <= 4; I++)
    {
        P = new simpul;
        P->INFO = NmS[I];
        LAST->left = P;
        LAST = LAST->left;
        P->left = NULL;
        P->right = NULL;
        pointS[I] = P;
        cout << P->INFO << endl;
        cout << "Alamat : " << pointS[I] << endl;
    }

    Q = FIRST;
    for (I = 0; I <= 4; I++)
    {
        R = Q;
        cout << "\nVertex : " << Q->INFO << endl;
        for (J = 0; J <= 4; J++)
        {
            if (A[I][J] != 0)
            {
                P = new simpul;
                P->INFO = A[I][J];
                R->right = P;
                P->left = pointS[J];
                cout << "Berhubungan dengan : " << P->left->INFO << endl;
                cout << "Bobot : " << P->INFO << endl;
                P->right = NULL;
                R = P;
            }
        }
        cout << endl;
        Q = Q->left;
    }
    return 0;
}