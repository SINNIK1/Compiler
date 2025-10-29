# Full Compiler — Scaffold


This scaffold provides a starting point for a full C++ compiler project. It includes a working frontend (lexer + parser skeleton + AST + simple semantic checks) and stubs for IR, codegen (x86 and LLVM), a VM, examples, and tests.


## Build
```bash
mkdir -p build && cd build
cmake ..
cmake --build . -- -j
# run the compiler
./compiler --help
```


## Recommended workflow
- Implement features incrementally: lexer -> parser -> AST -> sema -> IR -> codegen -> optimizations.
- Use `examples/` for small language programs and tests.