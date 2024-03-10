#include <iostream>



class Figures
{
public:
    enum Colors
    {
        NONE, WHITE, RED, BLUE, GREEN, YELLOW
    };

    Colors Color = Colors::NONE;
    std::string inColor = "none";
    double centerOfCoordinates;

    void setColors()
    {
        std::cout << "Input color figures: ";
        std::cin >> inColor;

        if (inColor == "none")
        {
            Color = Colors::NONE;
        }
        else if (inColor == "white")
        {
            Color = Colors::WHITE;
        }
        else if (inColor == "red")
        {
           Color = Colors::RED;
        }
        else if (inColor == "blue")
        {
            Color = Colors::BLUE;
        }
        else if (inColor == "green")
        {
            Color = Colors::GREEN;
        }
        else if (inColor == "yellow")
        {
            Color = Colors::YELLOW;
        }
    }
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
private:
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
};




int main()
{
    double inLength;
    std::string command;
    std::cout << "Enter command: ";
    //std::cin >> command;
    command = "circle";
    if (command == "circle")
    {
        std::cout << "Enter the radius of the circle: ";
        std::cin >> inLength;

        Circle circle(inLength);
        circle.setColors();
        circle.setAreaCircle();
        circle.setAreaCircumscribingRectangle();
        std::cout << "Area of a circle = " << circle.getAreaCircle() << std::endl;
        std::cout << "Area of a rectangle surrounding a circle = " << circle.getAreaCircumscribingRectangle() << std::endl;       
        circle.getColors();
    }
    else if (command == "square")
    {
        std::cout << "square" << std::endl;
    }
    else if (command == "triangle")
    {
        std::cout << "triangle" << std::endl;
    }
    else if (command == "rectangle")
    {
        std::cout << "rectangle" << std::endl;
    }

    return 0;
}