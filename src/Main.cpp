#include <iostream>
#include <parser.hpp>
#include <reflect_code_gen.hpp>

int main(int argc, char** argv)
{
    std::string demoFile = "character.hpp";

    cpp::parser p;

    if (!p.load(demoFile))
    {
        std::cout << "Failed to load file" << std::endl;
        return 1;
    }

    for (auto& c : p.classes)
    {
        std::cout << "Class: " << c.name << std::endl;

        for (auto& paren : c.parents)
        {
            std::cout << "Parent: " << paren.name << std::endl;
        }

		for (auto& m : c.macros)
		{
			std::cout << "Macro: " << m.macro << std::endl;
		}

        for (auto& f : c.fields)
        {
            std::cout << "Field: " << f.name << std::endl;
        }

        for (auto& f : c.funcs)
        {
            std::cout << "Func: " << f.name << std::endl;

            for (auto& arg : f.params)
            {
                std::cout << "Arg: " << arg.name << std::endl;
            }
        }
    }

    reflect_code_gen reflect;
    reflect.generate("character.reflect.hpp", p.classes);

	system("pause");

    return 0;
}
