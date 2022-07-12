#include <iostream>
#include <sstream>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int data = 0, Node *next = nullptr) : data(data), next(next) {}
};

struct List {
    Node *head {nullptr};
    int sizeList {};

    List() {}

    ~List() {
        destructer(head);
    }

    bool empty() {
        return head == nullptr;
    }
    
    void destructer(Node * node) {
        if(empty())
            return;
        
        destructer(node->next);
        delete(node);
    }

    void push_back(int value) {
        if(empty()) {
            this->head = new Node(value);
            return;
        }

        auto node = this->head;

        while(node->next != nullptr) 
            node = node->next;

        node->next = new Node(value);
        this->sizeList++;
    }

    void push_front(int value) {
        auto node = new Node(value);
        node->next = this->head;
        this->head = node;
        this->sizeList++;
    }

    Node * __pop_back(Node * node) {
        if (node->next == nullptr) {
            delete node;
            return nullptr;
        }
        
        node->next = __pop_back(node->next);

        return node;
    }

    void pop_back() {
        head = __pop_back(head);
    }

    void pop_front() {
        if (empty())
            return;

        auto node = head;
        head = head->next;
        delete node;
        this->sizeList--;
    }

    int size() {
        return this->sizeList;
    }

    friend ostream& operator<<(ostream& os, List& list) {
        os << "[ ";
        
        auto node = list.head;

        while(node != nullptr) {
            os << node->data << " ";
            node = node->next;
        }

        os << "]" << endl;

        return os;
    }
};

int main () {
    List list;

    while (true) {
        string line, command;
        int value;

        getline(cin, line);

        stringstream ss(line);
        cin >> command;

        if(command == "end")
            break;
        else if(command == "show")
            cout << list << endl;
        else if(command == "push_back") {
            while(ss >> value)
                list.push_back(value);
        } else if (command == "push_front") {
            while(ss >> value)
                list.push_front(value);
        } else if (command == "pop_back")
            list.pop_back();
        else if(command == "pop_front")
            list.pop_front();
        else if(command == "sizeList")
            cout << list.size() << endl;
    }
}