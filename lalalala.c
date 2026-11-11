#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "Header.h"

int main()
{
    setlocale(LC_ALL, "RUS");

    int choice;
    int size_for_draw;
    float a, a2;
    char s;
    float diff;
    int total_count;
    do
    {
        printf("\n=============================================================\n");
        printf("                            МЕНЮ \n");
        printf("=============================================================\n");
        printf("1) Рассчитать площадь треугольника\n");
        printf("2) Вывести определение фигуры\n");
        printf("3) Нарисовать фигуру\n");
        printf("4) Вывести параметры фигуры\n");
        printf("5) Сравнить по площади с другим треугольником\n");
        printf("0) Выход\n");
        printf("-------------------------------------------------------------\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Введите длину стороны: ");
            scanf("%f", &a);
            printf("-------------------------------------------------------------\n");
            printf("Площадь треугольника: %.2f\n", area_triangle(a));
            break;

        case 2:
            printf("-------------------------------------------------------------\n");
            printf("Введите длину стороны: ");
            scanf("%f", &a);
            print_definition(a);
            break;

        case 3:
            printf("Введите сторону треугольника: ");
            scanf("%d", &size_for_draw);
            printf("Введите символ: ");
            scanf(" %c", &s);
            printf("-------------------------------------------------------------\n");
            total_count = draw_triangle(size_for_draw, s);
            printf("Напечатано %d символов\n", total_count);
            break;

        case 4:
            printf("Введите длину стороны: ");
            scanf("%f", &a);
            printf("-------------------------------------------------------------\n");
            printf("Периметр треугольника: %.2f\n", print_perimetr(a));
            printf("Высота: %.2f\n", print_visota(a));
            break;

        case 5:
            printf("Введите сторону первого треугольника: ");
            scanf("%f", &a);
            printf("Введите сторону второго треугольника: ");
            scanf("%f", &a2);
            printf("-------------------------------------------------------------\n");

            diff = compare_triangle(a, a2);
            if (diff > 0.0001) {
                printf("Первый треугольник больше второго на %.2f\n", diff);
            }
            else if (diff < -0.0001) {
                printf("Второй треугольник больше первого на %.2f\n", fabs(diff));
            }
            else {
                printf("Площади треугольников равны.\n");
            }
            break;

        case 0:
            printf("Программа завершена.\n");
            break;

        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    return 0;
}
