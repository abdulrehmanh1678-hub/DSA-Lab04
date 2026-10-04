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

    void SearchNode(int searchData) {
        node* curr = head;
        int pos = 1;
        while (curr != nullptr) {
            if (curr->data == searchData) {
                cout << searchData << " found at position " << pos << endl;
                return;
            }
            curr = curr->next;
            pos++;
        }
        cout << "Value not found" << endl;
    }

    void PrintSecondNode() {
        if (head == nullptr || head->next == nullptr) {
            cout << "Less than two nodes in the list" << endl;
            return;
        }
        cout << "Second node: " << head->next->data << endl;
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

    cout << "Empty list" << endl;
    list.PrintSecondNode();
    list.SearchNode(20);

    list.AddNode(10);
    cout << "\nOne node" << endl;
    list.PrintSecondNode();

    list.ClearList();
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    list.AddNode(20);

    cout << "\nList: ";
    list.PrintList();
    list.PrintSecondNode();
    list.SearchNode(20);
    list.SearchNode(99);

    list.ClearList();
    return 0;
}