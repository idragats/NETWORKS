#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
	int i, j,N=10000,seed=4375,ymin=1,ymax=N-1,max;
	double gamma=2,y,x;
	int*K =malloc((N)*sizeof(int));
	srand(seed);		
	FILE *Power_Low;
	FILE *DistPL;
	Power_Low=fopen("Power_Low.txt","w");
	DistPL=fopen("DistPL.txt","w");
	for (i=0; i<N; i++)  K[i]=0;
	
for (i=0; i<N; i++){
	
	x=(double)rand() / (double)((unsigned)RAND_MAX + 1);
	y=(pow(ymax,1-gamma) - pow(ymin, 1-gamma))*x + pow(ymin,1-gamma); // transpose to power law Distribution
	y=pow(y,1/(1-gamma));
	K[i]=(int)y;
	printf("%d\n",K[i]);
 	fprintf(Power_Low,"%d\t%d\n",i,K[i]);
 } 
 
 //make distribution
 max=0; 
 for (i=0; i<N; i++){
 	if(K[i]>max){
 		max=K[i];
	 }
 }
 int*Dist =malloc((max+1)*sizeof(int));
 
 for (i=0; i<max; i++){

     Dist[i]=0;
    }
 
 for (i=0; i<N; i++){
    Dist[K[i]]++;
}
for (i=0; i<max; i++){
	fprintf(DistPL,"%d\t%d\n",i,Dist[i]);
}
 
return 0;	
}
