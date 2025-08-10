// Implementation of doubly linked list for insert and delete from the beginning, insert and delete from the end, insert and delete from any position, display, reverse display, reverse list, sort list, merge list, split list, concatenate list, and delete list.

// Written By: Md. Maruf Sarker
// Date: 03/12/2022
// CSE Batch: 221
// Green University of Bangladesh

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
        void search(int);
        void display();
        void reverse_display();
        void reverse_list();
        void sort_list();
        void merge_list(doubly_linked_list);
        void split_list(doubly_linked_list&, doubly_linked_list&);
        void concatenate_list(doubly_linked_list);
        void delete_list();
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
    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
    }
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
    for (int i = 1; i < pos; i++)
    {
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

void doubly_linked_list::search(int value){
    node *temp = new node;
    temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << "Element " << value << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element " << value << " not found in the list" << endl;
}

void doubly_linked_list::display(){
    node *temp = new node;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
}

void doubly_linked_list::reverse_display(){
    node *temp = new node;
    temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->prev;
    }
}

void doubly_linked_list::reverse_list(){
    node *current = new node;
    node *temp = new node;
    current = head;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;
}

void doubly_linked_list::sort_list(){
    node *current = new node;
    node *index = new node;
    int temp;
    if (head == NULL)
    {
        return;
    }
    else
    {
        for (current = head; current->next != NULL; current = current->next)
        {
            for (index = current->next; index != NULL; index = index->next)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
        }
    }
}

void doubly_linked_list::merge_list(doubly_linked_list list2){
    node *temp = new node;
    temp = tail;
    temp->next = list2.head;
    list2.head->prev = temp;
    tail = list2.tail;
}

void doubly_linked_list::split_list(doubly_linked_list &list1, doubly_linked_list &list2){
    node *temp = new node;
    temp = head;
    int size = 0;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    temp = head;
    int mid = size / 2;
    for (int i = 1; i < size; i++)
    {
        if (i < mid)
        {
            list1.insert_end(temp->data);
            temp = temp->next;
        }
        else
        {
            list2.insert_end(temp->data);
            temp = temp->next;
        }
    }
}

void doubly_linked_list::concatenate_list(doubly_linked_list list2){
    tail->next = list2.head;
    list2.head->prev = tail;
    tail = list2.tail;
}

void doubly_linked_list::delete_list(){
    node *current = new node;
    node *next = new node;
    current = head;
    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}

int main(){
    doubly_linked_list list1, list2, list3;
    int choice, element, position;
    while (1)
    {
        cout << endl;
        cout << "-----------------" << endl;
        cout << "Operations on Doubly Linked List" << endl;
        cout << "-----------------" << endl;
        cout << "1.Insert Element at beginning" << endl;
        cout << "2.Insert Element at a given position" << endl;
        cout << "3.Insert Element at end" << endl;
        cout << "4.Delete Element at beginning" << endl;
        cout << "5.Delete Element at a given position" << endl;
        cout << "6.Delete Element at end" << endl;
        cout << "7.Search Element" << endl;
        cout << "8.Display Linked List" << endl;
        cout << "9.Reverse Display Linked List" << endl;
        cout << "10.Reverse Linked List" << endl;
        cout << "11.Sort Linked List" << endl;
        cout << "12.Merge Linked List" << endl;
        cout << "13.Split Linked List" << endl;
        cout << "14.Concatenate Linked List" << endl;
        cout << "15.Delete Linked List" << endl;
        cout << "16.Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element: ";
            cin >> element;
            list1.insert_begin(element);
            cout << endl;
            break;
        case 2:
            cout << "Enter the element: ";
            cin >> element;
            cout << "Insert element at position: ";
            cin >> position;
            list1.insert_position(position, element);
            cout << endl;
            break;
        case 3:
            cout << "Enter the element: ";
            cin >> element;
            list1.insert_end(element);
            cout << endl;
            break;
        case 4:
            cout << "Element deleted from beginning: ";
            list1.delete_begin();
            cout << endl;
            break;
        case 5:
            cout << "Enter the position of element to be deleted: ";
            cin >> position;
            list1.delete_position(position);
            cout << endl;
            break;
        case 6:
            cout << "Element deleted from end: ";
            list1.delete_end();
            cout << endl;
            break;
        case 7:
            cout << "Enter the element to be searched: ";
            cin >> element;
            list1.search_element(element);
            cout << endl;
            break;
        case 8:
            cout << "Elements of list are: ";
            list1.display();
            cout << endl;
            break;
        case 9:
            cout << "Elements of list in reverse order are: ";
            list1.reverse_display();
            cout << endl;
            break;
        case 10:
            cout << "Linked List reversed" << endl;
            list1.reverse_list();
            cout << endl;
            break;
        case 11:
            cout << "Linked List sorted" << endl;
            list1.sort_list();
            cout << endl;
            break;
        case 12:
            cout << "Enter the elements of second list: ";
            list2.insert_end(1);
            list2.insert_end(2);
            list2.insert_end(3);
            list2.insert_end(4);
            list2.insert_end(5);
            list2.insert_end(6);
            list2.insert_end(7);
            list2.insert_end(8);
            list2.insert_end(9);
            list2.insert_end(10);
            cout << "Merged list: ";
            list1.merge_list(list2);
            list1.display();
            cout << endl;
            break;
        case 13:
            cout << "Split list: ";
            list1.split_list(list2, list3);
            cout << "First list: ";
            list2.display();
            cout << "Second list: ";
            list3.display();
            cout << endl;
            break;
        case 14:
            cout << "Enter the elements of second list: ";
            list2.insert_end(1);
            list2.insert_end(2);
            list2.insert_end(3);
            list2.insert_end(4);
            list2.insert_end(5);
            list2.insert_end(6);
            list2.insert_end(7);
            list2.insert_end(8);
            list2.insert_end(9);
            list2.insert_end(10);
            cout << "Concatenated list: ";
            list1.concatenate_list(list2);
            list1.display();
            cout << endl;
            break;
        case 15:
            cout << "Linked List deleted" << endl;
            list1.delete_list();
            cout << endl;
            break;
        case 16:
            exit(1);
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}
