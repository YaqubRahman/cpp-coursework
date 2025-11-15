#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Term.hpp"

class Student {
    std:: string id;
    std::vector<double> marks;
    Term terms;
};

#endif