#pragma once
#include<fstream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include<stdlib.h>
#include<time.h>
#define N 26
#define DEF_VAL 600
#define X std::numeric_limits<std::streamsize>::max()
using namespace std;

struct Player{
	string name;
	int score,time;
};
struct Box{
	string items[3] = {"'Dead Cat'","'Living Cat'","'Superposed Cat'"};
};
int valid_name(string);
int game(Player&);
int title_screen(Player&);
int get_num_lines(string);
int gen_score(int,int);
int numRows(int);

void save_game(Player&);
void new_game(Player&);

string myUpper(string);
string get_word();
string encrypt_word(string,string);





