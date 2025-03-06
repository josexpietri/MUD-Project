#include "battle.h"

using namespace std;
using json = json11::Json;

/**
 * @brief Calculates the total damage of an attack using the Gen 1 Pokémon damage formula.
 *
 * This method incorporates various battle mechanics, including Same-Type Attack Bonus (STAB), type effectiveness, and a randomness factor,
 * to calculate the total damage dealt by an attack. This function implements the following formula: 
 **************************************************************************************************************
 * 
 *                           2*level
 *                         ( ------- + 2 ) * power * (attackStat/defenseStat)
 *                               5
 *          damage = (  -------------------------------------------------  + 2 ) * STAB * damageMultiplier * randomMultiplier
 *                                            50
 *
 ****************************************************************************************************************  
 *
 * @param attackStat The attack stat of the attacking Pokémon.
 * @param defenseStat The defense stat of the defending Pokémon.
 * @param power The power of the used move.
 * @param STAB The Same-Type Attack Bonus, if applicable.
 * @param damageMultiplier The multiplier for type effectiveness.
 * @param randomMultiplier A random multiplier to introduce variability.
 * @return The calculated damage as an integer.
 */
int Battle::calculateDamage(float attackStat, float defenseStat, float power, float STAB, float damageMultiplier, float randomMultiplier) {
        
    // Note: Assume a default level of 9 for the attacking Pokémon.
    float level = 9.0f; 
    
    
    /** CODE:  the damage formula using calculation defined above */
    float damage = 0.0f * level; 

    return static_cast<int>(round(damage));    
}

/**
 * @brief Attempts to apply move damage from the attacker to the defender.
 *
 * This function:
 * - Checks if the move hits based on its accuracy and a random chance.
 * - Calculates the damage taking into account STAB, type effectiveness, and randomness.
 * - Applies the calculated damage to the defender's HP.
 * - Indicates if the defender faints as a result of the attack.
 *
 * @param attacker Pointer to the attacking Pokémon.
 * @param defender Pointer to the defending Pokémon.
 * @param attackersMove Pointer to the move being used.
 * @param rng A reference to an RNG object (std::mt19937), used for generating random numbers for the hit/miss chance and damage variability.
 * @return True if the defender faints as a result of the attack; false otherwise.
 */
bool Battle::applyMoveDamage(shared_ptr<Pokemon> attacker, shared_ptr<Pokemon> defender, Move* attackersMove, RNG& rng) {
    uniform_int_distribution<int> hitMiss(1, 100);   // For determining hit/miss.
    uniform_int_distribution<int> uni(217, 255);     // For random damage multiplier.

    float attackStat = 0.0f, defenseStat = 0.0f;
   
    /** CODE:   We need to get the attackStat for the attacker  and defenseStat for the defender. 
     *          However, there's 2 types, regular attack/defense and special attack/defense
     *          The code will determine the proper one to use based on the attacker's chosen move
     *          If the attacker's move's category is "Physical" then the attackStat is set to the attacker's regular attack
     *          and the defenseStat is set to the defender's regular defense stat.
     *          Otherwise, the getSpAttack and getSpDefense are used. 
     */

    /** CODE:   Calculate the Same Type Attack Bonus (STAB). 
     *          If the attacker's type is of the same type as the attackers's move then set STAB to 1.5f else default to 1.0f. 
     */
    

    /** CODE:   Get the defenders damage multiplier to determine the effectiveness of the attacker's move. */

    // Random factor for damage calculation.
    float randomMultiplier = static_cast<float>(uni(rng)) / 255.0f;

    /** CODE:   Calculate the final damage by calling the calculateDamage function.
     *          The calculation below is just a placeholder to avoid unused variable errors
     *          Remove the formula on the right and replace with a call to calcuateDamage
     */ 
    int damage = 0 * (attackStat + defenseStat + randomMultiplier); // REPLACE ME!!!!!!!!!!!!!!!! (variables included to avoid error message when compiling, this calculation is not correct)

    cout << attacker->getName() << " uses " << attackersMove->getName() << "!" << endl;

    // Apply damage if the move hits.
    if ((hitMiss(rng) % 100 + 1) <= attackersMove->getAccuracy() && attackersMove->usePP()) {
        /** CODE: Apply damage to the defender here.
         *  Ensure HP does not fall below 0 by setting negative values to 0.
         */ 
        
        cout << "\033[38;5;1m" << attacker->getName() << " hits " << defender->getName()  << " for " << damage << "\033[0m" << endl;
    } else {
        // Uses ANSI escape codes to change text color for emphasis. "\033[38;5;1m" sets the color, and "\033[0m" resets it back to default.
        // Experiment with them to add color to terminal output, enhancing the game's visual appeal and immersion.
        cout << "\033[38;5;2mThe move misses!\033[0m" << endl;
    }

    // Check if the defender's HP is 0 or less, indicating fainting, and display a message.
    // Return true to indicate the defender has fainted.
    if (defender->getHP() <= 0) {
        cout << "\033[38;5;208m" << defender->getName() << " fainted!" << "\033[0m" << endl;
        return true; // Defender fainted.
    }
    cout << endl;
    return false; // Defender did not faint.
}

/**
 * @brief Selects a random Pokémon and assigns up to four moves to it.
 *
 * This function performs the following steps:
 * - Randomly selects a Pokémon from the provided vector.
 * - Assigns up to four moves to the selected Pokémon, preferring moves that match the Pokémon's type.
 *
 * @param pokemons A vector of unique pointers to Pokémon, from which one will be randomly selected.
 * @param moves A vector of all available moves that can be assigned to the Pokémon.
 * @param rng A reference to an RNG object (std::mt19937), used to select both Pokémon and moves randomly.
 * @return A raw pointer to the newly created Pokémon instance, with moves assigned. Note: The caller is responsible for managing the returned Pokémon's memory.
 *
 * @note Students are not required to modify this function.
 */
shared_ptr<Pokemon> Battle::getRandomPokemon(vector<std::shared_ptr<Pokemon>>& pokemons, const vector<Move>& moves, RNG& rng) {
    // Generate a random index to select a Pokémon from the vector
    std::uniform_int_distribution<int> pokeDist(0, pokemons.size() - 1);
    // Clone the selected Pokémon to ensure unique instances
    auto randomPokemon = pokemons[pokeDist(rng)];

    // Assign up to four moves to the random Pokémon
    for (int i = 0; i < 4; ++i) {
        std::vector<Move> typeMoves; // Container for moves that match the Pokémon's type
        // Filter moves by matching types
        for (const auto& move : moves) {
            if (move.getType() == randomPokemon->getType()) {
                typeMoves.push_back(move);
            }
        }

        // If there are matching type moves, randomly assign one; otherwise, assign any move
        if (!typeMoves.empty()) {
            std::uniform_int_distribution<> specificMoveDist(0, typeMoves.size() - 1);
            randomPokemon->addMove(typeMoves[specificMoveDist(rng)]);
        } else {
            // Fallback to assigning any move if no type match is found
            randomPokemon->addMove(moves[pokeDist(rng)]);
        }
    }

    // Release the shared_ptr's ownership and return the raw pointer to the Pokémon
    return randomPokemon;
}

/**
 * @brief Prompts the user to select a move for the current Pokémon during battle.
 *
 * Displays the available moves for the selected Pokémon and reads user input to select a move.
 * Ensures the input is valid and within the range of available moves.
 *
 * @param pokemon Pointer to the Pokémon whose move is being selected.
 * @return The index of the selected move, adjusted for 0-based indexing.
 *
 * @note Students are not required to modify this function.
 */
int Battle::selectMove(const shared_ptr<Pokemon> pokemon) {
    int moveChoice = 0;
    cout << "\n" << pokemon->getName() << "'s turn. Choose a move:" << endl;
    pokemon->displayMoves();
    printf("> ");
    while(true) {
        if(!(cin >> moveChoice)) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Invalid input, please enter a number." << endl;
        } else {
            // Clamp the move choice within the valid range of available moves
            moveChoice = max(1, min(moveChoice, static_cast<int>(pokemon->getMoves().size())));
            break; // Exit loop if valid input
        }
    }
    return moveChoice - 1; // Adjust for 0-based index
}


/**
 * @brief Starts the battle between the player's selected Pokémon and a randomly chosen opponent Pokémon.
 *
 * This function manages the main battle loop, adhering to turn-based combat rules. The Pokémon with the higher speed attacks first each turn.
 * A Pokémon faints when its HP drops to 0, at which point the player can switch to another Pokémon, if available. The battle ends when all Pokémon in
 * the player's team have fainted or the opponent's Pokémon faints. This function is provided as-is for students to study and understand the battle mechanics,
 * without the need for modifications.
 *
 * @param team Pointer to the player's team of Pokémon.
 * @param pokemons A vector of unique pointers to Pokémon, representing potential opponents.
 * @param moves A vector containing all moves that Pokémon can learn, used for assigning moves to the randomly selected opponent Pokémon.
 *
 * @note Students are not required to modify this function.
 */
void Battle::start(Team* team, vector<shared_ptr<Pokemon>>& pokemons, const vector<Move>& moves) {

        const char* seed_str = std::getenv("RANDOM_SEED");
    long seed_value = 0;
    // Seed based on environment variable if it exists
    if (seed_str) {
      // Convert string to integer (handle potential conversion errors)
      try {
        seed_value = std::stol(seed_str);
      } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Invalid RANDOM_SEED value. Using default seed." << std::endl;
        seed_value = 0; // Default seed
      } catch (const std::out_of_range& e) {
        std::cerr << "Error: RANDOM_SEED value out of range. Using default seed." << std::endl;
        seed_value = 0; // Default seed
      }
    }
    // Initialize RNG based on seed or random_device
    RNG rng;
    if (seed_value) {
      // Seed with user-provided value
      std::cout << "Using RANDOM_SEED: " << seed_value << std::endl;
      rng.seed(static_cast<unsigned int>(seed_value));
    } else {
      // Seed with random_device (default)
      rng = RNG(random_device{}());
    }

    int currentPokemonIndex = 0; // Index to keep track of the current Pokémon in the player's team
    shared_ptr<Pokemon> pokemon1 = team->getPokemon(currentPokemonIndex); // Player's current Pokémon
    shared_ptr<Pokemon> pokemon2 = getRandomPokemon(pokemons, moves, rng); // Randomly selected opponent Pokémon

    // Distribution for selecting an opponent Pokémon's move
    uniform_int_distribution<size_t> pokemon2MoveDist(0, pokemon2->getMoves().size() - 1); // For selecting pokemon2's move

    cout << "Battle starts between " << pokemon1->getName() << " and " << pokemon2->getName() << "!\n" << endl;

    // Main battle loop
    while (currentPokemonIndex < team->getSize()) {

        // Check if the current Pokémon has fainted
        while (pokemon1->getHP() == 0) {
            currentPokemonIndex++;
            if(currentPokemonIndex < team->getSize()) {
                pokemon1 = team->getPokemon(currentPokemonIndex);
                cout << "\nYou switched to " << pokemon1->getName() << "!\n";
                cout << "\nBattle starts between " << pokemon1->getName() << " and " << pokemon2->getName() << "!\n" << endl;
            } else {
                // All Pokémon in the player's team have fainted
                cout << "All your Pokémon have fainted.\n"
                     << "You scurry back to a Pokémon Center, protecting your exhausted Pokémon from any further harm...\n";
                // Reset the HP of all Pokémon in the team before exiting the battle
                for(int i = 0; i < team->getSize(); i++) {
                    team->getPokemon(i)->resetHP();
                }
                cout << "\033[38;5;153mYour Pokémon are healed!\033[0m\n";
                return;
            }
        }

        pokemon1->displayStats();
        pokemon2->displayStats();

        // Prompt the player to select a move for their Pokémon
        int moveChoice = selectMove(pokemon1);

        // Retrieve the selected moves for both Pokémon
        auto& pokemon1Move = pokemon1->getMove(moveChoice);
        auto& pokemon2Move = pokemon2->getMove(pokemon2MoveDist(rng));

        // Determine the order of attacks based on Pokémon speed
        if (pokemon1->getSpeed() < pokemon2->getSpeed()) {
            // Opponent Pokémon attacks first
            if (applyMoveDamage(pokemon2, pokemon1, &pokemon2Move, rng)) continue;
            if (applyMoveDamage(pokemon1, pokemon2, &pokemon1Move, rng)) break; // Opponent Pokémon faints.
        } else {
            // Player's Pokémon attacks first
            if (applyMoveDamage(pokemon1, pokemon2, &pokemon1Move, rng)) break; // Opponent Pokémon faints.
            if (applyMoveDamage(pokemon2, pokemon1, &pokemon2Move, rng)) continue;
        }
    }

   
}