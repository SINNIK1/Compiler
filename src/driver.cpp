#include<iostream>
#include<fstream>
#include<string>
#include "frontend/lexer.h"
#include "frontend/parser.h"
#include "../common/diag.h"

using namespace std;

int main(int argc, char** argv){
    if(argc < 2){
        cout<< "usage: compiler <source-file> \n";
        return 0;
    }

    ifstream ifs(argv[1]);

    if(!ifs){
        cerr << "error: could not open " << argv[1] << "\n";
        return 1;
    }

    string src((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());

    tinyc::DiagEngine diags;
    tinyc::Lexer lexer(src, diags);
    auto tokens = lexer.tokenize();

}