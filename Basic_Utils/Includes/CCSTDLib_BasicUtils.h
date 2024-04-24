#pragma once
#ifndef __CCSTDLIB_BASIC_UTILS_H_
#define __CCSTDLIB_BASIC_UTILS_H_
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

#define TIL_END		(-1)

#endif
