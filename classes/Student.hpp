#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Term.hpp"

class Student {
private:
    std:: string id;
    double overalAverage;
    Term terms;

public:
    Student(std::string id, Term terms, double overalAverage);

    const std::string getId() const;

    const Term getTerms() const;

    const double getOveralAverage() const;

    void setTerms(Term terms);

    void setOveralAverage(double overalAverage);


};

#endif