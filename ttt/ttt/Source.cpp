#include "minimax.h"
#include <iostream>

using namespace std;
extern Player MAX;
extern Player MIN;



int main(int ac, char* argv[]) {
	minimax mm;
	if (ac != 3){
		cout << "bad input friend" << endl;
		exit(23);
	}
	if (argv[1][0] == 'X'){
		cout<<mm.decide(argv[2], 'X');
	}
	else{
		cout<<mm.decide(argv[2], 'O');
	}

	cin.get(); cin.get(); cin.get();
}