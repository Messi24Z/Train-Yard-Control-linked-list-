#include <array>
#include <queue>
#include <vector>
#include <thread>
#include <mutex>
#include "Train.h"

#define YARD_SIZE 5
#define SCHEDULED_TRAINS 20


/*
    Do not modify this class declaration
*/
class RailTrack {
public:

    std::queue<Train> trains;
    std::mutex station_platform_access;
    std::mutex train_queue_lock;

    std::thread addTrain(Train train);
    int processTrains();
};

/*
    Do not modify this class declaration
*/
class TrainYard {
    int processed_trains;
public:
    std::array<RailTrack, YARD_SIZE> yard;
    std::vector<std::thread> threads;
    void addTrain(int trackId, Train train);
    void processYard();
    void printStatus();
    int getPocessedTrainCount();
    void addPocessedTrainToCount();

    TrainYard(int processed_trains);

};
