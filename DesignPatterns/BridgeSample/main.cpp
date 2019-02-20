#include <iostream>
#include "AllShapes.h"
#include "AllColors.h"


using namespace std;


int main()
{
    /// Try create enum classes Colors{Red,Green, ... }
    OwnColor _color(23,234,232);
    RectangleShape rectangle;
    rectangle.SetColor(new RedColor);
    cout << "=================================\n";
    rectangle.Draw();
    cout << "=================================\n";
    rectangle.SetColor(&_color);
    rectangle.Draw();
    cout << "=================================\n";
    CircleShape circle;
    circle.SetColor(new GreenColor);
    cout << "=================================\n";
    circle.Draw();
    cout << "=================================\n";
    Color *color = circle.GetColor(); /// Taking color of Shape*
    color->Paint(); /// Override method of class color. Writes Color of shape
    cout << "=================================\n";
    ///
    return 0;
}
