#include <iostream>

using namespace std;

struct lnode
{
    int key;
    lnode* next;
    lnode(int k, lnode* n = nullptr) :key(k), next(n) {}
};

int wypisz(lnode* L) {
    lnode* current = L;
    while (current != nullptr) {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
    return 0;
}

int suma(lnode* L) {
    int sum = 0;
    lnode* current = L;
    while (current != nullptr) {
        sum += current->key;
        current = current->next;
    }
    return sum;
}

int nty(int n, lnode* L) {
    lnode* current = L;
    for (int i = 1; i < n && current != nullptr; i++) {
        current = current->next;
    }
    if (current != nullptr) {
        return current->key;
    }
    else {
        return 0;
    }
}

void insert(lnode*& L, int x) {
    L = new lnode(x, L);
}

void insert_after_smaller(lnode*& L, int x) {
    if (L == nullptr) {
        L = new lnode(x);
    }
    else if (x < L->key) {
        L = new lnode(x, L);
    }
    else {
        lnode* current = L;
        while (current->next != nullptr && current->next->key < x) {
            current = current->next;
        }
        current->next = new lnode(x, current->next);
    }
}

void remove(lnode*& L, int x) {
    lnode** current = &L;
    while (*current != nullptr) {
        if ((*current)->key == x) {
            lnode* toDelete = *current;
            *current = (*current)->next;
            delete toDelete;
        }
        else {
            current = &((*current)->next);
        }
    }
}

void filter(lnode*& L, bool(*cond)(int)) {
    lnode** current = &L;
    while (*current != nullptr) {
        if (!cond((*current)->key)) {
            lnode* toDelete = *current;
            *current = (*current)->next;
            delete toDelete;
        }
        else {
            current = &((*current)->next);
        }
    }
}

void destroy(lnode*& L) {
    while (L != nullptr) {
        lnode* toDelete = L;
        L = L->next;
        delete toDelete;
    }
}

int main() {
    lnode* L = nullptr;
    insert(L, 2);
    insert(L, 5);
    insert(L, 1);
    insert(L, 3);
    insert(L, 4);
    wypisz(L);
    cout << "Suma: " << suma(L) << endl;
    cout << "5-ty element: " << nty(5, L) << endl;
    insert_after_smaller(L, 2);
    insert_after_smaller(L, 3);
    wypisz(L);
    remove(L, 3);
    wypisz(L);
    filter(L, [](int x) {return x % 2 == 0; });
    wypisz(L);
    destroy(L);
    return 0;
}
