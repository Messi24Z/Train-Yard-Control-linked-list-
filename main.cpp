#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <iostream>
#include "TrainYard.h"


int main() {
    std::srand(std::time(0));// DO NOT MODIFY THIS LINE 

    int trains_processed = 0;// DO NOT MODIFY THIS LINE 
    TrainYard yard(trains_processed);// DO NOT MODIFY THIS LINE 


    for (int i = 0; i < SCHEDULED_TRAINS; i++) {
        int trackId = std::rand() % YARD_SIZE; // DO NOT MODIFY THIS LINE 
        int id = i + 1; // DO NOT MODIFY THIS LINE 
        std::string cargoName = "Cargo " + std::to_string(id); // MODIFY AS NEEDED
        int percentFull = std::rand() % 101; // MODIFY AS NEEDED
        Train train(id, cargoName, percentFull); // MODIFY AS NEEDED

        yard.addTrain(trackId, train);// MODIFY AS NEEDED

        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // DO NOT MODIFY THIS LINE 
        yard.processYard(); // DO NOT MODIFY THIS LINE 
        yard.printStatus(); // DO NOT MODIFY THIS LINE 
    }

    std::cout << "Finished Scheduled train travels, Checking platforms to see if trains have cleared the station so the station can close..." << std::endl;// DO NOT MODIFY THIS LINE 

    while (yard.getPocessedTrainCount() != SCHEDULED_TRAINS){// DO NOT MODIFY THIS LINE 
        std::cout << "Waiting for trains to clear the platform..." << std::endl;// DO NOT MODIFY THIS LINE 

        yard.processYard(); // DO NOT MODIFY THIS LINE 
        yard.printStatus(); // DO NOT MODIFY THIS LINE 
        
        std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // DO NOT MODIFY THIS LINE 
    std::cout << "Trains Processed: " << yard.getPocessedTrainCount() << "\nTrains scheduled: " <<  SCHEDULED_TRAINS << std::endl;// DO NOT MODIFY THIS LINE 
    }

    for (std::thread& t : yard.threads) { // DO NOT MODIFY THIS LINE 
        if (t.joinable()) { // DO NOT MODIFY THIS LINE 
            t.join(); // DO NOT MODIFY THIS LINE 
        }
    }



    return 0;
}
