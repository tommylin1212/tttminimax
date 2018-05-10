#ifndef MINIMAX_H
#define MINIMAX_H
#include <vector>
#include <string>
struct Player {
	char piece;
	int Val;
} ;


struct result {
	bool win;
	Player player;
};

class minimax {
public:
	minimax();
	std::string decide(std::string,char);
	int maxValue(std::string);
	int minValue(std::string);
	int utility(std::string);
	result termTest(std::string);
	std::vector<std::string> getNeighbors(std::string,Player);


private:


};




#endif