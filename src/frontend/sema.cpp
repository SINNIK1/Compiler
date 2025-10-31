#include "sema.h"
#include <unordered_set>

using namespace std;

namespace tinyc {

    Sema::Sema(DiagEngine &d) : diags(d) {}

    void Sema::analyze(Program* p) {
        unordered_set<string> defs;
        for(auto &s : p->body) {
            if( auto *vd = dynamic_cast<VarDecl*>(s.get())) {
                if(defs.count(vd->name)) diags.error("Duplicate definition of variable '" +vd->name+"'", -1, -1);
                defs.insert(vd->name);
                if(auto *ie = dynamic_cast<IdentExpr*>(vd->init.get())) {
                    if(!defs.count(ie->name)) diags.error("use of undeclared identifier '"+ie->name+"'", -1, -1);
                }
            }
        }
    }
}