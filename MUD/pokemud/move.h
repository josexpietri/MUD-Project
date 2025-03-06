#ifndef MOVE_H
#define MOVE_H
#include<string>
#include<iostream>
#include "json11.hpp"


using namespace std;
using json = json11::Json;

class Move {
private:
    string name, type, category;
    int power, accuracy, pp;

public:

    Move(): name(""), type("Normal"), category("Physical"), power(0), accuracy(0), pp(0) {}

    Move(const string& name, const string& type, const string& category, int power, int accuracy, int pp)
            : name(name), type(type), category(category), power(power), accuracy(accuracy), pp(pp) {}

    static Move* create(const json jd);

    bool usePP();

    // Getter methods
    string getType() const;
    string getName() const;
    string getCategory() const;
    int getPower() const;
    int getAccuracy() const;
    int getPP() const;
};

#endif

