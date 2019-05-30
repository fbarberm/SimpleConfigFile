# config_file
## Writing and reading configuration files in a very simple way.

config_file is a header-only library for writing and reading simple configuration files that associate variables with values as 'var1 = value1'. It is based on variadic templates for allowing a variable number of parameters.

In test_config.cpp there are examples of how to write and read a config file.

### Writing a configuration file

Basically, the file is written with the function:

    CFG::WriteFile(file, list_of_names, var1, var2, ...)

which has a variable number of parameters. *File* is an output stream and *list_of_names* is a container of *strings* (*vector*, *list*, *initializer_list*, ...).

For writing the file we can do something like this:
```c++
    // Variables that we want to store in the config file
    int x = 0;
    float f = 1.1;
    bool b = false;
    std::string s = "hola";
    std::vector<float> vf = {1.2, 2.1, 3};
    
    // Names for the variables in the config file. They can be different from the actual variable names.
    std::vector<std::string> ln = {"x","f","s","b","vf"};

    // Open the config file for writing
    std::ofstream f_out("test.cfg");
    if(! f_out)
        cout << "Error writing file !" << endl;
    else
    {
        CFG::WriteFile(f_out, ln, x,f,s,b,vf);
        f_out.close();
    }
```
This is the generated *test.cfg*:

    x=0
    f=1.1
    s=hola
    b=0
    vf=[1.2,2.1,3]

### Reading a configuration file

For reading the config file, we have the function:

    CFG::ReadFile(file, list_of_names, var1, var2, ...)

The type of the variables is taken into account for reading the data. Nowadays only simple types, vector and string are supported, and string only admits a single word (no blanks allowed). In any case, is very easy to add more types to the code.

If the name of a variable is not found in the configuration file, the variable remains unchanged. Therefore, it is a good idea to assign default values to the variables before reading the configuration file in case the variable is not found.

Any line in the config file beginning with **#** is ignored.

The previous config file can be read with the following code:
```c++
    // Variables where we want to store the data from the config file
    int x = 0;
    float f = 0;
    bool b = false;
    std::string s = "";
    std::vector<float> vf;
    
    // Names of the variables in the config file. 
    std::vector<std::string> ln = {"x","f","s","b","vf"};

    // Open the config file for reading
    std::ifstream f_in("test.cfg");
    if(! f_in)
        cout << "Error reading file !" << endl;
    else
    {
        CFG::ReadFile(f_in, ln, x,f,s,b,vf);
        f_in.close();
    }
```
There is also a function for setting the verbosity of the previous functions:

    CFG::SetDebugLevel(2);

The possible values are:
0 - No message, 1 - Only error, 2 - Show assignments

The default is 1.

### How to use

For using these functions in your program you only need to include *config_file.h*. You must compile with the **C++11** standard or greater (use *-std=c++11* for old versions of gcc).
