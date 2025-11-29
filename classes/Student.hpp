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
    Student(std::string id, const std::vector<Term> &terms, double overallAverage);

    std::string getId() const;

    const std::vector<Term>& getTerms() const;
    std::vector<Term>& getTerms();

    double getOverallAverage() const;

    void setTerms(const std::vector<Term> &terms);

    void addModuleMark(int termCode, const std::string &moduleCode, int mark);

    void setOverallAverage(double overallAverage);


};

#endif