#include "detail.hpp"
//#include "stream.hpp"
#include <string>
#include <iostream> 
using namespace std;
// Constructor
DETAIL::DETAIL() : PEO(){}
DETAIL::DETAIL(PEOPLE& _PEO) : PEO(_PEO){};
DETAIL::DETAIL(DETAIL& _DETAIL) : PEO(_DETAIL.PEO){};
// Assignment Operator
DETAIL& DETAIL::operator=(DETAIL& n_DETAIL)
{
    if(this != &n_DETAIL)
    {
        PEO = n_DETAIL.PEO;
    }
    return *this;
}
// Filter function
void DETAIL::military(vector<string> vec)
{
    /* 1. iterates given vector
       2. fint() each vec[i] in string
       3. if found: MILITARY will be assigned to 1, break iteration
       4. if not found for all element in vector, do nothing
    */
    vector<string>::iterator iter = vec.begin();
    for(iter; iter != vec.end(); ++iter)
    {
        size_t x = PEO.desc().find(*iter);
        if(x != string::npos)
        {
            MILITARY=1;
            break;
        }
    }
}
void DETAIL::party(vector<string> vec)
{
    /* 1. iterates given vector
       2. fint() each vec[i] in string
       3. if found: PARTY_STATUS will be assigned to 1, PARTY=(current *iter), break iteration
       4. if not found for all element in vector, assign a empty string
    */
    vector<string>::iterator iter = vec.begin();
    for(iter; iter != vec.end(); ++iter)
    {
        size_t x = PEO.desc().find(*iter);
        if(x != string::npos)
        {
            PARTY_STATUS=1;
            PARTY=*iter;
            break;
        }
    }
    if(!PARTY_STATUS)
    {
        PARTY = "";
    }
}
void DETAIL::gov(vector<string> vec)
{
    /* 1. iterates given vector
       2. fint() each vec[i] in string
       3. if found: GOV will be assigned to 1, break iteration
       4. if not found for all element in vector, do nothing
    */
    vector<string>::iterator iter = vec.begin();
    for(iter; iter != vec.end(); ++iter)
    {
        size_t x = PEO.desc().find(*iter);
        if(x != string::npos)
        {
            GOV=1;
            break;
        }
    }
}
void DETAIL::other(vector<string> vec)
{
    /* 1. iterates given vector
       2. fint() each vec[i] in string
       3. if found: OTHER_STATUS will be assigned to 1, OTHER.push_back(current *iter), keep iteration
       4. if not found for all element in vector, assign a "NONE"
    */
    vector<string>::iterator iter = vec.begin();
    for(iter; iter != vec.end(); ++iter)
    {
        size_t x = PEO.desc().find(*iter);
        if(x != string::npos)
        {
            OTHER_STATUS = 1;
            OTHER.push_back(*iter);
        }
    }
    if(!OTHER_STATUS)
    {
        OTHER.push_back("NONE");
    }
}
void DETAIL::edu(vector<string> vec1, vector<string> vec2)
{
    /*
        0. SEP contains multiple piece of string
           vec1 contains multiple school names
           vec2 contains multiple graduation status
        1. Iterate SEP:
                a. for each piece, find schools
                    i. if found: add school into 'EDU', search for grad_status
                        1> if found: add grad_status into 'GRAD_STATUS' and break
                        2> if not found for all: push an empty string and start next SEP iteration
                    ii. if not found for all do nothing and start next SEP iteration
        2. After iteration of SEP: if 'EDU' is empty, push "NONE" and empty string to 'EDU' and 'GRAD_STATUS' corespondingly 
    */
    bool tf = 0;
    for(vector<string>::iterator it = SEP.begin(); it != SEP.end(); ++it) // SEP iterator
    {
        
        for(vector<string>::iterator it1 = vec1.begin(); it1 != vec1.end(); ++it1)
        {
            size_t x1 = (*it).find(*it1);
            if(x1 != string::npos && (*it1).length()>1) // if found and it is not an empty string
            {
                EDU.push_back(*it1);
                tf = 1;
                EDU_STATUS = 1;
            } 
            if(tf)
            {
                int size_GS = GRAD_STATUS.size();
                for(vector<string>::iterator it2 = vec2.begin(); it2 != vec2.end(); ++it2)
                {
                    size_t x2 = (*it).find(*it2);
                    if(x2 != string::npos && (*it2).length()>1)
                    {
                        
                        GRAD_STATUS.push_back(*it2);
                        break;
                    }
                }
                if(GRAD_STATUS.size()==size_GS) // if sizes are same, meaning not found, then push empty string
                {GRAD_STATUS.push_back("");}
            }
            tf = 0;
        }

    }
    if(!EDU.size())
    {
        EDU.push_back("NONE");
        GRAD_STATUS.push_back("");
    }
}
void DETAIL::company(vector<string> vec1, vector<string> vec2, vector<string> vec3)
{
    /*
        0. SEP contains multiple piece of string
           vec1 contains multiple location names
           vec2 contains multiple department names
           vec3 contains multiple job titles
        1. Iterate SEP:
                a. for each piece, find locations names
                    i. if found: start find department names
                        1> if found: push string and break to step 'b'
                        2> if not found for all: push an empty string and start next SEP iteration
                    ii. if not found for all do nothing and start next SEP iteration
                b. once found both location and department, start find job_titles
                    i. if found: push and break;
                    ii. if not found for all: push empty string
                c. once found all three above: push dates
        2. After iteration of SEP: if 'EDU' is empty, push "NONE" and empty string to different vectors corespondingly 
    */
    bool tf = 0, tf1 = 0;
    string tmp = "";
    for(vector<string>::iterator it = SEP.begin(); it != SEP.end(); ++it)
    {
        //cout << *it << endl;
        int size_C = COMPANY.size();
        // search start words. e.g. 河南
        for(vector<string>::iterator it1 = vec1.begin(); it1 != vec1.end(); ++it1)
        {
            size_t x1 = (*it).find(*it1);
            // if got start words, search end word. e.g. 财政局
            if(x1 != string::npos && (*it1).length()>1)
            {
                for(vector<string>::iterator it2 = vec2.begin(); it2 != vec2.end(); ++it2)
                {
                    size_t x2 = (*it).find(*it2);
                    if(x2 != string::npos && (*it2).length()>1)
                    {
                        tmp = (*it).substr(x1, x2-x1+(*it2).length());
                        COMPANY.push_back(tmp);
                        tf = 1;
                        WORK_STATUS = 1;
                        break;
                    }
                }
            } 
            if(tf)
            {
                int size_JT = JOB_TITLE.size();
                for(vector<string>::iterator it3 = vec3.begin(); it3 != vec3.end(); ++it3)
                {
                    size_t x3 = (*it).find(*it3);
                    if(x3 != string::npos && (*it3).length()>1)
                    {
                        JOB_TITLE.push_back(*it3);
                        tf1 = 1;
                        break;
                    }
                }
                if(JOB_TITLE.size()==size_JT)
                {
                    JOB_TITLE.push_back("");
                    tf1 = 1;
                }
            }
            // Get time peiords
            if(tf1 && tf)
            {
                vector<string> tmp_vec;
                if(have_dates(*it))
                {
                    tmp_vec = locate_dates(*it);
                    if(tmp_vec.size()>0)
                    {
                        S_DATE.push_back(tmp_vec[0]);
                        E_DATE.push_back(tmp_vec[1]);
                        //cout << S_DATE.back() << "---" << E_DATE.back() << endl;
                    }
                    else
                    {
                        S_DATE.push_back("");
                        E_DATE.push_back("");
                    }
                }
                else
                {
                    S_DATE.push_back("");
                    E_DATE.push_back("");
                }
            }
            //cout << COMPANY.size() << "--" << JOB_TITLE.size() << "--" << S_DATE.size() << "--" << E_DATE.size() << endl;
            tf = 0;
            tf1 = 0;
            if(COMPANY.size()!=size_C)
            {
                break;
            }
        }
    }
    // if not experience at all
    if(!JOB_TITLE.size())
    {
        COMPANY.push_back("NONE");
        JOB_TITLE.push_back("");
        S_DATE.push_back("");
        E_DATE.push_back("");
    }
}
void DETAIL::college(vector<string> vec1, vector<string> vec2)
{
    /*
        Similiar to DETAIL::company()
    
    */
    bool tf = 0, tf1 = 0;
    for(vector<string>::iterator it = SEP.begin(); it != SEP.end(); ++it)
    {
        int size_CT = COLLEGE_TITLE.size();
        for(vector<string>::iterator it1 = vec1.begin(); it1 != vec1.end(); ++it1)
        {
            size_t x1 = (*it).find(*it1);
            if(x1 != string::npos && (*it1).length()>1)
            {
                COLLEGE_TITLE.push_back(*it1);
                tf = 1;
                COLLEGE_STATUS = 1;
            } 
            if(tf)
            {
                int size_C = COLLEGE.size();
                for(vector<string>::iterator it2 = vec2.begin(); it2 != vec2.end(); ++it2)
                {
                    size_t x2 = (*it).find(*it2);
                    if(x2 != string::npos && (*it2).length()>1)
                    {
                        COLLEGE.push_back(*it2);
                        tf1 = 1;
                        break;
                    }
                }
                if(COLLEGE.size()==size_C)
                {
                    COLLEGE_TITLE.pop_back();
                }
            }
            if(tf1 && tf)
            {
                vector<string> tmp_vec;
                if(have_dates(*it))
                {
                    tmp_vec = locate_dates(*it);
                    if(tmp_vec.size()>0)
                    {
                        CS_DATE.push_back(tmp_vec[0]);
                        CE_DATE.push_back(tmp_vec[1]);
                    }
                    else
                    {
                        CS_DATE.push_back("");
                        CE_DATE.push_back("");
                    }
                }
                else
                {
                    CS_DATE.push_back("");
                    CE_DATE.push_back("");
                }
            }
            tf = 0;
            tf1 = 0;
            if(COLLEGE_TITLE.size()!=size_CT)
            {
                break;
            }
        }

    }
    if(!COLLEGE.size())
    {
        COLLEGE.push_back("NONE");
        COLLEGE_TITLE.push_back("");
        CS_DATE.push_back("");
        CE_DATE.push_back("");
    }
}
// Minor functions
bool DETAIL::have_dates(string SEP_PIECE)
{
    /*
        Return true if string have dates, false otherwise
    */
    vector<string> indic = {"年","一九","二〇","二零","19","20"};
    vector<string>::iterator it = indic.begin();
    for(it; it != indic.end(); ++it)
    {
        if(SEP_PIECE.find(*it) != string::npos)
        {
            return true;
        }
    }
    return false;
}
int DETAIL::have_period(string& SEP_PIECE)
{
    /*
        Return seperator's length if string have 2 dates (a time peiord), otherwise 0
    */
    vector<string> indic = {"起","至今","至","--","-","～","~","——","—","//"};
    for(vector<string>::iterator it = indic.begin(); it != indic.end(); ++it)
    {
        size_t tmp  = SEP_PIECE.find(*it);
        if(tmp != string::npos)
        {
            if(!(*it).compare("起") || !(*it).compare("至今"))
            {
                SEP_PIECE.replace(tmp, (*it).length(), ""); 
                return 0;
            }
            else
            {
                SEP_PIECE.replace(tmp, (*it).length(), "#");
            }
            return (*it).length(); // return length of delimiter
        }
    }
    return 0;
}
string DETAIL::convert_str(string str)
{
    /*
        Convert Chinese character to numerics
    */
    string n_str = str;
    vector<string> ori = {"一","二","三","四","五","六","七","八","九","零","〇","十","年","月","日","-"};
    vector<string> cov = {"1","2","3","4","5","6","7","8","9","0","0","1","/","/","","/"};
    for(int i = 0; i < ori.size(); ++i)
    {
        for(int j = 0; j < n_str.length(); ++j)
        {
            size_t pos = n_str.find(ori[i]);
            if(pos != string::npos)
            {
                n_str.replace(pos, ori[i].length(), cov[i]);
            }
        }
    }
    return n_str;
}
vector<int> DETAIL::date_length(int index, string SEP_PIECE)
{
    /*
        Return the length of date and starting index
    */
    vector<int> pos;
    int len = 0;
    bool tf = 1, tf1 = 0;
    int non_digit = 0;
    for(int i = index; i < SEP_PIECE.length()-1; ++i)
    {
        if(isdigit(SEP_PIECE[i]) && tf)
        {
            pos.push_back(i);
            len = i;
            tf = 0;
            tf1 = 1;
        }
        else if(SEP_PIECE[i] == '#' && tf1) // for two period
        {
            len = i - len;
            tf1 = 0;
            break;
        }
        else if(!isdigit(SEP_PIECE[i]) && tf1) // for one period
        {
            if(!isdigit(SEP_PIECE[i+1]))
            {
                non_digit++;
            }
            if(non_digit==1)
            {
                len = i - len;
                tf1 = 0;
                break;
            }
        }
    }
    pos.push_back(len);
    return pos;
}
vector<string> DETAIL::locate_dates(string SEP_PIECE_ORI)
{
    /*
        Return vector with starting date and ending date
    
    */
    vector<string> dates;
    string SEP_PIECE = convert_str(SEP_PIECE_ORI);
    int have = have_period(SEP_PIECE);
    //cout << SEP_PIECE << endl;
    vector<int> pos = date_length(0, SEP_PIECE);
    vector<int> pos1;
    if(!have) // single peiord
    {
        //cout << pos[0] << "---" << pos[1] << endl;  
        //cout << SEP_PIECE.substr(pos[0], pos[1]) << endl;
         dates.push_back(SEP_PIECE.substr(pos[0], pos[1]));
         dates.push_back("");
    }
    else
    {
         int tmp = pos[0]+pos[1];
         pos1 = date_length(tmp, SEP_PIECE);
         dates.push_back(SEP_PIECE.substr(pos[0], pos[1]));
         dates.push_back(SEP_PIECE.substr(pos1[0], pos1[1]));
    }
    return dates;    
}
// NO OTHER GETTER OR SETTER, since all PUBLIC
// Setter
void DETAIL::people(PEOPLE n_people)
{PEO = n_people;}
// Getter
PEOPLE DETAIL::people()
{return PEO;}
// Split function
void DETAIL::split(vector<string> &C, string str) 
{
    C.clear ();
    for(int i = 0; i < PEO.del.size(); i++)
    {
        while(str.find(PEO.del[i]) != string::npos)
            {
                str.replace(str.find(PEO.del[i]), PEO.del[i].size(), ",");
            }
    }    
    int len = str.size();
    string tmp;
    for(int j = 0; j < len; j++) 
    {
        while (j < len && str[j] != ',' && str[j] != ';' && str[j] != '.' && str[j] != '|' && str[j] != ':' ) 
        {
            tmp += str[j];
            j++;
        }
        C.push_back(tmp);
        tmp = "";
    }
}
void DETAIL::split_desc()
{
    split(SEP, PEO.desc());
}
