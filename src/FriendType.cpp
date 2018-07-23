#include "FriendType.h"
// 링크드리스트 연동을 위한 연산자 오버로딩
bool FriendType :: operator>(FriendType item)
{
	return
		(this->GetID()>item.GetID());
}

// 링크드리스트 연동을 위한 연산자 오버로딩
bool FriendType ::operator<(FriendType item)
{
	return (this->GetID() < item.GetID());
}

// 링크드리스트 연동을 위한 연산자 오버로딩
FriendType& FriendType ::operator= (FriendType &ref)
{
	ID = ref.GetID();
	name = ref.GetName();

	return *this;
}

// 링크드리스트 연동을 위한 연산자 오버로딩
bool FriendType ::operator==(FriendType item)
{
	return (this->GetID() == item.GetID());
}