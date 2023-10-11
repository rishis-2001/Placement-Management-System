#include <iostream>
#include <vector>
#include "Job.h"
#include "Internship.h"
#include "../Utils/Display.h"

using namespace std;

#ifndef COMPANY_H
#define COMPANY_H

class Company {
private:
    string company_name;
    string company_location;
    string company_branch;
    int total_offers;
    vector<Job> jobs;
    vector<Internship> internships;

public:
    Company(const string& _company_name, const string& _company_location, const string& _company_branch, int _total_offers = 0)
        : company_name(_company_name), company_location(_company_location), company_branch(_company_branch), total_offers(_total_offers) {}

    // Setters
    void set_location(const string& _company_location) { company_location = _company_location; }
    void set_name(const string& _company_name) { company_name = _company_name; }
    void set_company_branch(const string& _company_branch) { company_branch = _company_branch; }
    void set_total_offers(int _total_offers) { total_offers = _total_offers; }

    // Getters
    string get_name() const { return company_name; }
    string get_location() const { return company_location; }
    string get_branch() const { return company_branch; }
    int get_total_offers() const { return total_offers; }

    void append_job() const {
        // Implementation for appending a job
        // ...
    }

    void append_internship() const {
        // Implementation for appending an internship
        // ...
    }

    void delete_job() const {
        // Implementation for deleting a job
        // ...
    }

    void delete_internship() const {
        // Implementation for deleting an internship
        // ...
    }

    void update_job_salary(int choice) const {
        // Implementation for updating a job's salary
        // ...
    }

    void update_internship_salary(int choice) const {
        // Implementation for updating an internship's salary
        // ...
    }

    // Display functions
    void display_internship(int owner = 0) const {
        // Implementation for displaying internships
        // ...
    }

    void display_job(int owner = 0) const {
        // Implementation for displaying jobs
        // ...
    }

    friend ostream& operator<<(ostream& out, const Company& company);
};

ostream& operator<<(ostream& out, const Company& company) {
    out << "\n\t\t\t\t\t\t || COMPANY DETAILS ||\n" << endl;
    out << "Name: " << company.get_name() << endl;
    out << "Location: " << company.get_location() << endl;
    out << "Branch Preferred: " << company.get_branch() << endl;
    out << "Total Offers made: " << company.get_total_offers() << endl;
    return out;
}

#endif
