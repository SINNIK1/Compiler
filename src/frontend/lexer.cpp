#include "lexer.h"
#include <cctype>

using namespace std;

namespace tinyc {
    Lexer::Lexer(const string &s, DiagEngine &d) : src(s), diags(d) {}

    char Lexer::peek() const {
        if(idx >= src.size()) return '\0';
        return src[idx];
    }

    char Lexer::advance() {
        char c = peek();
        if(c == '\n') {line++; col = 1;}
        else col++;
        idx++;
        return c;
    }

    void Lexer::skipWhitespace() {
        while (isspace(peek())) advance();
    }

    Token Lexer::makeToken(TokenKind k, const string& lexeme){
        return Token{k, lexeme, line, col};
    }

    Token Lexer::lexIdentifier() {
        string id;
        while(isalnum(peek()) || peek() == '_') id.push_back(advance());
        if(id == "let") return makeToken(TokenKind::KwLet, id);
        if(id == "fn") return makeToken(TokenKind::KwFn, id);
        if(id == "return") return makeToken(TokenKind::KwReturn, id);
        return makeToken(TokenKind::Identifier, id);
    }

    Token Lexer::lexNumber() {
        string num;
        while(isdigit(peek())) num.push_back(advance());
        return makeToken(TokenKind::Number, num);
    }

    Token Lexer::lexString() {
        advance();
        string s;
        while(peek() && peek() != '"') {
            s.push_back(advance());
        }
        if (peek() == '"') advance();
        else diags.error("unterminated string", line, col );
        return makeToken(TokenKind::String, s);
    }

    vector<Token> Lexer::tokenize() {
        vector<Token> out;
        while(true) {
            skipWhitespace();
            char c = peek();
            if( c == '\0' ) { out.push_back(makeToken(TokenKind::EndOfFile, "")); break; }
            if(isalpha(c) || c == '_') { out.push_back(lexIdentifier()); continue; }
            if(isdigit(c)) { out.push_back(lexNumber()); continue; }
            switch(c) {
                case '+': advance(); out.push_back(makeToken(TokenKind::Plus, "+")); break;
                case '-': advance(); out.push_back(makeToken(TokenKind::Minus, "-")); break;
                case '*': advance(); out.push_back(makeToken(TokenKind::Star, "*")); break;
                case '/': advance(); out.push_back(makeToken(TokenKind::Slash, "/")); break;
                case '(': advance(); out.push_back(makeToken(TokenKind::LParen, "(")); break;
                case ')': advance(); out.push_back(makeToken(TokenKind::RParen, ")")); break;
                case '{': advance(); out.push_back(makeToken(TokenKind::LBrace, "{")); break;
                case '}': advance(); out.push_back(makeToken(TokenKind::RBrace, "}")); break;
                case ',': advance(); out.push_back(makeToken(TokenKind::Comma, ",")); break;
                case ';': advance(); out.push_back(makeToken(TokenKind::Semicolon, ";")); break;
                case '=': advance(); out.push_back(makeToken(TokenKind::Assign, "=")); break;
                case '"': out.push_back(lexString()); break;
                default:
                    {
                        string s;
                        s.push_back(advance());
                        out.push_back(makeToken(TokenKind::Unknown, s));
                    }
            }
        }

        return out;
    }
}