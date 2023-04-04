#include <iostream>
using namespace std;

// Definicja struktury węzła listy jednokierunkowej
struct lnode {
    int key;        // klucz węzła
    lnode* next;    // wskaźnik na następny węzeł

    // Konstruktor inicjujący pola struktury
    lnode(int key) : key(key), next(nullptr) {}
};

// Funkcja odwracająca kolejność elementów na liście jednokierunkowej
void reverse(lnode*& L) {
    lnode* prev = nullptr;
    lnode* current = L;
    while (current != nullptr) {
        lnode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    L = prev;
}

// Procedura sortująca listę jednokierunkową przez wstawianie
void insertion_sort(lnode*& L) {
    lnode* new_list = nullptr;  // "Nowa" lista, na której będą wstawiane elementy w kolejności malejącej
    lnode* current = L;         // Aktualnie przetwarzany węzeł z listy L

    while (current != nullptr) {
        lnode* next = current->next;    // Zapamiętujemy wskaźnik na następny węzeł, aby nie stracić go przy przestawianiu

        // Wstawiamy aktualny węzeł na "nową" listę w kolejności malejącej
        if (new_list == nullptr || current->key >= new_list->key) {
            current->next = new_list;
            new_list = current;
        }
        else {
            lnode* new_current = new_list;
            while (new_current->next != nullptr && new_current->next->key > current->key) {
                new_current = new_current->next;
            }
            current->next = new_current->next;
            new_current->next = current;
        }

        current = next; // Przechodzimy do przetwarzania następnego węzła z listy L
    }

    L = new_list;   // Przypisujemy "nową" listę jako posortowaną listę wejściową
    reverse(L);     // Odwracamy kolejność węzłów na liście, aby lista była posortowana rosnąco
}
void print_list(lnode* L) {
    lnode* current = L;
    while (current != nullptr) {
        std::cout << current->key << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
int main() {
    // Tworzymy listę jednokierunkową o elementach 5, 3, 1, 4, 2
    lnode* L = new lnode(5);
    L->next = new lnode(3);
    L->next->next = new lnode(1);
    L->next->next->next = new lnode(4);
    L->next->next->next->next = new lnode(2);

    // Wyświetlamy nieposortowaną listę
    cout << "Nieposortowana lista: ";
    lnode* current = L;
    while (current != nullptr) {
        cout << current->key << " ";
        current = current->next;
    }
        insertion_sort(L);
        cout << "" << endl;
        cout << "Posortowana lista: ";
        print_list(L);
        return 0;
    
}