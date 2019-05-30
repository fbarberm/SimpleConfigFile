
/**
 * Program that shows examples of usage of config_file.h
 * 
 * @file test_config.cpp
 * @author F. Barber
 */

#include<iostream>
#include<string>
#include<vector>
#include "config_file.h"

using std::cout;
using std::endl;

int main(void)
{
    // Variables that we want to store in the config file
    int x = 0;
    float f = 1.1;
    bool b = false;
    std::string s = "hola";
    std::vector<float> vf = {1.2, 2.1, 3};

    CFG::SetDebugLevel(2);
    
    // Names for the variables in the config file. They can be different from the actual variable names.
    std::vector<std::string> ln = {"x","f","s","b","vf"};
    CFG::WriteFile(std::cout, ln, x,f,s,b,vf);
    cout << "\nWriting to test.cfg..." << endl;

    // Open the config file for writing
    std::ofstream f_out("test.cfg");
    if(! f_out)
        cout << "Error writing file !" << endl;
    else
    {
        CFG::WriteFile(f_out, ln, x,f,s,b,vf);
        f_out.close();
    }

    cout << "Read from file test.cfg:" << endl;
    
    // Open the config file for reading
    std::ifstream f_in("test.cfg");
    if(! f_in)
        cout << "Error reading file !" << endl;
    else
    {
        CFG::ReadFile(f_in, ln, x,f,s,b,vf);
        f_in.close();
    }
    
    cout << "Read from file test.cfg. Reading int as float and float as int. Also vf2 does not exist in file." << endl;

    int x2 = -1;
    float f2 = -1;
    
    std::ifstream f_in2("test.cfg");
    if(! f_in2)
        cout << "Error reading file !" << endl;
    else
    {
        CFG::ReadFile(f_in2, {"x","f","s","b","vf2"}, f2,x2,s,b,vf);
        cout << "Values obtained:" << endl;
        CFG::WriteFile(std::cout, {"f2","x2","s","b","vf"}, f2,x2,s,b,vf);
        f_in2.close();
    }
    return 0;
}
