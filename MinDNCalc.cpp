#include <math.h>
#include <stdio.h>


int main()

{

    int MinDN16, Swamp, Userswamp, Bits;
    float ReadNoise, Gain, BiasOffset;
    char FactorOpt;


    /* Obtain camera details from the user for the purposes of calculating the Minimum DN */

    printf("Enter your Read Noise (Whole or Floating Point): ");
    scanf_s("%f", &ReadNoise);
    printf("Enter your Gain in e-/ADU (Whole or Floating Point): ");
    scanf_s("%f", &Gain);
    printf("Enter your Bias Offset in ADU (Whole or Floating Point): ");
    scanf_s("%f", &BiasOffset);
    printf("Enter the Bit Depth of the Camera (Whole Numbers Only): ");
    scanf_s("%i", &Bits);

    /* Determine how the user wants to handle Swamping Factor */

    printf("Would you like to use the 3xRN^2 Rule for Swamping Factor? (y/n): ");
    scanf_s("%s", &FactorOpt, 1);

    if (FactorOpt == 'y' || FactorOpt == 'Y')
    {
        Swamp = pow(ReadNoise, 2) * 3;
    }
    else
    {
        printf("Would you like to use the default Swamping Factor of 20x? (y/n): ");
        scanf_s("%s", &FactorOpt, 1);
        if (FactorOpt == 'y' || FactorOpt == 'Y')
        {
            Swamp = pow(ReadNoise, 2) * 20;
        }

        else
        {
            printf("Please enter your Swamping Factor (Whole Numbers Only): ");
            scanf_s("%i", &Userswamp);
            Swamp = pow(ReadNoise, 2) * Userswamp;
        }
    }

    /* Calculate the Minimum DN and return it to the user */

    MinDN16 = ((Swamp / Gain) + BiasOffset) * pow(2, 16) / pow(2, Bits);
    printf("\n");
    printf("Minimum Exposure in 16-bit ADU: %i Median ADU\n", MinDN16);
    printf("\n");
    printf("Press the Enter key to close this application.\n");
    printf("\n");
}
