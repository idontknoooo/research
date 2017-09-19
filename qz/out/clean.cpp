// Note: this file doesn't work unless we sort the vector
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main()
{
    vector<string> vec;
    ofstream fout;
    fout.open("new_edu.csv");
    ifstream fin;
    fin.open("edu.csv");
    if(!fin.is_open())
    {
        cout << "Cannot open file" << endl;
    }
    
    string str;
    while(getline(fin, str))
    {
        vec.push_back(str);
    }
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    
    for(vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        fout << *it << endl;
    }
    return 0;
}
