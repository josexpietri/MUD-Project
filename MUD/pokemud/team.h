#ifndef TEAM_H
#define TEAM_H

#include <fstream>
#include <string>
#include <vector>
#include <memory>

#include "pokemon.h"
#include "move.h"
#include "json11.hpp"
#include "load_pson.h"

using namespace std;
using json = json11::Json;

class Team {
private:
    vector<shared_ptr<Pokemon>> team;
    static const int MAX_TEAM_SIZE = 3;

public:
    Team() = default;

    bool addPokemon(const shared_ptr<Pokemon>& pokemon);

    bool removePokemon(size_t index);

    bool isFull() const;

    shared_ptr<Pokemon> getPokemon(size_t index);

    int getSize() const;

    void printTeam() const;

    void writeTeam(const std::string& filename) const;
    bool loadTeam(const std::string& filename, vector<shared_ptr<Pokemon>>& pokemons, const std::vector<Move>& availableMoves);
    shared_ptr<Pokemon> findPokemonByName(vector<shared_ptr<Pokemon>>& pokemons, string name );
    Move* getMove(const vector<Move>& moves, string name);

};

#endif // TEAM_H
