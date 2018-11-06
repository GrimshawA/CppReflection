#include "parser.hpp"
#include "lex.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>

namespace cpp
{

bool parser::load(const std::string& filename)
{


    std::ifstream t(filename);
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

    lexer l;
    l.analyze(str);

    for (auto& t : l.tokens)
    {
        std::cout << "TK: " << t.text << std::endl;
    }

    parser_state ps;
    ps.tokens = l.tokens;
    ps.curr = &ps.tokens[0];

    while (ps.curr->type != RZTK_EOF)
    {
        if (ps.curr->type == RZTK_CLASS)
        {
            auto c = parseClass(ps);
            classes.push_back(c);
        }
        else
        {
            ps.next();
        }
    }

    return true;
}

cpp_class parser::parseClass(parser_state& ps)
{
    cpp_class c;

    c.name = ps.next().text;

    // Check for inheritance
    if (ps.next().type == RZTK_COLON)
    {
        // Irrelevant visib
        ps.next();
        auto parentClass = ps.next().text;
        ps.next();

        cpp_parent p;
        p.name = parentClass;
        c.parents.push_back(p);
    }

    // Open bracket
    ps.nextSkipSpace();
    ps.nextSkipSpace();

    if (ps.curr->type == RZTK_PUBLIC)
    {
        ps.next(); ps.nextSkipSpace(); // Skip public :
    }

    if (ps.current().type == RZTK_CLOSEBRACKET)
    {
        // We're done with the class already
        return c;
    }

    // Class contents loop
    while (ps.current().type != RZTK_CLOSEBRACKET)
    {
        auto decl = parseDecl(ps);

        if (decl.type == decl_composite::Func)
        {
            c.funcs.push_back(decl.func);
        }

		if (decl.type == decl_composite::MacroInvoke)
		{
			c.macros.push_back(decl.macro);
		}
    }

    return c;
}

void skipFunctionBody(parser_state& ps)
{
    if (ps.current().type != RZTK_OPENBRACKET)
    {
        ps.nextSkipSpace();
    }

    // ON {
    ps.nextSkipSpace();

    int parens = 1;

    while (parens > 0)
    {
        if (ps.current().type == RZTK_CLOSEBRACKET)
        {
            parens--;

            if (parens == 0)
                return;
        }
        else if (ps.current().type == RZTK_OPENBRACKET)
        {
            parens++;
        }
        ps.next();
    }
}

decl_composite parser::parseDecl(parser_state& ps)
{
    decl_composite compo;

    // First token of either a variable or method declaration or macro

    auto first = ps.current().text;

    ps.next();

	if (ps.current().type == RZTK_OPENPAREN)
	{
		// Macro detected
		compo.type = decl_composite::MacroInvoke;
		compo.macro.macro = first;

		ps.next(); ps.nextSkipSpace(); // Get out of macro
		return compo;
	}

    auto name = ps.current().text;

    compo.type = decl_composite::Func;
    compo.func.name = name;

    if (ps.next().type == RZTK_OPENPAREN)
    {
        ps.next();

        compo.func.params = parseParams(ps);
    }

    // We're done with the function, skip all function body
    skipFunctionBody(ps);

    // Let's go on to the next decl
    ps.nextSkipSpace();

    return compo;
}

std::vector<cpp_parameter> parser::parseParams(parser_state& ps)
{
    if (ps.current().type == RZTK_CLOSEPAREN)
    {
        return {};
    }

    std::vector<cpp_parameter> params;

    while (true)
    {
        bool is_const = false;

        if (ps.current().type == RZTK_CONST)
        {
            is_const = true;
            ps.next();
        }

        cpp_parameter param;
        auto type = ps.current().text;

		if (ps.next().type == RZTK_AMPERSAND)
		{
			ps.next();
		}

		// TODO: Handle here non named parameters

        auto name = ps.current().text;

        // go after the name
        ps.next();

        param.name = name;
        param.type.is_const = is_const;
        params.push_back(param);


        if (ps.current().type != RZTK_COMMA)
        {
            break;
        }
        else
        {
            ps.next();
        }
    }

    return params;
}

cpp_type parser::parseType(parser_state& ps)
{
	cpp_type t;

	// Types must start with identity, with optional template arguments

	return t;
}

}

