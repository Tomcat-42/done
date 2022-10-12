#pragma once

#include <libplatform/libplatform.h>
#include <uv.h>
#include <v8.h>

#include <libdone/fs.hpp>
#include <libdone/util.hpp>

class Done {
private:
  v8::Isolate *isolate;
  v8::Local<v8::Context> context;
  std::unique_ptr<v8::Platform> *platform;
  v8::Isolate::CreateParams create_params;
  // main event loop
  void WaitForEvents();
  // main execution loop
  void ExecuteScriptAndWaitForEvents(char *filename);
  static void Print(const v8::FunctionCallbackInfo<v8::Value> &args);

public:
  std::unique_ptr<v8::Platform> initializeV8(int argc, char *argv[]);
  void initializeVM();
  void InitializeProgram(char *filename);
  void Shutdown();
};
