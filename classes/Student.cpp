#include "Term.hpp"
#include "Student.hpp"
#include <string>
#include <utility>

Student::Student(std::string id, const std::vector<Term> &terms, const double overallAverage)
    : id(std::move(id)), terms(terms), overallAverage(overallAverage) {
}

std::string Student::getId() const {
    return id;
}

// A const one
const std::vector<Term>& Student::getTerms() const {
    return terms;
}
// A non const one
std::vector<Term>& Student::getTerms()
{
    return terms;
}

double Student::getOverallAverage() const {
    return overallAverage;
}

void Student::setTerms(const std::vector<Term> &terms) {
    this->terms = terms;
}

void Student::addModuleMark(int termCode, const std::string &moduleCode, int mark) {
    // 1. Find existing term
    int termIndex = -1;
    for (int i = 0; i < terms.size(); ++i) {
        if (terms[i].getTermCode() == termCode) {
            termIndex = i;
            break;
        }
    }
    // 2. If not found, create a new term
    if (termIndex == -1) {
        terms.push_back(Term(termCode));
        termIndex = terms.size() - 1;
    }
    // 3. Add module + mark to that term
    terms[termIndex].addModuleMark(moduleCode, mark);
}


void Student::setOverallAverage(const double overallAverage) {
    this->overallAverage = overallAverage;
}



