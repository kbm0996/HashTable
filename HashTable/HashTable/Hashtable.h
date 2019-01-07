#ifndef __HASH_H__
#define __HASH_H__
#include "SinglyLinkedlist.h"
#include "Config.h"

class Accountlist
{
protected:
	struct stACCOUNT
	{
		char chKey[df_LEN_MAX];		// ID
		char chValue[df_LEN_MAX];	// NAME
	};

	class Hashtable : protected Linkedlist<stACCOUNT*>
	{
	public:
		Hashtable() {}
		virtual ~Hashtable() {}

		bool Insert(char* chKey, char* chValue);
		bool Delete(char* chKey);

		void Print();
		bool SearchKey(char* chKey, stACCOUNT * chOutAccount = nullptr);
		bool SearchValue(char* chValue, stACCOUNT * chOutAccount = nullptr);

	private:
		friend class Accountlist;
		// TODO: ID의 ASCII의 총합을 시드값으로 사용. 출력값을 리스트의 인덱스로 사용
		static void Hashing(char* szString, int *OutHashCode);
	};

public:
	Accountlist(int iHashTable_Cnt = df_HASHTABLE_CNT);
	virtual ~Accountlist();

	bool Insert(char* szInID, size_t iIDLen, char* szInName, size_t iNameLen);
	bool Delete(char* szInID);
	void Print();
	bool Search(char* szInID);

private:
	bool Trim(char* szString, size_t iSize);

	int _iHashTable_Cnt;
	Hashtable* _Index[df_HASHTABLE_CNT];

};

#endif

