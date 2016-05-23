/**
 * given a integer, convert it to Roman numeral
 * Proper form is to subtract only a value with the next lower power of 10
 */

class Solution{
public:
    string intToRoman(int num){
        map<int,char> table;
        table[1] = 'I',table[5] = 'V';
        table[10] = 'X',table[50] = 'L';
        table[100] = 'C',table[500] = 'D';
        table[1000] = 'M';

        //int flagNumber[8] ={1,5,10,50,100,500,1000};
        string s;
        while(num != 0){
            if(num >= 1 && num < 5){
                if(num >= 4){
                    s.push_back(table[1]);
                    s.push_back(table[5]);
                    num -= 4;
                }else{
                    for(int i = 0; i < num/1; ++i) s.push_back(table[1]);
                    num %= 1;
                }
            }else if(num >= 5 && num < 10){
                if(num > 8){
                    s.push_back(table[1]);
                    s.push_back(table[10]);
                    num -= 9;
                }else{
                    s.push_back(table[5]);
                    num -= 5;
                }
            }else if(num >= 10 && num < 50){
                if(num >= 40){
                    s.push_back(table[10]);
                    s.push_back(table[50]);
                    num -= 40;
                }else{
                    for(int i = 0; i < num/10; ++i) s.push_back(table[10]);
                    num %= 10;
                }
            }else if(num >= 50 && num < 100){
                if(num >= 90){
                    s.push_back(table[10]);
                    s.push_back(table[100]);
                    num -= 90;
                }else{
                    s.push_back(table[50]);
                    num %= 50;
                }
            }else if(num >= 100 && num < 500){
                if(num >= 400){
                    s.push_back(table[100]);
                    s.push_back(table[500]);
                    num -= 400;
                }else{
                    for(int i = 0; i < num/100; ++i) s.push_back(table[100]);
                    num %= 100;
                }
            }else if(num >= 500 && num < 1000){
                if(num >= 900){
                    s.push_back(table[100]);
                    s.push_back(table[1000]);
                    num -= 900;
                }else{
                    s.push_back(table[500]);
                    num %= 500;
                }
            }else if(num >= 1000){
                for(int i = 0; i < num/1000; ++i) s.push_back(table[1000]);
                num %= 1000;
            }
        }

        return s;
    }
};
