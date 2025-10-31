#pragma once
#include <memory>
#include <vector>
#include <string>

using namespace std;

namespace tinyc {
    struct Node { virtual ~Node() = default; };

    struct Expr : Node {};
    struct Stmt : Node {};

    struct Program : Node {
        vector<unique_ptr<Stmt>> body;
    };

    struct NumberExpr : Expr { string value; };
    struct IdentExpr : Expr { string name; };
    struct BinaryExpr : Expr { 
        unique_ptr<Expr> lhs, rhs; 
        string op; 
        BinaryExpr( unique_ptr<Expr> l, unique_ptr<Expr> r, string o)
        : lhs(move(l)), rhs(move(r)), op(move(o)) {}
    };

    struct VarDecl : Stmt { string name; unique_ptr<Expr> init; };
    struct ExprStmt : Stmt { unique_ptr<Expr> expr; };

    unique_ptr<Program> makeProgram();
}