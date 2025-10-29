#include "ast.h"

using namespace std;

namespace tinyc {
    unique_ptr<Program> makeProgram() {return make_unique<Program>(); }
}