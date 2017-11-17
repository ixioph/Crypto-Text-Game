# Cipher-Cracking Cryptography Text Game

Author: Willie Cooley

#### SYNOPSIS
This game was born out of an idea I had after completing a programming challenge. It's a bit of a thinker, and I'm coming up with ways to speed it up in that regard, but it's a lot of fun once you get the hang of it.

>Hello, this game tests your skills at code cracking. Your objective: Break into this locked safe and uncover it's contents. Your tools: Your wit. This safe is encoded utilizing a keyword transposition cipher. You will be given a five character secret code and must use it to crack a five character security password. The weak-of-will will fail this challenge... Will you?

#### INSTRUCTIONS

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

#### run command:
```css
$ make game
```
------------------------------------------

#### TODO:

- [x] Improve Input Validation
- [ ] GUI Frontend
- [ ] Game Difficulty Levels
- [ ] Text Formatting
- [ ] Expanded Wordlist
