#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }

    // Open output file
    FILE *output_file = NULL;

    // Create buffer
    uint8_t buffer[512];

    // Define the counter
    int jpeg_counter = 0;

    // Create JPEG file array
    char jpeg_file[8];

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // If start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {

            if (output_file != NULL)
            {
                fclose(output_file);
            }

            sprintf(jpeg_file, "%03i.jpg", jpeg_counter);
            output_file = fopen(jpeg_file, "w");
            if (output_file == NULL)
            {
                printf("Could not create.\n");
                return 3;
            }
            jpeg_counter++;

            fwrite(buffer, 1, 512, output_file);
        }
        else if (output_file != NULL)
        {
            fwrite(buffer, 1, 512, output_file);
        }
    }

    // Close any remaining files
    if (output_file != NULL)
    {
        fclose(output_file);
    }
    fclose(card);

    return 0;
}
