//
// Created by Meseret Mengistie on 6/27/23.
//

#include "Train.h"

int main(){

  string cName = "Train";//
  int id = 1;
  double percent = 50;
  // creat a train class


  Train train(id,cName,percent);
  //cout<< "a train object created with variables cName, id, and percent passed"<<endl;
  cout<<"Train class function test begines=====================\n"<<endl;
  cout<<"\n1st test try removing a car from an empty class"<<endl;
  cout<<"result: ";
  train.removeCar();

  //insert a car class to our empty train
  cout<<"\n2nd test try inserting a car to an empty train"<<endl;
  train.insertCar();
  cout<<"a car inserted, therefore train size is "<<train.tLength<<endl;

  //insert a car class to our non empty train
  cout<<"\n3rd test try inserting another car to a train "<<endl;
  train.insertCar();
  cout<<"a car inserted, therefore train size is "<<train.tLength<<endl;

  //remove a car from non empty class
  cout<<"\n4th test try removing a car from an empty class"<<endl;
  cout<<"size before removing: "<<train.tLength<<endl;
  train.removeCar();
  cout<<"size after: "<<train.tLength<<endl;
  train.removeCar();
  cout<<"removed another car. size: "<<train.tLength<<endl;

  //uploading a number of cars with quantity of items to out train
  cout<<"\n4th test loading 5 cars with quantity of items to out train"<<endl;
  train.loadCargo(5);
  cout<< "cars loaded, size: "<<train.tLength<<endl;

  //calculate the percent of how full the train is
  cout<<"\n5th test calculate the percent of how full the train is"<<endl;
  cout<<"percent output: "<<train.prcCalculator()<<endl;

  //generate train type
  cout<<"\n6th test use random number generator(1-2) to get a train type "<<endl;
  cout<<"output: "<<train.trainTypeGen(train.rndNun(1,2))<<endl;

  cout<<"\n7th test use invalid number(not 1 0r 2) to get a train type "<<endl;
  cout<<"output: "<<train.trainTypeGen(3)<<endl;

  //generate random numbers
  cout<<"\n8th test random generator for a =-1 and  b=5 "<<endl;
  for(int i=0;i<3;i++){
      cout<<train.rndNun(-1,5)<<endl;
  }
  cout<<"test by switching the values of a and b"<<endl;
    for(int i=0;i<3;i++){
        cout<<train.rndNun(5,-1)<<endl;
    }

  //unload train
  cout<<"\n9th test unloading a train "<<endl;
  train.unloadCargo();
  cout<<"function unloadCargo loads the train with random amount of cars using the function loadCargo, "
        "rndNun function, and decides the train type by calling type genretor, and calculats the percentFull"
        "calling prcCalculator;"
        <<endl;

  cout<<"=============================================end of test.";


    return 0;
}