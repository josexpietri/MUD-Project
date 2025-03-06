
#ifndef DATA_H
#define DATA_H 

#include<stdbool.h>

typedef enum ItemType {
    ITEM_TYPE_NONE = -1,
    ITEM_TYPE_GENERAL,
    ITEM_TYPE_QUEST,
    ITEM_TYPE_POTION,
    ITEM_TYPE_WEAPON,
    ITEM_TYPE_ARMOR
} ItemType;

typedef struct Room {
    int id;
   char *name;
   char *description;
    int north;
    int south;
    int west;
    int east;
    int item;
    bool starting; 
    
} Room;

typedef struct Item {
    int id;
   char *name;
   char *description;
   int value;
   ItemType type;
   int damage;
   bool last;

} Item;


typedef enum Directions {
            NORTH = 'n', SOUTH = 's', EAST = 'e', WEST = 'w'
} Directions;

int find_max(char *filename);

Room * load_json_rooms(char * filename, int roomMaxId);

Item * load_json_items(char * filename, int itemMaxId);
/** DO NOT ADD CODE INSIDE THIS FILE ADD to data.c **/

#endif