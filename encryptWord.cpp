#include "gameFun.h"
#include "gameOut.h"

string encrypt_word(string base,string key) {
    string s;
    int n,i,j,k,x,y,c=0;
    char t;
    char alpha[N] = {'A','B','C','D','E','F','G','H',
                     'I','J','K','L','M','N','O','P',
                     'Q','R','S','T','U','V','W','X','Y','Z'};
    char beta[N];

      //split the key and message into vectors of characters
        vector<char> vkey(key.begin(),key.end());
        vector<char> vbase(base.begin(),base.end());
        
        //iterate over the key vector...
        for (i = 0; i < vkey.size(); i++){
            for (j = i+1; j < vkey.size(); j++){
                //...and delete duplicate characters in the key
                if (vkey[i] == vkey[j]){
                    vkey.erase(vkey.begin()+j);
                }
            }
        }
        
        x = vkey.size(); //x holds the width of the new array
        y = numRows(x); //y holds the height of the new array
        char mid[x][y];
        
        //fill the first row of the new array with the key
        for (i = 0; i < x; i++) mid[i][0] = vkey[i];
        
        //populate the new array with the normal alphabet, 
         //excluding characters that are present in the key
        for (i = 1; i < y; i++) { //for height, starting from 1
            for (j = 0; j < x; j++) { // for width, starting from 0
                //if the next value(c) in the alphabet cannot be found in the key vector...
                if (c<N){
                if(!(std::find(vkey.begin(), vkey.end(), alpha[c]) != vkey.end())) {
                    //add the value to the new alphabet at [k][j]
                    mid[j][i] = alpha[c];
                }else j--;}else mid[j][i] = '0';
                c++;
            }
        }c=0;
        //iterate over the key vector...
        for (i = 0; i < vkey.size(); i++){
            //...and place the characters in order (i.e. BLADE -> ABDEL)
            for (j = 0; j < vkey.size(); j++){
                t = vkey[i];
                if (vkey[i] < vkey[j]){
                    vkey[i] = vkey[j];
                    vkey[j] = t;
                }
            }
        }
        
      //reorganize the mid array
        //iterate over the top row [0..x][0] arranging entire columns in order
        for (i = 0; i < x; i++) {
            for (j = 0; j < x; j++){
                if (mid[i][0] < mid[j][0]){
                    for (k = 0; k < y; k++){
                        t = mid[i][k];
                        mid[i][k] = mid[j][k];
                        mid[j][k]= t;
                    }
                    
                }
                
            }
        }
      //feed the values into the new array
        i=0;
            for (j = 0; j < x; j++) {
                for (k = 0; k < y; k++) {
                    if (mid[j][k] != '0')
                        beta[i] = mid[j][k];
                    else i--;
                    i++;
                }
            }
      //translate the message
        for (i = 0; i < vbase.size(); i++){
            for (j = 0; j < N; j++){
                if (vbase[i] == alpha[j]) {
                    vbase[i] = beta[j];break;
                }
            }
        } 
        //output
        string result(vbase.begin(),vbase.end());
    return result;
}

