// Implementation of doubly linked list for insert and delete from the beginning, insert and delete from the end, insert and delete from any position, display.

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

class doubly_linked_list{
    private:
        node *head, *tail;
    public:
        doubly_linked_list(){
            head = NULL;
            tail = NULL;
        }
        void insert_begin(int);
        void insert_position(int, int);
        void insert_end(int);
        void delete_begin();
        void delete_position(int);
        void delete_end();
        void display();
};

void doubly_linked_list::insert_begin(int value){
    node *temp = new node;
    temp->data = value;
    temp->next = head;
    temp->prev = NULL;
    if (head != NULL)
        head->prev = temp;
    head = temp;
    if (tail == NULL)
        tail = temp;
}

void doubly_linked_list::insert_position(int pos, int value){
    node *pre = new node;
    node *cur = new node;
    node *temp = new node;
    cur = head;
    for (int i = 1; i < pos; i++)
    {
        pre = cur;
        cur = cur->next;
    }
    temp->data = value;
    pre->next = temp;
    temp->prev = pre;
    temp->next = cur;
    cur->prev = temp;
}

void doubly_linked_list::insert_end(int value){
    node *temp = new node;
    temp->data = value;
    temp->next = NULL;
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void doubly_linked_list::delete_begin(){
    node *temp = new node;
    temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void doubly_linked_list::delete_position(int pos){
    node *cur = new node;
    node *pre = new node;
    cur = head;
    for (int i = 1; i < pos; i++){
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
    cur->next->prev = pre;
    delete cur;
}

void doubly_linked_list::delete_end(){
    node *temp = new node;
    temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete temp;
}

void doubly_linked_list::display(){
    node *temp = new node;
    temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    doubly_linked_list dl;
    int choice, element, position;
    while (1){
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at any position" << endl;
        cout << "3. Insert at end" << endl;
        cout << "4. Delete from beginning" << endl;
        cout << "5. Delete from any position" << endl;
        cout << "6. Delete from end" << endl;
        cout << "7. Display" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Enter the element: ";
                cin >> element;
                dl.insert_begin(element);
                cout << endl;
                break;
            case 2:
                cout << "Enter the element: ";
                cin >> element;
                cout << "Enter the position: ";
                cin >> position;
                dl.insert_position(position, element);
                cout << endl;
                break;
            case 3:
                cout << "Enter the element: ";
                cin >> element;
                dl.insert_end(element);
                cout << endl;
                break;
            case 4:
                dl.delete_begin();
                cout << endl;
                break;
            case 5:
                cout << "Enter the position: ";
                cin >> position;
                dl.delete_position(position);
                cout << endl;
                break;
            case 6:
                dl.delete_end();
                cout << endl;
                break;
            case 7:
                dl.display();
                cout << endl;
                break;
            case 8:
                exit(1);
                break;
            default:
                cout << "Wrong choice" << endl;
        }
    }
    return 0;
}