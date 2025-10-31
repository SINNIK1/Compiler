#include "codegen.h"
#include <iostream>

using namespace std;

namespace tinyc { namespace codegen {

        bool emit_x86_assembly(const string &outPath) {
            cout<< "emitted x86 assembly" << outPath << "\n";
            return true;
        }
    }
}