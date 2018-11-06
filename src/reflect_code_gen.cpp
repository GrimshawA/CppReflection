#include "reflect_code_gen.hpp"
#include <sstream>

void reflect_code_gen::generate(const std::string& filename, std::vector<cpp_class> classes)
{
    std::string fileNameNoExt = filename.substr(0, filename.find_last_of('.'));

    generateCpp(fileNameNoExt + ".cpp", classes);

    FILE* fp = fopen(filename.c_str(), "w");

    if (!fp)
        return;

    std::stringstream ss;
    ss << "#ifndef REFLECT_HPP_\n";
    ss << "#define REFLECT_HPP_\n\n";

    for (auto& c : classes)
    {
        ss << "template<>\n";
        ss << "class reflection<" << c.name << "> {\n";

        // name
        ss << "\tstatic const char* name;\n\n";

        // fields
        ss << "\tstd::vector<reflection_field> fields;\n";

        ss << "};\n\n";
    }

    ss << "#endif\n";


    auto str  = ss.str();
    fputs(str.c_str(), fp);
    fclose(fp);
}

void reflect_code_gen::generateCpp(const std::string& filename, std::vector<cpp_class> classes)
{
    FILE* fp = fopen(filename.c_str(), "w");

    if (!fp)
        return;

    std::stringstream ss;

    ss << "#include \"dummy.hpp\"\n\n";

    for (auto& c : classes)
    {
        // Comment
        ss << "// Reflection for: " << c.name << "\n\n";

        // name
        ss << "const char* reflection<" << c.name << ">::name = \"" << c.name << "\";\n\n";
    }

    auto str  = ss.str();
    fputs(str.c_str(), fp);
    fclose(fp);
}
