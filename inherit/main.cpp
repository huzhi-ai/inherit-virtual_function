#include <iostream>

class Printable
{
public:
	virtual std::string GetClassName() = 0;

};

class Entity: public Printable
{
public:
	float X, Y;
	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
	virtual std::string GetName()
	{
		return "Entity";
	}
	virtual std::string GetWard() = 0 ;

	std::string GetClassName() override
	{
		return "Entity:";
	}

};

//virtual function   dynamic dispatch
/*
	compile with vitual table
	v table: table include all the virtual function setup with the base class
	override; map

	����븲д�������߷��� �����ڸ���ʹ���麯��

	��������Ƕ��ʽ��Ҫ���ǣ���������cpu��

	����ռ�洢v��������ȷ������

	�����г�Աָ�� ָ��v��

	�����麯��Ҫ����v�� ȷ������

==========================================================================
	���麯�� pure virtual function
	���ඨ��û��ʵ�ֵĺ���
	ǿ������ʵ��

	Ӧ�ã�
	ȷ�������ʵ��һ���ض�����ʹ�ô��麯�������ɳ��������Ϊ���������̳е����ࣩ
	֮������������¡�
*/



class Player : public Entity
{
private:
	std::string m_Name;
public :
	Player() {
	
	}
	Player(const std::string& name)
		:m_Name(name)
	{
	
	}
	
	std::string GetWard() override 
	{
		return "get ward";
	}

	std::string GetName() override
	{
		return m_Name;
	}

	const char* Name;

	void PrintName()
	{
		std::cout << Name << std::endl;
	}


	std::string GetClassName() override
	{
		return "Player:";
	}
};

void PrintName(Entity* entity)
{
	std::cout << entity->GetName() << std::endl;
}

void Print(Printable* obj)
{
	std::cout << obj->GetClassName() << std::endl;
}

int main() 
{
	Entity* e = new Entity();
	std::cout << e->GetName() << std::endl;

	Player* p = new Player("cherno");
	std::cout << p->GetName() << std::endl;

	Entity* entity = p;
	std::cout << entity->GetName() << std::endl;

	Print(e);
	Print(p);

	std::cout << sizeof(Player) << std::endl;
	Player player;
	player.Move(5, 5);
	player.X = 2;

}