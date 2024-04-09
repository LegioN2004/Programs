// roots of a quadratic equation using switch case statements
// doesn't work as intended and is not supposed to be using switch case statements as well
#include <stdio.h>
#include <math.h>

int main()
{
    float a = 0, b = 0, c = 0, root1, root2;
    printf("Enter the coefficients a, b, and c: ");
    scanf("%f%f%f", &a, &b, &c);
    float d = b * b - 4 * a * c;
    switch (d > 0 && a != 0)
    {
    case 1:
        root1 = (-b + sqrt(d)) / (2 * a);
        root2 = (-b - sqrt(d)) / (2 * a);
        printf("The roots are %.2f, %.2f\n", root1, root2);
        break;
    case 0:
        switch (d == 0 && a != 0)
        {
        case 1:
            root1 = -b / (2 * a);
            printf("The roots are %.2f, %.2f\n", root1, root1);
            break;
        case 0:
            switch (a != 0)
            {
            case 1:
                float realPart = -b / (2 * a);
                float imaginaryPart = sqrt(fabs(d)) / (2 * a);
                printf("The roots are %.2f + %.2fi, %.2f - %.2fi\n", realPart,
                       imaginaryPart, realPart, imaginaryPart);
                break;
            case 0:
                switch (a == 0 && b != 0)
                {
                case 1:
                    printf("It's a linear equation. The root is %.2f\n", -c / b);
                    break;
                case 0:
                    printf("It's a constant equation. No roots.\n");
                    break;
                }
            }
        }
    }
    return 0;
}