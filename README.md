# Build C++ code which links against LLVM

This project uses Eli Bendersky's ![llvm-clang-samples](https://github.com/eliben/llvm-clang-samples) repo in order to build C++ code that links against LLVM binaries. 

## How To:

1. Download LLVM release, unzip, rename to "src" and put into directory with version number. 

e.g.: ```/3.8.0/src/``` becomes the root of the LLVM source tree for version `3.8.0`

2. Put the code you wish to link against in the directory ```/3.8.0/llvm-clang-samples-llvm3.8/src_custom/```

3. run `build.sh 3.8.0` to use cmake or `ninja.sh 3.8.0` to use the ninja build system.

4. The compiled binary will appear somewhere, but I forget where.

In order to use other llvm versions, replace `3.8.0` with your version.
