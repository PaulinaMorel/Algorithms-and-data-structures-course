#include <iostream>
#include <cassert>
#include <cstring>
#include <sstream>
using namespace std;

struct node {
    int key;
    int nL; // liczba węzłów w lewym poddrzewie
    node* parent;
    node* left;
    node* right;

    node(int key) : key(key), nL(0), parent(nullptr), left(nullptr), right(nullptr) {}

};

void insert(node*& t, int x) {
    node** a = &t;  // a to adres wskaźnika na korzeń
    node* par = nullptr;

    while (*a != nullptr) {
        par = *a;   // Zapisz adres bieżącego węzła jako wskaźnik na rodzica
        if (x < (**a).key) {
            a = &(**a).left;
        }
        else {
            a = &(**a).right;
        }
    }
    *a = new node(x);   // znalazłeś właściwego nulla więc podczep tam x
    (*a)->parent = par; // Ustaw rodzica nowego węzła
}


//Zad 2
void inorder_do(node* t, void f(node*)) {
    if (t) {
        inorder_do(t->left, f);
        f(t);
        inorder_do(t->right, f);
    }
}

void cout_node(node* n) {
    cout << n->key << " ";
}
// -------------

node* ity(node* t, int i) {
    while (t != nullptr) {
        if (t->nL == i) {    // Jeśli ilość kluczy w lewym poddrzewie jest równa i, to zwracamy wskaźnik na ten węzeł
            return t;
        }
        else if (t->nL < i) {    // Jeśli ilość kluczy w lewym poddrzewie jest mniejsza niż i, to przechodzimy do prawego poddrzewa
            i -= (t->nL + 1);
            t = t->right;
        }
        else {    // W przeciwnym wypadku przechodzimy do lewego poddrzewa
            t = t->left;
        }
    }
    return t;   // Jeśli nie znaleźliśmy węzła o indeksie i, to zwracamy nullptr
}
int main() {
    node* t = nullptr;
    insert(t, 5);
    insert(t, 3);
    insert(t, 8);
    insert(t, 1);
    insert(t, 4);
    insert(t, 7);
    insert(t, 10);

    inorder_do(t, cout_node);
    cout << endl;
    cout << "3 element " << ity(t, 3) << endl;
    //
//    inorder_do_3(t, cout_node);
//    cout << endl;
    return 0;
}

