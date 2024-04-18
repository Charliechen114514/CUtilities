#include "CCDynamicArray.h"
#include "CCSTDLib_Utils.h"
CCDynamicArray* CCDynamicArray_createEmpty(CCSize_t elemSize)
{
	CCSTD_MALLOC_ONE(new_one, CCDynamicArray);
	new_one->core_data = NUL_PTR;
	new_one->core_size = 0;
	new_one->elem_size = elemSize;
	return new_one;
}


CCDynamicArray* CCDynamicArray_createCCDynamicArray(void* arrayBegin, CCSize_t n, CCSize_t size)
{
	CCSTD_MALLOC_ONE(new_one, CCDynamicArray);
	CCSTD_MALLOC_BYTES(core_datas, n * size);

	memcpy(core_datas, arrayBegin, n * size);
	new_one->core_data = core_datas;
	new_one->core_size = n;
	new_one->elem_size = size;
	return new_one;
}

CCDynamicArray* CCDynamicArray_cloneCCDynamicArray(CCDynamicArray* array)
{
	DEFAULT_DENY(array, NULL);
	CCSTD_MALLOC_ONE(new_one, CCDynamicArray);
	CCSTD_MALLOC_BYTES(core_datas, array->core_size * array->elem_size);

	memcpy(core_datas, array->core_data, array->core_size * array->elem_size);
	new_one->core_data = core_datas;
	new_one->core_size = array->core_size;
	new_one->elem_size = array->elem_size;

	return new_one;
}

CCBOOL_t		CCDynamicArray_pushBackSingle(CCDynamicArray* array, void* sigElem)
{
	DEFAULT_DENY(array, False);
	DEFAULT_DENY(sigElem, False);

	CCAny_t check = realloc(array->core_data, (array->core_size + 1) *array->elem_size);
	DEFAULT_DENY(check, False);
	array->core_data = check;
	CCBytes_t* p = (CCBytes_t*)array->core_data + array->core_size * array->elem_size;
	memcpy(p, sigElem, array->elem_size);
	array->core_size += 1;
	return True;
}

CCBOOL_t		CCDynamicArray_pushBackMulti(CCDynamicArray* pushee, void* array, CCSize_t n)
{
	DEFAULT_DENY(array, False);
	DEFAULT_DENY(pushee, False);

	CCAny_t check = realloc(pushee->core_data, (pushee->core_size + n) * pushee->elem_size);
	DEFAULT_DENY(check, False);
	pushee->core_data = check;
	CCBytes_t* p = (CCBytes_t*)pushee->core_data + pushee->core_size * pushee->elem_size;
	memcpy(p, array, pushee->elem_size * n);
	pushee->core_size += n;
	return True;
}


CCBOOL_t		CCDynamicArray_pushBackArray(CCDynamicArray* pushee, CCDynamicArray* array)
{
	DEFAULT_DENY(array, False);
	DEFAULT_DENY(pushee, False);
	DENY_NO_SAME_TYPE_CONT(array->elem_size, pushee->elem_size, False);
	CCAny_t check = realloc(pushee->core_data, (pushee->core_size + array->core_size) * pushee->elem_size);
	DEFAULT_DENY(check, False);
	pushee->core_data = check;
	CCBytes_t* p = (CCBytes_t*)pushee->core_data + pushee->core_size * pushee->elem_size;
	memcpy(p, array->core_data, array->elem_size * array->core_size);
	pushee->core_size += array->core_size;
	return True;
}

CCBOOL_t		CCDynamicArray_Iterate(CCDynamicArray* arr, HandleEachElem func, void* args)
{
	DEFAULT_DENY(arr, False);
	DEFAULT_DENY(arr->core_data, False);
	CCBytes_t* end = (CCBytes_t*)arr->core_data + arr->core_size * arr->elem_size;
	for (CCBytes_t* oper = arr->core_data;
		oper != end;
		oper += arr->elem_size) {
		func(oper, args);
	}
	return True;
}

CCBOOL_t		CCDynamicArray_Free(CCDynamicArray* arr)
{
	CCSTD_SAFE_FREE(arr->core_data);
	CCSTD_SAFE_FREE(arr);
	return True;
}
