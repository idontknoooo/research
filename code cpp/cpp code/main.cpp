#include "header\header.h"
#include "header\function.h"
#include "header\basic_info.h"
using namespace std;

int main () {
    init ();
    
    ofstream f_army ( "output\\f_army.txt" );
    ofstream f_acainfo ( "output\\f_acainfo.txt" );
    ofstream f_political ( "output\\f_political.txt" );
    ofstream f_party ( "output\\f_party.txt" );
    ofstream f_study ( "output\\f_study.txt" );
    ofstream f_work ( "output\\f_work.txt" );
    ofstream f_other ( "output\\f_other.txt" );
    
    string line, tmp, cv;
    ifstream fin ( "data\\chairman_cv.txt" );
    int cnt = 0;
    while ( getline ( fin, line ) ) {
        istringstream sin ( line );
        string name;
        sin >> name >> tmp >> tmp >> tmp >> cv;
        cnt++;
        name = num_to_str ( cnt ) + "\t" + name;
        
        vector<string> C;
        split_into_sentence ( C, cv );
        pre ( C );

        if ( is_army ( C ) != -1 ) f_army << name << "\tYES" << endl;
        else f_army << name << "\tNO" << endl;
        //  输出军队背景
        
        if ( is_teacher ( C ) != -1 ) {
            vector<string> aca_info = get_teachers ( C );
            for ( int i = 0; i < Size(aca_info); i++ )
                f_acainfo << name << "\t" << aca_info[i] << endl;
        }
        else f_acainfo << name << "\tNO" << endl;
        //  输出学术背景

        if ( is_political ( C ) != -1 ) f_political << name << "\tYES" << endl;
        else f_political << name << "\tNO" << endl;
        //  输出政治关联

        f_party << name << "\t" << get_party ( C ) << endl;
        //  输出党派信息

        vector<string> study_info = get_study ( C );
        if ( study_info.empty () ) f_study << name << "\t无" << endl;
        for ( int j = 0; j < Size(study_info); j++ )
            f_study << name << "\t" << study_info[j] << endl;
        //  输出学历信息
        
        vector<string> work_info = get_works ( C );
        get_positions ( C, work_info );
        for ( int j = 0; j < Size(work_info); j++ )
            f_work << name << "\t" << work_info[j] << endl;
        //  输出工作信息
        
        vector<string> other_info = get_others ( C );
        for ( int j = 0; j < Size(other_info); j++ )
            f_other << name << "\t" << other_info[j] << endl;
        //  输出其他信息
    }
    
    fin.close ();
    f_army.close ();
    f_acainfo.close ();
    f_political.close ();
    f_party.close ();
    f_study.close ();
    f_work.close ();
    f_other.close ();
    
    return 0;
}
