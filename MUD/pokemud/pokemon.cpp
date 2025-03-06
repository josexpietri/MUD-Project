#include "pokemon.h"

using namespace std;
using json = json11::Json;

// Static map defining how effective a Pokémon's move is against another Pokémon based on their types
map<string, map<string, double>> Pokemon::typeMultipliers = {
        {"Normal",   {{"Normal", 1.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0}, {"Rock", 0.5}}},
        {"Fire",     {{"Normal", 1.0}, {"Fire", 0.5}, {"Water", 0.5}, {"Electric", 1.0}, {"Grass", 2.0}, {"Rock", 0.5}}},
        {"Water",    {{"Normal", 1.0}, {"Fire", 2.0}, {"Water", 0.5}, {"Electric", 1.0}, {"Grass", 0.5}, {"Rock", 2.0}}},
        {"Electric", {{"Normal", 1.0}, {"Fire", 1.0}, {"Water", 2.0}, {"Electric", 0.5}, {"Grass", 0.5}, {"Rock", 1.0}}},
        {"Grass",    {{"Normal", 1.0}, {"Fire", 0.5}, {"Water", 2.0}, {"Electric", 1.0}, {"Grass", 0.5}, {"Rock", 2.0}}},
        {"Rock",     {{"Normal", 1.0}, {"Fire", 2.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0}, {"Rock", 1.0}}}
};

/**
 * Calculates and returns the damage multiplier based on the Pokémon's type and the opponent's move type.
 * Utilizes the typeMultipliers map to find the effectiveness of the move against this Pokémon's type.
 * @param opponentMoveType The type of the opponent's move.
 * @return The damage multiplier as a float.
 */
float Pokemon::getDamageMultiplier(const string& opponentMoveType) const {
    // Implement this method to calculate damage multiplier.
    // Hint: Use the opponentMoveType as the key to access the outer map of typeMultipliers.
    // Finally, use your Pokémon's type as the key to access the inner map for the specific damage multiplier.
    /** CODE: complete method */
    return 0.0f;
}

/**
 * Factory function that creates and returns a shared_ptr to a Pokémon object of a specific type.
 * Parses Pokémon attributes from JSON data to construct an instance of the corresponding subclass.
 * @param jd The JSON object containing Pokémon data.
 * @return A shared_ptr to the created Pokémon object.
 */
shared_ptr<Pokemon> pokemonFactory(const json jd) {
    // Extract the Pokémon type from JSON data
    string pmType = jd["type"].string_value();
    // Extract base information for the Pokémon
    json baseInfo = jd["base"];

    // Example case for Normal type Pokémon. Implement cases for other types similarly.
   
    if (pmType == "Normal") {
        return make_shared<NormalPokemon>(
                jd["name"].string_value(),
                baseInfo["HP"].int_value(),
                baseInfo["Attack"].int_value(),
                baseInfo["Defense"].int_value(),
                baseInfo["Sp. Attack"].int_value(),
                baseInfo["Sp. Defense"].int_value(),
                baseInfo["Speed"].int_value()
        );
    }else if(pmType == "Fire"){
        return make_shared<FirePokemon>(
                jd["name"].string_value(),
                baseInfo["HP"].int_value(),
                baseInfo["Attack"].int_value(),
                baseInfo["Defense"].int_value(),
                baseInfo["Sp. Attack"].int_value(),
                baseInfo["Sp. Defense"].int_value(),
                baseInfo["Speed"].int_value()
        );
    }else if(pmType == "Water"){
        return make_shared<WaterPokemon>(
                jd["name"].string_value(),
                baseInfo["HP"].int_value(),
                baseInfo["Attack"].int_value(),
                baseInfo["Defense"].int_value(),
                baseInfo["Sp. Attack"].int_value(),
                baseInfo["Sp. Defense"].int_value(),
                baseInfo["Speed"].int_value()
        );
    }else if(pmType == "Electric"){
        return make_shared<ElectricPokemon>(
                jd["name"].string_value(),
                baseInfo["HP"].int_value(),
                baseInfo["Attack"].int_value(),
                baseInfo["Defense"].int_value(),
                baseInfo["Sp. Attack"].int_value(),
                baseInfo["Sp. Defense"].int_value(),
                baseInfo["Speed"].int_value()
        );
    }else if(pmType == "Grass"){
        return make_shared<GrassPokemon>(
                jd["name"].string_value(),
                baseInfo["HP"].int_value(),
                baseInfo["Attack"].int_value(),
                baseInfo["Defense"].int_value(),
                baseInfo["Sp. Attack"].int_value(),
                baseInfo["Sp. Defense"].int_value(),
                baseInfo["Speed"].int_value()
        );


    }else if(pmType == "Rock"){
        return make_shared<RockPokemon>(
                jd["name"].string_value(),
                baseInfo["HP"].int_value(),
                baseInfo["Attack"].int_value(),
                baseInfo["Defense"].int_value(),
                baseInfo["Sp. Attack"].int_value(),
                baseInfo["Sp. Defense"].int_value(),
                baseInfo["Speed"].int_value()
        );


    }

    // Add similar blocks for other Pokémon types: Fire, Water, Electric, Grass, Rock,
    // ensuring the project is limited to these six types for simplicity.
    /** CODE: complete method */

    // If no matching type is found, return nullptr
    return nullptr;
}

/**
 * This function prints the Pokémon's name along with its current HP and base HP in a formatted manner.
 *
 * @note Students are not required to modify this function.
 */
void Pokemon::displayStats() const {
    cout << left << setw(10) << name
         << " (HP: " << hp << "/" << base_hp << ")\n";
}

/**
 * Outputs the Pokémon's moves, including their names and remaining PP (Power Points),
 * formatted with indices for easy reading. This function iterates through the Pokémon's
 * current moveset and displays each move's details in a structured format.
 *
 * @note Students are not required to modify this function.
 */
void Pokemon::displayMoves() const {
    cout << left;
    for (size_t i = 0; i < moves.size(); ++i) {
        cout << i + 1 << ": "
             << setw(20) << moves[i].getName()
             << "pp:" << setw(4) << moves[i].getPP()
             << endl;
    }
}

// Implement the getter and setter methods:

/**
 * Retrieves the name of the Pokémon.
 * @return The name as a string.
 */
string Pokemon::getName() const {
    /** CODE: complete method */
    return name;
}

/**
 * Gets the current HP (Hit Points) of the Pokémon.
 * @return The current HP as an integer.
 */
int Pokemon::getHP() const {
    /** CODE: complete method */
    return hp;
}

/**
 * Resets the Pokémon's HP to its base HP.
 */
void Pokemon::resetHP() {
    hp = base_hp;
}

/**
 * Sets the Pokémon's current HP to a new value.
 * @param new_hp The new HP value.
 */
void Pokemon::setHP(int new_hp) {
    hp = new_hp;
}

/**
 * Retrieves the Pokémon's Attack stat.
 * @return The Attack stat as an integer.
 */
int Pokemon::getAttack() const {
    /** CODE: complete method */
    return attack;
}

/**
 * Retrieves the Pokémon's Defense stat.
 * @return The Defense stat as an integer.
 */
int Pokemon::getDefense() const {
    /** CODE: complete method */
    return defense;
}

/**
 * Retrieves the Pokémon's Special Attack stat.
 * @return The Special Attack stat as an integer.
 */
int Pokemon::getSpAttack() const {
    /** CODE: complete method */
    return sp_attack;
}
/**
 * Retrieves the Pokémon's Special Defense stat.
 * @return The Special Defense stat as an integer.
 */
int Pokemon::getSpDefense() const {
    /** CODE: complete method */
    return sp_defense;
}

/**
 * Retrieves the Pokémon's Speed stat.
 * @return The Speed stat as an integer.
 */
int Pokemon::getSpeed() const {
    /** CODE: complete method */
    return speed;
}

/**
 * Returns a list of the Pokémon's moves.
 * @return A vector containing the Pokémon's moves.
 */
vector<Move> Pokemon::getMoves() const {
    /** CODE: complete method */
    return this->moves;
}

/**
 * Provides a reference to a move at a specified index within the Pokémon's move list.
 * @param index The index of the move.
 * @return A reference to the Move object.
 * @throws out_of_range If the index is out of range.
 */
Move& Pokemon::getMove(int index) {
    return moves.at(index);
}

