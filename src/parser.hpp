#ifndef CPP_PARSER_HPP_
#define CPP_PARSER_HPP_

#include <string>
#include <vector>
#include "cpp_class.hpp"
#include "lex.hpp"

namespace cpp
{
    class parser_state
    {
    public:

        token& current()
        {
            return *curr;
        }

        token& next()
        {
            if (curr->type == RZTK_EOF)
                return *curr;

            curr++;
            return *curr;
        }

        token& peek()
        {
            auto n = curr + 1;
            return *n;
        }

        token& nextSkipSpace()
        {
            if (curr->type == RZTK_EOF)
                return *curr;

            curr++;

            while (curr->type == RZTK_NEWLINE)
            {
                curr++;
            }

            return *curr;
        }

    public:
        std::vector<token> tokens;
        token* curr = nullptr;
    };

    class decl_composite
    {
    public:
        enum Result
        {
            Func,
            MacroInvoke,
            Field
        };

        Result type;
        cpp_function func;
		cpp_macro_invoke macro;
        cpp_field field;
    };

    class parser
    {
    public:

        bool load(const std::string& filename);

        cpp_class parseClass(parser_state& ps);
        decl_composite parseDecl(parser_state& ps);
        std::vector<cpp_parameter> parseParams(parser_state& ps);
		cpp_type parseType(parser_state& ps);

        std::vector<cpp_class> classes;
    };
}

#endif // CPP_PARSER_HPP_
