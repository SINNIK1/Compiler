#pragma once 
#include <string>

using namespace std;

namespace tinyc {

    struct CodegenOptions {
        bool emitAssembly = false;
        bool useLLVM = false;
    };

    bool emit_x86_assembly(const string &outPath);
    bool emit_llvm_ir(const string *outPath);
}