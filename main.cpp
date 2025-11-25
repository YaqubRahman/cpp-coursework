#include "classes/Student.hpp"
#include "classes/Term.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

// Vector holding all the student objects
vector<Student> students;
// Map holding all the module codes and module names
map<string, string> module_names;


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
            module_names[module_code] = module_name;
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

// int add_terms_record() {
//     ifstream in("data/grades.txt");
//
//     for(int i = 0; i < students.size(); i++){
//
//     }
//     return 0;
// }

int main() {
    add_modules_record();
    add_student_record();
    for (std::size_t i = 0; i < students.size(); ++i) {
        cout << "Student " << i << " ID " << students[i].getId() << '\n';
        const auto& terms = students[i].getTerms();
        cout << "Terms:\n";
        for (const Term& t : terms) {
            cout << "  Term code: " << t.getTermCode() << "\n";
        }
    }
    cout << module_names["CSC1027"];
}
