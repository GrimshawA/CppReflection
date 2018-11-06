#ifndef CPP_REFLECT_CODE_GEN_HPP_
#define CPP_REFLECT_CODE_GEN_HPP_

#include <string>
#include <vector>
#include <cpp_class.hpp>

class reflect_code_gen
{
public:
    void generate(const std::string& filename, std::vector<cpp_class> classes);

    void generateCpp(const std::string& filename, std::vector<cpp_class> classes);
};

#endif //CPP_REFLECT_CODE_GEN_HPP_
