#include "diag.h"
#include <iostream>

using namespace std;

namespace tinyc {
    void DiagEngine::error(const string&m, int line, int col){
        diags.push_back({Diag::Kind::Error, m , line, col});
    }    

    void DiagEngine::warn(const string&m, int line, int col){
        diags.push_back({Diag::Kind::Warning, m , line, col});
    } 

    bool DiagEngine::hadErrors() const {
        for(auto &d : diags) if ( d.kind == Diag::Kind::Error ) return true;
        return false;
    }

    void DiagEngine::print() const {
        for (auto &d : diags) {
            string k = (d.kind == Diag::Kind::Error?"error":(d.kind == Diag::Kind::Warning?"warning":"note"));
            if ( d.line >= 0 ) cout<<k<<": " << d.msg << " (" << d.line << ":" << d.col << ")\n";
            else cout<< k << ": " << d.msg << "\n";
        }
    }
} 
