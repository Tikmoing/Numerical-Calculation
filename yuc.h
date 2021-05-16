//author youryanmi
#pragma once
#include  <string.h>
#include  <iostream>

using namespace std;

/*Complex Define*/

//complex : x + yi, x,y are double
class complex{
    friend istream& operator >>(istream &in,complex c);
	friend ostream& operator <<(ostream &out,complex c);
    
    public:
    double x = 0,y = 0;
    //define by x and y
    complex(double x,double y){
        this->x = x;
        this->y = y;
    }
    complex(){}
    complex(double x){this->x = x;}
    complex(int x){this -> x = x;}
    // return real part
    double real(){
        return x;
    }
    //return imag part
    double imag(){
        return y;
    }
    //Complex conjugation : return conj
    complex conj(){
        complex res(x,-y);
        return res;
    }
    //Complex length : return double
    double length(){
        return (x * x + y * y);
    }    
};

/* operator */
//standard input : no other operator like : >> a + b
istream& operator >>(istream &in,complex c){
        in>>c.x>>c.y;
        return in;
    }

//standard output : no other operator like : << a + b
ostream& operator <<(ostream &out,complex c){
    if(c.y >= 0) out<<c.x<<"+"<<c.y<<"i";
    else out<<c.x<<c.y<<"i";
    return out;
}

/* operate with complex*/
//add
complex operator +(complex c1,complex c2){
    complex res(c1.x + c2.x, c1.y + c2.y); 
    return res;
}

//minus
complex operator -(complex c1,complex c2){
    complex res(c1.x - c2.x, c1.y - c2.y); 
    return res;
}

//multiplication
complex operator *(complex c1,complex c2){
    complex res(c1.x * c2.x - c1.y * c2.y, c1.x * c2.y + c1.y * c2.x); 
    return res;
}

//division
complex operator /(complex c1,complex c2){
    double c2_length = c2.length();
    c2.y *= -1;
    complex res((c1.x * c2.x - c1.y * c2.y)/c2_length, (c1.x * c2.y + c1.y * c2.x)/c2_length); 
    return res;
}

//compare their length
bool operator >(complex c1,complex c2){
    if(c1.length() > c2.length()) return true;
    else return false;
}

//compare their length
bool operator <(complex c1,complex c2){
    if(c1.length() < c2.length()) return true;
    else return false;
}

//compare their length
bool operator <=(complex c1,complex c2){
    if(c1.length() <= c2.length()) return true;
    else return false;
}

//compare their length
bool operator >=(complex c1,complex c2){
    if(c1.length() >= c2.length()) return true;
    else return false;
}
/*
// all value type
// template <class T>
// complex operator +(complex c , T t){
//     complex res(c.x + t,c.y);
//     return res;
// }

// template <class T>
// complex operator +( T t, complex c){
//     complex res(c.x + t,c.y);
//     return res;
// }

// template <class T>
// complex operator -(complex c , T t){
//     complex res(c.x - t,c.y);
//     return res;
// }

// template <class T>
// complex operator -( T t, complex c){
//     complex res(c.x - t,c.y);
//     return res;
// }

// template <class T>
// complex operator *(complex c , T t){
//     complex res(c.x *  t,c.y * t);
//     return res;
// }

// template <class T>
// complex operator *( T t, complex c){
//     complex res(c.x *  t,c.y * t);
//     return res;
// }

// template <class T>
// complex operator /(complex c , T t){
//     complex res(c.x /  t,c.y / t);
//     return res;
// }

// template <class T>
// complex operator /( T t, complex c){
//     complex res(c.x /  t,c.y / t);
//     return res;
// }
*/
//real convert to complex without a define
// complex rtc(double real){
//     complex res(real,0);
//     return res;
// }

