#include"gameFun.h"
#include"gameOut.h"

//game introduction
int game(Player &p){
	//introduction
	out_title_intro(p.name);
	
	switch(title_screen(p)){
		case 0: break;
		default: return 0;
	}
}

//title options
int title_screen(Player &p){
	int choice=0;
	do{
		switch (choice = out_title_choice()){
			case 1:
				do{
				new_game(p);
				}while(out_rematch());
				save_game(p);
				title_screen(p);
				break;
			case 2:
				out_check_board();
				title_screen(p);
			case 3:
				break;
			default:
				choice = 0;
		}choice++;
	}while(!choice);
	return choice;
}

int valid_name(string s){
	int i = 0;
	while(s[i]){
		if (isspace(s[i]) || i>=16) return 0;
		i++;
	}
	return 1;

}

//main game loop
void new_game(Player &p){
	int guesses=3,choice=0,ellapsed;
	bool win = false;
	string base_word,crypt_word,key_word,guess;
	time_t start,end;
	base_word = get_word();
	key_word = get_word();
	start = time(0);
	do{
	crypt_word = encrypt_word(base_word,key_word);
	choice = out_game_choice(crypt_word,key_word);
	do{
	switch (choice){
		case 1:
			guess = out_get_guess();
			if (myUpper(guess) == base_word) {
				guesses--;
				out_correct(base_word);
				win=true;
				end = time(0);ellapsed = (int)(end-start)+1;
				out_score_round(ellapsed,guesses);
				p.score += gen_score(ellapsed,guesses);
				p.time += ellapsed;
				out_score_game(p.score);
				out_reveal_box();
				break;}
			else {
				guesses--;
				out_incorrect(guesses, base_word);
				end = time(0);ellapsed = (int)(end-start)+1;
				p.time += ellapsed;
			}
			break;
		case 2:
			out_game_guide();break;
		case 777:
			cout<<base_word<<endl;break;
		case 3:
			end = time(0);ellapsed = (int)(end-start)+1;
			p.time += ellapsed;
			return;
		default:
			choice = 0;
	}
	}while(!choice);
	
	}while(guesses > 0 && !win);
	start = end = time(0);
}

//compares the player with the members of the leaderboard 
//and adds the player if player score is high enough
void save_game(Player &p){
	int i=0,j=0,tmpScore=0,tS=0; string s,tmpName=" ",tN=" ";
	//create a vector to hold top 5 scorers
	vector<Player> plist(5);
	//open the scoreboard file
	ifstream ifs(".lb");
	//pass the values from the file into the vector 
	while (i < 5){
		ifs >> plist[i].name;
		ifs >> plist[i].score;i++;
	}
	//close the file
	ifs.close();
	//check the values in the vector against the player's score
	for (i = 0; i < 5; i++){
		//if the player is in the top 5..
		if (p.score > plist[i].score){
			//add them to the board and displace each player beneath them
			tmpScore = plist[i].score;
			tmpName = plist[i].name;
			plist[i].score = p.score;
			plist[i].name = p.name;
			for (j=i+1; j < 5; j++){
				tS = plist[j].score; tN = plist[j].name;
				plist[j].score = tmpScore; plist[j].name = tmpName;
				tS = tmpScore; tN = tmpName;
			}
			break;
		}
	}
	//iterate over the vector, outputting the contents to the file
	ofstream ofs(".lb");
	for (i = 0; i < 5; i++) ofs <<plist[i].name<<"\t\t"<<plist[i].score<<"\n";
	ofs.close();

}

//function to generate the score
int gen_score(int time,int guesses) {
	if (time > DEF_VAL) return 1+guesses;
	else if (!guesses)return (DEF_VAL - time)/2;
	else return (DEF_VAL - time) * guesses+1;

}

//returns the number of lines in a file
int get_num_lines(string input){
	int n=0; string s;
	ifstream ifs(input.c_str());
	//check number of lines
	while (getline(ifs, s)){
		n++;
	}ifs.close();
	return n;
}

//pulls a random word from the wl word list file
string get_word(){
	string word;int num_lines=0,tar_line=0,i;
	srand(time(NULL));
	//calculate the number of words in the list
	num_lines = get_num_lines(".wl");
	static int nr=0;//not random
	//open word list file
	ifstream ifs(".wl");
	//check number of lines
	string arr[num_lines];
	for(i=0; i < num_lines; i++){
		ifs >> arr[i];
	}
	//grab a word from a line and store in variable
	tar_line = rand()%num_lines;
	if(nr == tar_line){
		while(nr == tar_line)
			tar_line = rand()%num_lines;
	}
	word = arr[tar_line];
	//close file
	ifs.close();
	//return word
	nr = tar_line;
	return word;
}

//returns the correct number of rows based on the number of columns created by the word
int numRows(int s){
    if (N%s) return (N/s)+1;
    else return N/s;
}

//converts given string to all caps
string myUpper(string s){
transform(s.begin(), s.end(), s.begin(), ::toupper);
return s;
}






