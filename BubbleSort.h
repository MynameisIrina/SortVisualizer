#pragma once
#include <SFML/Graphics.hpp>
#include <vector>


class BubbleSort
{
public:
    static void sort(std::vector<int>& array, sf::RenderWindow& window, bool& sorted);
    static void swap(int index1, int index2, std::vector<int>& array);
};