

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "operations.h"
#include "shop.h"
#include "pokemud/gym.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "pokemud/ui.h"
#include "muddydriver/bfs_muddy_driver.h"

using namespace std;

/** Put functions here **/

int invtrack = 0;

void gameLoop(Room roomslist[], Item itemlist[], int i){
    //int i = startingRoomId;
    int inventoryIDs[150];
    // extern int invtrack = 0;

    char ch[15] = "z";

    Shop weaponShoap(itemlist, ItemType::ITEM_TYPE_WEAPON); //here1

    bool whi = false;
    while(whi!=true){
        
        
        printf("#%d : %s\n", roomslist[i].id, roomslist[i].name);
        printf("%s\n", roomslist[i].description);

        if(roomslist[i].item > -1){
            printf("you see a %s \n", itemlist[roomslist[i].item].name);
        }
        printf("[ ");
        if(roomslist[i].north != -1){
            printf("[n]orth, ");
        }
        if(roomslist[i].south != -1){
            printf("[s]outh, ");
        }
        if(roomslist[i].east != -1){
            printf("[e]ast, ");
        }
        if(roomslist[i].west != -1){
            printf("[w]est, ");
        }
        printf("[l]ook, [g]et, [i]nventory, [d]rop, [sh]op, [p]okemon, [c]hallenge, [f]ind, [q]uit ] \n");

        printf(">");
        scanf(" %s", ch);
        
        if(ch[0]=='n' && roomslist[i].north != -1){
            i = roomslist[i].north;
        }else if(ch[0]=='s' && roomslist[i].south != -1 && ch[1] != 'h'){
            i = roomslist[i].south;
        }else if(ch[0]=='e' && roomslist[i].east != -1){
            i = roomslist[i].east;
        }else if(ch[0]=='w' && roomslist[i].west != -1){
            i = roomslist[i].west;
        }
        
        else if(ch[0]=='q'){
            printf("Exiting game\n");
            whi = true;
        }
        
        else if(ch[0]=='l'){
            printf("%s\n", itemlist[roomslist[i].item].description);
        }else if(ch[0]=='g'){
            inventoryIDs[invtrack] = roomslist[i].item;
            roomslist[i].item = -1;
            printf("You picked up a %s\n", itemlist[inventoryIDs[invtrack]].name);
            invtrack++;
        }else if(ch[0]=='i'){
           if(invtrack == 0){
            printf("You currently have nothing in your backpack\n");
           }else{
           printf("INVENTORY : \n");
            for(int j=0;j<invtrack;j++){
                if(inventoryIDs[j] == -1){}else{
                printf("+ [%d] %s\n", itemlist[inventoryIDs[j]].id, itemlist[inventoryIDs[j]].name);
                }
            }
            }
        }else if(ch[0]=='d'){
            if(invtrack == 0){
                printf("You currently have nothing in your backpack\n");
            }else{
            printf("INVENTORY : \n");
            for(int j=0;j<invtrack;j++){
                if(inventoryIDs[j] == -1){}else{
                printf("+ [%d] %s\n", itemlist[inventoryIDs[j]].id, itemlist[inventoryIDs[j]].name);
                }
            }
            int r;
            int z = 0;
            printf("Enter ID of item: \n");
            printf(">");
            scanf(" %d", &r);
    
            for(int h=0;h<invtrack;h++){
                 if(r == itemlist[inventoryIDs[h]].id){
                    roomslist[i].item = itemlist[inventoryIDs[h]].id;
                    inventoryIDs[h] = -1;
                    z = 1;
                }
            }
            if(z == 0){
                printf("Item does not exist in backpack");
            }
            }
        }else if(ch[0] == 'p'){
            pokemonMenu();
            

        }else if(ch[0] == 'c'){
        
            if(roomslist[i].id == 324){
                challengeTrainer(0);
            }else if(roomslist[i].id == 344){
                challengeTrainer(1);
            }else if(roomslist[i].id == 343){
                challengeTrainer(2);
            }else if(roomslist[i].id == 328){
                challengeTrainer(3);
            }else if(roomslist[i].id == 325){
                challengeTrainer(4);
            }else if(roomslist[i].id == 326){
                challengeTrainer(5);
            }else if(roomslist[i].id == 322){
                challengeTrainer(6);
            }else if(roomslist[i].id == 331){
                challengeTrainer(7);
            }else if(roomslist[i].id == 329){
                challengeTrainer(8);
            }else if(roomslist[i].id == 327){
                challengeTrainer(9);
            }else if(roomslist[i].id == 323){
                challengeTrainer(10);
            }else if(roomslist[i].id == 358){
                challengeTrainer(11);
            }else{
                cout << "NO TRAINERHERE" << endl;
            }

        }else if(ch[0]=='f'){
            cout << "Enter ID of destination" << endl;
            int destinationId;
            cin >> destinationId;
            BFSMuddyDriver bfsDriver(roomslist);
             bfsDriver.solve(roomslist[i].id, destinationId);
            
        }else{
            printf("invalid direction\n");
        }

    }
    
    cout << "GAME LOOP" << endl;
}