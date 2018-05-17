/* ====================================================================== *
 * Copyright (c) 2010-2018 ZFFramework
 * Github repo: https://github.com/ZFFramework/ZFFramework
 * Home page: http://ZFFramework.com
 * Blog: http://zsaber.com
 * Contact: master@zsaber.com (Chinese and English only)
 * Distributed under MIT license:
 *   https://github.com/ZFFramework/ZFFramework/blob/master/LICENSE
 * ====================================================================== */
#include "ZFImpl_default_ZFModuleDemo_impl.h"
#include "ZFCore.h"

ZF_NAMESPACE_GLOBAL_BEGIN

zfstring demoFuncFromImpl(void)
{
    return zfText("I'm string from ZFModuleDemo_impl");
}

ZF_GLOBAL_INITIALIZER_INIT(ZFModuleDemo_impl_test)
{
    zfLogT() << zfText("I'm contents from ZFModuleDemo_impl");
}
ZF_GLOBAL_INITIALIZER_END(ZFModuleDemo_impl_test)

ZF_NAMESPACE_GLOBAL_END

