// Copyright (c) 2012-2014 Zeex
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef STACKTRACE_H
#define STACKTRACE_H

#include <deque>
#include <iosfwd>
#include <string>

class StackFrame {
 public:
  StackFrame(void *ret_addr, const std::string &name = std::string());
  virtual ~StackFrame();

  void *return_address() const { return return_address_; }
  std::string callee_name() const { return callee_name_; }

  void Print(std::ostream &stream) const;

 private:
  void *return_address_;
  std::string callee_name_;
};

class StackTrace {
 public:
  StackTrace(void *context = 0);

  std::deque<StackFrame> GetFrames() const {
    return frames_;
  }

 protected:
  struct HappyCompiler {};
  StackTrace(HappyCompiler *happyCompiler);

  std::deque<StackFrame> frames_;
};

#endif // !STACKTRACE_H
