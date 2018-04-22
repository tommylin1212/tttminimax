#include "minimax.h"
#include <iostream>

using namespace std;


void pprint(string state) {
	cout << "* * * * * ";
	for (int i = 0; i < state.length(); i++) {
		if (i%3 == 0) {
			cout<<"*" << endl<<"*";
		}
		cout<<" " << state[i]<<" ";
	}
	cout <<"*"<< endl<<"* * * * * *"<<endl;
}


int main() {
	string example = "012345678";
	pprint(example);
	string start = "---------";
	minimax mm;
	bool player = false;
	cout << "Board" << endl;
	pprint(start);
	int number;
	while (!mm.termTest(start).win) {
		if (player) {
			do {
				cout<<endl << "enter a number 0-8 of a space that is blank" << endl;
				cin >> number;
			} while (start[number]!='-');
			start[number] = 'O';
			player = !player;
			pprint(start);
		}
		else {
			cout << endl << "MAX's turn" << endl;
			start=mm.decide(start);
			pprint(start);
			player = !player;
		}
	}
	if (start.find("-") == string::npos) {
		cout << "tie";
	}
	else {
		result res = mm.termTest(start);
		cout << res.player.piece << " wins";
	}
	cin.get(); cin.get(); cin.get();
}