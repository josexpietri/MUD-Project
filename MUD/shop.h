
#ifndef SHOP_H
#define SHOP_H 

#include <string>
#include "data.h"
#include "operations.h"

class ShopItem{
    public: 
    int id;
    std::string name;
    int damage;
    int value;
    ShopItem * next;
    ShopItem * prev;

    ShopItem(int id, const std::string& name, int damage, int value): id(id), name(name), damage(damage), value(value), next(nullptr), prev(nullptr) {}


    int getId() const { return id; }
    void setId(int newId) { id = newId; }

    std::string getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    int getDamage() const { return damage; }
    void setDamage(int newDamage) { damage = newDamage; }

    int getValue() const { return value; }
     void setValue(int newValue) { value = newValue; }

    ShopItem* getNext() const { return next; }
    void setNext(ShopItem* newNext) { next = newNext; }

    ShopItem* getPrev() const { return prev; }
    void setPrev(ShopItem* newPrev) { prev = newPrev; }

};

class Shop {
    public: 
    Shop(Item* item_list, ItemType objtype);
    void enter(int inventory[], int& inventoryCount);
    ShopItem* buyItem(ShopItem* item, int inventory[], int& inventoryCount);
    ShopItem* buyItemWORK(ShopItem* item, int inventory[], int& inventoryCount, int c);
    ShopItem* removeItem(ShopItem* nextptr, int index);

    private: 
    ShopItem* head;
    ShopItem* tail;
    void addShopItem(Item item);
    ShopItem *listItems(ShopItem *nextItemToShow);

};


#endif