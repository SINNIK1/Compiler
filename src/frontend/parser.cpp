#include "parser.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

namespace tinyc {
    Parser::Parser(const vector<Token> &t, DiagEngine &d) : toks(t), diags(d) {}

    const Token &Parser::peek() const { return toks[idx]; }
    const Token &Parser::advance() { return toks[idx++]; }
    bool Parser::match(TokenKind k) { if (peek().kind == k) { advance(); return true;} return false;}

    unique_ptr<Program> Parser::parse() {
        auto p = makeProgram();
        while ( peek().kind != TokenKind::EndOfFile) {
            auto s = parseStatement();
            if (s) p->body.push_back(move(s));
            else break;
        }
        return p;
    }

    unique_ptr<Stmt> Parser::parseStatement() {
        if ( peek().kind == TokenKind::KwLet) return parseVarDecl();

        auto e = parseExpression();
        if (match(TokenKind::Semicolon)) {
            auto s = make_unique<ExprStmt>();
            s->expr = move(e);
            return s;
        }
        diags.error("expected ';' after expression", peek().line, peek().col);
        return nullptr;
    }

    unique_ptr<Stmt> Parser::parseVarDecl() {
        advance();
        if(peek().kind != TokenKind::Identifier) { diags.error("expected identifier after let", peek().line, peek().col); return nullptr;}
        string name = peek().lexeme; advance();
        if(!match(TokenKind::Assign)) {diags.error("expected '=' in declaration", peek().line, peek().col); return nullptr; }
        auto init = parseExpression();
        if(!match(TokenKind::Semicolon)) {diags.error("expected ';' after declaration", peek().line, peek().col); return nullptr; }
        auto v = make_unique<VarDecl>();
        v->name = name;
        v->init = move(init);
        return v;
    }

    unique_ptr<Expr> Parser::parseExpression() {
        auto left = parsePrimary();
        if (!left) return nullptr;
        if (peek().kind == TokenKind::Plus ||
            peek().kind == TokenKind::Minus ||
            peek().kind == TokenKind::Star ||
            peek().kind == TokenKind::Slash) {
            string op = peek().lexeme; advance();
            auto right = parsePrimary();
            return make_unique<BinaryExpr>(move(left), move(right), move(op));
        }
        return left;
    }

    unique_ptr<Expr> Parser::parsePrimary() {
        if(peek().kind == TokenKind::Number) { auto n = make_unique<NumberExpr>(); n->value = peek().lexeme; advance(); return n; }
        if(peek().kind == TokenKind::Identifier) { auto id = make_unique<IdentExpr>(); id->name = peek().lexeme; advance(); return id; }
        diags.error("unexpected token in expression", peek().line, peek().col);
        return nullptr;
    }
}