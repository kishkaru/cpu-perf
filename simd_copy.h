#ifndef __SIMD_COPY_H__
#define __SIMD_COPY_H__

#include <emmintrin.h>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>

void simd_memcpy(void *dst, void *src, size_t nbytes);
void simd_memcpy_cache(void *dst, void *src, size_t nbytes);

#endif
