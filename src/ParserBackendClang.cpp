#include "ParserBackendClang.h"
#include "CodeGenerator.h"
#include "Structs/Class.h"

#include <clang-c/Index.h>
#include <vector>
#include <string>
#include <sstream>


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

std::string tostring(CXString s)
{
	std::string stdStr = clang_getCString(s);
	clang_disposeString(s);
	return stdStr;
}

Method BuildMethod(CXCursor cursor)
{
	Method m;
	CXType cxType = clang_getCursorType(cursor);
	CXTypeKind cxTypeKind = cxType.kind;
	m.name = tostring(clang_getCursorDisplayName(cursor));
	m.identifier = split(m.name, '(')[0];
	printf("METHOD %s\n", m.name.c_str());

	clang_visitChildren(cursor, [](CXCursor c, CXCursor parent, CXClientData method){
		CXCursorKind kind = clang_getCursorKind(c);
		if (kind == CXCursor_AnnotateAttr)
		{
			std::string annot = tostring(clang_getCursorDisplayName(c));
			static_cast<Method*>(method)->annotations.push_back(annot);
			printf("%s", annot.c_str());
		}

		return CXChildVisit_Continue;
	}, &m);

	return m;
}

void ClangParserBackend::parseFile(const std::string& filename)
{
	printf("PARSING FILE %s\n", filename.c_str());

	std::vector<char*> args;
	args.push_back("-x");
	args.push_back("c++");

	CXIndex idx = clang_createIndex(0, 1);
	CXTranslationUnit TU = clang_createTranslationUnitFromSourceFile(idx, filename.c_str(), args.size(), args.data(), 0, 0);
	CXCursor root = clang_getTranslationUnitCursor(TU);

	
	CXCursorVisitor visitor = [](CXCursor cursor, CXCursor parent, CXClientData parser) -> CXChildVisitResult{
		CXCursorKind kind = clang_getCursorKind(cursor);
		ClangParserBackend* backend = (ClangParserBackend*)parser;

		std::string annotation;

		//CXCursorKind::
		switch (kind)
		{
		case CXCursor_ClassDecl: {
									 Class c;
									 c.name = tostring(clang_getTypeSpelling(clang_getCursorType(cursor)));
									 if (backend->m_codeGen) backend->m_codeGen->onClassDecl(c);
									 //printf("CLASS! %s\n", c.name.c_str());
									 break;
		}
		case CXCursor_AnnotateAttr: {
										std::string annotation;
										printf("annotation\n");
										break;
		}
		case CXCursor_CXXMethod: {
									 Method m = BuildMethod(cursor);
									 if (backend->m_codeGen) backend->m_codeGen->onMethodDecl(m);
									 return CXChildVisit_Continue;
		}
		}
		//printf("NODE %d\n", kind);
		return CXChildVisit_Recurse;
	};

	clang_visitChildren(root, visitor, this);

}