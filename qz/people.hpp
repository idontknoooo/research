#ifndef PEOPLE_HPP
#define PEOPLE_HPP
#include <string>
#include <vector>
using namespace std;
class PEOPLE
{
private:
    string NAME; // First column of file: NAME of chairman
    string GENDER; // Second column of file: GENDER of chairman
    string DEGREE; // Third column of file: DEGREE of chairman
    int BORN_YEAR; // Fourth column of file: BORN YEAR of chairman
    string DESC; // Fifth column of file: Other information of chairman, descriptions
public:
    // Constructor
    PEOPLE();
    PEOPLE(string _NAME, string _GENDER, string _DEGREE, int _BORN_YEAR, string _DESC);
    PEOPLE(PEOPLE& _PEOPLE);
    // Assignment Operator
    PEOPLE& operator=(PEOPLE& n_PEOPLE);
    // Setter
    void name(string n_NAME);
    void gender(string n_GENDER);
    void degree(string n_DEGREE);
    void born_year(int n_BORN_YEAR);
    void desc(string n_DESC);
    // Getter
    string name(); 
    string gender(); 
    string degree(); 
    int born_year(); 
    string desc();
    vector<string> del; // A vector contains keywords, which is about to delete. This vector need to be assign before use. Assignment is from reading a file which contains all the keywords.
};
#endif
