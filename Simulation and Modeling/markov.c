#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STATES 2

enum Weather
{
    Sunny,
    Rainy
};

double transitionMatrix[STATES][STATES] = {
    {0.9, 0.1}, // Probabilities of going from Sunny to {Sunny, Rainy}
    {0.5, 0.5}  // Probabilities of going from Rainy to {Sunny, Rainy}
};

enum Weather getNextWeather(enum Weather currentWeather)
{
    double prob = (double)rand() / RAND_MAX;
    double cumulativeProb = 0.0;
    for (int i = 0; i < STATES; i++)
    {
        cumulativeProb += transitionMatrix[currentWeather][i];
        if (prob <= cumulativeProb)
        {
            return i;
        }
    }
    return Rainy; // Default case (should not be reached)
}

int main()
{
    srand(time(NULL));            // Seed the random number generator
    enum Weather weather = Rainy; // Start with Sunny weather
    for (int i = 0; i < 5; i++)
    {
        printf("Day %d: ", i + 1);
        if (weather == Sunny)
        {
            printf("Sunny\n");
        }
        else
        {
            printf("Rainy\n");
        }
        weather = getNextWeather(weather);
    }
    return 0;
}