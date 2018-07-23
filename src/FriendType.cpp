#include "FriendType.h"
// ��ũ�帮��Ʈ ������ ���� ������ �����ε�
bool FriendType :: operator>(FriendType item)
{
	return
		(this->GetID()>item.GetID());
}

// ��ũ�帮��Ʈ ������ ���� ������ �����ε�
bool FriendType ::operator<(FriendType item)
{
	return (this->GetID() < item.GetID());
}

// ��ũ�帮��Ʈ ������ ���� ������ �����ε�
FriendType& FriendType ::operator= (FriendType &ref)
{
	ID = ref.GetID();
	name = ref.GetName();

	return *this;
}

// ��ũ�帮��Ʈ ������ ���� ������ �����ε�
bool FriendType ::operator==(FriendType item)
{
	return (this->GetID() == item.GetID());
}