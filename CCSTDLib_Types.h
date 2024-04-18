#pragma once
#ifndef __CCSTDLIBS_TYPES__
#define __CCSTDLIBS_TYPES__
#include "CCSTDLibs_MyCompiles.h"



#ifdef CCSTD_LANGUAGE_C
typedef int				CCBOOL_t;			// CCBool_t
typedef unsigned int	CCSize_t;			// CCSize_t
typedef void*			CCAny_t;			// CCAny_t
typedef unsigned char	CCBytes_t;			// CCBytes_t	
#define NUL_PTR			NULL				// NUL_PTR
#define True			(1)
#define False			(0)
#else	
CCSTD_NAMESPACE_BEGIN
#include <cstddef>
using	CCBOOL_t		= bool;				// CCBool_t
using	CCSize_t		= unsigned int;		// CCSize_t
using	CCAny_t			= void*;			// CCAny_t
using	CCBytes_t		= unsigned char;	// CCBytes_t
const	nullptr_t		NUL_PTR = nullptr;	// NUL_PTR
const	bool			True = true;
const	bool			False = false;
CCSTD_NAMESPACE_END
#endif

#endif


