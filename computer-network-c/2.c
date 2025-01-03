#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void xor_operation(char *remainder, const char *divisor, int divisor_len)
{
    for (int i = 0; i < divisor_len; i++)
    {
        remainder[i] = (remainder[i] == divisor[i]) ? '0' : '1';
    }
}

void calculate_crc(const char *data, const char *generator, char *crc)
{
    int data_len = strlen(data);
    int generator_len = strlen(generator);
    char remainder[MAX_LEN];

    strncpy(remainder, data, generator_len - 1);
    remainder[generator_len - 1] = '\0';

    for (int i = generator_len - 1; i < data_len; i++)
    {
        remainder[generator_len - 1] = data[i];
        if (remainder[0] == '1')
        {
            xor_operation(remainder, generator, generator_len);
        }
        memmove(remainder, remainder + 1, generator_len - 1);
    }
    strcpy(crc, remainder);
}

int check_crc(const char *data_with_crc, const char *generator)
{
    int data_len = strlen(data_with_crc);
    int generator_len = strlen(generator);
    char remainder[MAX_LEN];

    strncpy(remainder, data_with_crc, generator_len - 1);
    remainder[generator_len - 1] = '\0';

    for (int i = generator_len - 1; i < data_len; i++)
    {
        remainder[generator_len - 1] = data_with_crc[i];
        if (remainder[0] == '1')
        {
            xor_operation(remainder, generator, generator_len);
        }
        memmove(remainder, remainder + 1, generator_len - 1);
    }

    for (int i = 0; i < generator_len - 1; i++)
    {
        if (remainder[i] != '0')
        {
            return 0; // Data is incorrect
        }
    }
    return 1; // Data is correct
}

int main()
{
    char generator[30] = "1100000001011";
    char transmitted_data[MAX_LEN], received_data[MAX_LEN], crc[30] = "";

    // Input data
    printf("Enter transmitted data: ");
    scanf("%s", transmitted_data);

    // Calculate CRC for transmitted data
    char padded_data[MAX_LEN];
    strcpy(padded_data, transmitted_data);
    strcat(padded_data, "000000000000"); // Append zeros
    calculate_crc(padded_data, generator, crc);

    // Append CRC to transmitted data
    strcat(transmitted_data, crc);
    printf("\nTransmitted data with CRC: %s\n", transmitted_data);

    // Input received data
    printf("Enter received data: ");
    scanf("%s", received_data);

    // Check received data
    if (check_crc(received_data, generator))
    {
        printf("Data transferred correctly.\n");
    }
    else
    {
        printf("Data transferred incorrectly.\n");
    }

    return 0;
}
