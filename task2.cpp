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

    int CountNodes() {
        int count = 0;
        node* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
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
    int n, val;

    cout << "How many numbers? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> val;
        list.AddNode(val);
    }

    cout << "List: ";
    list.PrintList();
    cout << "Count: " << list.CountNodes() << endl;

    list.ClearList();
    return 0;
}