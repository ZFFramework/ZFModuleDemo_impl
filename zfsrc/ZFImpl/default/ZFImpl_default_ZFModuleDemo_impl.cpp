#include "ZFImpl_default_ZFModuleDemo_impl.h"
#include "ZFCore.h"
#include "ZFModuleDemo_lib.h"

ZF_NAMESPACE_GLOBAL_BEGIN

zfstring demoFuncFromImpl(void) {
    zfstring ret = "I'm string from ZFModuleDemo_impl";
    ret += ", and I'm string from ZFModuleDemo_lib: ";
    ret += demoFunc();
    return ret;
}

ZF_GLOBAL_INITIALIZER_INIT(ZFModuleDemo_impl_test) {
    ZFLog() << "I'm contents from ZFModuleDemo_impl";
}
ZF_GLOBAL_INITIALIZER_END(ZFModuleDemo_impl_test)

ZF_NAMESPACE_GLOBAL_END

