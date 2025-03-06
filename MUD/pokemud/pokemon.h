#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

#include "move.h"
#include "json11.hpp"

using namespace std;
using json = json11::Json;

// Constant strings for Pokémon types
const string NORMAL = "Normal";
const string FIRE = "Fire";
const string WATER = "Water";
const string ELECTRIC = "Electric";
const string GRASS = "Grass";
const string ROCK = "Rock";


class Pokemon {
private:
    string name;
    int base_hp;
    int hp, attack, defense, sp_attack, sp_defense, speed;
    vector<Move> moves;

public:
    // Constructor
    Pokemon(const string& name, int hp, int attack, int defense, int sp_attack, int sp_defense, int speed)
            : name(name),base_hp(hp), hp(hp), attack(attack), defense(defense), sp_attack(sp_attack), sp_defense(sp_defense), speed(speed) {}


    void addMove(const Move& move) { moves.push_back(move); }

    void displayStats() const;
    void displayMoves() const;

    static std::map<std::string, std::map<std::string, double>> typeMultipliers;

    // Basic getters and setters
    string getName() const;
    int getHP() const;
    void resetHP();
    void setHP(int new_hp);
    int getAttack() const;
    int getDefense() const;
    int getSpAttack() const;
    int getSpDefense() const;
    int getSpeed() const;
    vector<Move> getMoves() const;
    Move& getMove(int index);

    // Virtual methods for polymorphic behavior
    virtual float getDamageMultiplier(const std::string& opponentMoveType) const;
    virtual string getType() const = 0;
    
    // Virtual destructor
    virtual ~Pokemon() = default;
};

/**
 * Example implementation of a NormalPokemon class that inherits from Pokemon.
 */
class NormalPokemon : public Pokemon {
    public:
        NormalPokemon(const string& name, int hp, int attack, int defense, int sp_attack, int sp_defense, int speed)
                : Pokemon(name, hp, attack, defense, sp_attack, sp_defense, speed) {}


    // Overridden getType method that returns the Pokémon's type
    string getType() const override { return NORMAL; }
   
};
class FirePokemon : public Pokemon {
    public:
        FirePokemon(const string& name, int hp, int attack, int defense, int sp_attack, int sp_defense, int speed)
                : Pokemon(name, hp, attack, defense, sp_attack, sp_defense, speed) {}


    // Overridden getType method that returns the Pokémon's type
    string getType() const override { return FIRE; }
   
};
class WaterPokemon : public Pokemon {
    public:
        WaterPokemon(const string& name, int hp, int attack, int defense, int sp_attack, int sp_defense, int speed)
                : Pokemon(name, hp, attack, defense, sp_attack, sp_defense, speed) {}


    // Overridden getType method that returns the Pokémon's type
    string getType() const override { return WATER; }
   
};
class ElectricPokemon : public Pokemon {
    public:
        ElectricPokemon(const string& name, int hp, int attack, int defense, int sp_attack, int sp_defense, int speed)
                : Pokemon(name, hp, attack, defense, sp_attack, sp_defense, speed) {}


    // Overridden getType method that returns the Pokémon's type
    string getType() const override { return ELECTRIC; }
   
};
class GrassPokemon : public Pokemon {
    public:
        GrassPokemon(const string& name, int hp, int attack, int defense, int sp_attack, int sp_defense, int speed)
                : Pokemon(name, hp, attack, defense, sp_attack, sp_defense, speed) {}


    // Overridden getType method that returns the Pokémon's type
    string getType() const override { return GRASS; }
   
};
class RockPokemon : public Pokemon {
    public:
        RockPokemon(const string& name, int hp, int attack, int defense, int sp_attack, int sp_defense, int speed)
                : Pokemon(name, hp, attack, defense, sp_attack, sp_defense, speed) {}


    // Overridden getType method that returns the Pokémon's type
    string getType() const override { return ROCK; }
   
};
//^^^^^^^
/** 
 * 
 * CODE: Implement the subclasses for the rest of the Pokémon types here 
 * 
 * */


// Factory function for creating Pokémon from JSON data.
shared_ptr<Pokemon> pokemonFactory(const json jd);

#endif 