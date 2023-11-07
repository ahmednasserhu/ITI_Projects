#include <iostream>
using namespace std;



class Complex
{
private:
    int Real;
    int Imaginary;
public:
    void setReal(int _Real)
    {
        Real = _Real;
    }
    int getReal(void)
    {
        return Real;
    }
    void setImaginary(int Imaginary_num)
    {
        Imaginary = Imaginary_num;
    }
    int getImaginary(void)
    {
        return Imaginary;
    }

    Complex add(Complex com)
    {
        Complex result;
        result.setReal(Real + com.getReal());
        result.setImaginary(Imaginary + com.Imaginary);
        return result;
    }

    Complex subtract(Complex com)
    {
        Complex result;
        result.setReal(Real - com.getReal());
        result.setImaginary(Imaginary - com.getImaginary());
        return result;
    }

    Complex add(Complex com1, Complex com2);
    void print(void);
    friend Complex subtract(Complex com1, Complex com2);
};

void Complex :: print(void)
{
    cout<<"Number = "<<Real;
    if(Imaginary>0)
    {
        cout<<"+"<<Imaginary<<"j";
    }
    else if(Imaginary<0)
    {
        cout<<Imaginary<<"j";
    }
    cout<<endl;
}

Complex subtract(Complex com1, Complex com2)
{
    Complex result;
    result.Real = com1.Real - com2.Real;
    result.Imaginary = com1.Imaginary - com2.Imaginary;
    return result;
}

Complex add(Complex com1, Complex com2)
{
    Complex result;
    result.setReal(com1.getReal() + com2.getReal());
    result.setImaginary(com1.getImaginary() + com2.getImaginary());
    return result;
}

int main()
{

    Complex c1, c2;
    c1.setReal(5);
    c1.setImaginary(4);
    c2.setReal(2);
    c2.setImaginary(2);
    Complex c3 = add(c1,c2);
    Complex c4 = c2.subtract(c1);
    c4.print();
    cout<<endl;
    c3.print();

    return 0;
}
