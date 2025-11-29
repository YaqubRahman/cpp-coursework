#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Term.hpp"

class Student {
private:
    std:: string id;
    std::vector<Term> terms;
    double overallAverage;

public:
    // Constructor
    Student(std::string id, const std::vector<Term> &terms, double overallAverage);

    // Getter function to get Student ID
    std::string getId() const;

    // Getter functions to get the terms associated with the student
    const std::vector<Term>& getTerms() const;
    std::vector<Term>& getTerms();

    // Getter function to get the overall average
    double getOverallAverage() const;

    // Setter function to set the Terms of the student
    void setTerms(const std::vector<Term> &terms);

    // Setter function to add the module marks
    void addModuleMark(int termCode, const std::string &moduleCode, int mark);

    // Setter function to set the overall average of the student
    void setOverallAverage(double overallAverage);


};

#endif