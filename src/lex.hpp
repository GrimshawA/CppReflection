#ifndef CPP_LEX_HPP_
#define CPP_LEX_HPP_

#include <string>
#include <vector>

namespace cpp {

    enum token_t
    {
        RZTK_LINECOMMENT,
        RZTK_MULTICOMMENT,
        RZTK_IDENTIFIER,
        RZTK_CLASS,
        RZTK_STRUCT,
        RZTK_LET,
        RZTK_BINOP,
        RZTK_STATIC,
        RZTK_THIS,
        RZTK_COMMA,
        RZTK_COLON,
        RZTK_TYPEDEF,
        RZTK_EOF,
        RZTK_OPENPAREN,
        RZTK_CLOSEPAREN,
        RZTK_OPENBRACKET,
        RZTK_CLOSEBRACKET,
        RZTK_SEMICOLON,
        RZTK_STRINGLITERAL,
        RZTK_INTLITERAL,
        RZTK_FLOATLITERAL,
        RZTK_OPERATOR,
        RZTK_CONST,
        RZTK_NEW,
        RZTK_DELETE,
        RZTK_SIZEOF,
        RZTK_TYPEOF,
        RZTK_AND,
        RZTK_IS,
        RZTK_ISNOT,
        RZTK_NOT,
        RZTK_FUNCTION,
        RZTK_IF,
        RZTK_ELSE,
        RZTK_WHILE,
        RZTK_SWITCH,
        RZTK_CASE,
        RZTK_DEFAULT,
        RZTK_FOR,
        RZTK_FOREACH,
        RZTK_DO,
        RZTK_NULL,
        RZTK_TRUE,
        RZTK_FALSE,
        RZTK_RETURN,
        RZTK_PUBLIC,
        RZTK_PROTECTED,
        RZTK_PRIVATE,
        RZTK_BREAK,
        RZTK_CONTINUE,
        RZTK_IN,
        RZTK_GOTO,
        RZTK_AS,
        RZTK_DOT,
        RZTK_OPENDIAMOND,
        RZTK_CLOSEDIAMOND,
        RZTK_OPENSQBRACKET,
        RZTK_CLOSESQBRACKET,
        RZTK_NAMESPACE,
        RZTK_USING,
        RZTK_TILDE,
        RZTK_ENUM,
        RZTK_UNION,
        RZTK_CAST,
        RZTK_HANDLE,
        RZTK_DIRECTIVE,
        RZTK_AUTO,
        RZTK_ASM,
        RZTK_INCREMENT,
        RZTK_DECREMENT,
        RZTK_SCOPE,
        RZTK_ARROW,
        RZTK_LAMBDA, //< =>
        RZTK_IMPORT, //< import
        RZTK_NEWLINE,
        RZTK_AMPERSAND,
        RZTK_UNKNOWN
    };

    class token
    {
    public:

        std::string text;
        token_t     type;
        int         line = 0;
    };

    class lexer
    {
    public:
        void analyze(const std::string& src);

        std::vector<token> tokens;
    };

    class parse_state;
}

#endif // CPP_LEX_HPP_
