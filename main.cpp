#include <iostream>
using namespace std;

// Структура вузла списку
struct Node {
    int data;      // Інформаційне поле
    Node* next;    // Вказівник на наступний вузол
};

// Функція для додавання нового вузла в початок списку
void addNode(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Функція для збільшення значення інформаційного поля кожного елемента списку на задану величину
void increaseList(Node* head, int increment) {
    Node* current = head;
    while (current != nullptr) {
        current->data += increment;
        current = current->next;
    }
}

// Функція для виведення елементів списку
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Додавання елементів до списку
    addNode(head, 1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 4);
    addNode(head, 5);

    // Виведення початкового списку
    cout << "Початковий список: ";
    printList(head);

    // Запит користувача для збільшення значення інформаційного поля
    int increment;
    cout << "Введіть значення для збільшення: ";
    cin >> increment;

    // Збільшення значення інформаційного поля кожного елемента списку
    increaseList(head, increment);

    // Виведення зміненого списку
    cout << "Змінений список: ";
    printList(head);

    // Видалення списку (видалення всіх вузлів)
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
