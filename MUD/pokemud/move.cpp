#include "move.h"

/**
     * Creates a Move object from JSON data. Parses the move's attributes and constructs a Move.
     * @param jd JSON object containing move data.
     * @return Pointer to the created Move object.
     */
Move* Move::create(const json jd) {
    // Parse move attributes from JSON and create a new Move object.
    // Hint: For implementation structure, see pokemonFactory, adapting the approach to return a Move* instead of a shared_ptr<Pokemon>.
    // Take a look at the Move constructor in move.h
    // For the json format, look at moves.json
    /** CODE: insert here */
    return new Move(); // REPLACE ME, just a placeholder
}

/**
 * Decreases the move's PP (Power Points) by one if possible, indicating the move has been used.
 * If the PP reaches 0, the move cannot be used anymore.
 * @return True if PP was successfully decremented, False if move has no PP left.
 */
bool Move::usePP() {
    // Implement PP decrement logic
    /** CODE: insert here */
    return false;
}

// Implement getter methods to provide read-only access to move attributes

/**
 * Returns the move's type.
 * @return Move type as a string.
 */
string Move::getType() const {
    // Return the move's type
    /** CODE: insert here */
    return "";
}

/**
 * Returns the move's name.
 * @return Move name as a string.
 */
string Move::getName() const {
    // Return the move's name
    /** CODE: insert here */
    return "";
}

/**
 * Returns the move's category (e.g., "Physical" or "Special").
 * @return Move category as a string.
 */
string Move::getCategory() const {
    // Return the move's category
    /** CODE: insert here */
    return "";
}

/**
 * Returns the move's power, determining the move's strength in battle.
 * @return Move power as an integer.
 */
int Move::getPower() const {
    // Return the move's power
    /** CODE: insert here */
    return -1;
}

/**
 * Returns the move's accuracy, affecting the chance of the move hitting the target.
 * @return Move accuracy as an integer.
 */
int Move::getAccuracy() const {
    // Return the move's accuracy
    /** CODE: insert here */
    return -1;
}

/**
 * Returns the current PP of the move, indicating how many more times the move can be used.
 * @return Move PP as an integer.
 */
int Move::getPP() const {
    // Return the move's current PP
    /** CODE: insert here */
    return -1;
}