
#include <string>


/*
   Partial Modfication Needed, where uncommented 
*/
class Train {
public:
    int id; // do not modify this line
    std::string cargoName;
    int percentFull;
    bool isUnloaded;

    Train(int id, std::string cargoName, int percentFull);
    void unloadCargo(); // do not modify this line
};
