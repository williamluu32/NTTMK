#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

void clear_stdin_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void input_n(int *n)
{
    while (1)
    {
        printf("\nEnter n: ");
        if (scanf("%d", n) != 1)
        {
            clear_stdin_buffer();
            fprintf(stderr, "Error: Invalid input. Please enter an integer\n");
            continue;
        }
        if (*n <= 0)
        {
            fprintf(stderr, "Error: Negative input. Please enter a positive number.\n");
            continue;
        }

        break;
    }
}

void input_array(float **pp_arr, int *n)
{
    input_n(n);

    if (n > 0)
    {
        *pp_arr = (float *)malloc((*n) * sizeof(float));

        if (!(*pp_arr))
        {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }

        printf("\nInput array:\n");

        for (int i = 0; i < *n; i++)
        {
            printf("  [%d] = ", i);
            while (1)
            {
                if (scanf("%f", (*pp_arr + i)) != 1)
                {
                    clear_stdin_buffer();
                    fprintf(stderr, "Error: Invalid input. Please enter a float\n");
                    continue;
                }

                break;
            }
        }
    }
}

void output_array(float **pp_arr, int n)
{
    if (!*pp_arr || n <= 0)
    {
        fprintf(stderr, "Error\n");
        return;
    }

    printf("\n[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", *(*pp_arr + i));
    }

    printf("]\n");
}

float find_max(float **pp_arr, int n)
{
    if (!(*pp_arr) || n <= 0)
    {
        return NAN;
    }

    float max = FLT_MIN;

    for (int i = 0; i < n; i++)
    {
        float current_val = *(*pp_arr + i);
        if (current_val > max)
        {
            max = current_val;
        }
    }

    return max;
}

int main()
{
    float *arr = NULL;
    int n;

    input_array(&arr, &n);
    output_array(&arr, n);

    float max = find_max(&arr, n);

    if (isnan(max))
    {
        fprintf(stderr, "Error in find_max.\n");
    }
    else
    {
        printf("Max: %.2f\n", max);
    }

    if (arr)
    {
        free(arr);
        arr = NULL;
    }

    return EXIT_SUCCESS;
}