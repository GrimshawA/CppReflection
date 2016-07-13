#include <iostream>
#include "ParserBackendClang.h"

int main(int argc, char** argv)
{
	AbstractParserBackend* parser = new ClangParserBackend();
	parser->parseFile("test.h");
	system("pause");
	return 0;
}