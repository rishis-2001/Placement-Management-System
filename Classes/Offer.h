#include <iostream>
#include <vector>
using namespace std;

#ifndef OFFER_H
#define OFFER_H

class Offer
{
private:
    int amount;
    string location;
    string type;

public:
    void set_amount(int _amount)
    {
        amount = _amount;
    }

    void set_location(const string &_location)
    {
        location = _location;
    }

    void set_type(const string &_type)
    {
        type = _type;
    }
    int get_amount() const {
        return amount;
    }

    string get_location() const {
        return location;
    }

    string get_type() const {
        return type;
    }
    
    friend class Company;
};

#endif