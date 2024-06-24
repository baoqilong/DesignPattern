//#include "FactoryMethodPattern.h"
#include "AbstractFactoryPattern.h"
#include <iostream>
void main() {
    //ShapeFactory* shapeFactory = new ShapeFactory();
    //// Create a Circle and draw it
    //Shape* shape1 = shapeFactory->getShape("CIRCLE");
    //if (shape1 != nullptr) {
    //    shape1->draw();
    //    delete shape1; // clean up
    //}

    //// Create a Rectangle and draw it
    //Shape* shape2 = shapeFactory->getShape("RECTANGLE");
    //if (shape2 != nullptr) {
    //    shape2->draw();
    //    delete shape2; // clean up
    //}

    //// Create a Triangle and draw it
    //Shape* shape3 = shapeFactory->getShape("TRIANGLE");
    //if (shape3 != nullptr) {
    //    shape3->draw();
    //    delete shape3; // clean up
    //}
    // 获取形状工厂
    AbstractFactory* shapeFactory = FactoryProducer::getFactory("Shape");

    // 获取形状为 Circle 的对象
    Shape* shape1 = shapeFactory->getShape("CIRCLE");
    // 调用 Circle 的 draw 方法
    if (shape1) shape1->draw();
    else cout << "Shape not found: CIRCLE" << endl;

    // 获取形状为 Rectangle 的对象
    Shape* shape2 = shapeFactory->getShape("RECTANGLE");
    // 调用 Rectangle 的 draw 方法
    if (shape2) shape2->draw();
    else cout << "Shape not found: RECTANGLE" << endl;

    // 获取形状为 Square 的对象
    Shape* shape3 = shapeFactory->getShape("SQUARE");
    // 调用 Square 的 draw 方法
    if (shape3) shape3->draw();
    else cout << "Shape not found: SQUARE" << endl;

    // 获取颜色工厂
    AbstractFactory* colorFactory = FactoryProducer::getFactory("Color");

    // 获取颜色为 Red 的对象
    Color* color1 = colorFactory->getColor("Red");
    // 调用 Red 的 fill 方法
    if (color1) color1->fill();
    else cout << "Color not found: Red" << endl;

    // 获取颜色为 Green 的对象
    Color* color2 = colorFactory->getColor("Green");
    // 调用 Green 的 fill 方法
    if (color2) color2->fill();
    else cout << "Color not found: Green" << endl;

    // 获取颜色为 Blue 的对象
    Color* color3 = colorFactory->getColor("Blue");
    // 调用 Blue 的 fill 方法
    if (color3) color3->fill();
    else cout << "Color not found: Blue" << endl;

    // Clean up
    delete shape1;
    delete shape2;
    delete shape3;
    delete color1;
    delete color2;
    delete color3;
    delete shapeFactory;
    delete colorFactory;
}