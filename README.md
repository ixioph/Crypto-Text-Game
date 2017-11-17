# Cipher-Cracking Cryptography Text Game

Author: Willie Cooley

#### SYNOPSIS
This game was born out of an idea I had after completing a programming challenge. It's a bit of a thinker, and I'm coming up with ways to speed it up in that regard, but it's a lot of fun once you get the hang of it.

>Hello, this game tests your skills at code cracking. Your objective: Break into this locked safe and uncover it's contents. Your tools: Your wit. This safe is encoded utilizing a keyword transposition cipher. You will be given a five character secret code and must use it to crack a five character security password. The weak-of-will will fail this challenge... Will you?

#### INSTRUCTIONS

>For this cipher, the given keyword is written on the first row and the normal alphabet is written on the following lines, making sure to use the same number of columns (characters) in each row. Duplicate letters are skipped. Let's take the keyword CAT and encrypted message VHALEHI:<br />
C - A - T<br />B - D - E<br />F - G - H<br />
I - J - K<br />L - M - N<br />O - P - Q<br />
R - S - U<br />V - W - X<br />Y - Z  <br />
Then the columns are in arranged in order by letter of the first row, and spread out 'horizontally'. Compare this ordering with the standard alphabet to crack the code!<br />
A-D-G-J-M-P-S-W-Z-C-B-F-I-L-O-R-V-Y-T-E-H-K-N-Q-U-X<br />
A-B-C-D-E-F-G-H-I-J-K-L-M-N-O-P-Q-R-S-T-U-V-W-X-Y-Z<br />
Thus; VHALEHI ...translates to... QUANTUM!

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
