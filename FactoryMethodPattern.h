#pragma once

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

class ShapeFactory {
public:
    Shape* getShape(const string& shapeType) {
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
};