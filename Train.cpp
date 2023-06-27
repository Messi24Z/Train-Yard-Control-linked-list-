//
// Created by Meseret Mengistie on 6/13/23.
//

#include <thread>
#include <chrono>
#include "Train.h"

// MODIFY AS NEEDED
/** Name:Train(), a constructor for the class Train
 * Desc: creates a Train object
 * Precondition:none
 * Postcondition:none
 * */
Train::Train(int id, std::string cargoName, int percentFull)
        : id(id), cargoName(cargoName), percentFull(percentFull), isUnloaded(false) {
          head = nullptr;
          tail = nullptr;
          tLength = 0;
          carsUnloaded=0;
          trainType = trainTypeGen(rndNun(1,2));

}
/** Name:~Train(), a distructor for the class Train
 * Desc: frees memories allocated in a Train object
 * Precondition:none
 * Postconditions:none
 * */
Train::~Train() {

    while(head!= nullptr){
        removeCar();
    }
    head = nullptr;
    tail = nullptr;
    tLength = 0;
}
/**
 * Name: unloadCargo()
 * Desc: unloads the train, calls the load function before unloading
 * Precondition: there exists a train
 * Postconditions: train unloaded
 * */



void Train::unloadCargo() {
    // give details of the train that is about to be unloaded here

    loadCargo(rndNun(MIN_CARS,MAX_CARS));//

    std::this_thread::sleep_for(std::chrono::seconds(4)); // DO NOT MODIFY THIS LINE
    isUnloaded = true;

    int cars = tLength;
    percentFull = prcCalculator();
    if (percentFull == -1.0){
        cout<<cargoName<<" has no cars to unload"<<endl;
    }else {
        cout << cargoName << " " << percentFull << "% full, trainType:" << trainType << " currently unloading..."
             << endl;
        //string trainName = trainTypeGen(rndNun(1,2));
        for (int i = 0; i < cars; i++) {
            if (trainType == "Passenger")
                cout << "Car" << i + 1 << ": " << head->getAmount() << " passengers" << endl;
            else
                cout << "Car" << i + 1 << ": " << head->getAmount() << " trackloads of material" << endl;
            removeCar();
            carsUnloaded++;
        }
        cout << cargoName << " just unloaded a total of " << carsUnloaded << " cars. it is now empty\n" << endl;

    }
    percentFull = 0;

}
/**
 * Name:insertCar()
 * Desc: inserts car to the train
 * Precondition: there exists a train
 * Postconditions: a new car is now inserted to our train
 * */


void Train::insertCar(){
    TrainCar* Car= new TrainCar();
    if(trainType == "Passenger")
        Car->setAmount(rndNun(MIN_NUM_OF_PASSENGERS,MAX_NUM_OF_PASSENGERS));
    else if(trainType== "Material")
        Car->setAmount(rndNun(MIN_NUM_OF_TRUCKLOADS,MAX_NUM_OF_TRUCKLOADS));
    Car->setNext(nullptr);
    if (head == nullptr){
        head = Car;
        tail = head;
        //tLength=1;
    }else{
        tail->setNext(Car);
        tail= Car;

    }
    tLength ++;
}
/**
 * Name: removeCar()
 * Desc: removes a car from a train
 * Precondition: there need to be at least 1 car in the train
 * Postconditions: car removed
 * */

void Train::removeCar(){


    if (head == nullptr){

        cout<<"there is no car to be removed"<<endl;
    }else

    if(head->getNext()== nullptr){
        //tail=head;
        delete head;
        tail= nullptr;
        head= nullptr;
        tLength = 0;
    }
    else{
        TrainCar* curr = head->getNext();
        delete head;
        head = curr;
        tLength--;
    }


    //cout<<tLength<<endl;
}
/**
 * Name:loadCargo(int num)
 * Desc: loads the cargo adding cars "num" amount of times. uses insertCar function to achieve this task
 * Precondition: train exists
 * Postconditions: train loaded with "num" amount of cars
 * */

void Train::loadCargo(int num){
    for(int i=0; i<num ; i++){
        insertCar();
    }

}
/**
 * Name:rndNun(int a, int b)
 * Desc: generates random numbers
 * Precondition:two integers passed
 * Postconditions: a random number between those numbers returned
 * */

int Train::rndNun(int a, int b){
    int ans = 0;
    if (b>a)
        ans = (rand() % (b-a+1) )+ a;
    else
        ans = (rand() % (a-b+1) )+ b;
    return ans;
}

/**
 * Name:trainTypeGen(int num)
 * Desc: decides the type of the train based on the numbers inserted
 * Precondition: passed number must be only 1 or 2
 * Postconditions:the name of the type of train returned
 * */

string Train::trainTypeGen(int num){
    string name="";
    if(num == 1){
        name = "Passenger";
    }else if(num==2){
        name = "Material";
    }else{
        cout<<"passed number must be 1 or 2"<<endl;
    }
    return name;
}
/**
 * Name:prcCalculator()
 * Desc:calculates how full the trains is interms of train
 * Precondition:there exists a train
 * Postconditions: percent calculation returned
 * */

double Train::prcCalculator(){
    double percent = 0;
    double totalIntrain =0;
    if(tLength==0){
        percent = -1;
    }else{
        TrainCar* curr = head;
        while(curr!= nullptr){
            totalIntrain += curr->getAmount();
            curr = curr->getNext();
        }
        if(trainType=="Passenger"){
            double fullCapacity = tLength * MAX_NUM_OF_PASSENGERS;
            percent = totalIntrain/fullCapacity * 100;
        }else if(trainType == "Material"){
            double fullCapacity = tLength * MAX_NUM_OF_TRUCKLOADS;
            percent = totalIntrain/fullCapacity * 100;
        }

    }
    return percent;

}