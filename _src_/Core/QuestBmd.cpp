#include "Core.h"
#include "QuestBmd.h"

BOOL QuestBmd::Decrypt()
{
	assert(_buf.size() > 0);

	int size = sizeof(QUEST_INFO);
	int count = 200;

	if (_buf.size() != (count * size))
	{
		cout << "Warning: InputFile size check failed. (may be a wrong file) \n";
#ifdef STRICT_SIZE_CHECK
		return FALSE;
#endif
	}

	_map.clear();

	int pos = 0;
	for (int i = 0; i < count; i++)
	{
		Xor3Byte(&_buf[pos], size);
		QUEST_INFO* ptr = (QUEST_INFO*)&_buf[pos];

		if (ptr->ItemCount + ptr->TypeCount > 0)
		{
			int key = i;
			_map.insert(make_pair(key, ptr));
		}

		pos += size;
	}

	return TRUE;
}

BOOL QuestBmd::Encrypt()
{
	assert(_buf.size() > 0);

	int size = sizeof(QUEST_INFO);
	for (int p = 0; p + size <= _buf.size(); p += size)
		Xor3Byte(&_buf[p], size);

	_map.clear(); // T* now -> encrypted data
	return TRUE;
}

int QuestBmd::GetKey(QUEST_INFO * ptr)
{
	return 0;
}

void QuestBmd::TxtOut(ofstream & os)
{
	assert(os);

	for (auto it = _map.begin(); it != _map.end(); it++)
	{
		QUEST_INFO* ptr = it->second;

		os << "//================================================="<< endl;
		os << "//==Quest: " << ptr->QuestName << endl;
		os << "//=================================================" << endl;
		os << "//ItemCount\tTypeCount\tNPC\tQuestName" << endl;
		os << ptr->ItemCount << '\t';
		os << ptr->TypeCount << '\t';
		os << ptr->NPC << '\t';
		os << ptr->QuestName << '\t';
		os << endl;

		os << "//QuestItems" << endl;
		os << "//Flag\tQuestType\tItemCat\tItemIndex\tLevel\tAmount\tGL\tDW\tDK\tFE\tMG\tDL\tSU\tRF\tMsg_1\tMsg_2\tMsg_3\tMsg_4" << endl;
		
		for (int i = 0; i < ptr->ItemCount; i++)
		{
			os << (int)ptr->Items[i].Flag << '\t';
			os << (int)ptr->Items[i].QuestType << '\t';
			os << (int)ptr->Items[i].ItemCat << '\t';
			os << (int)ptr->Items[i].ItemIndex << '\t';
			os << (int)ptr->Items[i].Level << '\t';
			os << (int)ptr->Items[i].Amount << '\t';
			os << (int)ptr->Items[i].GL << '\t';
			os << (int)ptr->Items[i].DW << '\t';
			os << (int)ptr->Items[i].DK << '\t';
			os << (int)ptr->Items[i].FE << '\t';
			os << (int)ptr->Items[i].MG << '\t';
			os << (int)ptr->Items[i].DL << '\t';
			os << (int)ptr->Items[i].SU << '\t';
			os << (int)ptr->Items[i].RF << '\t';
			os << ptr->Items[i].Msg_1 << '\t';
			os << ptr->Items[i].Msg_2 << '\t';
			os << ptr->Items[i].Msg_3 << '\t';
			os << ptr->Items[i].Msg_4 << '\t';
			os << endl;
		}

		os << "//QuestTypes" << endl;
		os << "//Flag\tType\tQuestIndex\tMinLvl\tMaxLvl\tNeedStr\tNeedZen\tMsg" << endl;

		for (int i = 0; i < ptr->TypeCount; i++)
		{
			os << (int)ptr->Types[i].Flag << '\t';
			os << (int)ptr->Types[i].Type << '\t';
			os << ptr->Types[i].QuestIndex << '\t';
			os << ptr->Types[i].MinLvl << '\t';
			os << ptr->Types[i].MaxLvl << '\t';
			os << ptr->Types[i].NeedStr << '\t';
			os << ptr->Types[i].NeedZen << '\t';
			os << ptr->Types[i].Msg << '\t';
			os << endl;
		}

		os << "//" << endl;
	}

}

void QuestBmd::TxtIn(ifstream & is)
{
	assert(is);

	string line;
	int size = sizeof(QUEST_INFO);
	int count = 200;
	_map.clear();

	_buf.resize(count * size);
	memset(_buf.data(), 0x0, _buf.size());

	int n = 0;
	while (getline(is, line) && n < count)
	{
		if (line[0] == '/' && line[1] == '/')
			continue;

		QUEST_INFO* ptr = (QUEST_INFO*)&_buf[n*size];
		sscanf(line.c_str(),
			"%hd\t%hd\t%hd\t%[^\t]%*c"
			, &ptr->ItemCount, &ptr->TypeCount, &ptr->NPC, &ptr->QuestName
		);
		
		if (ptr->ItemCount > 16 || ptr->TypeCount > 16)
		{
			cout << "Error: Quest Items/Types Count must not > 16." << endl;
			return;
		}

		int i = 0;
		while (getline(is, line) && i < ptr->ItemCount)
		{
			if (line[0] == '/' && line[1] == '/')
				continue;

			QUEST_INFO_ITEM* pItem = &ptr->Items[i];
			sscanf(line.c_str(),
				"%hhd\t%hhd\t%hd\t%hhd\t%hhd\t%hhd\t"
				"%hhd\t%hhd\t%hhd\t%hhd\t%hhd\t%hhd\t%hhd\t%hhd\t"
				"%hhd\t%hhd\t%hhd\t%hhd"
				, &pItem->Flag, &pItem->QuestType, &pItem->ItemCat, &pItem->ItemIndex, &pItem->Level, &pItem->Amount
				, &pItem->GL, &pItem->DW, &pItem->DK, &pItem->FE, &pItem->MG, &pItem->DL, &pItem->SU, &pItem->RF
				, &pItem->Msg_1, &pItem->Msg_2, &pItem->Msg_3, &pItem->Msg_4
			);
			i++;
		}

		i = 0;
		while (getline(is, line) && i < ptr->TypeCount)
		{
			if (line[0] == '/' && line[1] == '/')
				continue;

			QUEST_INFO_TYPE* pType = &ptr->Types[i];
			sscanf(line.c_str(),
				"%hhd\t%hhd\t%hd\t%hd\t%hd\t%d\t%d\t%hd"
				, &pType->Flag, &pType->Type, &pType->QuestIndex, &pType->MinLvl, &pType->MaxLvl, &pType->NeedStr, &pType->NeedZen, &pType->Msg
			);

			i++;
		}

		n++;
	}
}
