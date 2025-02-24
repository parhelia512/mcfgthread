/* This file is part of MCF Gthread.
 * See LICENSE.TXT for licensing information.
 * Copyleft 2022 - 2024, LH_Mouse. All wrongs reserved.  */

#include "precompiled.h"

void*
__cdecl
__MCF_mfill(void* dst, int val, size_t size);

__MCF_DLLEXPORT
void*
__cdecl
memset(void* dst, int val, size_t size);

__MCF_DLLEXPORT
void*
__cdecl
memset(void* dst, int val, size_t size)
  {
    return __MCF_mfill(dst, val, size);
  }
