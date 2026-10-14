#include "Block.h"

Block::Block() : name("невідома"), color("невідомий"), height(0), width(0), cost(0.0f)
{
    std::cout << "Викликано конструктор без параметрів" << std::endl;
}

Block::Block(const std::string& name, const std::string& color, int height, int width, float cost)
    : name(name), color(color), height(height), width(width), cost(cost)
{
    std::cout << "Викликано конструктор з параметрами" << std::endl;
}

void Block::showInfo() const
{
    std::cout << "Назва: " << name << std::endl;
    std::cout << "Колір: " << color << std::endl;
    std::cout << "Висота: " << height << " см" << std::endl;
    std::cout << "Ширина: " << width << " см" << std::endl;
    std::cout << "Вартість: " << cost << " грн" << std::endl;
}


void Block::setBlockParameters(const std::string& name, const std::string& color, int height, int width, float cost)
{
    this->name = name;
    this->color = color;
    this->height = height;
    this->width = width;
    this->cost = cost;
}

int Block::KilkistBloсkiv(int wallHeight, int wallWidth) const
{
    int blocksInHeight = wallHeight / height + 1;
    int blocksInWidth = wallWidth / width + 1;
    return blocksInHeight * blocksInWidth;
}

float Block::VartistStinu(int wallHeight, int wallWidth) const
{
    int totalBlocks = KilkistBloсkiv(wallHeight, wallWidth);
    return totalBlocks * cost;
}

std::string Block::getName() const
{
    return name;
}

void Block::setName(const std::string& name)
{
    this->name = name;
}

std::string Block::getColor() const
{
    return color;
}

void Block::setColor(const std::string& color)
{
    this->color = color;
}

int Block::getHeight() const
{
    return height;
}

void Block::setHeight(int height)
{
    this->height = height;
}

int Block::getWidth() const
{
    return width;
}

void Block::setWidth(int width)
{
    this->width = width;
}

float Block::getCost() const
{
    return cost;
}

void Block::setCost(float cost)
{
    this->cost = cost;
}