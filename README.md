[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/cwqRHL62)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=11328171&assignment_repo_type=AssignmentRepo)
# project_1

You have been tasked by the train yard from the image to enhance their basic train system by implementing advanced control and monitoring capabilities for their trains. Currently, the train company has limited information, such as the time it takes for trains to unload, the cargo content, and the level of fullness. They desire more details, specifically the quantity of passengers or the amount of material in each train car.

To this end, you will need to modify the existing code so that when a train unloads  cargo, the passenger count or material quantity for each individual car is printed. Additionally, the code should print the final number of train cars processed once all the cargo has been unloaded.

To complete the project's requirements, you will need to redefine the train class as a linked-list. You have the option to either create your own linked list implementation or use existing one in an include. Each node of the linked list  represents a train car. Note: the engine and caboose should be assumed to be present in every train, but they do not affect the linked list or the car count of the train.

When the trains are created, create a random number of cars in the train, and a random quantity of cargo / passengers, and a random choice of cargo or passenger.

Write test cases only for your implementation of the linked-list.

![image](./trains.png)

to complete this project

1st: I created a Car class in the train class which workes as a node 

2nd: created more variables and functions to my Train class that allowed me to make the class a linked list class
- created functions that help insert and remove cars from the train
- a separate class to loead a certain amount of cars with values to my car
- created a function help choose the type of our train based of a value passed
- created a function that helps generate randome numbers
- made a function that helps calculate the how much the train is full interms of percentage
  - used the total quantity loaded on the train before unloading aginst the total capacity of the train to calculate the function

- the last and the main function of our class is the unloadCargo function which uses all the above functions to help us give a detail information about our train. 
    - as the train is ready to unload the function prints out the name, type, and fullness (in percent) of the train
    - as it unloads it gives us the detail every car in the train and remove each one of them from the train
    - and after unloading evry one of the cars it gives prints out the total amount of cars the train had
    
3rd. we have the constructor class to creat a new object of and a destructor that helps us clean the allocated memories.

