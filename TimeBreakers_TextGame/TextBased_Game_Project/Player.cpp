#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	m_Inventory = new Inventory();
}


Player::~Player()
{
	delete m_Inventory;
}

void Player::AddItemToInv(Item* item)
{
	m_Inventory->PutInInventory(item);

}

void Player::DecreaseHealth(int value)
{
	m_Health -= value;
}

void Player::IncreaseHealth(int value)
{
	m_Health += value;
}

void Player::SetName(string name)
{
	m_Name = name;
}

Inventory *& Player::GetInventory()
{
	return m_Inventory;
}

const int & Player::GetHealth()
{
	return m_Health;
}

const string & Player::GetName()
{
	return m_Name;
}

