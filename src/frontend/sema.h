#pragma once 
#include "../common/diag.h"
#include "ast.h"

using namespace std;

namespace tinyc {
    class Sema {
        DiagEngine &diags;

    public:
        Sema(DiagEngine &d);
        void analyze(Program* p);
    };
}