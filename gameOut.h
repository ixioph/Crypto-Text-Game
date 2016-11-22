#pragma once
#include <iostream>
#include <string>

using namespace std;

void out_title_intro(string);
void out_game_guide();
void out_check_board();
void out_reveal_box();
void out_incorrect(int,string);
void out_correct(string);
void out_score_round(int,int);
void out_score_game(int);

int out_title_choice();
int out_game_choice(string,string);

bool out_rematch();

string out_get_guess();
