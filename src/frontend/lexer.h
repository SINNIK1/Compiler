#pragma once
#include <string>
#include <string>
#include <vector>
#include "common/diag.h"

using namespace std;

namespace tinyc {

enum class TokenKind {
    Identifier, Number, String,
    KwLet, KwFn, KwReturn,
    Plus, Minus, Star, Slash,
    LParen, RParen, LBrace, RBrace,
    Comma, Semicolon, Assign, EndOfFile, Unknown
};

struct Token {
    TokenKind kind;
    string lexeme;
    int line;
    int col;
};

class Lexer {
    const string src;
    size_t idx{0};
    int line{1}, col{1};
    DiagEngine &diags;

public:
    Lexer(const string &s, DiagEngine &d);
    vector<Token> tokenize();

private:
    char peek() const;
    char advance();
    void skipWhateSpace();
    Token makeToken(TokenKind k, const string &lexeme);
    Token lexIdentifier();
    Token lexNumber();
    Token lexString(); 
};    

}