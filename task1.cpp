
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

    void CreateThreeNodes() {
        int a, b, c;
        cout << "Enter three numbers: ";
        cin >> a >> b >> c;

        node* n1 = new node;
        node* n2 = new node;
        node* n3 = new node;

        n1->data = a;
        n2->data = b;
        n3->data = c;

        n1->next = n2;
        n2->next = n3;
        n3->next = nullptr;
        head = n1;
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

    cout << "Before creation: ";
    list.PrintList();

    list.CreateThreeNodes();

    cout << "After creation: ";
    list.PrintList();

    list.ClearList();
    return 0;
}