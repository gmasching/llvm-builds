#!/bin/sh
SCRIPT=$(readlink -f "$0")
SCRIPTPATH=$(dirname "$SCRIPT")
cd "$SCRIPTPATH"/"$1"
mkdir -p build
cd build
cmake -G "Ninja" \
      -DCMAKE_BUILD_TYPE=Release \
      -DLLVM_BUILD_TOOLS="ON" \
      -DLLVM_INCLUDE_TOOLS="ON" \
      -DLLVM_BUILD_EXAMPLES="OFF" \
      -DLLVM_APPEND_VC_REV="OFF" \
      -DLLVM_TARGETS_TO_BUILD="X86" \
      -DLLVM_TARGET_ARCH="X86" \
      -DLLVM_ENABLE_FFI=ON \
      -DLLVM_PARALLEL_COMPILE_JOBS="4" \
      -DLLVM_PARALLEL_LINK_JOBS="4" \
      -DLLVM_BUILD_LLVM_DYLIB="ON" \
      ../src/

