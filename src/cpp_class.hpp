#ifndef CPP_CLASS_HPP_
#define CPP_CLASS_HPP_

#include <string>
#include <vector>

class cpp_type
{
public:
    bool is_const;
    bool is_volatile;
    std::string name;
};

class cpp_parameter
{
public:
    std::string name;
    cpp_type type;
};

class cpp_function
{
public:
    std::string name;
    std::string ret;
    std::vector<cpp_parameter> params;
};

class cpp_parent
{
public:
    std::string name;
};

class cpp_class
{
public:

    std::vector<cpp_function> funcs;
    std::vector<cpp_parent> parents;
    std::string name;
};


#endif // CPP_CLASS_HPP_
