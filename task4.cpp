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

    void InsertAtBeginning(int addData) {
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = head;
        head = newNode;
    }

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

    list.InsertAtBeginning(20);
    cout << "After inserting 20 at beginning: ";
    list.PrintList();

    list.InsertAtBeginning(10);
    cout << "After inserting 10 at beginning: ";
    list.PrintList();

    list.AddNode(30);
    cout << "After appending 30: ";
    list.PrintList();

    list.ClearList();
    return 0;
}