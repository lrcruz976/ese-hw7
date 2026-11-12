#include <iostream>
#include <string>
using namespace std;




struct Car {
    int id;
    string plate;
    Car* next;
};


Car createCar(int id, string plate) ;           //list of functions
void parkCar(Car*& top, const Car& newCar);
bool leaveCar(Car*& top, Car& left);
Car peekTop(const Car* top);
void printCars(const Car* top);
void clearCars(Car*& top);

int main() {
    Car* top = nullptr;
    int Q;
    int nextID = 1;

    cout << "Enter number of operations: ";
    cin >> Q;
    cin.ignore();

    cout << "--- Executing Commands ---" << endl;

    for (int i = 0; i < Q; i++) {
        string command;
        getline(cin, command);

        if (command.substr(0, 5) == "PARK ") {
            string plate = command.substr(5);

            Car newCar = createCar(nextID, plate);
            parkCar(top, newCar);

            cout << "[PARK] Parked car #" << nextID
                 << ": " << plate << endl;

            nextID++;
        }
        else if (command == "LEAVE") {
            Car left;

            if (leaveCar(top, left)) {
                cout << "[LEAVE] Car #" << left.id
                     << " left: " << left.plate << endl;
            }
            else {
                cout << "[LEAVE] Lane is empty" << endl;
            }
        }
        else if (command == "PEEK") {
            Car current = peekTop(top);

            if (current.id == -1) {
                cout << "[PEEK] Lane is empty" << endl;
            }
            else {
                cout << "[PEEK] Top car -> #" << current.id
                     << ": " << current.plate << endl;
            }
        }
        else if (command == "SHOW") {
            cout << "[SHOW] Cars (Top->Bottom):" << endl;
            printCars(top);
        }
        else if (command == "CLEAR") {
            clearCars(top);
            cout << "[CLEAR] Lane cleared" << endl;
        }
        else if (command == "EXIT") {
            break;
        }
    }

    cout << "--- Session End ---" << endl;
    cout << "Remaining Cars (Top->Bottom):" << endl;
    printCars(top);
    clearCars(top);

    return 0;
}

//NOTE TO SELF: TOP==HEAD

// 1. Create and return a Car by value
Car createCar(int id, string plate) {
    Car c;
    c.id = id;
    c.plate = plate;
    c.next = nullptr;
    return c;
}

// 2. Push a new car onto the stack
void parkCar(Car*& top, const Car& newCar) {

    Car *temp = new Car;            //create and allocate memory for a new car
    *temp = newCar;     
    temp->next = top;
    top = temp;

    

}


bool leaveCar(Car*& top, Car& left) {
    if(top == nullptr){return false;}

    left = *top;        //save ptr in left
    Car *temp = top;        
    top = top->next;
    delete temp;
    return true;
    


}


Car peekTop(const Car* top) {
     if(top == nullptr){cout << "lot is empty" <<endl; return createCar(-1,"error");}
    
    return *top;
}

// 5. Print cars from top to bottom
void printCars(const Car* top) {

    const Car *p = top;

    while(p != nullptr) {


        cout << p->id << " " << p->plate << endl;
        p = p->next;
    }

}

// 6. Delete all cars and set top to nullptr
void clearCars(Car*& top) {

    while(top != nullptr){
        Car *temp = top;
        top = top ->next;
        delete temp;
    }

}