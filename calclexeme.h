#ifndef CALCLEXEME_H
#define CALCLEXEME_H

#include <ostream>

using std::ostream;

class CalcLexeme
{
private:
    char type;
    double value;
public:
    char GetType(){return type;}
    double GetValue(){return value;}

    CalcLexeme(char , double = 0);

    CalcLexeme & operator+ (CalcLexeme);
    CalcLexeme & operator- (CalcLexeme);
    CalcLexeme & operator/ (CalcLexeme);
    CalcLexeme & operator* (CalcLexeme);

    friend ostream & operator<< (ostream & os, CalcLexeme & obj);
};

#endif // CALCLEXEME_H
