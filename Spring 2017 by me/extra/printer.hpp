#ifndef PRINTER_HPP
#define PRINTER_HPP
#include <iostream>
#include "detail.hpp"
#include <fstream>
#include <sstream>
using namespace std;
class PRINTER
{
private:
    DETAIL DET;
public:
    stringstream print_army();
    ofstream open_file(string str);
};
#endif
