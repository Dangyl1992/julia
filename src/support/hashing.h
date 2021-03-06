// This file is a part of Julia. License is MIT: http://julialang.org/license

#ifndef HASHING_H
#define HASHING_H

#ifdef __cplusplus
extern "C" {
#endif

uint_t nextipow2(uint_t i);
JL_DLLEXPORT uint32_t int32hash(uint32_t a);
JL_DLLEXPORT uint64_t int64hash(uint64_t key);
JL_DLLEXPORT uint32_t int64to32hash(uint64_t key);
#ifdef _P64
#define inthash int64hash
#else
#define inthash int32hash
#endif
JL_DLLEXPORT uint64_t memhash(const char *buf, size_t n);
JL_DLLEXPORT uint64_t memhash_seed(const char *buf, size_t n, uint32_t seed);
JL_DLLEXPORT uint32_t memhash32(const char *buf, size_t n);
JL_DLLEXPORT uint32_t memhash32_seed(const char *buf, size_t n, uint32_t seed);

#ifdef _P64
#define bitmix(a,b) int64hash((a)^bswap_64(b))
#else
#define bitmix(a,b) int64to32hash((((uint64_t)a)<<32)|((uint64_t)b))
#endif

#ifdef __cplusplus
}
#endif

#endif
