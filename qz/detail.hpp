#ifndef DETAIL_HPP
#define DETAIL_HPP
#include <vector>
#include <string>
#include "people.hpp"
class DETAIL // People class after scrapped
{
private:
    PEOPLE PEO; // PEO with information
public:
    string NAME = ""; // Name of people
    bool GOV = 0; // Whether had/have government related job
    
    bool EDU_STATUS = 0; // Whether had/have education background
    vector<string> EDU; // if EDU_STATUS==1, then EDU is the name of school
    vector<string> GRAD_STATUS; // Whether graduated from school
    
    bool WORK_STATUS = 0; // Whether had/have work background
    vector<string> COMPANY; // If WORK_STATUS==1, then COMPANY is the name of company
    vector<string> JOB_TITLE; // Job title of people
    vector<string> S_DATE;  // Starting period
    vector<string> E_DATE; // Ending period
    
    bool COLLEGE_STATUS = 0; // Whether had/have worked in a college
    vector<string> COLLEGE; // If COLLEGE_STATUS==1, then COLLEGE is the name of the college
    vector<string> COLLEGE_TITLE; // College title of people
    vector<string> CS_DATE; // Starting period in college
    vector<string> CE_DATE; // Ending period in college
    
    bool MILITARY = 0;  // Whether had/have military experience
    
    bool PARTY_STATUS = 0; // Whether had/have party information
    string PARTY = ""; // If PARTY_STATUS==1, PARTY is the name of party
    
    bool OTHER_STATUS = 0; // Whether had/have other information
    vector<string> OTHER; // Other information
    
    // Constructors
    DETAIL();
    DETAIL(PEOPLE& _PEO);
    DETAIL(DETAIL& _DETAIL);
    // Assignment Operator
    DETAIL& operator=(DETAIL& n_PEOPLE);
    // Filter function
    void military(vector<string> vec);
    void party(vector<string> vec);
    void gov(vector<string> vec);
    void other(vector<string> vec);
    void edu(vector<string> vec1, vector<string> vec2);
    void company(vector<string> vec1, vector<string> vec2, vector<string> vec3);
    void college(vector<string> vec1, vector<string> vec2);
    
    // Minor function: used in filter function
    bool have_dates(string SEP_PIECE); // Search keyword to decide whether there are dates
    string convert_str(string str); // Convert chinese character to numerics. e.g. 九 -> 9
    int have_period(string& SEP_PIECE); // Check whether string have start-end time period, return length of delimeter
    vector<int> date_length(int index, string SEP_PIECE); // Return a vector with first element is starting index of 'date', the second is length of this date
    vector<string> locate_dates(string SEP_PIECE); // filter and add dates in S_DATE, E_DATE
    
    // NO GETTER OR SETTER, since all PUBLIC
    void people(PEOPLE n_people);
    PEOPLE people();
    
    // Split line into SEP
    void split(vector<string> &C, string str);
    void split_desc();
    vector<string> SEP; // Seperated piece of peo.desc()
};
#endif
