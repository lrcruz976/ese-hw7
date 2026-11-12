
#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <stack>
using namespace std;

void showOrders(queue<string> orders){
    cout<<"Orders: ";                       
    if(orders.empty()){                     //stl operation on order queue
        cout<<"[EMPTY]";
    }
    else{
        while(!orders.empty())
        {                 
            cout<<"["<<orders.front()<<"]";         //prints the first element to go into queue
            orders.pop();                           //removes the first elemont to go into queue
            if(!orders.empty()) cout<<" -> ";
        }
    }
    cout<<endl;
}

int main(){
    list<string> menu;
    queue<string> orders;
    stack<string> served;
    int Q;                              //amount of comands that will be given
    cin>>Q;

    for(int i=0; i<Q; i++){             //loop runs for q loops     
        string command;                 //saves user command
        cin>>command;

        if(command=="MENU_ADD"){
            int pos;
            string item;
            cin>>pos>>item;             

            if(pos<1 || pos>menu.size()+1){
                cout<<"Error: invalid position."<<endl;
            }
            else{
                auto it=menu.begin();
                for(int j=1;j<pos;j++){
                    it++;
                }
                menu.insert(it,item);
                cout<<"OK MENU_ADD "<<item<<" at "<<pos<<endl;     //copy and pasted from the lab doc
            }
        }
        else if(command=="MENU_REMOVE"){
            string item;
            cin>>item;
            bool found=false;

            for(auto it=menu.begin();it!=menu.end();it++){
                if(*it==item){
                    found=true;
                    break;
                }
            }

            if(found){
                menu.remove(item);
                cout<<"OK MENU_REMOVE "<<item<<endl;
            }
            else{
                cout<<"Error: "<<item<<" is not on the menu."<<endl;
            }
        }
        else if(command=="MENU"){
            cout<<"Menu: ";
            if(menu.empty()){
                cout<<"[EMPTY]";
            }
            else{
                for(auto it=menu.begin();it!=menu.end();it++){
                    if(it!=menu.begin()) cout<<" -> ";
                    cout<<"["<<*it<<"]";
                }
            }
            cout<<endl;
        }
        else if(command=="ORDER"){
            string item;
            cin>>item;
            bool found=false;

            for(auto it=menu.begin();it!=menu.end();it++){
                if(*it==item){
                    found=true;
                    break;
                }
            }

            if(found){
                orders.push(item);
                cout<<"OK ORDER "<<item<<endl;
            }
            else{
                cout<<"Error: "<<item<<" is not on the menu."<<endl;
            }
        }
        else if(command=="SERVE"){
            if(orders.empty()){
                cout<<"Error: no orders waiting."<<endl;
            }
            else{
                string item=orders.front();
                orders.pop();
                served.push(item);
                cout<<"SERVE "<<item<<endl;
            }
        }
        else if(command=="ORDERS"){
            showOrders(orders);
        }
        else if(command=="NEWEST"){
            if(orders.empty()){
                cout<<"Error: no orders waiting."<<endl;
            }
            else{
                cout<<"NEWEST "<<orders.back()<<endl;
            }
        }
        else if(command=="LAST"){
            if(served.empty()){
                cout<<"Error: nothing served yet."<<endl;
            }
            else{
                cout<<"LAST "<<served.top()<<endl;
            }
        }
        else if(command=="REFUND"){
            if(served.empty()){
                cout<<"Error: nothing to refund."<<endl;
            }
            else{
                cout<<"REFUND "<<served.top()<<endl;
                served.pop();
            }
        }
        else if(command=="EXIT"){
            break;
        }
    }

    return 0;
}
