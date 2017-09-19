#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "people.hpp"
#include "detail.hpp"
using namespace std;
/*-----------------------------------------------------------------------------------------------*/
/*-------------------------------------------SEPERATION------------------------------------------*/
/*-----------------------------------------------------------------------------------------------*/
// Pre-set vectors for keywords
vector<string> military, begins, chairman_cv, college_title, companys, degrees, deletes, ending, gov, others, positions, schools, party;
// String for file stream
string str = "csv"; // Input folder name
string str3 = "out"; // Output folder name
// File name
string str_military = "military.csv";
string str_begins = "begins.csv";
string str_college_title = "college_title.csv";
string str_companys = "companys.csv";
string str_degrees = "degrees.csv";
string str_deletes = "deletes.csv";
string str_ending = "ends.csv";
string str_gov = "gov.csv";
string str_others = "others.csv";
string str_positions = "positions.csv";
string str_schools = "schools.csv";
string str_party = "party.csv";
// Load function to open stream to store keywords in vector
void load(vector<string>& vec, string str1, string str2);
// Load output stream
ofstream load_out(string str1, string str2);
/*-----------------------------------------------------------------------------------------------*/
/*-------------------------------------------SEPERATION------------------------------------------*/
/*-----------------------------------------------------------------------------------------------*/
int main()
{
    // Initialize all vectors
    load(military, str, str_military);
    load(begins, str, str_begins);
    load(college_title, str, str_college_title);
    load(companys, str, str_companys);
    load(degrees, str, str_degrees);
    load(deletes, str, str_deletes);
    load(ending, str, str_ending);
    load(gov, str, str_gov);
    load(others, str, str_others);
    load(positions, str, str_positions);
    load(schools, str, str_schools);
    load(party, str, str_party);
    // Initilize all output file
    ofstream out_military = load_out(str3, str_military);
    ofstream out_party = load_out(str3, str_party);
    ofstream out_other = load_out(str3, str_others);
    ofstream out_gov = load_out(str3, str_gov);
    ofstream out_edu = load_out(str3, "edu.csv");
    ofstream out_academy = load_out(str3, "academy.csv");
    ofstream out_experience = load_out(str3, "experience.csv");
    // Initialize PEO to store each line in .csv  
    PEOPLE peo;
    // Open input stream to read all info of CEO
    ifstream in_chairman;
    in_chairman.open("csv/chairman_cv.csv");
    if(!in_chairman.is_open())
    {
        cerr << "Unable to open chairman_cv.csv" << endl;
    }
    string line; // string of each line
    while(getline(in_chairman, line))
    {
        stringstream line_stream(line); // convert to stringstream and separate using ','
        char deli = ','; // delimiter for getline()
        int i = 0;
        while(i < 5) // 5 columns in total
        {
           getline(line_stream, line, deli);
           if(line=="--") 
           {line = "";} // convert missing BORN_DATE to empty string 
           if(i == 0)
           {peo.name(line);} // Read Name
           else if(i==1)
           {peo.gender(line);} // Read Gender
           else if(i==2) 
           {peo.degree(line);} // Read Degree
           else if(i==3)
           {
                if(!line.length()){line="0";}
                peo.born_year(stoi(line));  // Read Born_date
                deli = '\n'; // switch back to '\n' for desc()
           }
           else
           {peo.desc(line);} // Read Description
           ++i;
        }
        // Declare DETAIL with "peo" as member
        DETAIL det(peo);
        // Assign vector to members in PEO
        det.people().del = deletes;
        // Delete stuff
        det.split_desc();
        
        // Filter: for each line, filt out information and store them in variables in DETAIL
        det.military(military); // Whether worked in military services
        det.party(party); // Party which a person belongs to
        det.gov(gov); // Whether worked in government
        det.other(others); // Certificates and other honors
        det.edu(schools, degrees); // School and degree
        det.college(college_title, schools); // School worked, title and time period
        det.company(begins, ending, positions); // Company worked, title and time period       
        
        // Printer: Print out information to specific files
        out_military << det.people().name() << "," << det.MILITARY << "\n";
        out_party << det.people().name() << "," << det.PARTY << "\n";
        out_gov << det.people().name() << "," << det.GOV << "\n";
        for(int i=0; i < det.OTHER.size(); ++i)
        {
                out_other << det.people().name() << "," << det.OTHER[i] << "\n";
        }
        for(int i=0; i < det.EDU.size(); ++i)
        {
                out_edu << det.people().name() << "," << det.EDU[i] << "," << det.GRAD_STATUS[i] << "\n";
        }
        for(int i=0; i < det.COLLEGE.size(); ++i)
        {
                 out_academy << det.people().name() << "," << det.COLLEGE[i] << "," << det.COLLEGE_TITLE[i] << "," << det.CS_DATE[i] << "," << det.CE_DATE[i] << "\n";
        }
        for(int i=0; i < det.COMPANY.size(); ++i)
        {
                out_experience << det.people().name() << "," << det.COMPANY[i] << "," << det.JOB_TITLE[i] << "," << det.S_DATE[i] << "," << det.E_DATE[i] << "\n";
        }
    }
    
    // Close all output stream
    out_military.close();
    out_party.close();
    out_gov.close();
    out_other.close();
    out_edu.close();
    out_experience.close();
    out_academy.close();
    // Close input stream
    in_chairman.close();
    return 0;
}
/*-----------------------------------------------------------------------------------------------*/
/*-------------------------------------------SEPERATION------------------------------------------*/
/*-----------------------------------------------------------------------------------------------*/
void load(vector<string>& vec, string str1, string str2)
{
    // Open stream for specific name
    ifstream fin;
    fin.open((str1+"/"+str2));
    if(!fin.is_open())
    {
        cout << "Cannot open stream: " << str1 << "/" << str2 << endl;
    }
    string s;
    // Read in values
    while(getline(fin, s))
    {
        stringstream ss;
        ss.str(s);
        getline(ss, s, ',');
        vec.push_back(s);
    }
    // Close stream
    fin.close();
}
ofstream load_out(string str1, string str2)
{
    ofstream fout;
    fout.open((str1+"/"+str2));
    if(!fout.is_open())
    {
        cout << "Cannot open stream: " << str1 << "/" << str2 << endl;
    }
    return fout;
}
