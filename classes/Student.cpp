#include "Term.hpp"
#include "Student.hpp"
#include <string>
#include <utility>

// Constructor
Student::Student(std::string id, const std::vector<Term> &terms, const double overallAverage)
    : id(std::move(id)), terms(terms), overallAverage(overallAverage) {
}

// Getter function to get Student ID
std::string Student::getId() const {
    return id;
}

// Getter functions to get the terms associated with the student
// A const one that is read-only access
const std::vector<Term>& Student::getTerms() const {
    return terms;
}
// A non const one that can be modified
std::vector<Term>& Student::getTerms()
{
    return terms;
}

// Getter function to get the overall average
double Student::getOverallAverage() const {
    return overallAverage;
}

// Setter function to set the Terms of the student
void Student::setTerms(const std::vector<Term> &terms) {
    this->terms = terms;
}

// Setter function to add the module marks
void Student::addModuleMark(int termCode, const std::string &moduleCode, int mark) {
    // Find an existing term
    int termIndex = -1;
    for (int i = 0; i < terms.size(); ++i) {
        if (terms[i].getTermCode() == termCode) {
            termIndex = i;
            break;
        }
    }
    // If not found, create a new term
    if (termIndex == -1) {
        terms.push_back(Term(termCode));
        termIndex = terms.size() - 1;
    }
    // Add the module and mark to that term
    terms[termIndex].addModuleMark(moduleCode, mark);
}

// Setter function to set the overall average of the student
void Student::setOverallAverage(const double overallAverage) {
    this->overallAverage = overallAverage;
}



