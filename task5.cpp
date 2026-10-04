#include <iostream>
using namespace std;

class List {
private:
    struct node {
        int data;
        node* next;
    };
    node* head;

public:
    List() { head = nullptr; }

    void AddNode(int addData) {
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }
        node* curr = head;
        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = newNode;
    }

    void DeleteNode(int delData) {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }

        // first node holds the value
        if (head->data == delData) {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node* prev = head;
        node* curr = head->next;
        while (curr != nullptr && curr->data != delData) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << delData << " not found" << endl;
            return;
        }
        prev->next = curr->next;
        delete curr;
    }

    void PrintList() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void ClearList() {
        node* curr = head;
        while (curr != nullptr) {
            node* temp = curr->next;
            delete curr;
            curr = temp;
        }
        head = nullptr;
    }
};

int main() {
    List list;

    cout << "Delete from empty list:" << endl;
    list.DeleteNode(5);

    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(20);
    list.AddNode(30);
    cout << "\nOriginal: ";
    list.PrintList();

    list.DeleteNode(20);
    cout << "Delete 20 (middle): ";
    list.PrintList();

    list.DeleteNode(10);
    cout << "Delete 10 (first): ";
    list.PrintList();

    list.DeleteNode(30);
    cout << "Delete 30 (last): ";
    list.PrintList();

    list.DeleteNode(99);
    cout << "Delete 99 (missing): ";
    list.PrintList();

    list.DeleteNode(20);
    cout << "Delete 20 (only node): ";
    list.PrintList();

    list.ClearList();
    return 0;
}