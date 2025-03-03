#include "ZFImpl_default_ZFModuleDemo_impl.h"
#include "ZFModuleDemo_lib/protocol/ZFProtocolZFModuleDemo.h"

ZF_NAMESPACE_GLOBAL_BEGIN

ZFPROTOCOL_IMPLEMENTATION_BEGIN(ZFModuleDemoImpl_default, ZFModuleDemo, v_ZFProtocolLevel::e_Default)
public:
    virtual zfstring demoImpl(void) {
        return "string from ZFModuleDemoImpl";
    }
ZFPROTOCOL_IMPLEMENTATION_END(ZFModuleDemoImpl_default)

ZF_NAMESPACE_GLOBAL_END

