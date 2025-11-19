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

    const std::string getId() const {
        return id;
    }

    const Term getTerms() const {
        return terms;
    }

    const double getOveralAverage() const {
        return overalAverage;
    }

    void setTerms(Term terms) {
        this->terms = terms;
    }

    void setOveralAverage(double overalAverage) {
        this->overalAverage = overalAverage;
    }


};

#endif