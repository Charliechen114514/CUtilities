#pragma once
#define __USE_C_



#ifdef __USE_C_

#define CCSTD_LANGUAGE_C
#define CCSTD_NAMESPACE_BEGIN
#define CCSTD_NAMESPACE_END
#else
#define CCSTD_LANGUAGE_CPP
#define CCSTD_NAMESPACE_BEGIN	namespace CCSTD{
#define CCSTD_NAMESPACE_END		}
#endif