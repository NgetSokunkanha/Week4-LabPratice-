#include <iostream>
using namespace std;

class Node {
    public:
    int order_Id;
    int day, month, year;
    string item_Name;
    double item_Price;
    int item_Amount;
    int total_Price;
    Node* next = nullptr;

    public:
    Node(int id, string name, double price, int amount, int d, int m, int y){
        order_Id = id;
        day = d;
        month = m;
        year = y;
        item_Name = name;  
        item_Price = price;
        item_Amount = amount;
        total_Price = item_Price * item_Amount;
    }

    void display_Date(){
        cout << "DD/MM/YY : " << day << " / " << month << " / " << year << endl;
    }

};

class Queue {
    public:
    Node* Front = nullptr;
    Node* Rear = nullptr;
    int length = 0;

    public:
    void Enqueue(int id, string name, double price, int amount, int d, int m, int y){
        Node* nNode = new Node(id, name, price, amount, d, m, y);
        if (Front == nullptr){    
            Front = nNode;
            Rear = nNode;   
        } else {
            Rear->next = nNode;
            Rear = nNode; 
        }
        length ++;
    }

    void Dequeue(){
        if (Front == nullptr){
            cout << "The queue is empty!" << endl;
            return;
        } 
        Node* Temp = Front;
        if (Front == Rear){
            Front = nullptr;
            Rear = nullptr;
            delete Temp;
        } else {
            Front = Front->next;
            delete Temp;
        }
        length --;
    }
    
    void display_Queue(){
        Node* cur = Front;
        if (Front == nullptr){
            cout << "The queue is empty!" << endl;
            return;
        }
        cout << "--- Queue ---" << endl;
        while (cur != nullptr){
            cout << endl << "- Order No." << cur->order_Id << "  -"<< endl;
            cout << "Item: " << cur->item_Name << endl;
            cout << "Amount: " << cur->item_Amount << endl;
            cout << "Price per unit: " << cur->item_Price << endl;
            cout << "Total price: " << cur->total_Price << "$" << endl;
            cur->display_Date();
            cur = cur->next;
        }
    }
};