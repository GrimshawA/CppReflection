#include "DaevaCodeGenerator.h"

#include "Structs/Class.h"

DaevaCodeGenerator::DaevaCodeGenerator()
{
	target = fopen("module_generated.cpp", "w");
}

void DaevaCodeGenerator::onClassDecl(const Class& c)
{
	printf("CLASS DECL %s\n", c.name.c_str());
}

void DaevaCodeGenerator::onMethodDecl(const Method& m)
{
	printf("METHOD DECL: %s\n", m.name.c_str());

	if (m.hasAttribute("AEON_INVOKABLE"))
	{
		std::string wrapperFunction;
		wrapperFunction += "void aeon_wrapper_" + m.identifier + "(aeVM* vm){\n";
		wrapperFunction += "// Code here\n";
		wrapperFunction += "}\n\n";

		fputs(wrapperFunction.c_str(), target);
	}
}