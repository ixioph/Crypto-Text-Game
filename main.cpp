#include "gameFun.h"

int main(){
	Player player; string name;
	cout<<"\tWelcome to \"What's In the Box: A safe-cracking game\"!\n";//cin.get();
	do
	{
	cout<<"\tFor our records, please enter your name: ";getline(cin,name);
	}while(!valid_name(name));
	
	player.name = name; player.score = 0; player.time = 0;
	game(player);
	
	
	cout<<"Thanks for playing!\n";
	if(player.time)cout<<"Time spent decrypting: "<<player.time<<" seconds."<<endl;
	return 0;
}
