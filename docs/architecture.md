# Architecture (one-page)


- frontend: lexer -> parser -> AST -> semantic analysis
- IR: TIR (three-address) -> SSA
- passes: optimization pipeline (const-fold, dce, inlining, liveness)
- codegen: x86 emitter + LLVM backend
- runtime: small stdlib and runtime support