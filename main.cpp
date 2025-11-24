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


// int add_modules_record() {
//     ifstream in("data/modules.txt");
//     string line;
//     string module_code;
//     string module_name;
//
//     while (getline(in, line)) {
//         istringstream line_s(line);
//
//         if(!(line_s >> module_code)){
//             continue;
//         }
//
//         if(line_s >> ws && getline(line_s, module_name)){
//             module_names[module_code] = module_name;
//         }
//     }
//     return 0;
// }

int add_student_record() {
    ifstream in("data/requests.txt");
    if (!in) {
        cerr << "Unable to open data/requests.txt" << endl;
    }


    string line;
    string student_id;
    double term_code;

    while (getline(in, line)) {
        istringstream line_s(line);

        if(!(line_s >> student_id)){
            continue;
        }

        if(line_s >> term_code){
            students.push_back(Student(student_id, Term(term_code), 0.0));
        } else{
            students.push_back(Student(student_id, Term(0), 0.0));
        }
    }
    return 0;
}

// int add_terms_record() {
//     ifstream in("data/grades.txt");
//     ifstream in("data/modules.txt");
//
//     for(int i = 0; i < students.size(); i++){
//     }
// }

int main() {
    add_student_record();
    for (std::size_t i = 0; i < students.size(); ++i) {
        cout << "Student " << i << " ID " << students[i].getId() << '\n';

    }
}
