#pragma once

#include <string>
#include <vector>

using namespace std;

namespace tinyc {
    struct Diag {
        enum class Kind {Error, Warning, Note } kind;
        string msg;
        int line{-1};
        int col{-1};
    };

    class DiagEngine {
        vector<Diag> diags;
    public:
        void error(const string& m, int line=-1, int col=-1);
        void warn(const string& m, int line=-1, int col=-1);
        bool hadErrors() const;
        void print() const;        
    };

}