/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-08 10:45:40
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-01 21:41:06
 */

#include<iostream>
using namespace std;

class Complex {
    private:
        double real;
        double imag;
    public:
        Complex() {}
        friend istream & operator >> (istream & , Complex &);
        friend ostream & operator << (ostream & , Complex &);
        Complex operator + (Complex &);
        Complex operator - (Complex &);
        Complex operator * (Complex &);
        Complex operator / (Complex &);
};

istream & operator << (istream &input , Complex &c) {
    cin >> c.real >> c.imag;
}

ostream & operator << (ostream &ouput , Complex &c) {
    cout << c.real << "+" << c.imag;
}

Complex::operator +(Complex &c) {
    return Complex(this->real + c.real , this->imag + c.imag);
}

Complex::operator - (Complex &c) {
    return Complex(this->real - c.real , this->imag - c.imag);
}

Complex::operator + (Complex &c) {
    return Complex(this->real + c.real , this->imag + c.imag);
}
