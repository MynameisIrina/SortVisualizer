#include "BubbleSort.h"
#include <iostream>
#include <cstdlib>

void BubbleSort::sort(std::vector<int> &array, sf::RenderWindow &window, bool &sorted)
{
    bool swapped;

    for (int i = 0; i < array.size(); i++)
    {
        swapped = false;
        for (int j = 0; j < array.size() - i - 1; j++)
        {
            if (!sorted)
            {

                sf::RectangleShape bar1(sf::Vector2f(10, array[j]));
                bar1.setOutlineThickness(2);
                bar1.setOutlineColor(sf::Color::Red);
                bar1.setPosition(j * 15, 600 - array[j]);
                bar1.setFillColor(sf::Color::White);
                window.draw(bar1);

                sf::RectangleShape bar2(sf::Vector2f(10, array[j + 1]));
                bar2.setOutlineThickness(2);
                bar2.setOutlineColor(sf::Color::Red);
                bar2.setPosition((j + 1) * 15, 600 - array[j + 1]);
                bar2.setFillColor(sf::Color::White);
                window.draw(bar2);

                window.display();
                sf::sleep(sf::milliseconds(10));

                if (array[j + 1] < array[j])
                {
                    swapped = true;
                    swap(j, j + 1, array);
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

        if (!swapped)
            break;
    }
}

void BubbleSort::swap(int index1, int index2, std::vector<int> &array)
{
    int tmp = array[index2];
    array[index2] = array[index1];
    array[index1] = tmp;
}
