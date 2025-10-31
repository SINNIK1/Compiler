#pragma once 
#include <vector>
#include <string>

using namespace std;

namespace tinyc { namespace ir {

        struct Instr { string op; string dst; string a, b;};
        struct BasicBlock { string name; vector<Instr> instrs;};
        struct Func { string name; vector<BasicBlock> blocks;};
        
    }
}