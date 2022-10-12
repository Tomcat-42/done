#pragma once

#include <v8.h>

namespace Util {
v8::Local<v8::String> v8_str(const char *x);

// Copied from https://github.com/v8/v8/blob/master/samples/shell.cc
const char *ToCString(const v8::String::Utf8Value &value);

// Copied from https://github.com/v8/v8/blob/master/samples/shell.cc
void ReportException(v8::Isolate *isolate, v8::TryCatch *try_catch);
} // namespace Util
