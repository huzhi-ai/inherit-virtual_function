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

	如果想覆写函数或者方法 则须在父类使用虚函数

	开销：（嵌入式需要考虑，尤其垃圾cpu）

	额外空间存储v表（分配正确函数）

	基类有成员指针 指向v表

	调用虚函数要遍历v表 确定函数

==========================================================================
	纯虚函数 pure virtual function
	基类定义没有实现的函数
	强制子类实现

	应用：
	确保类必须实现一个特定方法使用纯虚函数，构成抽象基类作为参数（被继承到子类）
	之后子类调用做事。
	
===================================================================================
	
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
