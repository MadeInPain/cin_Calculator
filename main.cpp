//Console calculator
//in: 1 + 2 * 3;
//out: res = 7

#include <iostream>
#include <calclexeme.h>
#include <vector>
#include <string>

using namespace std;

void printVect(vector<CalcLexeme> &);
void eraseVect(vector<CalcLexeme> &obj, unsigned int);

int main()
{
    cout << "inpun your expression: " << endl;

    //unsigned int vect_size = 20;

    vector<CalcLexeme> vect;
    vector<CalcLexeme>::iterator it;
    it = vect.begin();

    for(string in; cin >> in;){ // fill vector of lexem

        if(in[0] == 'q')
            return 0;

        switch (in[0]) {
        case '+':
            vect.insert(vect.begin(), CalcLexeme('+'));
            break;
        case '-':
            vect.insert(vect.begin(), CalcLexeme('-'));
            cin >> in;
            if(stod(in))
                vect.insert(vect.begin(), CalcLexeme('v', -stod(in)));
            break;
        case '*':
            vect.insert(vect.begin(), CalcLexeme('*'));
            break;
        case '/':
            vect.insert(vect.begin(), CalcLexeme('/'));
            break;
        default:
            if(stod(in))
                vect.insert(vect.begin(), CalcLexeme('v', stod(in)));
            break;
        }

    }

    printVect(vect);

    cout << "-------" << endl;

    for(unsigned int i = vect.size() - 1; i > 0; i--){ // do mul/div operation
        if(vect[i].GetType() == 'v')
            continue;
        if(vect[i].GetType() == '/'){ // div
            cout << "div: " << vect[i-1].GetValue() << " / " << vect[i+1].GetValue() << endl;

            vect[i-1] = vect[i-1] / vect[i+1];
            eraseVect(vect, i);

        }
        else if(vect[i].GetType() == '*'){ // mul
            cout << "mul: " << vect[i-1].GetValue() << " * " << vect[i+1].GetValue() << endl;

            vect[i-1] = vect[i-1] * vect[i+1];
            eraseVect(vect, i);

        }

    }

     for(unsigned int i = vect.size() - 1; i > 0; i--){
        if((vect[i].GetType() == '+') || (vect[i].GetType() == '-')){
            cout << "add: " << vect[i-1].GetValue() << " + " << vect[i+1].GetValue() << endl;

            vect[i-1] = vect[i-1] + vect[i+1];
            eraseVect(vect, i);

        }
//        else if(vect[i].GetType() == '-'){
//            cout << "sub: " << vect[i-1].GetValue() << " - " << vect[i+1].GetValue() << endl;

//            vect[i-1] = vect[i-1] + vect[i+1];
//            eraseVect(vect, i);

//        }

    }

    cout << "res = " << vect[0].GetValue() << endl;


    return 0;
}

void eraseVect(vector<CalcLexeme> &obj, unsigned int i){
    obj.erase(obj.begin() + i, obj.begin() + i + 2);
    //obj.erase();
    printVect(obj);
}

void printVect(vector<CalcLexeme> & v){
    for(CalcLexeme out : v)
        cout << out;
    cout << "- - - - -"<< endl;

}
