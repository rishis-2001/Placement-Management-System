#include "Offer.h"

#ifndef JOB_H
#define JOB_H

class Job : public Offer
{
private:
    int required_experience;
    string role;

public:
    Job() : required_experience(0), role("")
    {
        amount = 0;
        location = "";
        type = "";
        required_experience = 0;
        role = "";
    }

    Job(int _amount, string &_location, string &_type, int _required_experience, string &_role)
    : required_experience(_required_experience), role(_role)
    {
        amount = _amount;
        location = _location;
        type = _type;
    }

    void set_required_experience(int _required_experience)
    {
        required_experience = _required_experience;
    }

    void set_role(string &_role)
    {
        role = _role;
    }

    int get_required_experience() const {
        return required_experience;
    }

    string get_role() const {
        return role;
    }

    friend class Company;
    friend ostream &operator<<(ostream &, const Job &);
};

ostream &operator<<(ostream &out, const Job &job)
{
    out << "\n\t\t\t\t\t|| JOB DETAILS ||\n"<< endl;
    out << " Role: " << job.role << endl;
    out << " Amount: Rs." << job.amount << endl;
    out << " Location: " << job.location << endl;
    out << " Type: " << job.type << endl;
    out << " Required Experience: " << job.required_experience << " years" << endl;
    return out;
}

#endif
