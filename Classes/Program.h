#include <iostream>
using namespace std;

#ifndef PROGRAM_H
#define PROGRAM_H

class Program
{
private:
    string name;
    string type;
    int duration;
    int seats;

public:
    Program(string &_program_name, string &_type, int _seats,  int _duration )
    : name(_program_name), type(_type), duration(_duration), seats(_seats) {}
    
    string get_name() const {
        return name;
    }

    int get_duration() const {
        return duration;
    }

    string get_type() const {
        return type;
    }

    int get_seats() const {
        return seats;
    }

    void set_seats(int _seats)
    {
        seats = _seats;
    }

    void set_type(string &_type)
    {
        type = _type;
    }

    void set_name(string &_name)
    {
        name = _name;
    }

    void set_duration(int _duration)
    {
        duration = _duration;
    }

    friend class Student;
    friend ostream& operator<<(ostream&, const Program& program);
};

ostream& operator<<(ostream& out, const Program& program){
    out<<"\t || PROGRAM DETAILS ||"<<endl;
    out<<"Program Name: "<<program.name<<endl;
    out<<"Program Type: "<<program.type<<endl;
    out<<"Program Duration: "<<program.duration<<endl;
    out<<"Program Seats: "<<program.seats<<endl;
    return out;
}

#endif