#include <stdio.h>

// Macro for converting integer Celsius to Fahrenheit
#define INT_C_TO_F(celsius) ((celsius) * 9/5 + 32)


// Macro for converting floating-point Celsius to Fahrenheit
#define FLOAT_C_TO_F(celsius) ((celsius) * 9.0/5 + 32)

int main() {
    int intCelsius = 25;
    float floatCelsius = 25.5;

    int intFahrenheit = INT_C_TO_F(intCelsius);
    float floatFahrenheit = FLOAT_C_TO_F(floatCelsius);

    printf("%d Celsius is equal to %d Fahrenheit\n", intCelsius, intFahrenheit);
    printf("%.2f Celsius is equal to %.2f Fahrenheit\n", floatCelsius, floatFahrenheit);

    return 0;
}

