#ifndef BFS_MUD_DRIVER_H
#define BFS_MUD_DRIVER_H
#include<string>
#include<vector>
#include<map>
#include "muddy_driver.h" 
#include "../data.h"

using namespace std;
Directions charToDirection(char direction);
class BFSMuddyDriver : public MuddyDriver {
private:
    void createSolution(int endingRoomId, map<int,int> cameFrom);    
public:
    
    BFSMuddyDriver(Room * rooms ) : MuddyDriver(rooms) {}
    
    char getDirection(int from, int to);
    bool solve(int startingRoom, int finishingRoom) override;


};

#endif