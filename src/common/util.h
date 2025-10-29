#pragma once
#include <string>
#include <sstream>
using namespace std;

namespace tinyc {
    inline string to_string_fmt(const char* fmt, ...) {
        char buf[1024];
        va_list ap; va_start(ap, fmt);
        vsnprint(buf, sizeof(buf), fmt, ap);
        va_end(ap);
        return string(buf);
    }
}