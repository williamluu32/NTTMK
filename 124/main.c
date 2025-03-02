#include <stdio.h>
#include <stdlib.h>

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

void input_array(int **pp_arr, int *n)
{
    if (!pp_arr)
    {
        fprintf(stderr, "\nError: pp_arr is NULL.");
        exit(EXIT_FAILURE);
    }

    input_n(n);

    if (n > 0)
    {
        *pp_arr = (int *)malloc((*n) * sizeof(int));

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
                if (scanf("%d", (*pp_arr + i)) != 1)
                {
                    clear_stdin_buffer();
                    fprintf(stderr, "Error: Invalid input. Please enter an integer\n");
                    continue;
                }
                break;
            }
        }
    }
}

void output_array(int **pp_arr, int n)
{
    if (!pp_arr || !*pp_arr || n <= 0)
    {
        fprintf(stderr, "Error\n");
        return;
    }

    printf("\n[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(*pp_arr + i));
    }

    printf("]\n");
}

int is_even(int num)
{
    return num % 2 == 0 ? 1 : 0;
}

int has_even_less_than_2004(int **pp_arr, int n)
{
    if (pp_arr == NULL || *pp_arr == NULL || n <= 0)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int current_val = *(*pp_arr + i);
        if (is_even(current_val) && current_val < 2004)
            return 1;
    }

    return 0;
}

int main()
{
    int *arr = NULL;
    int n = 0;
    input_array(&arr, &n);
    output_array(&arr, n);

    printf("%d", has_even_less_than_2004(&arr, n));

    if (arr != NULL)
    {
        free(arr);
        arr = NULL;
    }

    return EXIT_SUCCESS;
}