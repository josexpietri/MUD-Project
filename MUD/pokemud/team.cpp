#include "team.h"

using namespace std;
using json = json11::Json;

/**
 * Tries to add a new Pokémon to the team. If the team has not reached its maximum size, then it adds it to the team.
 * This method ensures that the team does not exceed its predefined size limit.
 *
 * @param pokemon A shared pointer to the Pokémon to be added to the team.
 * @return True if the Pokémon is successfully added, false if the team is already at its maximum capacity.
 */
bool Team::addPokemon(const shared_ptr<Pokemon>& pokemon) {
    if (isFull()) {        
        return false;
    }
    /** CODE: insert here and return true*/
    return false;
}


/**
 * Removes a Pokémon from the team based on its index in the team's list. This method ensures that the team can dynamically change its members.
 *
 * @param index The position of the Pokémon in the team's list to be removed.
 * @return True if the Pokémon is successfully removed, indicating the index was within the valid range. False if the index is out of range, indicating no Pokémon was removed.
 */
bool Team::removePokemon(size_t index) {    
    if (index < team.size()) {
        // If the index is valid, erase the Pokémon at that index from the team and return true.
        /** CODE: insert here*/
    }
    // Return false if the index is invalid, meaning no Pokémon is removed.
    return false;
}

/**
 * Determines if the team has reached its maximum capacity.
 *
 * @return True if the team's size equals the maximum team size, indicating the team is full. False otherwise, indicating there's room for more Pokémon.
 */
bool Team::isFull() const {
    // Check if the current team size equals the MAX_TEAM_SIZE.
    /** CODE: insert here*/
    return false; // Placeholder return statement. Replace with the actual condition check.
}


/**
 * Fetches a pointer to a Pokémon in the team based on its position (index) in the team's list.
 * This method facilitates access to specific Pokémon for battle, display, or other purposes.
 *
 * @param index The index of the Pokémon in the team list.
 * @return A pointer to the Pokémon if the index is valid. Returns nullptr if the index is out of range, indicating no Pokémon exists at that position.
 */
 shared_ptr<Pokemon> Team::getPokemon(size_t index) {
    // If the index is within the bounds of the team array, return a pointer to the Pokémon at that index.
    /** CODE: insert here*/
    return nullptr; // Return nullptr if the index is out of bounds.
}


/**
 * Gets the number of Pokémon currently in the team.
 * @return The size of the team.
 */
int Team::getSize() const {
    // Return the number of Pokémon in the team.
    /** CODE: insert here*/
    return -1;
}

// Displays the stats of each Pokémon in the team, numbered in the order they were added.
void Team::printTeam() const {
    if (team.size() == 0) printf("You have no Pokemon in your team");
    for (size_t i = 0; i < team.size(); i++) {
        cout << i+1 << ". ";
        team[i]->displayStats();
    }
    printf("\n");
}

/**
 * Finds a Pokémon by its name in a list and returns the pointer to it.
 * @param pokemonList The list of Pokémon to search through.
 * @param name The name of the Pokémon to find.
 * @return A shared_ptr to the found Pokémon, or nullptr if not found.
 */
shared_ptr<Pokemon> Team::findPokemonByName(vector<shared_ptr<Pokemon>>& pokemonList, string name) {
    // Loop through the given list to find a Pokémon by name and return the pointer to it if found.
    /** CODE: insert here*/
    return nullptr; // Return nullptr if the Pokémon is not found.
}

/**
 * Finds a Move by its name in a list of Moves.
 * @param movesList The list of Moves to search through.
 * @param name The name of the Move to find.
 * @return A pointer to a copy of the found Move, or nullptr if not found.
 */
Move* Team::getMove(const vector<Move>& movesList, string name) {
    /** CODE: Iterate through the list of moves if found, use the copy constructor to create a pointer to a new Move
     *          Move * newMove = new Move(currentMove)
     *          return newMove
     */ 
    
    return nullptr; // Return nullptr if the Move is not found.
}


/**
 * Loads team configuration from a JSON file. This includes creating Pokémon based on their names and assigning their moves from the file.
 * It's a good introduction to parsing JSON data with json11.
 *
 * @param filename The name of the JSON file to load.
 * @param pokemonList A reference to a vector of Pokémon, used to find and clone the specified Pokémon.
 * @param movesList A reference to a vector of available Moves, used to assign moves to the Pokémon.
 * @return True if the team is successfully loaded from the file, false if there are errors or if specific Pokémon/moves cannot be found.
 */
bool Team::loadTeam(const string& filename, vector<shared_ptr<Pokemon>>& pokemonList, const vector<Move>& movesList) {
    string err;
    string fileContents; // You need to load the file content into this string.
    // Example of reading a file into a string (pseudo-code):
    // std::ifstream ifs(filename);
    // std::string fileContents((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    
    /** CODE: read from the JSON file and load into a string */

    // Parse the JSON content
    auto jsonCBs = json::parse(fileContents, err);
    if (!err.empty()) {
        cout << "loadTeam in team.cpp has failed to parse the JSON of " << filename << " because of " << err << endl;
        return false;
    }

    /** CODE: uncomment for loop */
    // Process each Pokémon configuration in the JSON array
    //for (const auto& pm : jsonCBs.array_items()) {
        // Example of accessing a Pokémon's name and moves from the JSON object:
        // string name = pm["name"].string_value();
        // auto movesJson = pm["moves"].array_items();
        shared_ptr<Pokemon> pokemon;
        /** CODE:   Find the Pokémon by name using 'findPokemonByName' and set pokemon to the returned value (using the pokemon variable is required)
         *          For each move in 'movesJson', find the move using 'getMove' and add it to the Pokémon
         *          If any Pokémon or moves are not found, print an error message and return false
         */

        // After processing each Pokémon and its moves, add it to the team
        /** CODE: insert here*/
    //}

    return true; // Return true if all Pokémon and their moves are successfully processed
}


/**
 * Saves the team's composition to a JSON file. Each Pokémon's name and their moves are included.
 * @param filename The name of the file to write the team's composition to.
 *
 * @note Students are not required to modify this function.
 */
void Team::writeTeam(const string& filename) const {
    vector<json> teamJson;

    // Iterates through each team member to create a JSON representation
    for (const auto& member : team) {
        vector<string> moves;
        // Converts each move of the member to a string and stores in a vector
        for (const auto& move : member->getMoves()) {
            moves.push_back(move.getName()); // Gets the name of the move
        }

        // Creates a JSON object for the team member and adds it to the teamJson vector
        teamJson.push_back(json::object {
                {"name", member->getName()}, // Adds the member's name
                {"moves", json(moves)} // Adds the member's moves
        });
    }

    ofstream outFile(filename); // Creates an ofstream to write to the file
    if (outFile.is_open()) {
        json teamArray = json::array(teamJson); // Converts the team vector into a JSON array
        outFile << teamArray.dump(); // Writes the JSON array to the file
        outFile.close();
    } else {
        cerr << "Failed to open " << filename << " for writing.\n";
    }
}


