#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "move.h"
#include "pokemon.h"
#include "json11.hpp"
#include "team.h"
#include "battle.h"
#include "load_pson.h"
#include "gym.h"

using namespace std;
using json = json11::Json;

// Function to get and validate user input.
int getInput() {
    int input;
    while (true) {
        cout << "Enter your choice: ";
        if (!(cin >> input)) {  // Check for end of input stream
            if (cin.eof()) {
                cout << "End of input reached.\n";
                exit(0);
            } else {
                cin.clear();    // Clear error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input
                cout << "Invalid input. Please enter an integer.\n";
            }
        } else {
            cout<<endl;
            break;
        }
    }
    return input;
}

/**
 * Prompts the user to select a Pokémon type from a predefined list.
 * Updates the passed selectedType reference with the user's choice.
 *
 * @param selectedType Reference to a string where the selected Pokémon type will be stored.
 * @return True if a valid type is selected, false otherwise (indicating an invalid selection or out of range choice).
 */
bool selectPokemonType(string& selectedType) {
    // Array of available Pokémon types for selection
    string types[] = {"", "Normal", "Fire", "Water", "Electric", "Grass", "Rock"};
    
    // Display the types to the user
    cout << "Choose Type:\n";
    for (int i = 1; i < 7; i++) {
        cout << i << ". " << types[i] << "\n";
    }

    /** CODE: Call the getInput() function to get the user's choice */
    

    /** CODE: Check if the choice is invalid return false (see for loop for valid range of values.) 
     *        Otherwise, update selectedType 
     */

    return false;
}


/**
 * Selects a Pokémon of the specified type from a list of available Pokémon.
 *
 * Displays the available Pokémon of the specified type and prompts the user to select one.
 * If a valid choice is made, returns the selected Pokémon.
 *
 * @param selectedType The type of Pokémon to select.
 * @param pokemonList A vector containing pointers to available Pokémon.
 * @return the selected Pokémon or nullptr if no valid choice was made.
 */
shared_ptr<Pokemon> selectPokemonFromType(const string& selectedType, vector<shared_ptr<Pokemon>>& pokemonList) {
    cout << "Select your " << selectedType << " type Pokemon:\n";

    /** CODE:   Display the pokemon of the selected Type for the user to select 
     *          The displayed list must start at 1
     *          The display when Grass is the selected type will start off with 
     *           1. Bulbasaur
     *           2. Ivysaur ...
     */    
    
    /** CODE: Call the getInput() function to get the user's choice **/
    
    /** CODE: return the chosen pokemon */
    
    // If no valid choice was made, return nullptr
    return nullptr;
}

/**
 * Allows the user to select up to 4 moves for a specified Pokémon from a list of available moves.
 * This function displays moves of the Pokémon's type and the "Normal" type, then lets the user choose up to 4 move,
 * ENSURING no duplicates are selected. 
 * 
 * @param selectedPokemon A reference to a unique pointer pointing to the selected Pokémon.
 * @param movesList A vector containing all available moves.
 * @param selectedType The type of the selected Pokémon.
 */
void selectMovesForPokemon(shared_ptr<Pokemon>& selectedPokemon, const vector<Move>& movesList, const string& selectedType) {
    cout << "Choose up to 4 moves for " << selectedPokemon->getName() << " (enter 0 to exit early):\n";

    /** CODE:   Display the moves of the selectedType and of Normal type for the user to select
     *          The display should use a single loop and print the moves in the order they 
     *          appear in the moves.json.
     *          The displayed list must start at 1
     *          The display will look something like 
     *           1. Thunder
     *           2. Thunder Punch ...
     */

    
    /** CODE:   only allow the user to select up to 4 moves 
     *          Allow the user to enter a selection from the list above 
     *          If move already selected then show error message SELECTED_MOVE_NAME << " move #" << USER_CHOICE << " is already selected, please select a different move" << endl;
     *          If valid choice and not previously selectedthen 
     *              add the move to the selectedPokemon
     *              Print: "Your Pokemon, " << selectedPokemon->getName() << ", learned " << NAME_OF_MOVE << endl;
     *          If otherwise invalid choice then print "Invalid move selected, please try again" << endl;
     *          if user enters 0 exit the loop
     */
        
    /** CODE:   If no moves are selected "No moves selected for " << selectedPokemon->getName() << endl */
    /** CODE:   If more than 1 move is selected then print  "Selection complete. " << selectedPokemon->getName() << " now knows " << NUM_MOVES_SELECTED << " move(s)." << endl */
    
}

/**
 * @brief Adds a Pokémon with selected moves to the user's team.
 *
 * This function walks the user through selecting a Pokémon type, choosing a Pokémon of that type,
 * selecting up to four moves for it, and then attempting to add this Pokémon to their team.
 *
 * @param team Pointer to the user's team.
 * @param pokemonList List of all available Pokémon.
 * @param movesList List of all available moves.
 * @return True if the Pokémon is successfully added, false otherwise (e.g., team is full).
 * 
 */
bool addPokemonToTeam(Team* team, vector<shared_ptr<Pokemon>>& pokemonList, const vector<Move>& movesList) {
    /** CODE: Generally, select a type, select a pokemon from that type, select its moves, then add to the team but return false if unsuccesful
     *        If team is full "Team is full. Cannot add more Pokémon.\nTry removing a Pokemon.\n\n" and return false
     *        Select the type of Pokemon to add, if the selection fails then the add fails (use selectPokemonType)
     *        Select a Pokemon based on the type, if no Pokemon is selected then the add fails (use selectPokemonFromType)
     *        Select the pokemonList moves (use selectMovesForPokemon)
     *        Do not allow duplicate moves to be added  
     *        Add the Pokemon to the team, if successful then print "Successfully added " << selectedPokemon->getName() << " to your team!" << endl; and return true
     */
    
    return false;
}

/**
 * Allows the user to remove a Pokémon from their team by selecting from a printed list of current team members.
 * It ensures the selection is valid and returns true if the removal is successful, false otherwise.
 *
 * @param team A pointer to the Team object representing the player's team.
 * @return True if the removal is successful, false otherwise.
 */
bool removePokemonFromTeam(Team* team) {

    /** CODE: if the team has 0 members, print the error mesage "No Pokemon to remove" and return false */

    cout << "Choose a Pokemon to Remove:\n";
    /** CODE: Print your team. (HINT: team has a printTeam function) */
    
    /** CODE:   Prompt for input to select a Pokémon to remove by calling the getInput() function.
     *          subtract 1 from choice to line up with 0-based list
     *          Validate the chosen number is within the valid range
     */
    
    /** CODE:   Attempt to remove the selected Pokémon from the team using the relevant method.
     *          If removal is successful, print "Successfully removed {pokemon name}" and return true.
     *          If removal fails, print "Failed to remove the Pokémon." and return false.
     */
    
    return false;
}

/**
 * @brief Main entry point for Pokémon Joust: CSE 240 Gym Edition.
 *
 * Features:
 * - Load movesList and Pokémon from JSON files.
 * - Manage a Pokémon team, allowing the user to view, add, or remove Pokémon.
 * - Engage in battles against random opponents or specific gym leaders.
 * - Persist team changes to a file.
 * @return int Returns 0 on successful execution.
 *
 * @note Students are not required to modify this function.
 */

void pokemonMenu() {
    vector<Move> movesList = loadMoves("moves.json");
    vector<shared_ptr<Pokemon>> pokemonList = loadPokemon("pokemon.json");

    // Instantiate a team object and load tem
    string filename = "team.json";
    Team *team = new Team();
    team->loadTeam(filename, pokemonList, movesList);

    // Instantiate a battle object to fight a random Pokémon
    Battle *battle = new Battle();

    int choice;
    do {

        cout << "---------\n" << "MAIN MENU\n" << "---------\n";
        cout << "1. Show Pokemon\n";
        cout << "2. Choose Pokemon\n";
        cout << "3. Remove Pokemon\n";
        cout << "4. Battle Random\n";
        
        cout << "6. Exit\n";

        choice = getInput();

        switch(choice) {
            case 1:
                // Print your team
                cout << "Your Pokemon:" << endl;
                team->printTeam();
                break;
            case 2:
                // Add Pokémon to team
                if (addPokemonToTeam(team, pokemonList, movesList)) {
                    team->writeTeam(filename);
                }
                break;
            case 3:
                // Remove Pokémon from team
                if (removePokemonFromTeam(team)) {
                    team->writeTeam(filename);
                }
                break;
            case 4:
                // Enter the battle loop with a random Pokémon.
                battle->start(team, pokemonList, movesList);
                break;
            
            case 6:
                // Quit
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice!=6);

    delete(team);
    delete(battle);
 
}