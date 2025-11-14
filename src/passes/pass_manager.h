#pragma once 
#include <bits/stdc++.h>
#include "../ir/tir.h"
#include <functional>

using namespace std;

namespace tinyc { namespace passes{

    using Pass = function<bool(tinyc::ir::Func&)>;

    class PassManager {
        vector<Pass> passes;

        public: 
            void addPass(Pass p) { passes.push_back(move(p));}

            bool run(tinyc::ir::Func &f) {
                bool changed = false;
                for(auto &p : passes) {
                    try{
                        if(p(f)) changed = true;
                    } catch (exception e) {

                    }
                }
                return changed;
            }
    };
}}