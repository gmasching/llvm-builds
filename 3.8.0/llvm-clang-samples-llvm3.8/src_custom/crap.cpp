#include "KaleidoscopeJIT.h"
#include "llvm-c/Target.h"

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

  llvm::orc::JITSymbol KaleidoscopefindSymbol (char* sym){
    return TheJIT->findSymbol(sym);
  }

#ifdef __cplusplus
}
#endif
