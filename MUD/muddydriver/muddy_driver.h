#ifndef MUDDY_DRIVER_H
#define MUDDY_DRIVER_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "../data.h"

using namespace std; 

class MuddyDriver {
    
public:    

    explicit MuddyDriver(Room * rooms) : solution() {
        this->rooms = rooms;
    }

    virtual bool solve(int startingRoom, int finishingRoom) = 0;

    vector<Directions> getSolution();
 
protected:
    Room * rooms;
    vector<Directions> solution; 
    vector<Directions> moves = {NORTH, SOUTH, EAST, WEST }; 
};

#endif //BASE_MUD_DRIVER_H
