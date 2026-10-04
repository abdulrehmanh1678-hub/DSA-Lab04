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

    void DeleteNode(int delData) {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }

        if (head->data == delData) {
            node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << delData << endl;
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
        cout << "Deleted " << delData << endl;
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
    int choice, val;

    do {
        cout << "\n1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Search value" << endl;
        cout << "4. Delete value" << endl;
        cout << "5. Display list" << endl;
        cout << "6. Count nodes" << endl;
        cout << "7. Show second node" << endl;
        cout << "8. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Value: ";
            cin >> val;
            list.InsertAtBeginning(val);
            break;
        case 2:
            cout << "Value: ";
            cin >> val;
            list.AddNode(val);
            break;
        case 3:
            cout << "Value: ";
            cin >> val;
            list.SearchNode(val);
            break;
        case 4:
            cout << "Value: ";
            cin >> val;
            list.DeleteNode(val);
            break;
        case 5:
            list.PrintList();
            break;
        case 6:
            cout << "Nodes: " << list.CountNodes() << endl;
            break;
        case 7:
            list.PrintSecondNode();
            break;
        case 8:
            cout << "Bye" << endl;
            break;
        default:
            cout << "Invalid choice, try again" << endl;
        }
    } while (choice != 8);

    list.ClearList();
    return 0;
}