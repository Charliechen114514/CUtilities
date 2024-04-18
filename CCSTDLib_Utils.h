#pragma once
#ifndef __CCSTDLIBS_UTILS__
#define __CCSTDLIBS_UTILS__
#include "CCSTDLibs_MyCompiles.h"
#include "CCSTDLib_Err.h"
#include "CCSTDLib_Types.h"
// Mallocs
#ifdef CCSTD_LANGUAGE_C
#include <stdlib.h>
#include <memory.h>
// DENY_NUL
#define DENY_NUL(pointers, ERR_LEVEL, _RET)			\
do{													\
	if(!pointers)									\
	{												\
		if(ERR_LEVEL == EXIT)						\
			exit(_RET);								\
		else										\
			return (_RET);							\
	}												\
}while(0)

#define DEFAULT_DENY(pointers, RET)					DENY_NUL(pointers, RETURN, RET)	
#define SERIOUS_QUIT(pointers, RET)					DENY_NUL(pointers, EXIT, RET)


#define CCSTD_MALLOC_ONE(decleared_ptr_name, type)		\
type* decleared_ptr_name = NUL_PTR;						\
do{														\
	type* __CHECKING__ = (type*)malloc(sizeof(type));	\
	SERIOUS_QUIT(__CHECKING__, MALLOC_FAILED);			\
	decleared_ptr_name = __CHECKING__;					\
	memset(decleared_ptr_name, 0, sizeof(type));		\
}while(0)


#define CCSTD_MALLOC_BYTES(decleared_ptr_name, bytes_req) \
CCAny_t decleared_ptr_name;								\
do{														\
	CCBytes_t* __CHECKING__ = (CCBytes_t*)malloc(sizeof(CCBytes_t) * (bytes_req));\
	SERIOUS_QUIT(__CHECKING__, MALLOC_FAILED);			\
	decleared_ptr_name = (CCAny_t)__CHECKING__;			\
	memset(decleared_ptr_name, 0, sizeof(bytes_req));		\
}while(0)


#define CCSTD_MALLOC_TYPES_RAW_ARRAY(decleared_ptr_name, type, N) \
type* decleared_ptr_name = NUL_PTR;							\
do{															\
	type* __CHECKING__ = (type*)malloc(sizeof(type) * (N));	\
	SERIOUS_QUIT(__CHECKING__, MALLOC_FAILED);				\
	decleared_ptr_name = __CHECKING__;						\
	memset(decleared_ptr_name, 0, sizeof(type) * (N));			\
}while(0)

#define CCSTD_SAFE_FREE(pointers) \
do{ \
	free((pointers));\
	(pointers) = NULL;\
}while(0)


// DENY_INVALID_SIZE
#define IS_INVALID_SIZE(size)	( (size >= 0) ) 

// Sizes
#define TYPE_SIZE(type) \
	type##_SIZE = sizeof(type) \

#define WITH_U_TYPE_SIZE(type) \
	type##_SIZE = sizeof(type), \
	U##type##_SIZE = sizeof(unsigned type)

enum DEF_TYPE_SIZE {
	WITH_U_TYPE_SIZE(int),
	WITH_U_TYPE_SIZE(short),
	WITH_U_TYPE_SIZE(char),
	TYPE_SIZE(float),
	TYPE_SIZE(double)
};

#else
#include <new>

#endif







#endif
