#include "gameFun.h"
#include "gameOut.h"

void out_title_intro(string name){
	
	cout<<"\n\nHello, "<< name<<", this game tests your skills at code cracking. \nYour"
	<<" objective: Break into this locked safe and uncover it's contents. \nYour"
	<<" tools: Your wit. This safe is encoded utilizing a keyword transposition \ncipher."
	<<" You will be given a five character secret code and must use it \nto crack"
	<<" a five character security password. \nThe weak-of-will will fail this challenge"
	<<"\n... Will you?\n\n";
	
	cout<<"Let's begin, shall we..?\n\n";
}

int out_title_choice(){
	int choice;
	
	cout<<"1.) New Game\n";
	cout<<"2.) Check Leaderboard\n";
	cout<<"3.) Exit\n";
	do{
	cin.clear();
	cout<<"\tChoice: ";cin >> choice;
	cin.clear();cin.ignore(X,'\n');
	}while(cin.fail() || (choice <= 0 || choice > 3));
	cout<<endl;
	
	return choice;

}

int out_game_choice(string crypt_word,string key_word){
	int choice=0;
	
	cout << "\tYour word to decrypt is: \t"<<crypt_word<<endl;
	cout << "\tYour secret key is:   \t"<<key_word<<endl;
	//options
	cout << "1.) Make Guess\n";
	cout << "2.) How To Decrypt\n";
	cout << "3.) Quit Round\n";
	do{
	cin.clear();
	cout<<"\tChoice: ";cin >> choice;
	cin.clear();cin.ignore(X,'\n');
	}while(cin.fail() || (choice <= 0 || (choice > 3 && choice != 777)));
	
	return choice;
}

//function that prompts the player to play again
bool out_rematch(){
	char choice = 'x';
	cout<<"\nWould you like to play again(Y/n): ";cin >> choice;cin.clear();cin.ignore(X,'\n');
	switch (choice){
		case 'y':
		case 'Y':
			return true;break;
		case 'n':
		case 'N':
			return false;break;
		default:
			cout<<"Defaulting to option \'No\'... Thanks for Playing!";
			return false;break;
	}
}

void out_game_guide(){
	cout<<"\n*****************************************************\n";
	cout << "Game Guide:\n";
	cout<<"*****************************************************\n";
	cout << "For this cipher, the given keyword is written \nand the alphabet follows the keyword in \ncolumns below. Duplicate letter's are skipped. \nLet's take the key CAT and encrypted message VHALEHI:\n\n";
	cout<<"\t\tC - A - T\nB - D - E\nF - G - H\n";
	cout<<"\t\tI - J - K\nL - M - N\nO - P - Q\n";
	cout<<"\t\tR - S - U\nV - W - X\nY - Z  \n";
	cout<<"\nThen the columns are in arranged in order by \nletter of the first row, and spread out \n'horizontally'. Compare this ordering with the standard \nalphabet to crack the code!\n";
	cout<<"A-D-G-J-M-P-S-W-Z-C-B-F-I-L-O-R-V-Y-T-E-H-K-N-Q-U-X\n";
	cout<<"A-B-C-D-E-F-G-H-I-J-K-L-M-N-O-P-Q-R-S-T-U-V-W-X-Y-Z\n";
	cout<<"\nThus; VHALEHI ...translates to... QUANTUM\n";
	cout<<"*****************************************************\n\n";
}

//prints the leaderboard
void out_check_board(){
	string s;int i=1;
	cout<<"\nLeaderboards: \n";
	//open leaderboard file
	ifstream ifs(".lb");
	//print each line one at a time
	while (getline(ifs, s)){
		cout<<i<<".) "<<s<<endl;i++;
	}cout<<endl;
	//close leaderboard file
	ifs.close();
}

void out_incorrect(int guesses, string base_word){
	cout<<"That's Incorrect.\n\n";
		if (!guesses) 
			cout<<"The Answer Was: "<<base_word<<endl;
}

string out_get_guess(){
	string guess = " ";
	cout<<"\tGuess: ";
	getline(cin,guess);
	return guess;
}

void out_correct(string base_word){
	cout<<"\n\n"<<base_word<<", Correct!\n\n";
}

void out_score_round(int ellapsed,int guesses){
	cout<<"\nRound Score:"<<gen_score(ellapsed,guesses);
}

void out_score_game(int score){
	cout<<"\nTotal Score:"<<score;
}

void out_reveal_box(){
	Box box;
	srand(time(NULL));
	cout<<"\n\n***This Box held: "<<box.items[rand()%3]<<"***"<<endl;
}

















