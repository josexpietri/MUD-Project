#include "shop.h"
#include "data.h"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Shop::Shop(Item* itemlist, ItemType ttype) : head(nullptr), tail(nullptr){
    int x = 0;
   
   
      while (!itemlist[x].last) {

        if (itemlist[x].id != -1 && itemlist[x].type == ttype) {
            addShopItem(itemlist[x]);
        }
        x++;
    }
    if(itemlist[x].last){
        addShopItem(itemlist[x]);
    }
}

void Shop::addShopItem(Item item){
    //here1
    ShopItem* it = new ShopItem(item.id, item.name, item.damage, item.value);
    if(!head){
        head = it;
        tail = it;
    }else{
        tail -> next = it;
        it -> prev = tail;
        tail = it;
    }
}

ShopItem *Shop::listItems(ShopItem * nextItemToShow){

    cout << left << setw(7) << "Item#" << setw(40) << "Name" << setw(10) << "Damage" << setw(5) << "Value" << endl;
    cout << left << setw(7) << "-----" << setw(40) << "--------------------" << setw(10) << "-----" << setw(5) << "-----" << endl;

    ShopItem* cur = nextItemToShow;
    int itemN = 1;


        for(int i=0;i<10;i++){
            if(cur){
                cout << left << setw(7) << itemN++  << setw(40)  << cur->getName()  << setw(10)  << cur->getDamage() << setw(5) << cur->getValue() << endl;
                if(cur->next == nullptr){
                    cout << "to buy items in this list add +5 to the value" << endl;
                    i=10;
                }else{
                    cur = cur->next;
                    }
                
            }else{
                    i=10;
            }
        }

        if(cur){
            cout << "RETURN TO LIST " << cur->getName() << endl;
            return cur;
        }else{
            return nullptr;
        }


}
ShopItem* Shop::buyItemWORK(ShopItem* item, int inventory[], int& inventoryCount, int c){
        ShopItem* ret;
        for(int i=0;i<c;i++){
            item = item->prev;
        }
      
        inventory[inventoryCount] = item->getId(); 
        inventoryCount++;
  
        std::string name1 = head->getName();
        std::string name2 = tail->getName();
        std::string name3 = item->getName();
        
        if(name1 == name3){
            cout << "2" << endl;
            head = item->next;
            cout << "You bought " << name3 << endl;
            ret = listItems(head);
        }else if(name2 == name3){
           
            tail = item->prev;
            for(int i=0;i<10;i++){
                item = item->prev;
            }
            cout << "You bought " << name3 << endl;
            ret = listItems(item);
            
        }else{
            
            cout << "1" << endl;
            item->prev->next = item->next;
            item->next->prev = item->prev;
            //HERE
            cout << item->prev->next->getName() << endl;
            cout << item->next->prev->getName() << endl;
            cout << "You bought " << name3 << endl;

            if(c==10){
                cout << "1" << endl;
                ret = listItems(item->prev->next);
            }else if(c==1){
                cout << "10" << endl;
                ShopItem* hold = item->prev->next;
                 for(int i=0;i<10-c;i++){
                    hold = hold->prev;
                }
                cout << hold->getName() << endl;
                ret = listItems(hold);
            }else{
                for(int i=0;i<10-c;i++){
                    item = item->prev;
                }
                ret = listItems(item);
            }
        }
      
    delete item;    
    return ret;

}
ShopItem* Shop::buyItem(ShopItem* item, int inventory[], int& inventoryCount){
    ShopItem* ret;
    int inp;
    cout << "Enter line number" << endl;
    scanf("%d", &inp);
    if(inp== 1){
        ret = buyItemWORK(item, inventory, inventoryCount,10);
    }else if(inp == 2){
       ret =  buyItemWORK(item, inventory, inventoryCount,9);
    }else if(inp == 3){
       ret = buyItemWORK(item, inventory, inventoryCount,8);
    }else if(inp == 4){
       ret = buyItemWORK(item, inventory, inventoryCount,7);
    }else if(inp == 5){
       ret = buyItemWORK(item, inventory, inventoryCount,6);
    }else if(inp == 6){
        ret = buyItemWORK(item, inventory, inventoryCount,5);
    }else if(inp == 7){
        ret = buyItemWORK(item, inventory, inventoryCount,4);
    }else if(inp == 8){
       ret =  buyItemWORK(item, inventory, inventoryCount,3);
    }else if(inp == 9){
        ret = buyItemWORK(item, inventory, inventoryCount,2);
    }else if(inp == 10){
       ret =  buyItemWORK(item, inventory, inventoryCount,1);
    }

    return ret;


}

ShopItem* Shop::removeItem(ShopItem* ptr, int index){
    ShopItem* cur = ptr;
    ShopItem* nex = ptr->next;
    ShopItem* pre = ptr->prev;

    if(pre == nullptr && nex != nullptr){
        head = nex;

    }else if(pre != nullptr && nex == nullptr){
        tail = pre;
    }else{
        ptr->prev->next = nex;
        ptr->next->prev = pre;
    }
    return cur;
}
void Shop::enter(int inventory[], int& inventoryCount) {
    char ch[5] = "z";

    ShopItem* cur = listItems(head);
    std::string name1 = head->getName();

    while(ch[0] != 'e'){
        cout << "Press Enter or 'n' to go forward, 'p' to go back, 'b' to buy or 'e' to exit:" << endl;
        scanf("%s", ch);
        if(ch[0] == 'n'){
            
            cur = listItems(cur);
        }



        else if(ch[0] == 'p'){
            ShopItem* in = cur;
                for(int i=0;i<10;i++){ 
                }
            std::string name2 = in->getName(); 
            cout << "CHECK " << name2 << endl;

            if(name1 == name2){ 
                cur = listItems(head);
             }else{ 
                 
                 if(name2 == "Dragonfang"){
                    ShopItem* in = cur;
                for(int i=0;i<14;i++){ 
                    in = in -> prev;
                }
                cur = listItems(in);
                 }else{
                ShopItem* in = cur;
                for(int i=0;i<20;i++){  
                    in = in -> prev;
                }
                cur = listItems(in);
                 }
            } 
         }else if(ch[0] == 'b'){
             cur = buyItem(cur, inventory, inventoryCount);
         }
    }
}