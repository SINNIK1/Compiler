add_executable(compiler
driver.cpp
frontend/lexer.cpp
frontend/parser.cpp
frontend/ast.cpp
frontend/sema.cpp
common/diag.cpp
vm/vm.cpp
codegen/x86_emitter.cpp
codegen/llvm_backend.cpp
)


target_include_directories(compiler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


# Example: enable warnings
if(MSVC)
target_compile_options(compiler PRIVATE /W4 /permissive-)
else()
target_compile_options(compiler PRIVATE -Wall -Wextra -Wpedantic -Wconversion)
endif()


# tools
add_executable(irviz tools/irviz.cpp)


target_include_directories(irviz PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})