#include "KaleidoscopeJIT.h"
#include "llvm-c/Target.h"

#ifdef __cplusplus
extern "C" {
#endif

  LLVMBool LLVMInitializeNativeTarget__(void) {
    return LLVMInitializeNativeTarget();
  }

  LLVMBool LLVMInitializeNativeAsmParser__(void) {
    return LLVMInitializeNativeAsmParser();
  }

  LLVMBool LLVMInitializeNativeAsmPrinter__(void) {
    return LLVMInitializeNativeAsmPrinter();
  }

  LLVMBool LLVMInitializeNativeDisassembler__(void) {
    return LLVMInitializeNativeDisassembler();
  }

  static llvm::orc::KaleidoscopeJIT *TheJIT;
  
  void KaleidoscopeCreate (void){
    TheJIT = new llvm::orc::KaleidoscopeJIT();
  }

  void KaleidoscopeDestroy (){
    delete TheJIT;
  }

  llvm::orc::KaleidoscopeJIT::ModuleHandleT KaleidoscopeAddModule (std::unique_ptr<llvm::Module> M) {
    auto ret = TheJIT->addModule(std::move(M));
    return ret;
  }

  void KaleidoscopeRemoveModule (llvm::orc::KaleidoscopeJIT::ModuleHandleT M) {
    TheJIT->removeModule(M);
  }

  llvm::orc::JITSymbol KaleidoscopefindSymbol (char *sym){
    return TheJIT->findSymbol(sym);
  }

#ifdef __cplusplus
}
#endif
