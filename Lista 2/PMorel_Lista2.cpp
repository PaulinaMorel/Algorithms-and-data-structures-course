#include <iostream>

// definicja struktury węzła drzewa BST
struct node
{
    int key; // wartość przechowywana w węźle
    node* left; // wskaźnik na lewe poddrzewo
    node* right; // wskaźnik na prawe poddrzewo
    node* parent; // wskaźnik na rodzica węzła

    // konstruktor węzła drzewa
    node(int x0, node* p = nullptr, node* l = nullptr, node* r = nullptr)
        : key(x0), parent(p), left(l), right(r)
    {}
};

// funkcja dodająca węzeł o wartości x do drzewa BST
void insert(node*& t, int x)
{
    // ustawienie wskaźnika na wskaźnik korzenia
    node** t1 = &t;
    // dopóki aktualny węzeł istnieje, przesuwaj wskaźnik w lewo lub w prawo w zależności od wartości wstawianego klucza
    while (*t1)
        t1 = x < (*t1)->key ? &(*t1)->left : &(*t1)->right;
    // po znalezieniu odpowiedniego węzła, utwórz nowy węzeł i ustaw go jako lewe lub prawe dziecko aktualnego węzła
    *t1 = new node(x, *t1);
}

// funkcja usuwająca węzeł o wartości x z drzewa BST
void remove(node*& t, int x) {
    // ustawienie wskaźnika na wskaźnik korzenia
    node** t1 = &t;
    while (*t1 && (*t1)->key != x)
        t1 = x < (*t1)->key ? &(*t1)->left : &(*t1)->right;

    if (*t1)
    {
        if ((*t1)->right && (*t1)->left)
        {
            node** t2 = &(*t1)->right;
            while ((*t2)->left)
                t2 = &(*t2)->left;
            (*t1)->key = (*t2)->key;
            t1 = t2;
        }
        // w przeciwnym wypadku, przepnij syna usuwanego węzła na miejsce usuwanego węzła
        node* son = (**t1).right ? (**t1).right : (**t1).left;
        delete* t1;
        *t1 = son;
    }
}

void inorder_do(node* t, void(*f)(node*))
{
    if (t)
    {
        inorder_do(t->left, f); // Rekurencyjnie wywołuje inorder_do dla lewego poddrzewa
        f(t); // Wywołuje funkcję f dla bieżącego węzła
        inorder_do(t->right, f); // Rekurencyjnie wywołuje inorder_do dla prawego poddrzewa
    }
}

void cout_node(node* n)
{
    std::cout << n->key << " "; // Wypisuje klucz bieżącego węzła na standardowe wyjście
}

void inorder_do_3(node* t, void f(node*)) {
    while (t) {
        if (!t->left) { // Jeśli nie ma lewego poddrzewa
            f(t); // Wywołuje funkcję f dla bieżącego węzła
            t = t->right; // Przechodzi do prawego poddrzewa
        }
        else {
            node* pred = t->left; // Ustawia pred na lewe poddrzewo
            while (pred->right && pred->right != t) // Szuka poprzednika
                pred = pred->right;
            if (!pred->right) { // Jeśli nie ma prawego dziecka pred, ustawia pred->right na bieżący węzeł i przechodzi do lewego dziecka
                pred->right = t;
                t = t->left;
            }
            else { // Jeśli pred->right wskazuje na bieżący węzeł, usuwa krawędź i wywołuje f dla bieżącego węzła
                pred->right = nullptr;
                f(t);
                t = t->right; // Przechodzi do prawego
            }
        }
    }
}
int main()
{
    node* t = nullptr;
    insert(t, 9);
    insert(t, 7);
    insert(t, 28);
    insert(t, 12);
    insert(t, 46);
    insert(t, 75);
    insert(t, 10);

    inorder_do(t, cout_node);
    std::cout << std::endl;

    remove(t, 7);

    inorder_do_3(t, cout_node);
    std::cout << std::endl;

    return 0;
}