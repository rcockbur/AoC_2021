#include <iostream>
#include <string>
#include <fstream>
#include <list>

std::ifstream infile("data.txt");

//part 1
//int main()
//{
//	std::list<int> numbers;
//	std::string line;
//	int result = 0;
//	while (std::getline(infile, line)) {
//		numbers.push_back(std::stoi(line));
//	}
//	for (auto it1 = numbers.cbegin(); it1 != std::prev(numbers.cend()); ++it1) {
//		auto it2 = std::next(it1);
//		if (*it1 < *it2) {
//			++result;
//		}
//	}
//	std::cout << result << std::endl;
//	return 0;
//}

//part2
int main()
{
	std::list<int> numbers;
	std::string line;
	int result = 0;
	while (std::getline(infile, line)) {
		numbers.push_back(std::stoi(line));
	}
	for (auto it1 = numbers.cbegin(); it1 != std::prev(numbers.cend(), 3); ++it1) {
		auto it2 = std::next(it1);
		auto it3 = std::next(it2);
		auto it4 = std::next(it3);
		if (*it1 + *it2 + *it3 < *it2 + *it3 + *it4) {
			++result;
		}
	}
	std::cout << result << std::endl;
	return 0;
}