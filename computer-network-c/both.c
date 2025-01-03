#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 200

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
    char generator_crc12[30] = "1100000001011";     // CRC-12 generator polynomial 13 bits 
    char generator_crc16[30] = "11000000000000101"; // CRC-16 generator polynomial 17 bits
    char transmitted_data[MAX_LEN], received_data[MAX_LEN], crc[MAX_LEN] = "";
    int crc_choice;

    // Select CRC version
    printf("Select CRC version (12 or 16): ");
    scanf("%d", &crc_choice);

    const char *generator;
    int zero_padding;

    if (crc_choice == 12)
    {
        generator = generator_crc12;
        zero_padding = 12;
    }
    else if (crc_choice == 16)
    {
        generator = generator_crc16;
        zero_padding = 16;
    }
    else
    {
        printf("Invalid choice. Please select 12 or 16.\n");
        return 1;
    }

    // Input transmitted data
    printf("Enter transmitted data: ");
    scanf("%s", transmitted_data);

    // Prepare data by appending zeros for CRC calculation
    char padded_data[MAX_LEN];
    strcpy(padded_data, transmitted_data);
    for (int i = 0; i < zero_padding; i++)
    {
        strcat(padded_data, "0");
    }

    // Calculate CRC
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
