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

  llvm::JITSymbol wowwow = nullptr;
  
  llvm::JITSymbol* KaleidoscopeFindSymbol (const char* sym){
    std::string s(sym);
    std::cout << "fuck me fuck you times";
    wowwow = TheJIT->findSymbol(s);
    std::cout << "fuck me five times";
    return &wowwow;
  }

  llvm::JITTargetAddress KaleidoscopeGetSymbolAddress (llvm::JITSymbol sym){
    llvm::Expected<llvm::JITTargetAddress> fuckme = sym.getAddress();
    auto dearly = *fuckme.operator->();
    //    std::cout << "fuck me five times";
    return dearly;
  }

#ifdef __cplusplus
}
#endif
