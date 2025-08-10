// Written by: Md. Maruf Sarker
// Platform: Arch Linux
// Problem: Implementation of Queue, using arrays with a user defined function
// Language: cpp / go / c / python
// Date: 2022-11-10

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define space = " "
#define pi 3.141592653589793238462
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define ld long double

int Queue[100], front = -1, rear = -1, n = 100;

void enqueue(int x){
    system("clear");
    if (rear == n - 1){
        cout << "Queue is full" << endl;
        return;
    }
    if (front == -1 && rear == -1) front = rear = 0;
    else rear++;

    Queue[rear] = x;
}

void dequeue(){
    system("clear");
    if (front == -1 || front > rear){
        cout << "Queue is empty" << endl;
        return;
    }
    else front++;
}

void display(){
    system("clear");
    if (front == -1 || front > rear){
        cout << "Queue is empty" << endl;
        return;
    }
    for (int i = front; i <= rear; i++) cout << Queue[i] << " ";
    cout << endl;
}

int main(){
    int choice, x;
    do{
        cout << "Implementation of Queue, \nusing arrays with a user defined function" << endl;
        cout << "---------------------------\n";
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> x;
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 4);
    return 0;
}