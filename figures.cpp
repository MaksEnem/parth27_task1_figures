#include <iostream>



class Figures
{
public:
    enum Colors
    {
        NONE, WHITE, RED, BLUE, GREEN, YELLOW
    };

    Colors Color = Colors::NONE;    
    double centerOfCoordinates;
    
    void getColors()
    {
        if (Color == Colors::NONE)
        {
            std::cout << "Shape color is missing." << std::endl;
        }
        else if (Color == Colors::WHITE)
        {
            std::cout << "Figure color is white." << std::endl;
        }
        else if (Color == Colors::RED)
        {
            std::cout << "Figure color is red." << std::endl;
        }
        else if (Color == Colors::BLUE)
        {
            std::cout << "Figure color is blue." << std::endl;
        }
        else if (Color == Colors::GREEN)
        {
            std::cout << "Figure color is green." << std::endl;
        }
        else if (Color == Colors::YELLOW)
        {
            std::cout << "Figure color is yellow." << std::endl;
        }
    }
};

class Circle : public Figures
{
    double radius = 0;
    double AreaCircle = 0;
    double areaRectangle = 0;

public:
    Circle(double& inLength)
    {
        radius = inLength;
    }

    void setAreaCircle()
    {
        AreaCircle = 3.14 * radius * radius;
    }

    double getAreaCircle()
    {
        return AreaCircle;
    }

    void setAreaCircumscribingRectangle()
    {
        areaRectangle = (2 * radius);
        areaRectangle *= areaRectangle;
    }

    double getAreaCircumscribingRectangle()
    {
        return areaRectangle;
    }
    void setColors()
    {
        Color = Colors::RED;
    }
};

class Square : public Figures
{
    double length;
    double AreaSquare = 0;
    double areaRectangle = 0;

public:
    Square(double& inLength)
    {
        length = inLength;
    }

    void setAreaSquare()
    {
        AreaSquare = length * length;
    }

    double getAreaSquare()
    {
        return AreaSquare;
    }

    void setAreaCircumscribingRectangle()
    {
        areaRectangle = AreaSquare;
    }

    double getAreaCircumscribingRectangle()
    {
        return areaRectangle;
    }

    void setColors()
    {
        Color = Colors::YELLOW;
    }
};

class Triangle : public Figures
{
    double length;
    double areaTriangle = 0;
    double areaRectangle = 0;
    
public:
    Triangle(double& inLength)
    {
        length = inLength;
    }

    void setAreaTriangle()
    {       
        areaTriangle = (length * length * std::sqrt(3.f)) / 4;
    }

    double getAreaTriangle()
    {
        return areaTriangle;
    }

    void setAreaCircumscribingRectangle()
    {
        areaRectangle = length * length;
    }

    double getAreaCircumscribingRectangle()
    {
        return areaRectangle;
    }

    void setColors()
    {
        Color = Colors::WHITE;
    }
};

int main()
{
    double inLength;
    std::string command;
    std::cout << "Enter command: ";
    //std::cin >> command;
    command = "triangle";

    if (command == "circle")
    {
        std::cout << "Enter the radius of the circle: ";
        std::cin >> inLength;
       
        Circle* circle = new Circle(inLength);
        circle->setColors();
        circle->setAreaCircle();
        circle->setAreaCircumscribingRectangle();
        std::cout << "Area of a circle = " << circle->getAreaCircle() << std::endl;
        std::cout << "Area of a rectangle surrounding a circle = " << circle->getAreaCircumscribingRectangle() << std::endl;
        circle->getColors();
    }
    else if (command == "square")
    {
        std::cout << "Enter the side length of the square: ";
        std::cin >> inLength;

        Square* square = new Square(inLength);
        square->setColors();
        square->setAreaSquare();
        square->setAreaCircumscribingRectangle();
        std::cout << "Area of a square = " << square->getAreaSquare() << std::endl;
        std::cout << "Area of a rectangle surrounding a circle = " << square->getAreaCircumscribingRectangle() << std::endl;
        square->getColors();
    }
    else if (command == "triangle")
    {
        std::cout << "Enter the edge length of the equilateral triangle: ";
        std::cin >> inLength;

        Triangle* triangle = new Triangle(inLength);
        triangle->setColors();
        triangle->setAreaTriangle();
        triangle->setAreaCircumscribingRectangle();
        std::cout << "Area of a square = " << triangle->getAreaTriangle() << std::endl;
        std::cout << "Area of a rectangle surrounding a circle = " << triangle->getAreaCircumscribingRectangle() << std::endl;
        triangle->getColors();
    }
    else if (command == "rectangle")
    {
        std::cout << "rectangle" << std::endl;
    }

    return 0;
}