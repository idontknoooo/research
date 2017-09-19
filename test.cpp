#include <iostream>
#include <string>
#include <vector>
using namespace std;
string convert_str(string str)
{
    string n_str = str;
    vector<string> ori = {"一","二","三","四","五","六","七","八","九","零","〇","十","年","月","日","-", "//"};
    vector<string> cov = {"1","2","3","4","5","6","7","8","9","0","0","1","/","/","","/","#"};
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
int main()
{
    vector<string> vec;
	string s = "hello world yes";
	string s1 = "yes";
	vec.push_back(s1);
	vec.push_back("world");
	auto iter = vec.begin();
	for(iter; iter!=vec.end(); ++iter)
	{
	    size_t x1 = s.find(*iter);
	    if(x1 != string::npos)
	    {
	        cout << "found" << endl;
	        cout << x1 << endl;
	        cout << *iter << endl;
	        //break;
	    }
	}
	string s12 = "2009-2-21至二零一零年十二月九日";
	string s13 = "一九九八年七月十三日--2000-2-2";
	string s14 = "2001-12-2于这里";
	/*
	for(int i = 0; i < s12.length()-2; i=i+3)
	{
	    cout << s12.substr(i, 3);
	}
	*/
	cout << convert_str(s12) << endl;
	cout << convert_str(s14) << endl;
	return 0;
}
