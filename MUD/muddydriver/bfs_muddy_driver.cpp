#include <queue>
#include <vector>
#include <utility>
#include <map>
#include "bfs_muddy_driver.h"

using namespace std;


/** CODE: backtrack and store the path to the solution vector start at the ending room and trace 
 * backwards to the starting room. If initialized in solve, the starting room in 
 * cameFrom[startingRoomId] will equal -1 Example, the BFS found a path from 
 * the Temple of Mota to the Weapon Shop 
 *     ==> South South East East North
 *
 *                   #1 Temple of Mota        
 *                   (starting point)
 *                         | 
 *                  #5 Temple Square
 *                   (Rubber Duck) 
 *                         |                 #11 Weapon          
 *                         |        Grocer      Shop     
 *                         |          |           |          
 * <---Main-Street----#14 Market---#15 Main---#16 Main ------->
 *                       Square    Street       Street     
 *  
 * This will result in a cameFrom that looks like this 
 * cameFrom[11] = 16
 * cameFrom[16] = 15
 * cameFrom[15] = 14
 * cameFrom[14] = 5
 * cameFrom[5] = 1
 * cameFrom[1] = -1
 *
 * The job of createSolution is to turn that cameFrom 
 * Into a solution that's a vector of directions like this
 * vector<Directions> solution = {'s','s','e','e','n'}
 *  
 * Starting from cameFrom[11] = 16 we try to find the direction 
 * from 16 to 11, look at the map above (NORTH), add NORTH to the solution 
 * vector, and move to the next room (16)
 * cameFrom[16] = 15
 * What direction was moved to get to room 16 from 15? EAST
 * Add EAST to the solution vector and the next room is 14
 * ....
 * We suggest creating a getDirection method that takes the from and to
 * and returns the direction taken to get from X to Y.
 * 
 */
char BFSMuddyDriver::getDirection(int from, int to) {
    if (rooms[from].north == to) return 'n';
    if (rooms[from].south == to) return 's';
    if (rooms[from].east == to) return 'e';
    if (rooms[from].west == to) return 'w';
    return -1; 
}

Directions charToDirection(char direction) {
    if(direction == 'n'){
        return NORTH;
    }else if(direction == 's'){
        return SOUTH;
    }else if(direction == 'e'){
        return EAST;
    }else if(direction == 'w'){
        return WEST;
    }
    
    return NORTH;
}

void BFSMuddyDriver::createSolution(int endingRoomId, map<int,int> cameFrom){
    vector<Directions> tempSolution; 
    int currentRoom = endingRoomId;
    char sol[100];
    int i = 0;


    while (cameFrom[currentRoom] != -1) {
        int previousRoom = cameFrom[currentRoom];
        char direction = getDirection(previousRoom, currentRoom);
        sol[i] = direction;
        i++;
        Directions dir = charToDirection(direction);
        tempSolution.push_back(dir);
        currentRoom = previousRoom;
    }
    cout << "S" << endl;
    
    while(0 <= i){
        cout << sol[i] <<" ";
        i--;
    }
   cout << endl;
    solution.assign(tempSolution.rbegin(), tempSolution.rend());

}

/** CODE: Perform BFS to find the shortest path in the maze.
 *  @return true if path was found and false if it was not 
 */
bool BFSMuddyDriver::solve(int startingRoom, int finishingRoom)  {
    std::map<int,int> cameFrom;
    std::queue<int> queue;
    std::map<int, bool> visited;
    
    queue.push(startingRoom);
    visited[startingRoom] = true;
    cameFrom[startingRoom] = -1;

    /** CODE:   Loop through the queue until it's empty 
     *              Explore each exit in order of the Directions in this->moves
     *              If a valid direction and not previously visited mark it
     *              If newest location is the target destination then create the solution and return true
     *          If exiting the loop normally then no path was found to destination
    */
    
     while (!queue.empty()) {
        int currentRoom = queue.front();
        queue.pop();

        // Check if we reached the target room.
        if (currentRoom == finishingRoom) {
            createSolution(finishingRoom, cameFrom);
            return true;
        }

        for (auto move : moves) {

            int nextRoom;
            if(move=='n'){
            nextRoom = rooms[currentRoom].north;
            }else if(move=='s'){
                nextRoom = rooms[currentRoom].south;
            }else if(move=='e' ){
                nextRoom = rooms[currentRoom].east;
            }else if(move=='w'){
                nextRoom = rooms[currentRoom].west;
            }

            if (nextRoom != -1 && !visited[nextRoom]) {
                queue.push(nextRoom);
                visited[nextRoom] = true;
                cameFrom[nextRoom] = currentRoom;
            }
        }
    }

    return false;
}

