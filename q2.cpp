
#include <iostream>
using namespace std;

struct Passenger{
    int id;
    Passenger* next;
};

class CheckInLine{
private:
    Passenger* head;
    Passenger* tail;
    int count;

public:
    CheckInLine(){          //declares empty linked list
        head=nullptr;
        tail=nullptr;
        count=0;
    }

    ~CheckInLine(){
        clear();
    }

    void join(int id){                     
        Passenger* p=new Passenger;         //allocate memory foe new passenger
        p->id=id;                           //give passenger id
        p->next=nullptr;                    //nothing comes after so it just gets null ptr as next

        if(head==nullptr){                  //case fo empty queue
            head=p;
            tail=p;
        }
        else{
            tail->next=p;                   //tail pointer points to new tail
            tail=p;                         //current tail updates to new tail
        }
        count++;
    }

    bool serve(int& id){                    //this just pops the head off the queue
        if(head==nullptr){
            return false;           
        }

        Passenger* temp=head;               //temp pointer now points to the same thing head points to
        id=temp->id;                       
        head=head->next;

        if(head==nullptr){
            tail=nullptr;
        }

        delete temp;
        count--;
        return true;
    }

    void show() const{              //prints out the stuff
        cout<<"Line: ";

        if(head==nullptr){
            cout<<"[EMPTY]";
        }
        else{
            Passenger* temp=head;

            while(temp!=nullptr){
                cout<<"["<<temp->id<<"]";

                if(temp->next!=nullptr){
                    cout<<" -> ";
                }

                temp=temp->next;
            }
        }
        cout<<endl;
    }

    void reverse(){
        Passenger* prev=nullptr;            //3 pointer method for reversing linked list
        Passenger* current=head;
        Passenger* nextNode=nullptr;

        while(current!=nullptr){        
            nextNode=current->next;
            current->next=prev;
            prev=current;
            current=nextNode;
        }

        tail=head;
        head=prev;
    }

    bool removeAt(int index){           //func removes passenger at index
        if(index<0 || index>=count){
            return false;
        }

        if(index==0){                       //if index ==0 its the same as just popping the head off and doing nothing else  
            Passenger* temp=head;
            head=head->next;

            if(head==nullptr){
                tail=nullptr;
            }

            delete temp;
            count--;
            return true;
        }

        Passenger* temp=head;

        for(int i=0;i<index-1;i++){         //search for the passenger that comes before the index
            temp=temp->next;
        }

        Passenger* toDelete=temp->next;             //toDelete points to whats being deleted now
        temp->next=toDelete->next;    //links the passenger befor todelete to passenger after todelete

        if(toDelete==tail){                 
            tail=temp;
        }

        delete toDelete;
        count--;
        return true;
    }

    void clear(){
        while(head!=nullptr){       
            Passenger* temp=head;
            head=head->next;
            delete temp;
        }

        tail=nullptr;
        count=0;
    }
};

int main(){
    CheckInLine line;
    int Q;
    cin>>Q;

    for(int i=0;i<Q;i++){
        string command;
        cin>>command;

        if(command=="JOIN"){
            int id;
            cin>>id;
            line.join(id);
            cout<<"OK JOIN "<<id<<endl;
        }
        else if(command=="SERVE"){
            int id;
            if(line.serve(id)){
                cout<<"SERVE "<<id<<endl;
            }
            else{
                cout<<"Error: line is empty"<<endl;
            }
        }
        else if(command=="SHOW"){
            line.show();
        }
        else if(command=="REVERSE"){
            line.reverse();
            cout<<"OK REVERSE"<<endl;
        }
        else if(command=="REMOVE"){
            int index;
            cin>>index;

            if(line.removeAt(index)){
                cout<<"OK REMOVE idx="<<index<<endl;
            }
            else{cout<<"Error: invalid index"<<endl;}
        }
        else if(command=="CLEAR"){
            line.clear();
            cout<<"OK CLEAR"<<endl;
        }
    }

    return 0;
}
