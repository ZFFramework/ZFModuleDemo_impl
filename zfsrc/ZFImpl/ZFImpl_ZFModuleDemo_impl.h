/**
 * @file ZFImpl_ZFModuleDemo_impl.h
 * @brief global header for ZFModuleDemo_impl module
 */

#ifndef _ZFI_ZFImpl_ZFModuleDemo_impl_h_
#define _ZFI_ZFImpl_ZFModuleDemo_impl_h_

#include "ZFImpl.h"

ZF_NAMESPACE_GLOBAL_BEGIN

/** @brief used to export symbols */
#ifndef ZFLIB_ZFModuleDemo_impl
    #define ZFLIB_ZFModuleDemo_impl ZF_ENV_IMPORT
#endif
// export a dummy class to ensure the lib really "contains" something
zfclassNotPOD ZFLIB_ZFModuleDemo_impl _ZFP_ZFLIB_ZFModuleDemo_impl {};

ZF_NAMESPACE_GLOBAL_END
#endif // #ifndef _ZFI_ZFImpl_ZFModuleDemo_impl_h_

