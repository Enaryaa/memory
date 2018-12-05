    #include<stdio.h>
    #include<stdlib.h>
    #include<graph.h>
    #include<math.h>

    #define CYCLE 100000L


    void timer(void)
    {
    	
    	unsigned long Microsecondes(), temps;
    	char buf[100];
    	int seconde;
  		int go_on == 0;

		InitialiserGraphique();   /*créer la fenetre */
		CreerFenetre(200,190,1280,720);

    	temps = Microsecondes() + CYCLE;

    	while (go_on = 0)
    	{
  
    		if (Microsecondes()>temps){
    			seconde++; 
    			temps = (Microsecondes()+CYCLE);
    			snprintf(buf,100,"temps : %d",seconde);
    		}
    	}

    }
/*-CYCLE)*pow(10,-6));*/