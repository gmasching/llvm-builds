#include "KaleidoscopeJIT.h"
#include "llvm-c/Target.h"
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

  LLVMBool LLVMInitializeNativeTarget__()
  {
    return LLVMInitializeNativeTarget();
  }

  LLVMBool LLVMInitializeNativeAsmParser__()
  {
    return LLVMInitializeNativeAsmParser();
  }

  LLVMBool LLVMInitializeNativeAsmPrinter__()
  {
    return LLVMInitializeNativeAsmPrinter();
  }

  LLVMBool LLVMInitializeNativeDisassembler__()
  {
    return LLVMInitializeNativeDisassembler();
  }

  static llvm::orc::KaleidoscopeJIT *TheJIT;

  llvm::TargetMachine* KaleidoscopeGetTargetMachine (){
    auto wtf = TheJIT->getTargetMachine();
    return wtf;
  }
  
  void KaleidoscopeCreate ()
  {
    TheJIT = new llvm::orc::KaleidoscopeJIT();
  }

  void KaleidoscopeDestroy ()
  {
    delete TheJIT;
  }

  llvm::orc::KaleidoscopeJIT::ModuleHandleT KaleidoscopeAddModule (llvm::Module* M)
  {
    return TheJIT->addModule(M);
  }

  void KaleidoscopeRemoveModule (llvm::orc::KaleidoscopeJIT::ModuleHandleT M)
  {
    TheJIT->removeModule(M);
  }

  llvm::orc::JITSymbol KaleidoscopeFindSymbol (const char* sym){
    auto fuckme = TheJIT->findSymbol(sym);
    std::cout << "fuck me four times";
    return fuckme;
  }

  llvm::orc::TargetAddress KaleidoscopeGetSymbolAddress (llvm::orc::JITSymbol sym){
    auto fuckme = sym.getAddress();
    std::cout << "fuck me five times";
    return fuckme;
  }

#ifdef __cplusplus
}
#endif
