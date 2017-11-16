#include "calclexeme.h"

CalcLexeme::CalcLexeme(char ch, double val) : type(ch), value(val){

}

ostream & operator<< (ostream & os, CalcLexeme & obj){
    os << "type: "<< obj.type << ", val: " << obj.value << std::endl;
    return os;
}

CalcLexeme & CalcLexeme::operator+ (CalcLexeme obj){
    value += obj.value;
    return *this;
}
CalcLexeme & CalcLexeme::operator- (CalcLexeme obj){
    value -= obj.value;
    return *this;
}
CalcLexeme & CalcLexeme::operator/ (CalcLexeme obj){
    value /= obj.value;
    return *this;
}
CalcLexeme & CalcLexeme::operator* (CalcLexeme obj){
    value *= obj.value;
    return *this;
}
