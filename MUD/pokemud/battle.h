#ifndef BATTLE_H
#define BATTLE_H
#include <iostream>
#include "team.h"
#include <random>
#include "pokemon.h"
#include "move.h"
#include "json11.hpp"
#include "load_pson.h"

using namespace std;
using json = json11::Json;
using RNG = mt19937;

class Battle {

public:
    Battle(){}

    void start(Team* team, vector<shared_ptr<Pokemon>>& pokemons, const vector<Move>& moves);

    bool applyMoveDamage(shared_ptr<Pokemon> attacker, shared_ptr<Pokemon> defender, Move* move, RNG& rng);
    int calculateDamage(float attackStat, float defenseStat, float power, float STAB, float damageMultiplier, float randomMultiplier);

    shared_ptr<Pokemon> getRandomPokemon(vector<shared_ptr<Pokemon>>& pokemons, const vector<Move>& moves, RNG& rng);
    int selectMove(const shared_ptr<Pokemon> pokemon);

};

#endif 