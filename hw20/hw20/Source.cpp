#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <map>



int main()
{
	int yahtzee = 0;
	int full_house = 0;
	int four_kind = 0;
	int three_kind = 0;
	int two_pair = 0;
	int one_pair = 0;
	int nothing = 0;
	int small = 0;
	int large = 0;



	for (int value = 0; value < 7776; ++value)
	{
		std::map<int, int>m;

		int roll = value;
		for (int i = 1; i <= 5; ++i)
		{
			++m[1 + (roll % 6)];
			roll /= 6;
		

		}
		if (m.size() == 1);
		{
			std::cout << "YAHTZEE" << std::endl;
		}
		else if (m.size() == 2 )
		{
			int x = m.begin()->second;
			if ((x == 1) || (x == 4))
			{
				std::cout << "FOUR OF A KIND" << std::endl;
			}
			else
			{
				std::cout << "FULL HOUSE" << std::endl;
			}
		}
		else if (m.size() == 3)
		{
			int total = 0;
			for (const std::pair<int, int>& die : m)
			{
				if (die.second > 1)
				{
					total += die.second;
				}
			}
			if (total == 3)
				std::cout << "THREE OF KIND" << std::endl;
			else
				std::cout << "TWO PAIR" << std::endl;

		}
		else if (m.size() == 4)
		{
			int total = 0;
			for (const std::pair<int,int>& die : m)
				total += die.first;
			if ((total == 10) || (total == 18))
				std::cout << "SMALL STRAIGHT" << std::endl;
			else if (total == 14)
			{
				if (m.begin()->first == 2)
					std::cout << "SMALL STRAIGHT" << std::endl;
				else
					std::cout << "YOU HAVE NOTHING" << std::endl;
			}
			else
				std::cout << "YOU HAVE NOTHING " << std::endl;
		}
		else if (m.size() == 5)
		{
			int total = 0;
			for (const std::pair<int, int>& die : m)
				total += die.first;
			if ((total == 15) || (total == 20))
				std::cout << "LARGE STRAIGHT" << std::endl;
			else if ((total == 16) || (total == 19))
			{
				if (m.begin()->first == 2)
					std::cout << "SMALL STRAIGHT" << std::endl;
			}
			

			else
				std::cout << "YOU HAVE NOTHING " << std::endl;
		}

	}












}