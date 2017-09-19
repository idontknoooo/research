#include "header.h"

vector<string> army, political;
vector<string> schools, Ends, Begins, positions, deletes, others;
vector<string> students, teachers;

int load ( vector<string> &vs, const string &path ) {
    ifstream fin ( path.c_str() );
    string str;
    
    vs.clear ();
    while ( fin >> str )
        vs.push_back ( str );
    fin.close ();
    
    return 1;
}

int init () {
    load ( army, "data\\army.txt" );
    load ( schools, "data\\schools.txt" );
    load ( Ends, "data\\ends.txt" );
    load ( Begins, "data\\begins.txt" );
    load ( positions, "data\\positions.txt" );
    load ( deletes, "data\\deletes.txt" );
    load ( students, "data\\students.txt" );
    load ( teachers, "data\\teachers.txt" );
    load ( others, "data\\others.txt" );
    load ( political, "data\\political.txt" );
    srand ( time ( NULL ) );
    
    return 1;
}

void split_into_sentence ( vector<string> &C, string str ) {
    C.clear ();
    
    for ( int i = 0; i < Size(deletes); i++ )
        while ( str.find ( deletes[i] ) != string::npos )
            str.replace ( str.find ( deletes[i] ), deletes[i].length(), "," );
    
    int len = str.length();
    string tmp;
    for ( int j = 0; j < len; j++ ) {
        while ( j < len && str[j] != ',' && str[j] != ';' && str[j] != '.' && str[j] != '|' && str[j] != ':' ) {
            tmp += str[j];
            j++;
        }
        C.push_back ( tmp );
        tmp = "";
    }
}

void pre ( vector<string> &C ) {
    for ( int i = 0; i < Size(C); i++ )
        if ( C[i].find ( "µÈ½±" ) != string::npos )
            C[i] = "";
}

string num_to_str ( int x ) {
    string tmp, re;
    while ( x ) {
        tmp += (char)( x % 10 + '0' );
        x /= 10;
    };
    for ( int i = tmp.size()-1; i >= 0; i-- )
        re += tmp[i];
    return re;
}
