
#include "load_pson.h"
#include <iostream>
using namespace std;
using json = json11::Json;

/**
* This function reads the json file and returns json data
* @param file_path
* @return json data
*/
json read_json_file(const string &file_path) {

    ifstream t(file_path);
    string str((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());

    string err;
    const auto json1 = json::parse(str, err);
    return json1;
}

/**
 * Loads move data from a JSON file and creates a vector of Move objects.
 * Each move's data is extracted from the JSON and used to create a Move object.
 * @param filename The name of the JSON file containing moves data.
 * @return A vector of Move objects constructed from the JSON file data.
 *
 * @note Students are not required to modify this function.
 */
vector<Move> loadMoves(string filename){
    json jsonMoves = read_json_file(filename);
    vector<Move> moves;
    // Parse the JSON array and create Move objects
    for (auto& entry : jsonMoves.array_items()){
        // Each 'entry' represents move data. Move::create constructs a Move objects and push_back adds it to the moves vector.
        Move *move = Move::create(entry);
        moves.push_back(*move);
    }
    return moves;
}

/**
 * Loads Pokémon data from a JSON file and creates a vector of shared_ptr to Pokémon objects.
 * Each Pokémon's data is extracted from the JSON and used to instantiate Pokémon objects through a factory method.
 * @param filename The name of the JSON file containing Pokémon data.
 * @return A vector of shared_ptr to Pokémon objects constructed from the JSON file data.
 */
vector<shared_ptr<Pokemon>> loadPokemon(string filename){
   
    json jsonPokemon = read_json_file(filename);
    vector<shared_ptr<Pokemon>> pokemonList;
    // Iterate over each entry in the JSON array to create Pokémon objects.
    for (auto& entry : jsonPokemon.array_items()){
       

        shared_ptr<Pokemon> pokemon;
        /** CODE: Utilize the pokemonFactory to create a shared_ptr to a Pokémon from the JSON entry, set the result to the pokemon variable or the code will fail the first test . */
        /** CODE: remove cout below */  
        
        pokemon = pokemonFactory(entry);
        //cout << "load_pson:loadPokemon >>> " << entry["name"].string_value() << endl;
        
        if (pokemon != nullptr){
            /** CODE: Add the created shared_ptr<Pokemon> to the pokemonList vector */    

            pokemonList.push_back(pokemon);
            
        }
    }
   
    return pokemonList;
}
