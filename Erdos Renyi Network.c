#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000   // numper of nodes
#define M 1000   // runs  
#define p 0.16   // propabillity conection for 2 nodes
#define seed 4375

int main(){
	int*K=malloc((N)*sizeof(int)); //alocate memory
	int i, j,numEdges,Edges,runs,max;
	double rand_num;
	srand(seed);
	
	
	FILE *ERD_REN;
	FILE  *ERD_RENDist;
	
	 ERD_REN=fopen("ERD_REN.txt","w");
	 ERD_RENDist=fopen("ERD_RENDist.txt","w");  
	 
	   
	   
for (runs=0; runs<M; runs++) {
	
for(i=0; i<N; i++) K[i]=0;

    for (i=0; i<N; i++){
    	for (j=N-1; j>i; j--){
	   	     rand_num=(double)rand() / (double)((unsigned)RAND_MAX + 1);
	   	        if (rand_num<=p){
	   	              K[i]=K[i]+1;
	   	              K[j]=K[j]+1;    //calculate sum of conections   
		        }
		    
        	}
		}



 // make distribution
 max=0;
     for (i=0; i<N; i++){
	   if(K[i]>max){
	    	max=K[i];    
	    }
    }
	
int *Distribution=malloc((max+1)*sizeof(int));	
	
	
   for (i=0; i<max; i++){

     Distribution[i]=0;
    }
	
    for (i=0; i<N; i++){
    	Distribution[K[i]]++;
    		
    }	
    
    for (i=0; i<max; i++){
 	fprintf(ERD_RENDist,"%d\t%d\n",i,Distribution[i]/runs);
 }
 
}
 
// write data

for (i=0; i<N; i++){
	printf("%d\t%f\n",i,(double)K[i]/runs);
 	fprintf(ERD_REN,"%d\t%f\n",i,(double)K[i]/runs);
 }
 






return 0;	
}
