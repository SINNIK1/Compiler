#pragma once
#include <vector>
#include <memory>
#include "lexer.h"
#include "ast.h"
#include "../common/diag.h"

using namespace std;

namespace tinyc {
    class Parser {
        const vector<Token> &toks;
        size_t idx{0};
        DiagEngine &diags;

    public:
        Parser(const vector<Token> &t, DiagEngine &d);
        unique_ptr<Program> parse();
    
    private:
        const Token &peek() const;
        const Token &advance();
        bool match(TokenKind k);
        unique_ptr<Stmt> parseStatement();
        unique_ptr<Stmt> parseVarDecl();
        unique_ptr<Expr> parseExpression();
        unique_ptr<Expr> parsePrimary();
    };
}