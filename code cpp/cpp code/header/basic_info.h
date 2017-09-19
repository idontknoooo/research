#include "header.h"

string get_name ( const vector<string> &C ) {
    return C[0];
}

int is_army ( vector<string> &C ) {
    int re = -1;
    
    for ( int i = 0; i < Size(C); i++ ) {
        bool flag = false;
        for ( int j = 0; j < Size(army) && !flag; j++ )
            if ( C[i].find ( army[j] ) != string::npos ) {
                flag = true;
                re = i;
                C[i] = "";
            }
    }
    
    return re;
}

int is_political ( vector<string> &C ) {
    int re = -1;
    for ( int i = 0; i < Size(C) && re == -1; i++ ) {
        for ( int j = 0; j < Size(political); j++ )
            if ( C[i].find ( political[j] ) != string::npos ) {
                re = 1;
                break;
            }
    }
    return re;
}

int is_teacher ( vector<string> &C ) {
    int re = -1;
    for ( int i = 0; i < Size(C) && re == -1; i++ ) {
        for ( int j = 0; j < Size(teachers); j++ )
            if ( C[i].find ( teachers[j] ) != string::npos ) {
                re = 1;
                break;
            }
    }
    return re;
}

string get_party ( vector<string> &C ) {
    string re = "无";
    for ( int i = 0; i < Size(C) && re == "无"; i++ ) {
        if ( C[i].find ( "中共党员" ) != string::npos )
            re = "中共党员";
        else if ( C[i].find ( "民革" ) != string::npos || C[i].find ( "国民党革命委员会" ) != string::npos )
            re = "民革";
        else if ( C[i].find ( "民盟" ) != string::npos )
            re = "民盟";
        else if ( C[i].find ( "民建" ) != string::npos || C[i].find ( "中国民主建国会" ) != string::npos )
            re = "民建";
        else if ( C[i].find ( "九三学社" ) != string::npos )
            re = "九三学社";
        else if ( C[i].find ( "致公党" ) != string::npos )
            re = "致公党";
        else if ( C[i].find ( "党员" ) != string::npos || C[i].find ( "共产党" ) != string::npos )
            re = "中共党员";
        
        if ( re != "无" ) C[i] = "";
    }
    
    return re;
}

vector<string> get_works ( vector<string> &C ) {
    vector<string> re;
    
    for ( int i = 0; i < Size(C); i++ ) {
        int location_p = C[i].length(), work_p = -1;
        bool found_location = false;
        for ( int j = 0; j < Size(Ends); j++ )
            if ( C[i].find ( Ends[j] ) != string::npos ) {
                int t = C[i].find ( Ends[j] ) + Ends[j].length();
                if ( work_p < t ) work_p = t;
            }
        for ( int j = 0; j < Size(Begins); j++ )
            if ( C[i].find ( Begins[j] ) != string::npos ) {
                found_location = true;
                int t = C[i].find ( Begins[j] );
                if ( location_p > t ) location_p = t;
            }
        if ( !found_location ) location_p = 0;
        string tmp;
        if ( work_p != -1 && work_p - location_p > 4) {
            tmp = C[i].substr ( location_p, work_p - location_p );
            re.push_back ( tmp );
            C[i].replace ( location_p, work_p-location_p, string("@") );
        }
    }
    return re;
}

void get_positions ( vector<string> &C, vector<string> &work ) {
    string str;
    vector<int> pos;
    for ( int i = 0; i < Size(C); i++ )
        for ( int j = 0; j < Size(C[i]); j++ ) {
            str += C[i][j];
            pos.push_back ( i );
        }
    int cnt = -1;
    for ( int i = 0; i < Size(str); i++ )
        if ( str[i] == '@' ) {
            i++;
            cnt++;
            string tmp;
            vector<int> ppos;
            for ( ; i < Size(str) && str[i] != '@'; i++ ) {
                tmp += str[i];
                ppos.push_back ( pos[i] );
            }
            //  提取两个单位信息之间的字符串

            for ( int k = 0; k < Size(positions); k++ )
                if ( tmp.find ( positions[k] ) != string::npos ) {
                    work[cnt] += string("\t") + positions[k];
                    
                    int j = ppos[tmp.find(positions[k])];
                    if ( C[j].find ( positions[k] ) == string::npos )
                        cout << "Error" << endl;
                    else C[j].replace ( C[j].find ( positions[k] ), positions[k].length(), "#" );
                    
                    string rep;
                    for ( int j = 0; j < Size(positions[k]); j++ )
                        rep += " ";
                    tmp.replace ( tmp.find ( positions[k] ), positions[k].length(), rep );
                }
            //  提取职务信息
            i--;
        }
}

vector<string> get_teachers ( vector<string> &C ) {
    //  返回简历中的学术经历
    vector<string> re;
    
    for ( int i = 0; i < Size(C); i++ ) {
        int tmp1 = -1, tmp2 = -1;
        for ( int j = 0; j < Size(schools) && tmp1 == -1; j++ )
            if ( C[i].find ( schools[j] ) != string::npos )
                tmp1 = j;
        for ( int j = 0; j < Size(teachers) && tmp2 == -1; j++ )
            if ( C[i].find ( teachers[j] ) != string::npos )
                tmp2 = j;
        if ( tmp1 + 1 && tmp2 + 1 ) {
            re.push_back ( schools[tmp1] + "\t" + teachers[tmp2] );
            //C[i].replace ( C[i].find ( schools[tmp1] ), schools[tmp1].length(), "~" );
            //C[i].replace ( C[i].find ( teachers[tmp2] ), teachers[tmp2].length(), "~" );
            C[i] = "";
        }
    }
    
    return re;
}

vector<string> get_study ( vector<string> &C ) {
    //  返回简历中的学历信息
    vector<string> re;
    
    for ( int i = 0; i < Size(C); i++ ) {
        int tmp1 = -1, tmp2 = -1;
        for ( int j = 0; j < Size(schools) && tmp1 == -1; j++ )
            if ( C[i].find ( schools[j] ) != string::npos )
                tmp1 = j;
        for ( int j = 0; j < Size(students) && tmp2 == -1; j++ )
            if ( C[i].find ( students[j] ) != string::npos )
                tmp2 = j;
        if ( tmp1 + 1 && tmp2 + 1 ) {
            re.push_back ( schools[tmp1] + "\t" + students[tmp2] );
            C[i] = "";
        } else if ( tmp1 + 1 ) {
            re.push_back ( schools[tmp1] );
            C[i] = "";
        }
    }
    
    return re;
}

vector<string> get_others ( vector<string> &C ) {
    //  返回简历中的其他信息
    vector<string> re;
    
    for ( int i = 0; i < Size(C); i++ ) {
        for ( int j = 0; j < Size(others); j++ )
            if ( C[i].find ( others[j] ) != string::npos ) {
                C[i].replace ( C[i].find(others[j]), others[j].length(), "" );
                re.push_back ( others[j] );
            }
    }
    
    return re;
}
