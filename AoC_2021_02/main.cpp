#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <unordered_map>
#include <algorithm>



std::string split(std::string& str, const std::string& delimiter) {
	std::string token = str.substr(0, str.find(delimiter));
	str.erase(0, str.find(delimiter) + delimiter.length());
	return token;
}

//part 1
//int main() {
//	std::ifstream infile("data.txt");
//	std::unordered_map<std::string, std::vector<int>> directionMap;
//	std::vector<int> position(2);
//	directionMap.insert(std::pair<std::string, std::vector<int>>("down", { 0, 1 }));
//	directionMap.insert(std::pair<std::string, std::vector<int>>("up", { 0, -1 }));
//	directionMap.insert(std::pair<std::string, std::vector<int>>("forward", { 1, 0 }));
//
//	std::string line;
//
//	while (std::getline(infile, line)) {
//		std::string direction = split(line, " ");
//		int magnitude = std::stoi(line);
//
//		std::vector<int> move(2);
//		std::transform(directionMap[direction].begin(), directionMap[direction].end(), move.begin(), [magnitude](int& c) { return c * magnitude; });
//
//		std::transform(position.begin(), position.end(), move.begin(), position.begin(), std::plus<int>());
//
//		
//	}
//	std::cout << position[0] << "," << position[1] << std::endl;
//	std::cout << position[0] * position[1] << std::endl;
//}

//part 2
int main() {
	std::ifstream infile("data.txt");
	std::unordered_map<std::string, std::vector<int>> directionMap;
	std::vector<int> position(3);			// X, Y, Aim, where Y is depth, not height
	directionMap.insert(std::pair<std::string, std::vector<int>>("down", { 0, 0, 1 }));
	directionMap.insert(std::pair<std::string, std::vector<int>>("up", { 0, 0, -1 }));
	directionMap.insert(std::pair<std::string, std::vector<int>>("forward", { 1, 0, 0 }));

	std::string line;

	while (std::getline(infile, line)) {
		std::string direction = split(line, " ");
		int magnitude = std::stoi(line);

		std::vector<int> move(3);
		std::transform(directionMap[direction].begin(), directionMap[direction].end(), move.begin(), [magnitude](int& c) { return c * magnitude; });

		std::transform(position.begin(), position.end(), move.begin(), position.begin(), std::plus<int>());

		if (direction == "forward") {
			std::vector<int> forwardDepthMove = { 0, position[2] * magnitude, 0 };
			std::transform(position.begin(), position.end(), forwardDepthMove.begin(), position.begin(), std::plus<int>());
		}
		std::cout << position[0] << "," << position[1] << "," << position[2] << std::endl;
	}
	/*std::cout << position[0] << "," << position[1] << position[2] << std::endl;*/
	std::cout << position[0] * position[1] << std::endl;
}
