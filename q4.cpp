
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node{
    int id;
    Node* next;
};

struct Queue{
    Node* head;
    Node* tail;
};

struct Stack{
    Node* top;
};

void enqueue(Queue& q, int id)
{
    Node* temp = new Node;      //node pointer
    temp->id = id;              // save id
    temp->next = nullptr;       

    if(q.head == nullptr)           //case for if empty queue
    {
        q.head = temp;
        q.tail = temp;
    }
    else
    {
        q.tail->next = temp;       //save mem address of next in current tail
        q.tail = temp;              //change current address
    }
}


bool dequeue(Queue& q, int& id){    //remove thing from queue
    if(q.head == nullptr)           //check if queue is empty
    {
        return false;
    }

    Node* temp = q.head;                 
    id = temp->id;

    q.head = q.head->next;

    if(q.head == nullptr)
    {
        q.tail = nullptr;
    }

    delete temp;
    return true;
}


void push(Stack& s, int id)
{
    Node* temp = new Node;    //allocate mem
    temp->id = id;                  //give pointer id
    temp->next = s.top;                 //new top points to previous top

    s.top = temp;                   //update top
}

bool pop(Stack& s, int& id)
{
    if(s.top == nullptr)
    {
        return false;
    }

    Node* temp = s.top;             //save top address to temp
    id = temp->id;              

    s.top = s.top->next;            //update top

    delete temp;                    //deletw old top
    return true;
}

void showQueue(Queue q)
{
    cout << "Queue: ";
    if(q.head == nullptr)
    {   cout << "[EMPTY]" << endl;      
        return;
    }
     Node* temp = q.head;

    while(temp != nullptr){   
         cout << "[" << temp->id << "]";     //sorts through queue with temp pointer
         if(temp->next != nullptr) {cout << " -> ";}

        temp = temp->next;
    }

    cout << endl;
}

void showStack(Stack s)
{
    cout << "Stack(top->bottom): ";            

    if(s.top == nullptr)                    //check if empty
    {
        cout << "[EMPTY]" << endl;
        return;
    }

    Node* temp = s.top;             //traverse the linked list with a temp pointer

    while(temp != nullptr)
    {
        cout << "[" << temp->id << "]";

        if(temp->next != nullptr)
        {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}


void clearQueue(Queue& q)
{
    int id;
     while(dequeue(q, id))  // Keep removing nodes until the queue is empty
    {
      
    }
}

// Delete all nodes in the stack
void clearStack(Stack& s)
{
    int id;
    while(pop(s, id))// Keep removing nodes until the stack is empty
    {
        
    }
}

int main()              //read user input then use functions
{
    Queue q;
    q.head = nullptr;
    q.tail = nullptr;

    Stack s;
    s.top = nullptr;

    string line;
    string command;

    while(true)
    {
        cout << "> ";

        if(!getline(cin, line))
        {
            break;
        }

        stringstream ss(line);
        ss >> command;

        if(command == "EXIT")
        {
            break;
        }
        else if(command == "ADD")
        {
            int id;
            ss >> id;
            enqueue(q, id);
            cout << "OK ADD " << id << endl;
        }
        else if(command == "PRINT")
        {
            int id;
             if(dequeue(q, id))
            {
                cout << "PRINT " << id << endl;
            }
            else
            {
                cout << "Error: queue is empty." << endl;
            }
        }
        else if(command == "URGENT")
        {
            int id;
            ss >> id;
            push(s, id);
            cout << "OK URGENT " << id << endl;
        }
        else if(command == "PRINT_URGENT")
        {
            int id;
            if(pop(s, id)){
            cout << "PRINT_URGENT " << id << endl;
            }
            else
            {
                cout << "Error: stack is empty." << endl;
            }
        }
        else if(command == "MOVE_ALL")
        {
            int id;
            int count = 0;

            while(dequeue(q, id))           //dequeue then push to stack
            {
                push(s, id);
                count++;
            }

            cout << "OK MOVE_ALL " << count;

            if(count == 1){
                cout << " job" << endl;
            }
            else{cout << " jobs" << endl;}
        }
        else if(command == "SHOW_QUEUE")
        {
            showQueue(q);
        }
        else if(command == "SHOW_STACK")
        {
            showStack(s);
        }
        else if(command == "CLEAR")
        {
            clearQueue(q);
            clearStack(s);

            cout << "OK CLEAR" << endl;
        }
    }

    clearQueue(q);
    clearStack(s);

    return 0;
}
