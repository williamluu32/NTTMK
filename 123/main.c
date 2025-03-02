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

int get_min_pos(int **pp_arr, int n)
{
    if (pp_arr == NULL || *pp_arr == NULL || n <= 0)
        return -1;

    int min = INT_MAX;
    int min_pos = -1;

    for (int i = 0; i < n; i++)
    {
        int current_val = *(*pp_arr + i);
        if (current_val < min)
        {
            min = current_val;
            min_pos = i;
        }
    }

    return min_pos;
}

int main()
{
    int *arr = NULL;
    int n = 0;

    input_array(&arr, &n);
    output_array(&arr, n);

    int min_pos = get_min_pos(&arr, n);
    printf("\nMin pos: %d", min_pos);

    if (arr)
    {
        free(arr);
        arr = NULL;
    }

    return 0;
}