//
//  main.cpp
//  词法分析器
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/4/3.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

// Lexical_Analysis.cpp : 定义控制台应用程序的入口点。
//
#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

char prog[80],token[20];

char ch;
int syn,p = 0,m=0, row, sum = 0;
char *rwtab[32] = {"auto", "break", "case", "char" ,"const", "continue",
                     "default", "do", "double", "else", "enum",  "extern",
                     "float",  "for",  "goto", "if", "int", "long",
                    "register", "return", "short", "signed", "sizeof",  "static",
                    "struct",  "switch",  "typedef", "union", "unsigned", "void",
                    "volatile", "while"
        };


void scaner() {
    for(int i = 0;i < 8;i++) {
        token[i] = NULL;
    }
    ch = prog[p++];
    while(ch == ' ') {
        ch = prog[p];
        p++;
    }
    if((ch >= 'a'&& ch <= 'z')||(ch >= 'A' && ch <= 'Z')) {
        m=0;
        while(( ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'z')||(ch >= 'A'&& ch <= 'Z')) {
            token[m++] = ch;
            ch = prog[p++];
        }
        token[m++] ='\0';
        p--;
        syn = 10;
        for(int i = 0;i < 6;i++)
            if(strcmp(token, rwtab[i]) == 0) {
                syn = i+1;
                break;
            }
    }
    else if((ch>='0'&&ch<='9')) {
        sum = 0;
        while((ch >= '0' && ch <= '9')) {
            sum = sum*10 + ch - '0';
            ch = prog[p++];
        }
        p--;
        syn = 11;
        if(sum > 32767)
            syn = -1;
    }
    else switch(ch) {
        case'<':{
            m = 0;
            token[m++] = ch;
            ch = prog[p++];
            if(ch >= '>') {
                syn = 21;
                token[m++] = ch;
                
            } else if(ch == '=') {
                syn = 22;
                token[m++] = ch;
            } else {
                syn = 23;
                p--;
            }
        }
            break;
        case'>':{
            m = 0;
            token[m++] = ch;
            ch = prog[p++];
            if(ch == '=') {
                syn = 24;
                token[m++] = ch;
            } else {
                syn = 20;
                p--;
            }
        }
            break;
        case':': {
            m = 0;
            token[m++] = ch;
            ch = prog[p++];
            if(ch == '=') {
                syn = 18;
                token[m++] = ch;
            }
            else {
                syn = 17;
                p--;
            }
        }
            break;
        case'*': syn=13; token[0]=ch; break;
        case'/': syn=14; token[0]=ch; break;
        case'+': syn=15; token[0]=ch; break;
        case'-': syn=16; token[0]=ch; break;
        case'=': syn=25; token[0]=ch; break;
        case';': syn=26; token[0]=ch; break;
        case'(': syn=27; token[0]=ch; break;
        case')': syn=28; token[0]=ch; break;
        case'#': syn=0;  token[0]=ch; break;
        case'\n':syn=-2; break;
        default: syn=-1; break;
    }
}

int main( ) {
    p=0;
    row=1;
    cout<<"Please input string:"<<endl;
    do {
        cin.get(ch);
        prog[p++]=ch;
    }
    while(ch != '#');
    p=0;
    do {
        scaner();
        switch(syn)
        {
            case 11: cout << "(" << "_" << "," << sum << ")" << endl;     break;
            case -1: cout << "Error in row "<< row<<"!"<< endl;   break;
            case -2: ++row; break;
            default: cout<<"("<< "_" <<","<<token<<")"<<endl;  break;
        }
    }
    while (syn!=0);
}

