#pragma once
#include <string>
#include <cstdarg>  
#include <cstdio> 
#include <stdexcept>

using namespace std;

namespace tinyc {
    inline string to_string_fmt(const char* fmt, ...) {
        char buf[1024];
        va_list ap;
        va_start(ap, fmt);
        int n = vsnprintf(buf, sizeof(buf), fmt, ap);
        va_end(ap);
        if (n < 0) throw runtime_error("formatting error");
        return string(buf, (n < (int)sizeof(buf) ? n : (int)sizeof(buf)));
    }
} 
