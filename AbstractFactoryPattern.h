/*
* ���󹤳�ģʽ
* ���������Ĺ���
*/
#ifndef DesignPattern_AbstractFactoryPattern
#define DesignPattern_AbstractFactoryPattern
#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // pure virtual function
    virtual ~Shape() {} // virtual destructor
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Shape: Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Shape: Rectangle" << endl;
    }
};

class Triangle : public Shape {
public:
    void draw() override {
        cout << "Shape: Triangle" << endl;
    }
};

class Color {
public:
    virtual void fill() = 0; // pure virtual function
    virtual ~Color() {} // virtual destructor
};

class Red : public Color {
public:
    void fill() override {
        cout << "Inside Red::fill() method" << endl;
    }
};

class Blue : public Color {
public:
    void fill() override {
        cout << "Inside Blue::fill() method" << endl;
    }
};

class Green : public Color {
public:
    void fill() override {
        cout << "Inside Green::fill() method" << endl;
    }
};

class AbstractFactory {
public:
    virtual Shape* getShape(const string& shapeType) = 0;
    virtual Color* getColor(const string& colorType) = 0;
    virtual ~AbstractFactory() {} // virtual destructor
};

class ShapeFactory : public AbstractFactory {
public:
    Shape* getShape(const string& shapeType) override {
        if (shapeType == "CIRCLE") {
            return new Circle();
        }
        else if (shapeType == "RECTANGLE") {
            return new Rectangle();
        }
        else if (shapeType == "TRIANGLE") {
            return new Triangle();
        }
        return nullptr;
    }

    Color* getColor(const string& colorType) override {
        return nullptr; // ShapeFactory doesn't produce colors
    }
};

class ColorFactory : public AbstractFactory {
public:
    Color* getColor(const string& colorType) override {
        if (colorType == "Red") {
            return new Red();
        }
        else if (colorType == "Blue") {
            return new Blue();
        }
        else if (colorType == "Green") {
            return new Green();
        }
        return nullptr;
    }

    Shape* getShape(const string& shapeType) override {
        return nullptr; // ColorFactory doesn't produce shapes
    }
};

class FactoryProducer {
public:
    static AbstractFactory* getFactory(const string& choice) {
        if (choice == "Color") {
            return new ColorFactory();
        }
        else if (choice == "Shape") {
            return new ShapeFactory();
        }
        return nullptr;
    }
};

class AbstractFactoryPatternDemo {
public:
    static void demo() {
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
};
#endif // !DesignPattern_AbstractFactoryPattern
