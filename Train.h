
//
// Created by Meseret Mengistie on 6/13/23.
//
#include <iostream>
#include <string>


using namespace std;

const int MAX_NUM_OF_PASSENGERS = 40;
const int MIN_NUM_OF_PASSENGERS = 0;
const int MAX_NUM_OF_TRUCKLOADS = 4;
const int MIN_NUM_OF_TRUCKLOADS = 0;
const int MIN_CARS =0;
const int MAX_CARS =20;

/*
 * a node class called Train car
 * has two variables amount in the car and a pointer to the next car
 * has getter ans setter functions that help accessing the private members
 * */


class TrainCar{
      int amount;
      TrainCar* next;
public:
    //default constructor, creates a car object
    TrainCar(){
        amount =0;
        next = nullptr;
    }
    //sets n as the next car
    void setNext(TrainCar* n){
        next= n;
    }
    // gets the next object
    TrainCar* getNext(){
        return  next;
    }
    // sets the amount of the car to num
    void setAmount(int num){
        amount= num;
    }
    //gets the amount of a car
    int getAmount(){
        return amount;
    }
};

/*
   Partial Modfication Needed, where uncommented
*/
class Train {
    
    TrainCar* head;
    TrainCar* tail;

public:
    int tLength;
    int id; // do not modify this line
    std::string cargoName;
    int percentFull;
    bool isUnloaded;
    int carsUnloaded;
    string trainType;

    Train(int id, std::string cargoName, int percentFull);//constructor
    ~Train();//destructor
    void unloadCargo(); // do not modify this line
    void insertCar();//inserts car
    void removeCar();//removes car
    void loadCargo(int num);// loads train
    double prcCalculator();//calculates a the percetFull
    int rndNun(int a, int b);//generates random num
    string trainTypeGen(int num);//returns the type of the trainType
};