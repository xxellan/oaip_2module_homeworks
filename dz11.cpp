//3 задачи на очередь
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

//1 task
void addToQueue(queue<string>& q, const string& person) {
    q.push(person);
}

void processQueue(queue<string>& q) {
    if (!q.empty()) {
        cout << "Processed client: " << q.front() << endl;
        q.pop();
    } else {
        cout << "The queue is empty." << endl;
    }
}

void runTask1() {
    cout << "=== TASK 1: Queue in the store ===" << endl;
    queue<string> shopQueue;

    addToQueue(shopQueue, "Ivan");
    addToQueue(shopQueue, "Anna");
    addToQueue(shopQueue, "Peter");

    processQueue(shopQueue);
    processQueue(shopQueue);
    processQueue(shopQueue);
    processQueue(shopQueue); 
    cout << endl;
}



//2 task
void addEvent(queue<string>& eventQueue, const string& event) {
    eventQueue.push(event);
}

void processEvents(queue<string>& eventQueue) {
    if (!eventQueue.empty()) {
        cout << "Processing event: " << eventQueue.front() << endl;
        eventQueue.pop();
    } else {
        cout << "The event queue is empty." << endl;
    }
}

void runTask2() {
    cout << "=== TASK 2: Network events ===" << endl;
    queue<string> events;

    addEvent(events, "User login");
    addEvent(events, "Message received");
    addEvent(events, "File sent");

    while (!events.empty()) {
        processEvents(events);
    }
    processEvents(events);
    cout << endl;
}



//3 task
struct Order {
    string customerName;
    vector<string> items;
};

void addOrder(queue<Order>& orderQueue, const Order& newOrder) {
    orderQueue.push(newOrder);
}

void processOrder(queue<Order>& orderQueue) {
    if (!orderQueue.empty()) {
        Order current = orderQueue.front();
        
        cout << "Customer: " << current.customerName << endl;
        cout << "Items: ";
        for (const string& item : current.items) {
            cout << item << ", ";
        }
        cout << endl << "-------------------" << endl;
        
        orderQueue.pop();
    } else {
        cout << "The order queue is empty." << endl;
    }
}

void runTask3() {
    cout << "=== TASK 3: Online store ===" << endl;
    queue<Order> orders;

    Order order1 = {"Dmitry", {"Phone", "Charger"}};
    Order order2 = {"Elena", {"Book"}};
    Order order3 = {"Maxim", {"Laptop", "Mouse"}};

    addOrder(orders, order1);
    addOrder(orders, order2);
    addOrder(orders, order3);

    while (!orders.empty()) {
        processOrder(orders);
    }
    cout << endl;
}


int main() {
    runTask1();
    runTask2();
    runTask3();
    return 0;

}
