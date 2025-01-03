#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ONE "1"

// Function declarations
const char *binary_division(const char *, const char *, int *);
const char *binary_subtraction(const char *, const char *);

int main()
{
    const char *crc_remainder, *final_remainder;
    char generator[30] = "1100000001011", td[30], padded_transmitted_data[30], crc[30] = "", rd[30];
    int zero_padding_index = 0, is_data_correct = 0;

    // Input data
    printf("Enter transmitted data: ");
    scanf("%s", td);
    printf("Enter received data: ");
    scanf("%s", rd);

    // Prepare the transmitted data by appending zeros for CRC calculation
    strcpy(padded_transmitted_data, td);
    strcat(td, "000000000000");
    printf("\n%s ) %s (", generator, td);

    // Perform CRC division on transmitted data
    crc_remainder = binary_division(td, generator, &is_data_correct);
    if (!crc_remainder)
    {
        printf("\nError: Memory allocation failed in binary_division.");
        return 1;
    }

    // Add leading zeros to CRC remainder if necessary
    if (strlen(crc_remainder) < 12)
    {
        for (int i = strlen(crc_remainder); i < 12; i++)
        {
            crc[zero_padding_index++] = '0';
        }
        crc[zero_padding_index] = '\0';
    }
    strcat(crc, crc_remainder);
    strcat(padded_transmitted_data, crc);
    printf("\n         ------------------");
    printf("\nCRC is         %s", crc);

    // Perform CRC division on received data
    strcat(rd, crc);
    printf("\n\n%s ) %s (", generator, rd);

    final_remainder = binary_division(rd, generator, &is_data_correct);
    if (!final_remainder)
    {
        printf("\nError: Memory allocation failed in binary_division.");
        free((void *)crc_remainder);
        return 1;
    }

    printf("\n %s", final_remainder);
    printf("\n -----------------");

    // Check if the data was transferred correctly
    if (is_data_correct == 1)
        printf("\nData transferred correctly");
    else
        printf("\nData transferred incorrectly");

    // Free allocated memory
    free((void *)crc_remainder);
    free((void *)final_remainder);

    return 0;
}

const char *binary_division(const char *data, const char *generator, int *is_data_correct)
{
    int i, j, buffer_index = 0, first_one_index, division_window_size = 13, generator_index, result_index = 0;
    char *buffer = malloc(30 * sizeof(char));
    if (!buffer)
        return NULL;    // Handle memory allocation failure
    strcpy(buffer, ""); // Initialize

    char quotient[15] = "";
    const char *subtraction_result;

    for (i = 0; i < strlen(data); i++)
    {
        if ((i + division_window_size) > strlen(data))
            division_window_size = (i + division_window_size) - strlen(data) + 1;

        for (j = i; j < (i + division_window_size); j++)
            buffer[buffer_index++] = data[j];
        buffer[buffer_index] = '\0';

        if (strlen(buffer) == 12)
            break;

        printf("\n %s", generator);
        printf("\n -----------------");

        subtraction_result = binary_subtraction(buffer, generator);
        if (!subtraction_result)
        {
            free(buffer);
            return NULL;
        }

        buffer_index = 0;
        i = j - 1;

        for (first_one_index = 0; first_one_index < strlen(subtraction_result); first_one_index++)
            if (subtraction_result[first_one_index] == ONE)
                break;

        if (first_one_index == strlen(subtraction_result))
        {
            *is_data_correct = 1; // Update correctness flag
            free((void *)subtraction_result);
            return buffer;
        }

        for (generator_index = first_one_index; generator_index < strlen(subtraction_result); generator_index++)
            quotient[result_index++] = subtraction_result[generator_index];
        quotient[result_index] = '\0';

        division_window_size = 13 - strlen(quotient);
        strcpy(buffer, quotient);
        buffer_index = strlen(quotient);
        result_index = 0;

        free((void *)subtraction_result);
    }

    return buffer;
}

const char *binary_subtraction(const char *dividend, const char *divisor)
{
    char *result = malloc(15 * sizeof(char));
    if (!result)
        return NULL;    // Handle memory allocation failure
    strcpy(result, ""); // Initialize

    char one[2] = "1", zero[2] = "0";

    for (int i = 0; i < strlen(dividend); i++)
    {
        int both_ones = (dividend[i] == '1') && (divisor[i] == '1');
        int both_zeros = (dividend[i] == '0') && (divisor[i] == '0');

        if (both_ones || both_zeros)
            strcat(result, zero);
        else
            strcat(result, one);
    }

    return result;
}
