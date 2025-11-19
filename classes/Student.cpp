#include "Term.cpp"
#include "Student.hpp"
#include <string>

Student::Student(std::string id, Term terms, double overalAverage)
    : id(id), terms(terms), overalAverage(overalAverage) {
}

const std::string Student::getId() const {
    return id;
}

const Term Student::getTerms() const {
    return terms;
}

const double Student::getOveralAverage() const {
    return overalAverage;
}

void Student::setTerms(Term terms) {
    this->terms = terms;
}

void Student::setOveralAverage(double overalAverage) {
    this->overalAverage = overalAverage;
}



