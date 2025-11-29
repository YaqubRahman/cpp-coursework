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

int add_student_record() {
    ifstream in("data/grades.txt");
    // This was for debugging - remove later
    if (!in) {
        cerr << "Unable to open data/grades.txt" << endl;
    }
    string line;
    string student_id;
    int term_code;
    string module_code;
    int mark;
    while (getline(in, line)) {
        istringstream line_s(line);
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
        students[index].addModuleMark(term_code, module_code, mark);
    }
    return 0;
}

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
            for (it = modules.begin(); it != modules.end(); ++it) {
                string moduleCode = it->first;
                float mark = it->second;
                const float credit = module_credits[moduleCode];
                weighted_sum += mark * credit;
                credits_sum += credit;
            }
            float term_average = weighted_sum / credits_sum;
            term.setTermAverage(term_average);

            student_weighted_sum += weighted_sum;
            student_credits_sum += credits_sum;
        }
        float student_average = student_weighted_sum / student_credits_sum;
        students[i].setOverallAverage(student_average);
    }
return 0;
}

int main() {
    add_modules_record();
    add_student_record();
    compute_average();

    cout << fixed << setprecision(2);

    for (std::size_t i = 0; i < students.size(); ++i) {
        cout << '\n' << "Student " << "ID " << students[i].getId() << '\n';
        const auto& terms = students[i].getTerms();

        for (int i = 0; i < terms.size(); ++i) {
            const Term& t = terms[i];
            cout << "  Term " << t.getTermCode() << "\n";

            const std::map<std::string, int>& modules = t.getModules();
            map<string, int>::const_iterator it = modules.begin();

            for (it = modules.begin(); it != modules.end(); ++it)
            {
                const string code = it->first;
                const int mark = it->second;
                const string name = module_names[code];
                cout << "    " << code << name << mark << "\n";
            }
            cout << "  Term Average: " <<  t.getTermAverage() <<  "\n";
        }
        cout << "  Overall Average: " <<  students[i].getOverallAverage() <<  "\n";
    }
}
