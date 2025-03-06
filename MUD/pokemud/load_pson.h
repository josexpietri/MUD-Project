#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include "move.h"
#include "pokemon.h"
#include "json11.hpp"

using namespace std;
using json = json11::Json;
/**
* This function reads the json file and returns json data
* @param file_path
* @return json data
*/

json read_json_file(const string &file_path);
vector<Move> loadMoves(string filename);
vector<shared_ptr<Pokemon>> loadPokemon(string filename);

#endif