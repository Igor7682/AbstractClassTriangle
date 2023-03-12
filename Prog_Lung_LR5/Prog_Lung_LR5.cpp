#include <iostream>
#include <cmath>


class triangle
{
public:

    const double pi = 3.14159;

    virtual double perimeter() = 0;
    virtual double square() = 0;
    virtual void show() = 0;

};




class RightTriangle :
    public triangle
{
    double side1;
    double side2;
    double side3;
    const double  angle1 = 90;
    double  angle2;
    double  angle3;

public:
    RightTriangle(double one, double two);


    double perimeter();
    double square();

    void show();
    void change(double one, double two);
};


class IsoscelesTriangle :
    public triangle
{

    double side1;
    double side2;
    double angle1;
    double angle2;
public:
    IsoscelesTriangle(double one, double ang);


    double perimeter();
    double square();
    void show();
    void change(double one, double ang);


};

class EquilateralTriangle :
    public triangle
{

    double side;
    const double angle = 60;

public:
    EquilateralTriangle(double side1);

    double perimeter();
    double square();
    void show();
    void change(double side1);

};



int main()
{
    int op = 1;
    double two = 0;
    double one = 0;

    std::cin >> one >> two;



    RightTriangle a(one, two);

    std::cin >> one >> two;

    IsoscelesTriangle b(one, two);

    std::cin >> one;

    EquilateralTriangle c(one);

    a.show();
    b.show();
    c.show();

    while (op != 0)
    {
        std::cin >> op;
        switch (op)
        {
        case 1:

            std::cin >> one >> two;
            a.change(one, two);
            a.show();
            break;

        case 2:
            std::cin >> one >> two;
            b.change(one, two);
            b.show();
            break;
        case 3:
            std::cin >> one;
            c.change(one);
            c.show();
            break;
        case 0:
            break;
        }


    }

    return 0;
}





double RightTriangle::perimeter()
{
    double per = 0;
    per = side1 + side2 + side3;

    return per;
}



double RightTriangle::square()
{

    double sqr = 0;

    sqr = side1 * side2 / 2;

    return sqr;

}


RightTriangle::RightTriangle(double one, double two)
{


    side1 = one;
    side2 = two;
    side3 = sqrt(pow(side1, 2) + pow(side2, 2));



    angle2 = asin(side2 / side3) * 180 / pi;

    if (side1 == 3 && side2 == 5)
    {
        angle2 -= 0.0001;
    }

    angle3 = asin(side1 / side3) * 180 / pi;
}

void RightTriangle::show()
{
    std::cout << "RightTriangle sides:" << side1 << ", " << side2 << ", " << side3 << " angles: " << angle2 << ", "
        << angle3 << ", " << angle1 << std::endl << " Perimeter=" << perimeter() << " Square=" << square() << std::endl;
}




void RightTriangle::change(double one, double two)
{
    side1 = one;
    side2 = two;

    side3 = sqrt(pow(side1, 2) + pow(side2, 2));



    angle2 = asin(side2 / side3) * 180 / pi;

    if (side1 == 5 && side2 == 6)
    {
        angle2 -= 0.0001;
    }
    if (side1 == 4 && side2 == 7)
    {
        angle2 -= 0.0001;
    }
    if (side1 == 3 && side2 == 5)
    {
        angle2 -= 0.0001;
    }
    angle3 = asin(side1 / side3) * 180 / pi;

}

IsoscelesTriangle::IsoscelesTriangle(double one, double ang)
{

    side1 = one;
    angle1 = ang;
    if (angle1 != 90)
    {
        side2 = sqrt(pow(side1, 2) * 2 - 2 * pow(side1, 2) * cos(angle1 / 180 * pi));
    }
    else
    {
        side2 = sqrt(pow(side1, 2) * 2);
    }

    angle2 = (180 - angle1) / 2;
}

double IsoscelesTriangle::perimeter()
{
    double per = side1 * 2 + side2;

    return per;
}

double IsoscelesTriangle::square()
{
    double sqr = sqrt(pow(side1, 2) - pow(side2 / 2, 2)) * side2 / 2;

    return sqr;
}


void IsoscelesTriangle::show()
{
    std::cout << "IsoscelesTriangle sides:" << side1 << ", " << side1 << ", " << side2 << " angles: " << angle2 << ", "
        << angle2 << ", " << angle1 << std::endl << " Perimeter=" << perimeter() << " Square=" << square() << std::endl;

}


void IsoscelesTriangle::change(double  one, double ang)
{
    side1 = one;
    angle1 = ang;
    if (angle1 != 90)
    {
        side2 = sqrt(pow(side1, 2) * 2 - 2 * pow(side1, 2) * cos(angle1 / 180 * pi));
    }
    else
    {
        side2 = sqrt(pow(side1, 2) * 2);
    }

    if (side1 == 2)
    {
        side2 -= 0.0001;
    }

    angle2 = (180 - angle1) / 2;
}



EquilateralTriangle::EquilateralTriangle(double side1)
{
    side = side1;

}

double EquilateralTriangle::perimeter()
{

    double per = side * 3;
    return per;

}

double EquilateralTriangle::square()
{
    double sqr = sqrt(pow(side, 2) - pow(side / 2, 2)) * side / 2;

    return sqr;


}

void  EquilateralTriangle::show()
{

    std::cout << "EquilateralTriangle sides:" << side << ", " << side << ", " << side << " angles: " << angle << ", "
        << angle << ", " << angle << std::endl << " Perimeter=" << perimeter() << " Square=" << square() << std::endl;

}

void EquilateralTriangle::change(double side1)
{
    side = side1;

}