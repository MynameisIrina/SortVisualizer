#include <SFML/Graphics.hpp>
#include <vector>
#include "BubbleSort.h"
#include "InsertionSort.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sorting Visualizer");

    std::vector<int> data;
    int numberOfBars = 50;
    bool sorted = false;

    for (int i = 0; i < numberOfBars; i++)
    {
        data.push_back(rand() % 600);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //BubbleSort::sort(data, window, sorted);
        InsertionSort::sort(data, window, sorted);

        sorted = true;
        window.display();
    }

    return 0;
}
