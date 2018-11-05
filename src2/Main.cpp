#include <iostream>
#include "ParserBackendClang.h"
#include "DaevaCodeGenerator.h"

int main(int argc, char** argv)
{
	AbstractParserBackend* parser = new ClangParserBackend();
	CodeGenerator* codeGen = new DaevaCodeGenerator;
	parser->setCodeGenerator(codeGen);
	parser->parseFile("test.h");
	system("pause");
	return 0;
}