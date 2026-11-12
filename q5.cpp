
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

class MyQueue
{
private:
    stack<int> s1;              //stack using stl 
    stack<int> s2;

        void transfer()
    {
        while(!s1.empty())   //
        {
            s2.push(s1.top());  //push entire s1 onto s2 which reverses the order of the stack
            s1.pop();
        }
    }

public:
    
    void push(int x)
    {
        s1.push(x);           
    }

    void pop()
    {
        if(s2.empty())
        {
            transfer();
        }

        s2.pop();
    }

     int front()
    {
        if(s2.empty())
        {
            transfer();
        }

        return s2.top();
    }

                                    // Check if the queue is empty
    bool empty()
    {
        return s1.empty() && s2.empty();
    }

                                    // Display elements from front to back
    void show()
    {
        if(empty())
        {
            cout << "Queue(front->back): [EMPTY]" << endl;
            return;
        }

        stack<int> temp1 = s1;                 
        stack<int> temp2 = s2;
        stack<int> temp3;

        bool first = true;

        cout << "Queue(front->back): ";

        while(!temp2.empty())           // s2 is already in front-to-back order
        {
            if(!first)
            {
                cout << " -> ";
            }

            cout << "["<< temp2.top()<< "]";
            temp2.pop();
            first = false;
        }

        while(!temp1.empty())// Reverse s1 so the oldest element comes first
        {
            temp3.push(temp1.top());
            temp1.pop();            
        }

        while(!temp3.empty())           
        {
            if(!first)
            {
                cout << " -> ";
            }

            cout << "[" << temp3.top() << "]";
            temp3.pop();
            first = false;
        }

        cout << endl;
    }
};

int main()
{
    MyQueue q;

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
        else if(command == "PUSH")
        {
            int x;
            ss >> x;

            q.push(x);

            cout << "OK PUSH " << x << endl;
        }
        else if(command == "POP")
        {
            if(q.empty())
            {
                cout << "Error: queue is empty." << endl;
            }
            else
            {
                int x = q.front();
                q.pop();

                cout << "POP " << x << endl;
            }
        }
        else if(command == "FRONT")
        {
            if(q.empty())
            {
                cout << "Error: queue is empty." << endl;
            }
            else
            {
                cout << "FRONT " << q.front() << endl;
            }
        }
        else if(command == "SHOW")
        {
            q.show();
        }
        else if(command == "EMPTY")
        {
            if(q.empty())
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
    }

    return 0;
}
