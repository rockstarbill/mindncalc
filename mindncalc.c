#include <math.h>
#include <stdio.h>


int main()

{

int MinDN16, Swamp, Bits; 
float ReadNoise, Gain, BiasOffset;
char FactorOpt;


        /* Give credit to Jon for the formula and educate the user to be careful about input, since there is no error handling yet */
        
        printf("\n");
        printf("This calculation is borrowed from Jon Rista, from the Cloudy Nights Forum.\n");
        printf("Please ensure you only enter accurate responses, as this simple application does not handle errors yet.\n");
        printf("You can use the BasicCCDParameters script in Pixinsight to obtain the data used as input for this application.\n");
        printf("If you understand this, press Enter to continue otherwise use CTRL + C to abort!\n");
        getchar();
 
        /* Obtain camera details from the user for the purposes of calculating the Minimum DN */
        
	printf("Enter your Read Noise (Whole or Floating Point): ");
	scanf("%f", &ReadNoise);
        printf("Enter your Gain in e-/ADU (Whole or Floating Point): ");
	scanf("%f", &Gain);
	printf("Enter your Bias Offset in ADU (Whole or Floating Point): " );
	scanf("%f", &BiasOffset);
 	printf("Enter the Bit Depth of the Camera (Whole Numbers Only): ");
	scanf("%i", &Bits);
        
        /* Determine how the user wants to handle Swamping Factor */
        
        printf("Would you like to use the 3xRN^2 Rule for Swamping Factor? (y/n): ");
        scanf("%s", &FactorOpt);
        
        if (FactorOpt == 'y' || FactorOpt == 'Y')
        {
            Swamp = pow(ReadNoise, 2) * 3; 
            ReadNoise = 1; /* This is here to remove the ReadNoise term from the MinDN16 calculation that happens later, since it is already accounted for via the 3xRN^2 Rule */ 
        }
        else
        {
            printf("Would you like to use the default Swamping Factor of 20x? (y/n): ");
            scanf("%s", &FactorOpt);
                if (FactorOpt == 'y' || FactorOpt == 'Y')
                {
                    Swamp = 20;
                }   
                
                else
                {
                    printf("Please enter your Swamping Factor (Whole Numbers Only): ");
                    scanf("%i", &Swamp);
                }
        }

	/* Calculate the Minimum DN and return it to the user */

	MinDN16 = (((ReadNoise * Swamp) / Gain) + BiasOffset) * pow(2, 16) / pow(2, Bits);
        printf("\n");
	printf("Minimum DN in 16-bit background sky is: %i Median ADU\n", MinDN16);
        printf("\n");
        printf("Press the Enter key to close this application. May The Force Be With You...\n");
        printf("\n");
        
        /* Double getchar() to allow the input buffer to not be skipped due to scanf usage and \n carriage return  */
    
        getchar();
        getchar();
}
