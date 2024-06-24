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
    // ��ȡ��״����
    AbstractFactory* shapeFactory = FactoryProducer::getFactory("Shape");

    // ��ȡ��״Ϊ Circle �Ķ���
    Shape* shape1 = shapeFactory->getShape("CIRCLE");
    // ���� Circle �� draw ����
    if (shape1) shape1->draw();
    else cout << "Shape not found: CIRCLE" << endl;

    // ��ȡ��״Ϊ Rectangle �Ķ���
    Shape* shape2 = shapeFactory->getShape("RECTANGLE");
    // ���� Rectangle �� draw ����
    if (shape2) shape2->draw();
    else cout << "Shape not found: RECTANGLE" << endl;

    // ��ȡ��״Ϊ Square �Ķ���
    Shape* shape3 = shapeFactory->getShape("SQUARE");
    // ���� Square �� draw ����
    if (shape3) shape3->draw();
    else cout << "Shape not found: SQUARE" << endl;

    // ��ȡ��ɫ����
    AbstractFactory* colorFactory = FactoryProducer::getFactory("Color");

    // ��ȡ��ɫΪ Red �Ķ���
    Color* color1 = colorFactory->getColor("Red");
    // ���� Red �� fill ����
    if (color1) color1->fill();
    else cout << "Color not found: Red" << endl;

    // ��ȡ��ɫΪ Green �Ķ���
    Color* color2 = colorFactory->getColor("Green");
    // ���� Green �� fill ����
    if (color2) color2->fill();
    else cout << "Color not found: Green" << endl;

    // ��ȡ��ɫΪ Blue �Ķ���
    Color* color3 = colorFactory->getColor("Blue");
    // ���� Blue �� fill ����
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