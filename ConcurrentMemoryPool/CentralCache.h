#pragma once
#include"Common.h"

class CentralCache
{
public:
	static CentralCache* GetInstance()
	{
		return &_inst;
	}

	//��Page Cache��ȡһ��Span
	Span* GetOneSpan(SpanList& spanlist, size_t byte_sizes);
	
	//�����Ļ����ȡһ�������Ķ����Thread Cache
	size_t FetchRangeObj(void*&start, void*&end, size_t n, size_t byte_sizes);

	//��һ�������Ķ����ͷŵ�span���
	void ReleaseListToSpan(void* start, size_t size);
private:
	SpanList _spanlist[NLISTS];
private:
	CentralCache()
	{}
	CentralCache(CentralCache&) = delete;
	static CentralCache _inst;
};