#include <thread>
#include <chrono>
#include "Train.h"

// MODIFY AS NEEDED
Train::Train(int id, std::string cargoName, int percentFull)
    : id(id), cargoName(cargoName), percentFull(percentFull), isUnloaded(false) {}


/**
    @note NEEDS PARTIAL MODIFICATION
   
*/
void Train::unloadCargo() {
    // give details of the train that is about to be unloaded here

    std::this_thread::sleep_for(std::chrono::seconds(4)); // DO NOT MODIFY THIS LINE 
    isUnloaded = true;
    
    // give details of the train that is about to be unloaded here
    // MODFY FURTHER HERE 
    percentFull = 0;
}
