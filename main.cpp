#include "classes/Student.hpp"
#include "classes/Term.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

vector<Student> students;

int add_student_record() {
    ifstream in("data/requests.txt");
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

int main() {
    add_student_record();
    for (std::size_t i = 0; i < students.size(); ++i) {
        cout << "Students loaded: " << students.size() << '\n';

    }
}
