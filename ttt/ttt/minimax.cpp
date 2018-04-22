#include "minimax.h"
#include <algorithm>
#include <iostream>
int MAXV = 1;
int MINV = -1;
int TIEV = 0;
char BLANK = '-';
using namespace std;
Player TIE;
Player MIN;
Player MAX;
result XWIN,XLOSE,TIEGAME,NOTDONE;

minimax::minimax(){


	MAX.piece = 'X';
	MAX.Val = MAXV;

	MIN.piece = 'O';
	MIN.Val = MINV;

	TIE.piece = '-';
	TIE.Val = TIEV;

	XWIN.win = XLOSE.win = TIEGAME.win = true;
	NOTDONE.win = false;
	XWIN.player = MAX;
	XLOSE.player = MIN;
	TIEGAME.player = TIE;
}

string minimax::decide(string state){
	vector<string>neighbors = getNeighbors(state, MAX);
	vector<int>vals;
	for (int i = 0; i < neighbors.size(); i++) {
		vals.push_back(minValue(neighbors[i]));
	}
	vector<int>::iterator i= max_element(vals.begin(), vals.end());
	int value = distance(vals.begin(), i);
	return neighbors[value];

}

int minimax::maxValue(string state){
	int maxV = -10;
	result res = termTest(state);
	if (res.win)return res.player.Val;
	vector<string>neighbors = getNeighbors(state, MAX);
	for (int i = 0; i < neighbors.size(); i++) {
		maxV=max(maxV,minValue(neighbors[i]));
	}
	return maxV;
}

int minimax::minValue(string state){
	int minV = 10;
	result res = termTest(state);
	if (res.win)return res.player.Val;
	vector<string>neighbors = getNeighbors(state, MIN);
	for (int i = 0; i < neighbors.size(); i++) {
		minV = min(minV, maxValue(neighbors[i]));
	}
	return minV;
}

int minimax::utility(string state){
	termTest(state);
	return 0;
}

result minimax::termTest(string state){
	if (state.find("-") == string::npos) {
		return TIEGAME;
	}
	for (int i = 0, j=0; i < state.length();j++, i+=3) {
		if (state[i] == state[i + 1]&&state[i+1] == state[i + 2]) {//horizontal
			if (state[i] == 'X')return XWIN;
			else if (state[i] == 'O')return XLOSE;
		}
		if (state[j] == state[j + 3]&&state[j+3] == state[j + 6]) {//vertical
			if (state[j] == 'X')return XWIN;
			else if (state[j] == 'O')return XLOSE;
		}
	}
	if (state[0] == state[4]&&state[4] == state[8]) {
		if (state[0] == 'X')return XWIN;
		else if (state[0] == 'O')return XLOSE;
	}
	if (state[6] == state[4]&&state[4] == state[2]) {
		if (state[6] == 'X')return XWIN;
		else if (state[6] == 'O')return XLOSE;
	}

	return NOTDONE;
}

vector<string> minimax::getNeighbors(string state,Player player){
	vector<string> ret;
	string temp;
	for (int i = 0; i < state.length(); i++) {
		if (state[i] == BLANK) {
			temp = state;
			temp[i] = player.piece;
			ret.push_back(temp);
		}
	}
	return ret;
}

