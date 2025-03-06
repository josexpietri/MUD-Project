#include <stdio.h>
#include <string.h>
#include "data.h"
#include <stdlib.h>

/** Add code for .h here **/

// Find maximum ID in JSON
int find_max(char *filename) {
    FILE *fo = fopen(filename, "r");
   
   
    if (fo == NULL) {
    perror("Error opening file");
    return -1;
    }


    int hold = 0;
    int id ;
    char line[285];

    while (fgets(line, sizeof(line), fo)) {
        if (sscanf(line, " \"id\": %d", &id) == 1) {
            if (id > hold) {
                hold = id;
            }
        }
    }

    fclose(fo);
    return hold;
}

ItemType extract_type(char* value) {
    if (strstr(value, "general")) { return ITEM_TYPE_GENERAL; }
    if (strstr(value, "quest")) { return ITEM_TYPE_QUEST; }
    if (strstr(value, "potion")) { return ITEM_TYPE_POTION; }
    if (strstr(value, "weapon")) { return ITEM_TYPE_WEAPON; }
    if (strstr(value, "armor")) { return ITEM_TYPE_ARMOR; }
    return ITEM_TYPE_NONE;
}

char *extract_string(char *val) {
    char *neww = strchr(val, ':');
    neww += 3;
    char *end = strchr(neww, '"');
    
    int len = end - neww;
    char *word = (char*)malloc((len + 1) * sizeof(char));
    if (word == NULL) {
        return NULL;
    }

    strncpy(word, neww, len);
    word[len] = '\0';

    // Capitalize first character
    if (len > 0 && word[0] >= 'a' && word[0] <= 'z') {
        word[0] -= 32;
    }

    return word;
}

int extract_int(char *val) {
    char *neww = strchr(val, ':');
    neww += 2;
    int num;
    if (strstr(neww, "null")) {
        num = -1;
    } else {
        num = atoi(neww);
    }
    return num;
}

struct Room *load_json_rooms(char * filename, int roomMaxId) {
    struct Room roomI = {
        -1, 
        NULL, 
        NULL,
         -1, 
         -1, 
         -1, 
         -1, 
         -1, 
         0
    };

    struct Room *roomslist = (Room *)malloc((roomMaxId + 1) * sizeof(Room));
    for (int i = 0; i <= roomMaxId; i++) {
        roomslist[i] = roomI;
    }

    FILE *fo = fopen(filename, "r");
    char line[1000];
    Room curroom = roomI;

    while (fgets(line, sizeof(line), fo)) {
        if (strstr(line, "\"id\"")) {
            curroom.id = extract_int(line);
        } else if (strstr(line, "\"name\"")) {
            curroom.name = extract_string(line);
        } else if (strstr(line, "\"description\"")) {
            curroom.description = extract_string(line);
        } else if (strstr(line, "\"north\"")) {
            curroom.north = extract_int(line);
        } else if (strstr(line, "\"south\"")) {
            curroom.south = extract_int(line);
        } else if (strstr(line, "\"west\"")) {
            curroom.west = extract_int(line);
        } else if (strstr(line, "\"east\"")) {
            curroom.east = extract_int(line);
        } else if (strstr(line, "\"item\"")) {
            curroom.item = extract_int(line);
        } else if (strstr(line, "\"starting\"")) {
            curroom.starting = extract_int(line);
        }

        if (strchr(line, '}')) {
            roomslist[curroom.id] = curroom;
            curroom = roomI;
        }
    }
    fclose(fo);
    return roomslist;
}

// Load JSON items
struct Item *load_json_items(char * filename, int itemMaxId) {
    struct Item itemI = {
        -1, NULL, NULL, -1, ITEM_TYPE_NONE, false
    };

    struct Item *itemlist = (Item *)malloc((itemMaxId + 1) * sizeof(Item));
    for (int i = 0; i <= itemMaxId; i++) {
        itemlist[i] = itemI;
    }

    FILE *fo = fopen(filename, "r");
    char line[2000];
    Item curitem = itemI;
    int lastValidItemId = -1;

    while (fgets(line, sizeof(line), fo)) {
        if (strstr(line, "\"id\"")) {
            curitem.id = extract_int(line);
            lastValidItemId = curitem.id;
        } else if (strstr(line, "\"name\"")) {
            curitem.name = extract_string(line);
        } else if (strstr(line, "\"description\"")) {
            curitem.description = extract_string(line);
        } else if (strstr(line, "\"value\"")) {
            curitem.value = extract_int(line);
        } else if (strstr(line, "\"damage\"")) {
            curitem.damage = extract_int(line);
        } else if (strstr(line, "\"type\"")) {
            curitem.type = extract_type(line);
        } else if (strstr(line, "\"last\"")) {
            curitem.last = (curitem.id > -1);
        }

        if (strchr(line, '}')) {
            itemlist[curitem.id] = curitem;
            curitem = itemI;
        }
    }

    if (lastValidItemId > -1) {
        itemlist[lastValidItemId].last = true;
    }

    fclose(fo);
    return itemlist;
}
