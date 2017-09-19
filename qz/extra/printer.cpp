#include "printer.hpp"
stringstream PRINTER::print_army()
{
    stringstream ss;
    string str = "army";
    ofstream fout = open_file(str);
    ss << DET.people().name() << "," << DET.people().MILITARY << "\n";
    return ss;
}

ofstream PRINTER::open_file(string str)
{
    ofstream fout;
    fout.open(str);
    if(!fout.is_open())
    {
        cerr << "Cannot open file: " << str << endl;
    }
    return fout;
}
