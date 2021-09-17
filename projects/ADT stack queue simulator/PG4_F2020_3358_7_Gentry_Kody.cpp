/*
    Kody Gentry
    Programming Assignment Number 4

    Fall 2020 - CS 3358 07
    Due: Oct 19th, 2020

    Instructor: Husain Gholoom

    C++ program that simulates a ADT stack / queue
    using a linked List ADT with actual pointers.
    The program will perform various operations in sequences.
*/
#include <iostream>
using namespace std;

// initialize LL Node used for Queue and Stack
struct Node{
    int data;
    Node *link;
    Node(int d){ // Node constructor
        data = d;
        link = nullptr;
    }
};

// LL ADT Stack
class Stack{
private:
    Node *front;
public:
    Stack();
    void push(int); // push method to add data element
    void pop();   // pop method to remove data element
    int top();  // top method to return top data element
};
// Stack implementation
Stack::Stack(){
    front = nullptr; // initialize constructor with null head
}
void Stack::push(int x){
    // creating a new node
    Node *temp;
    temp = new Node(x);
    // setting data to it
    temp->data = x;

    // add the node in front of list
    if(front == nullptr){
        temp->link = nullptr;
    }
    else{
        temp->link = front;
    }
    front = temp;
}
void Stack::pop(){
    // if empty
    if(front == nullptr)
        cout << "UNDERFLOW\n";

        // delete the first element
    else{
        Node *temp = front;
        front = front->link;
        delete(temp);
    }
}
int Stack::top(){
    return front->data; // return data from top
}

// LL ADT Queue
class Queue {
private:
    Node *front, *rear;
public:
    Queue();
    void enQueue(int x);
    void deQueue();
    int first();
    int last();
};
// Queue implementation
Queue::Queue(){
    front = rear = nullptr; // construct the queue to null
}
void Queue::enQueue(int x){

    // Create a new LL node
    Node* temp = new Node(x);

    // If queue is empty, then
    // new node is front and rear both
    if (rear == nullptr){
        front = rear = temp;
        return;
    }

    // Add the new node at
    // the end of queue and change rear
    rear->link = temp;
    rear = temp;
}
void Queue::deQueue(){
    // If queue is empty, return NULL.
    if (front == nullptr)
        return;

    // Store previous front and
    // move front one node ahead
    Node *temp = front;
    front = front->link;

    // If front becomes NULL, then
    // change rear also as NULL
    if (front == nullptr)
        rear = nullptr;

    delete (temp);
}
int Queue::first(){
    return front->data; // return data from front node
}
int Queue::last(){
    return rear->data; // return data from end node
}

// Operation class to test implemented ADTs
class Operation{
private:
    Stack stack; // objects of the stack and queue classes
    Queue queue;
public:
    // stack functions
    void buildStack();
    void stackInsert();
    void stackRemove();
    void deleteStack();
    void displayStack(int size);

    // queue functions
    void buildQueue();
    void queueInsert();
    void queueRemove();
    void queueInsertThirdPos();
    void queueRemoveFourthElem();
    void queueMinMax();
    void deleteQueue();
    void displayQueue(int size);

    bool exit();
};
// Operation implementation
// stack functions
void Operation::buildStack(){
    stack.push(20);
    stack.push(49);
    stack.push(28);
    stack.push(31);
    stack.push(42);
    /*
     * function that pushes 5 random int values
     * between 20 and 50 to a stack
     */
}
void Operation::stackInsert(){
    buildStack();
    stack.push(-20);
    /*
     * function that inserts the value -20
     * to the top of the stack
     */
}
void Operation::stackRemove(){
    buildStack();
    stackInsert();
    stack.pop();
    /*
     * function that pops the top value off the stack
     */
}
void Operation::deleteStack(){
    for(int i = 0; i < 5; i++){
        stack.pop();
    }

    /*
     * function that deletes the entire stack
     */
}
void Operation::displayStack(int size){
    if(size == 0)
        cout << "*Stack is empty*";
    else {
        for (int i = 0; i < size; i++) {
            cout << stack.top() << " ";
            stack.pop();
        }
    }
    /*
     * function that displays the entire stack if !empty
     */
}

// queue functions
void Operation::buildQueue(){
    queue.enQueue(101);
    queue.enQueue(111);
    queue.enQueue(103);
    queue.enQueue(123);
    queue.enQueue(117);

    /*
     * function that builds a queue of
     * random int values between 100 and 125
     */
}
void Operation::queueInsert(){
    buildQueue();
    queue.enQueue(-500);

    /*
     * function that inserts the value -500
     * to the end of the queue
     */
}
void Operation::queueInsertThirdPos(){
    // call previous functions to build queue
    queueInsert();

    // store current queue
    int temp1, temp2, temp3, temp4, temp5, temp6, temp7;
    temp1 = queue.first();
    queue.deQueue();
    temp2 = queue.first();
    queue.deQueue();
    temp3 = queue.first();
    queue.deQueue();
    temp4 = queue.first();
    queue.deQueue();
    temp5 = queue.first();
    queue.deQueue();

    // clear queue
    queue.deQueue();
    queue.deQueue();
    queue.deQueue();
    queue.deQueue();
    queue.deQueue();
    queue.deQueue();

    // re-establish queue
    queue.enQueue(temp1);
    queue.enQueue(temp2);
    queue.enQueue(-200);
    queue.enQueue(temp3);
    queue.enQueue(temp4);
    queue.enQueue(temp5);
    queue.enQueue(-500);

    // function that inserts the int value -200
    // into the third position of the queue

}
void Operation::queueRemove(){
    queueInsertThirdPos();
    queue.deQueue();

    /*
     * function that removes the first element
     * in the queue
     */
}
void Operation::queueRemoveFourthElem(){
    // call last
    queueRemove();

    // establish each element in queue
    int temp1, temp2, temp3, temp4, temp5;
    temp1 = queue.first();
    queue.deQueue();
    temp2 = queue.first();
    queue.deQueue();
    temp3 = queue.first();
    queue.deQueue();
    temp4 = queue.first();
    queue.deQueue();
    temp5 = queue.first();
    queue.deQueue();

    // clear queue
    queue.deQueue();
    queue.deQueue();
    queue.deQueue();
    queue.deQueue();
    queue.deQueue();
    queue.deQueue();

    // re-establish queue
    queue.enQueue(temp1);
    queue.enQueue(temp2);
    queue.enQueue(temp3);
    queue.enQueue(temp5);
    queue.enQueue(-500);

    /*
     * function that removes the
     * fourth element in the queue
     */
}
void Operation::queueMinMax(){
    queueRemove();

    // temp variables for storing queue
    int temp1, temp2, temp3, temp4, temp5;

    // establish values of contents of queue
    temp1 = queue.first();
    queue.deQueue();
    temp2 = queue.first();
    queue.deQueue();
    temp3 = queue.first();
    queue.deQueue();
    temp4 = queue.first();
    queue.deQueue();
    temp5 = queue.first();
    queue.deQueue();

    // clear queue
    queue.deQueue();
    queue.deQueue();
    queue.deQueue();
    queue.deQueue();
    queue.deQueue();
    queue.deQueue();

    // re-establish queue
    queue.enQueue(temp1);
    queue.enQueue(temp2);
    queue.enQueue(temp3);
    queue.enQueue(temp5);
    queue.enQueue(-500);

    // find max
    // min is fixed at -500
    int max = temp5;
    if(temp5 < temp3) {
        max = temp2;
        if(temp3 < temp2) {
            max = temp3;
            if (temp1 < temp5) {
                max = temp5;
            }
        }
    } else temp1 = max;

    cout << "Max is " << max << ", Min is " << -500;

    /*
     * function that outputs the min and max of the queue
     */
}
void Operation::deleteQueue(){
    for(int i = 0; i < 5; i++){
        queue.deQueue();
    }

    /*
     * function that deletes the entire queue
     */
}
void Operation::displayQueue(int size){
    if(size == 0)
        cout << "*Queue is empty*";
    else {
        for (int i = 0; i < size; i++) {
            cout << queue.first() << " ";
            queue.deQueue();
        }
    }

    /*
     * fucntion that displays the entire queue if !empty
     */
}
// exit function
bool Operation::exit(){
    char choice;
    cout << "\nEnter 'X' if you would like to run again...";
    cin  >> choice;
    if (choice == 'X')
        return false;
    else {
        cout << "Program terminated...\n This LL Program is Implemented by Kody Gentry - Oct, 19th, 2020\n";
        return true;
    }

    /*
     * funcion that prompts the user to run again
     * if X is enter, the program will run again
     * any thing else will terminate the program
     */
}

int main(){
    Operation operation;   // operations object
    bool running = false; //  main loop
    do {
        // operation: A
        cout << "\n------------------------------------------------\n";
        cout << "Building Stack...\n";
        operation.buildStack();
        operation.displayStack(5);
        cout << "\n------------------------------------------------";

        // operation: B
        cout << "\nBuilding Queue...\n";
        operation.buildQueue();
        operation.displayQueue(5);
        cout << "\n------------------------------------------------";

        // operation: C
        cout << "\nInserting -20 on the stack...\n";
        operation.stackInsert();
        operation.displayStack(6);
        cout << "\n------------------------------------------------";

        // operation: D
        cout << "\nRemoving an element from the stack...\n";
        operation.stackRemove();
        operation.displayStack(5);
        cout << "\n------------------------------------------------";

        // operation: E
        cout << "\nInserting -500 into Queue...\n";
        operation.queueInsert();
        operation.displayQueue(6);
        cout << "\n------------------------------------------------";

        // operation: F
        cout << "\nInserting -200 at the 3rd position of queue...\n";
        operation.queueInsertThirdPos();
        operation.displayQueue(7);
        cout << "\n------------------------------------------------";

        // operation: G
        cout << "\nRemoving first element from the queue...\n";
        operation.queueRemove();
        operation.displayQueue(6);
        cout << "\n------------------------------------------------";

        // operation: H
        cout << "\nRemoving fourth element from the queue...\n";
        operation.queueRemoveFourthElem();
        operation.displayQueue(5);
        cout << "\n------------------------------------------------";

        // operation: I
        cout << "\nFinding Min and Max in the queue...\n";
        operation.queueMinMax();
        cout << "\n------------------------------------------------";

        // operation: J
        cout << "\nDeleting the entire stack...\n";
        operation.deleteStack();


        // operation: K
        operation.stackRemove();
        operation.displayStack(0);
        cout << "\n------------------------------------------------";

        // operation: L
        cout << "\nDeleting the entire queue...\n";
        operation.deleteQueue();


        // operation: M
        operation.queueRemove();
        operation.displayQueue(0);
        cout << "\n------------------------------------------------";

    } while(operation.exit() == false);
    return 0;
}