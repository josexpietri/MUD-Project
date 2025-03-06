#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "operations.h"

int main(int argc, char *argv[]) {
    char roomsFilePath[256];
    char itemsFilePath[256];

    if (argc > 1 && argv[1][0] != '\0') {
        snprintf(itemsFilePath, sizeof(itemsFilePath), "%s/items.json", argv[1]);
        snprintf(roomsFilePath, sizeof(roomsFilePath), "%s/rooms.json", argv[1]);
    } else {
        snprintf(roomsFilePath, sizeof(roomsFilePath), "./rooms.json");
        snprintf(itemsFilePath, sizeof(itemsFilePath), "./items.json");
    }

    int roomMaxId = find_max(roomsFilePath);
    int itemMaxId = find_max(itemsFilePath);

    printf("roomMaxId=%d\n", roomMaxId);
    printf("itemMaxId=%d\n", itemMaxId);

    Room *roomslist = load_json_rooms(roomsFilePath, roomMaxId);
    Item *itemslist = load_json_items(itemsFilePath, itemMaxId);

    printf("%d %s\n", roomslist[5].id, roomslist[5].name);
    printf("%d %s\n", roomslist[359].id, roomslist[359].name);
    printf("%d %s %d %d %d %d\n",
           itemslist[1697].id,
           itemslist[1697].name,
           itemslist[1697].value,
           itemslist[1697].damage,
           itemslist[1697].type,
           itemslist[1697].last);

    gameLoop(roomslist, itemslist, 1); 

    for (int i = 0; i <= roomMaxId; i++) {
        free(roomslist[i].name);
        free(roomslist[i].description);
    }
    free(roomslist);

    for (int i = 0; i <= itemMaxId; i++) {
        free(itemslist[i].name);
        free(itemslist[i].description);
    }
    free(itemslist);

    return 0;
}