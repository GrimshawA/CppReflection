#include <iostream>
#include <parser.hpp>

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

        for (auto& f : c.funcs)
        {
            std::cout << "Func: " << f.name << std::endl;

            for (auto& arg : f.params)
            {
                std::cout << "Arg: " << arg.name << std::endl;
            }
        }
    }

	system("pause");

    return 0;
}
