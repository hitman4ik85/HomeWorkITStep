#pragma once
#include <string>
#include <iostream>

class Block
{
private:
    std::string name;
    std::string color;
    int height;
    int width;
    float cost;

public:
    Block();

    Block(const std::string& name, const std::string& color, int height, int width, float cost);

    void showInfo() const;

    void setBlockParameters(const std::string& name, const std::string& color, int height, int width, float cost);

    int KilkistBloñkiv(int wallHeight, int wallWidth) const;

    float VartistStinu(int wallHeight, int wallWidth) const;

    std::string getName() const;
    void setName(const std::string& name);
    std::string getColor() const;
    void setColor(const std::string& color);
    int getHeight() const;
    void setHeight(int height);
    int getWidth() const;
    void setWidth(int width);
    float getCost() const;
    void setCost(float cost);
};