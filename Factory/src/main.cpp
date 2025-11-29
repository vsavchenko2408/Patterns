#include <iostream>

class Enemies
	{
		public:
		virtual void attack()
		{
			std::cout << "Enemy attacked!" << std::endl;
		}
		private:

	};
class Mage:public Enemies
	{
		public:
		void attack() override
		{
		std::cout << "Mage cast fireball!" << std::endl;
		}
		private:	
	
	};
class Warrior: public Enemies
	{
		public:
		void attack() override
		{
		std::cout << "Warrior attacked sword!" << std::endl;
		}
		private:
		
	};

class Factory
	{
		public:
		Enemies* CreateEnemy(int enemy)
		{
			switch (enemy)
			{
			case 1:
				return new Mage;

			case 2:
				return new Warrior;

			default:
			return nullptr;

			}
		}

	};
int main()
{
	Factory fact;
	auto mage = fact.CreateEnemy(1);
	auto war = fact.CreateEnemy(2);
	mage->attack();
	war->attack();

return 0;
}
