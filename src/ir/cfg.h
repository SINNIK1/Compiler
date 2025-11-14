#pragma once 
#include "tir.h"
#include <bits/stdc++.h>

using namespace std;

namespace tinyc { namespace ir {

    struct CFG{
        Func *func{nullptr};

        CFG(Func *f=nullptr) : func(f) {}

        void dump(ostream &os = cout) const {
            if(!func) { os << "<empty-func>\n"; return; }

            os<< "Function: "<<func->name << "\n";
            for(const auto &bb : func->blocks) {
                os<<" BB: "<< bb.name << "\n";
                for(const auto &i : bb.instrs){
                    os<< " " << i.dst << " = " << i.op;
                    if(!i.a.empty()) os << " "<< i.a;
                    if(!i.b.empty()) os << " "<< i.b;
                    os<<"\n";
                }
            }
        }

    };
}}