#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "Header.h"

float area_triangle(float a)
{
    return (sqrt(3.0) / 4.0) * a * a;
}

float print_definition(float a)
{
    setlocale(LC_ALL, "RUS");
    printf("Равносторонний треугольник — это треугольник, у которого все три стороны равны, а все углы равны 60 градусам.\n");
    printf("Параметры вашей фигуры:\n");
    printf("Сторона A = %.2f\n", a);
    printf("Периметр  = %.2f\n", print_perimetr(a));
    printf("Площадь   = %.2f\n", area_triangle(a));
    printf("Высота    = %.2f\n", print_visota(a));
}

int draw_triangle(int a, char s)
{
    int count = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 0; j < i - 1; j++)
            printf(" ");
        for (int j = 1; j <= 2 * (a - i + 1) - 1; j++)
        {
            if (i == 1 || j == 1 || j == 2 * (a - i + 1) - 1) {
                printf("%c", s);
                count++;
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    return count;
}

float print_perimetr(float a)
{
    return (3 * a);
}

float print_visota(float a)
{
    return (sqrt(3.0) / 2.0) * a;
}

float compare_triangle(float a1, float a2)
{
    float s1 = area_triangle(a1);
    float s2 = area_triangle(a2);
    return s1 - s2;
}