#include <thread>
#include <iostream>
#include <iterator>
#include "TrainYard.h"


/*
    Do not modify this function
*/
std::thread RailTrack::addTrain(Train train) {
    train_queue_lock.lock();
    trains.push(train);
    Train& lastTrain = trains.back();
    train_queue_lock.unlock();

    return std::thread([this, &lastTrain]() {
        std::lock_guard<std::mutex> lock(station_platform_access);
        lastTrain.unloadCargo();
    });
}


/*
    Do not modify this function
*/
int RailTrack::processTrains() {
    while (!trains.empty() && trains.front().isUnloaded) {
        trains.pop();
        return 1;
    }

    return 0;
}

/*
    Do not modify this function
*/
TrainYard::TrainYard(int processed_trains) : processed_trains(processed_trains) {}

/*
    Do not modify this function
*/
void TrainYard::addTrain(int trackId, Train train) {
    if (trackId >= 0 && trackId < YARD_SIZE) {
        threads.push_back(yard[trackId].addTrain(train));
    }
}

/*
    Do not modify this function
*/
void TrainYard::processYard() {
    // Iterate over the yard array
    for (auto track_iterator = yard.begin(); track_iterator != yard.end(); ++track_iterator) {

        if (track_iterator->processTrains()){
            std::size_t index = std::distance(yard.begin(), track_iterator);
            std::cout << "A train left the platform on track " << index + 1 << std::endl;
            addPocessedTrainToCount();
        }
    }
}

/*
    Do not modify this function
*/
void TrainYard::printStatus() {
    for (int i = 0; i < YARD_SIZE; i++) {
        std::cout << "Track " << i + 1 << ": " << yard[i].trains.size() << " trains\n";
    }
    std::cout << "----\n";
}

/*
    Do not modify this function
*/
int TrainYard::getPocessedTrainCount(){
    return processed_trains;
}

/*
    Do not modify this function
*/
void TrainYard::addPocessedTrainToCount(){
    processed_trains ++;
}