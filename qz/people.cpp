#include <iostream>
#include "people.hpp"
using namespace std;
// Constructor
    // Default Constructor
PEOPLE::PEOPLE() : NAME(""), GENDER(""), DEGREE(""), BORN_YEAR(0), DESC(""){};
    // Parameter Constructor
PEOPLE::PEOPLE(string _NAME, string _GENDER, string _DEGREE, int _BORN_YEAR, string _DESC) : NAME(_NAME), GENDER(_GENDER), DEGREE(_DEGREE), BORN_YEAR(_BORN_YEAR), DESC(_DESC){};
    // Copy Constructor
PEOPLE::PEOPLE(PEOPLE& _PEOPLE) : NAME(_PEOPLE.NAME), GENDER(_PEOPLE.GENDER), DEGREE(_PEOPLE.DEGREE), BORN_YEAR(_PEOPLE.BORN_YEAR), DESC(_PEOPLE.DESC){};
// Assignment Operator
PEOPLE& PEOPLE::operator=(PEOPLE& n_PEOPLE)
{
    if(this != &n_PEOPLE)
    {
        NAME = n_PEOPLE.NAME;
        GENDER = n_PEOPLE.GENDER;
        DEGREE = n_PEOPLE.DEGREE;
        BORN_YEAR = n_PEOPLE.BORN_YEAR;
        DESC = n_PEOPLE.DESC;
    }
    return *this;
}
// Setter
void PEOPLE::name(string n_NAME)
{NAME = n_NAME;}
void PEOPLE::gender(string n_GENDER)
{GENDER = n_GENDER;}
void PEOPLE::degree(string n_DEGREE)
{DEGREE = n_DEGREE;}
void PEOPLE::born_year(int n_BORN_YEAR)
{BORN_YEAR = n_BORN_YEAR;}
void PEOPLE::desc(string n_DESC)
{DESC = n_DESC;}
// Getter
string PEOPLE::name()
{return NAME;}
string PEOPLE::gender()
{return GENDER;}
string PEOPLE::degree()
{return DEGREE;}
int PEOPLE::born_year()
{return BORN_YEAR;}
string PEOPLE::desc()
{return DESC;}
