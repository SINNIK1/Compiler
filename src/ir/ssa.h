#pragma once 
#include <bits/stdc++.h>

using namespace std;

namespace tinyc{ namespace ir {

    struct SSAVariable{
        string name;
    };

    struct SSAInstr {
        string op;
        string dst;
        string a;
        string b; 
    };

    struct SSABasicBlock {
        string name;
        vector<SSAInstr> instrs;
    };

    struct SSAFunction {
        string name;
        vector<SSABasicBlock> blocks;
    };

    }
}