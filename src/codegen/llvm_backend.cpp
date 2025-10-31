#include "codegen.h"
#include <iostream>

using namespace std;

namespace tinyc { namespace codegen {

        bool emit_llvm_ir(const string &outPath) {
            cout<< "emitted llvm ir" << outPath << "\n";
            return true;
        }
    }
}