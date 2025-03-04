#include "InsertionSort.h"
#include <iostream>

void InsertionSort::sort(std::vector<int> &array, sf::RenderWindow &window, bool &sorted)
{
    for (int i = 1; i < array.size(); i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (!sorted)
            {

                sf::RectangleShape bar1(sf::Vector2f(10, array[j]));
                bar1.setOutlineThickness(2);
                bar1.setOutlineColor(sf::Color::Red);
                bar1.setPosition(j * 15, 600 - array[j]);
                bar1.setFillColor(sf::Color::White);
                window.draw(bar1);

                sf::RectangleShape bar2(sf::Vector2f(10, array[j - 1]));
                bar2.setOutlineThickness(2);
                bar2.setOutlineColor(sf::Color::Red);
                bar2.setPosition((j - 1) * 15, 600 - array[j - 1]);
                bar2.setFillColor(sf::Color::White);
                window.draw(bar2);

                window.display();
                sf::sleep(sf::milliseconds(10));

                if (array[j - 1] > array[j])
                {
                    //swapped = true;
                    swap(j - 1, j, array);
                }
            }

            window.clear(sf::Color::Black);
            for (int i = 0; i < array.size(); i++)
            {
                sf::RectangleShape bar(sf::Vector2f(10, array[i]));
                bar.setOutlineThickness(2);
                bar.setOutlineColor(sf::Color::Green);
                bar.setPosition(i * 15, 600 - array[i]);
                bar.setFillColor(sf::Color::White);
                window.draw(bar);
            }
        }
    }
}

void InsertionSort::swap(int index1, int index2, std::vector<int> &array)
{
    int tmp = array[index2];
    array[index2] = array[index1];
    array[index1] = tmp;
}
