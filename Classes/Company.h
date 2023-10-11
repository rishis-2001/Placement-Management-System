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

    void get_job(int choice) {
        if (choice > 0 && choice <= jobs.size()) {
            cout << jobs[choice - 1];
        }
    }

    void get_internship(int choice) {
        if (choice > 0 && choice <= internships.size()) {
            cout << internships[choice - 1];
        }
    }

    void append_job() {
        int _amount;
        string _location;
        string _type;
        string _role;
        int _required_experience;
        cout << "Enter the salary that will be provided: ";
        cin >> _amount;
        cout << "Enter location: ";
        cin >> _location;
        cout << "Type of job (remote/on-site): ";
        cin >> _type;
        cout << "Enter the required experience: ";
        cin >> _required_experience;
        cout << "Enter the role at the company: ";
        cin >> _role;
        Job newJob(_amount, _location, _type, _required_experience, _role);
        jobs.push_back(newJob);
        cout << "Job added successfully!" << endl;
    }

    void append_internship() {
        int _amount;
        string _location;
        string _type;
        string _role;
        int _program_count;
        cout << "Enter the salary that will be provided: ";
        cin >> _amount;
        cout << "Enter location: ";
        cin >> _location;
        cout << "Type of internship (remote/on-site): ";
        cin >> _type;
        cout << "Enter the role at the company: ";
        cin >> _role;
        cout << "Enter the number of programs of students required: ";
        cin >> _program_count;
        Internship newInternship(_amount, _location, _type, _role, _program_count);
        internships.push_back(newInternship);
        cout << "Internship added successfully!" << endl;
    }

    void delete_job() {
        if (jobs.empty()) {
            cout << "No jobs to delete." << endl;
            return;
        }

        int index;
        display_job(1);
        cout << "Enter the serial number of the job you wish to delete: ";
        cin >> index;
        if (index > 0 && index <= jobs.size()) {
            jobs.erase(jobs.begin() + (index - 1));
            cout << "Job deleted successfully!" << endl;
        } else {
            cout << "Invalid job serial number." << endl;
        }
    }

    void delete_internship() {
        if (internships.empty()) {
            cout << "No internships to delete." << endl;
            return;
        }

        int index;
        display_internship(1);
        cout << "Enter the serial number of the internship you wish to delete: ";
        cin >> index;
        if (index > 0 && index <= internships.size()) {
            internships.erase(internships.begin() + (index - 1));
            cout << "Internship deleted successfully!" << endl;
        } else {
            cout << "Invalid internship serial number." << endl;
        }
    }

    void update_job_salary(int choice) {
        if (choice > 0 && choice <= jobs.size()) {
            int _salary;
            cout << "\nEnter the new salary: ";
            cin >> _salary;
            jobs[choice - 1].set_amount(_salary);
            cout << "Salary updated successfully!" << endl;
        } else {
            cout << "Invalid job serial number." << endl;
        }
    }

    void update_internship_salary(int choice) {
        if (choice > 0 && choice <= internships.size()) {
            int _salary;
            cout << "\nEnter the new salary: ";
            cin >> _salary;
            internships[choice - 1].set_amount(_salary);
            cout << "Salary updated successfully!" << endl;
        } else {
            cout << "Invalid internship serial number." << endl;
        }
    }

    void display_internship(int owner = 0) {
        cout << "\t\t\t\t\t\t\t  || LIST OF INTERNSHIPS ||\n" << endl;
        cout.width(3);
        cout << "\t\t\t\t| Serial No.|";
        cout.width(15);
        cout << "Location" << "\t|";
        cout.width(10);
        cout << "Type" << "   \t|";
        cout.width(15);
        cout << "Role" << "\t|" << endl;
        cout << "\t\t\t\t-------------------------------------------------------------------------" << endl;

        int index = 1;
        for (const auto& internship : internships) {
            cout << "\t\t\t\t";
            cout.width(3);
            cout << "|   " << index << " \t  |";
            index++;
            cout.width(15);
            cout << internship.get_location() << "\t|";
            cout.width(10);
            cout << internship.get_type() << "\t|";
            cout.width(15);
            cout << internship.get_role() << "\t|" << endl;
        }
        cout << "\t\t\t\t-------------------------------------------------------------------------" << endl;

        if (!owner) {
            cout << "\n" << endl;
            cout << "\t\t\t\t==========================================================================" << endl;
            cout << "Enter serial number of the internship to see in detail\n(0 if you wish to skip): ";
            cin >> index;
            cout << "\t\t\t\t==========================================================================" << endl;

            if (index > 0 && index <= internships.size()) {
                cout << internships[index - 1];
            } else {
                cout << "Invalid internship serial number." << endl;
            }
        }
    }

    void display_job(int owner = 0) {
        cout << "\t\t\t\t\t\t\t  || LIST OF JOBS ||\n" << endl;
        cout.width(3);
        cout << "\t\t\t\t| Serial No.|";
        cout.width(15);
        cout << "Location" << "\t|";
        cout.width(10);
        cout << "Type" << "   \t|";
        cout.width(15);
        cout << "Role" << "\t|" << endl;
        cout << "\t\t\t\t-------------------------------------------------------------------------" << endl;

        int index = 1;
        for (const auto& job : jobs) {
            cout << "\t\t\t\t";
            cout.width(3);
            cout << "|   " << index << " \t  |";
            index++;
            cout.width(15);
            cout << job.get_location() << "\t|";
            cout.width(10);
            cout << job.get_type() << "\t|";
            cout.width(15);
            cout << job.get_role() << "\t|" << endl;
        }
        cout << "\t\t\t\t-------------------------------------------------------------------------" << endl;

        if (!owner) {
            cout << "\n" << endl;
            cout << "\t\t\t\t==========================================================================" << endl;
            cout << "Enter serial number of the job to see in detail\n(0 if you wish to skip): ";
            cin >> index;
            cout << "\t\t\t\t==========================================================================" << endl;

            if (index > 0 && index <= jobs.size()) {
                cout << jobs[index - 1];
            } else {
                cout << "Invalid job serial number." << endl;
            }
        }
    }

    friend ostream &operator<<(ostream &out, const Company &company);
    friend void display_companies(vector<Company> &Companies);
    friend void display_line(int line);
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
