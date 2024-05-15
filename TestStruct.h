#pragma once

struct tagList
{
	int iValue;
	tagList* Next_Index;
};

struct tagLink
{
	int iValue;
	tagLink* pPrevious_Index;
	tagLink* pNext_Index;
};