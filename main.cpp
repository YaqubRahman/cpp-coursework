#include "classes/Student.hpp"
#include "classes/Term.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

// Vector holding all the student objects
vector<Student> students;
// Map holding all the module codes and module names
map<string, string> module_names;
// Map holding the module codes with the module credits
map<string, int> module_credits;

// Function to assign each module code to its corresponding module name
int add_modules_record() {
    ifstream in("data/modules.txt");
    string line;
    string module_code;
    string module_name;
    int credits;

    while (getline(in, line)) {
        istringstream line_s(line);
        if(!(line_s >> module_code >> credits)){
            continue;
        }
        if(getline(line_s, module_name)){
            module_names[module_code] = module_name +" ("+ to_string(credits) +" credits): ";
            module_credits[module_code] = credits;
        }
    }
    return 0;
}

// Function to add all the students from grades.txt with corresponding term code, module code and mark
int add_student_record() {
    ifstream in("data/grades.txt");
    string line;
    string student_id;
    int term_code;
    string module_code;
    int mark;
    while (getline(in, line)) {
        istringstream line_s(line);
        // We set an index to -1 indicating there is no student of index -1
        int index = -1;
        if (!(line_s >> student_id >> term_code >> module_code >> mark)) {
            continue;
        }
        for (int i = 0; i < students.size(); ++i) {
            if (student_id == students[i].getId()) {
                index = i;
            }
        }
        if (index == -1) {
            students.push_back(Student(student_id, {}, 0));
            index = students.size() - 1;
        }
        // Adding the module_code and mark for each student
        students[index].addModuleMark(term_code, module_code, mark);
    }
    return 0;
}

// Function to calculate the averages for term average and overall average for each student
int compute_average()
{
    for (int i = 0; i < students.size(); ++i)
    {
        float student_weighted_sum = 0;
        float student_credits_sum = 0;
        for (int j = 0; j < students[i].getTerms().size(); ++j)
        {
            float weighted_sum = 0;
            float credits_sum = 0;
            Term& term = students[i].getTerms()[j];
            const map<string,int>& modules = term.getModules();

            map<string,int>::const_iterator it;
            // Looping over each module in a specific term
            for (it = modules.begin(); it != modules.end(); ++it) {
                string moduleCode = it->first;
                float mark = it->second;
                const float credit = module_credits[moduleCode];
                weighted_sum += mark * credit;
                credits_sum += credit;
            }
            // Calculation for the term average
            float term_average = weighted_sum / credits_sum;
            term.setTermAverage(term_average);

            student_weighted_sum += weighted_sum;
            student_credits_sum += credits_sum;
        }
        // Calculation for the student average
        float student_average = student_weighted_sum / student_credits_sum;
        students[i].setOverallAverage(student_average);
    }
return 0;
}

// Function for handling what students should show from requests.txt
int handle_requests()
{
    ifstream in("data/requests.txt");
    string line;
    string student_id;
    int term_code;
    while (getline(in, line))
    {
        istringstream line_s(line);
        if (!(line_s >> student_id ))
        {
            continue;
        }
        // Check if there is a term code on the line
        bool has_term = false;
        if (line_s >> term_code)
        {
            has_term = true;
        }
        // Finding the student in the vector
        int index = -1;
        for (int i = 0; i < students.size(); ++i)
        {
            if (students[i].getId() == student_id)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            continue;
        }
        Student& student = students[index];

        // If no term is specified - show all terms
        if (!has_term)
        {
            cout << "\nStudent ID: " << student.getId() << "\n";
            const vector<Term>& terms = student.getTerms();
            // Loop over each term and output it
            for (int i = 0; i < terms.size(); ++i)
            {
                const Term& term = terms[i];
                cout << "  Term " << term.getTermCode() << ":" << "\n";

                const map<string, int>& modules = term.getModules();
                map<string,int>::const_iterator it;

                // Loop over each module with the code, name and mark and output it
                for (it = modules.begin(); it != modules.end(); ++it)
                {
                    const string code = it->first;
                    const int mark = it->second;
                    const string name = module_names[code];
                    cout << "    " << code << name << mark << "\n";
                }
                cout << "  Term Average: " <<  term.getTermAverage() <<  "\n";
            }
            cout << "  Overall Average: " << student.getOverallAverage() << "\n";
        }

        // If terms are specified
        else
        {
            cout << "\nStudent ID: " << student.getId() << '\n';
            const vector<Term> &terms = student.getTerms();
            // Loop over each term and output only the ones specified
            for (int i = 0; i < terms.size(); ++i)
            {
                const Term &term = terms[i];
                // Checking if the termcode specified is the current termcode
                if (term.getTermCode() == term_code)
                {
                    cout << "  Term " << term.getTermCode() << ":" << "\n";

                    const map<string, int> &modules = term.getModules();
                    map<string, int>::const_iterator it;

                    // Loop over each module with the code, name and mark and output it
                    for (it = modules.begin(); it != modules.end(); ++it)
                    {
                        const string code = it->first;
                        const int mark = it->second;
                        const string name = module_names[code];
                        cout << "    " << code << name << mark << "\n";
                    }
                    cout << "  Term Average: " << term.getTermAverage() << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}

// Main function where program starts execution
int main() {
    add_modules_record();
    add_student_record();
    compute_average();
    cout << fixed << setprecision(2);
    handle_requests();

    return 0;
}
