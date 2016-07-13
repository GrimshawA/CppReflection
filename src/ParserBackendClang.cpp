#include "ParserBackendClang.h"

#include <clang-c/Index.h>

void ClangParserBackend::parseFile(const std::string& filename)
{
	printf("PARSING FILE\n");

	CXTranslationUnit TU = clang_createTranslationUnitFromSourceFile(0, filename.c_str(), 0, 0, 0, 0);
	CXCursor cursor = clang_getCursor(TU, CXSourceLocation());
	
	
}