    #include<stdio.h>
    #include<stdlib.h>
    #include<graph.h>
    #include<math.h>

    #define CYCLE 10000L
    #define INFINI 1

    int main(int argc, char * argv[])
    {
    	unsigned long Microsecondes();
    	unsigned long suivant;
    	int temps = 0;

    	suivant = Microsecondes();

    	while (INFINI == 1)
    	{
    		if (Microsecondes() > suivant)
    		{
    			suivant = ((Microsecondes()-CYCLE)*pow(10,-6));
    			printf("%d", temps);
    			temps++;
    		}
    	}
    	return EXIT_SUCCESS;
    }
