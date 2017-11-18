//Console calculator
//in: 1 + 2 * 3;
//out: res = 7

#include <iostream>
#include <calclexeme.h>
#include <vector>
#include <string>

using namespace std;

void printVect(vector<CalcLexeme> &);
void printHello();
void eraseVect(vector<CalcLexeme> &obj, unsigned int);
int runCalc(vector<CalcLexeme> &);

int main()
{
    printHello();

    vector<CalcLexeme> vect;

    while(!runCalc(vect)){
        ;
    }


    return 0;
}

void eraseVect(vector<CalcLexeme> &obj, unsigned int i){
    obj.erase(obj.begin() + i, obj.begin() + i + 2);
    //printVect(obj);
}

void printVect(vector<CalcLexeme> & v){
    for(CalcLexeme out : v)
        cout << out;
    cout << "- - - - -"<< endl;

}

int runCalc(vector<CalcLexeme> & vect){
    cout << "inpun your expression:\n " << endl;

    //unsigned int vect_size = 20;

    for(string in; cin >> in ;){ // fill vector of lexem

        if(in[0] == 'q')
            return 1;

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
            vect.insert(vect.begin(), CalcLexeme('v', stod(in)));
            if((stod(in) == 0) && (vect[1].GetType() == '/')){
                cout << "error: div by zero" << endl;
                return 1;
            }
            break;
        }

    }

    printVect(vect);

    cout << "-------" << endl;

    for(unsigned int i = vect.size() - 1; i > 0; i--){ // do mul/div operation
        if(vect[i].GetType() == 'v')
            continue;
        if(vect[i].GetType() == '/'){ // div
            cout << "div: " << vect[i+1].GetValue() << " / " << vect[i-1].GetValue();

            vect[i-1] = vect[i+1] / vect[i-1];
            cout << " = " << vect[i-1].GetValue() << endl;
            eraseVect(vect, i);

        }
        else if(vect[i].GetType() == '*'){ // mul
            cout << "mul: " << vect[i+1].GetValue() << " * " << vect[i-1].GetValue();

            vect[i-1] = vect[i+1] * vect[i-1];
            cout << " = " << vect[i-1].GetValue() << endl;
            eraseVect(vect, i);

        }

    }

     for(unsigned int i = vect.size() - 1; i > 0; i--){ // add and sub operation
        if((vect[i].GetType() == '+') || (vect[i].GetType() == '-')){
            cout << "add: " << vect[i+1].GetValue() << " + " << vect[i-1].GetValue();

            vect[i-1] = vect[i+1] + vect[i-1];
            cout << " = " << vect[i-1].GetValue() << endl;
            eraseVect(vect, i);

        }

    }

    cout << "res = " << vect[0].GetValue() << endl;
    vect.erase(vect.begin());
    cin.clear();


    return 0;
}

void printHello(){
    cout << endl;
    cout << "Hello\nUsage: in: 1 + 2 * 3 / 4 ... (with spaces!),\n"
            "to calculate: type cntr-z on Windows, cntr-d on Linux\n"
            "negative value doesn't work! (-4 * 2) but 0 - 4 * 2 \n"
            "to exit: type q " << endl;
}
