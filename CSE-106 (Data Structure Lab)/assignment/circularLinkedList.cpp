// Implement circular linked list and perform following operations on it
// 1. Insertion at beginning
// 2. Insertion at end
// 3. Insertion at given position
// 4. Deletion at beginning
// 5. Deletion at end
// 6. Deletion at given position
// 7. Display
// 8. Exit

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class circularLinkedList{
    node *head, *tail;
    int size;

public:
    circularLinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertAtBeginning(int data){
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;

        if (head == NULL){
            head = temp;
            tail = temp;
            temp->next = head;
        }
        else{
            temp->next = head;
            head = temp;
            tail->next = head;
        }
        size++;
    }

    void insertAtEnd(int data){
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;

        if (head == NULL){
            head = temp;
            tail = temp;
            temp->next = head;
        }
        else{
            tail->next = temp;
            tail = temp;
            tail->next = head;
        }
        size++;
    }

    void insertAtPosition(int data, int position){
        if (position > size + 1 || position < 1){
            cout << "Invalid position" << endl;
            return;
        }

        if (position == 1){
            insertAtBeginning(data);
            return;
        }

        if (position == size + 1){
            insertAtEnd(data);
            return;
        }

        node *temp = new node;
        temp->data = data;
        temp->next = NULL;

        node *current = head;
        for (int i = 1; i < position - 1; i++){
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
        size++;
    }

    void deleteAtBeginning(){
        if (head == NULL){
            cout << "List is empty" << endl;
            return;
        }

        node *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
        size--;
    }

    void deleteAtEnd(){
        if (head == NULL){
            cout << "List is empty" << endl;
            return;
        }

        node *current = head;
        for (int i = 1; i < size - 1; i++){
            current = current->next;
        }
        node *temp = current->next;
        current->next = head;
        tail = current;
        delete temp;
        size--;
    }

    void deleteAtPosition(int position){
        if (position > size || position < 1){
            cout << "Invalid position" << endl;
            return;
        }

        if (position == 1){
            deleteAtBeginning();
            return;
        }

        if (position == size){
            deleteAtEnd();
            return;
        }

        node *current = head;
        for (int i = 1; i < position - 1; i++){
            current = current->next;
        }
        node *temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
    }

    void display(){
        if (head == NULL){
            cout << "List is empty" << endl;
            return;
        }

        node *current = head;
        for (int i = 1; i <= size; i++){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int getSize(){
        return size;
    }

    ~circularLinkedList(){
        node *current = head;
        while (current != tail){
            node *temp = current;
            current = current->next;
            delete temp;
        }
        delete tail;
    }

};

int main(){
    circularLinkedList list;
    int choice, data, position;

    while (true){
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at given position" << endl;
        cout << "4. Delete at beginning" << endl;
        cout << "5. Delete at end" << endl;
        cout << "6. Delete at given position" << endl;
        cout << "7. Display" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                cout << "Enter data: ";
                cin >> data;
                list.insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
            case 3:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter position: ";
                cin >> position;
                list.insertAtPosition(data, position);
                break;
            case 4:
                list.deleteAtBeginning();
                break;
            case 5:
                list.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> position;
                list.deleteAtPosition(position);
                break;
            case 7:
                list.display();
                break;
            case 8:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}