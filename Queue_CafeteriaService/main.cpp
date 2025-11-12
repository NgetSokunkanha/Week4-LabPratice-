#include <iostream>
#include <string>
#include "queue.hpp" 
using namespace std;

int main() {
    Queue cafeteriaQueue;
    int choice = 0;         
    int orderCounter = 1;   
    int day, month, year;

    cout << "Enter today's date (day month year): ";
    cin >> day >> month >> year;

    while (choice != 4) {
        cout << endl;
        cout << "--- Cafeteria Queue Menu ---" << endl;
        cout << "1. Add Order" << endl;
        cout << "2. Serve Order" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string itemName;
            double price;
            int amount;

            cout << "Enter item name: ";
            cin.ignore(); 
            getline(cin, itemName);

            cout << "Enter item price ($): ";
            cin >> price;

            cout << "Enter item amount: ";
            cin >> amount;

            cafeteriaQueue.Enqueue(orderCounter++, itemName, price, amount, day, month, year);
            cout << "Order added to queue." << endl;

        } else if (choice == 2) {
            if (cafeteriaQueue.length == 0) {
                cout << "The queue is empty. No order to serve." << endl;
            } else {
                cout << "Serving Order No." << cafeteriaQueue.Front->order_Id << endl;
                cout << "Item: " << cafeteriaQueue.Front->item_Name << endl;
                cout << "Amount: " << cafeteriaQueue.Front->item_Amount << endl;
                cout << "Total Price: " << cafeteriaQueue.Front->total_Price << endl;
                cout << "Order Date: ";
                cafeteriaQueue.Front->display_Date();
                cafeteriaQueue.Dequeue();
            }

        } else if (choice == 3) {
            cafeteriaQueue.display_Queue();

        } else if (choice == 4) {
            cout << "Exiting program." << endl;

        } else {
            cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
