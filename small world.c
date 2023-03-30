#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000   // numper of nodes 
#define p 0.20   // propabillity conection for 2 nodes
#define seed 4375

int main(){
	int i,j,k=14000,left,right,rightnet,leftnet,find;
	int (*K)[N] = malloc(sizeof(int[N][N]));
	int*Edges=malloc((N)*sizeof(int));
	int step,newnode;
	double rand_num;
	srand(seed);
	
	
	FILE *SMALL_WORLD;
	FILE *SMALL_WORLDDelta;
	
	 SMALL_WORLD=fopen("SMALL_WORLD.txt","w");
	 SMALL_WORLDDelta=fopen("SMALL_WORLDDelta.txt","w");  
	   
	// initiallaization arrays   
	for (i=0; i<N; i++) Edges[i]=0;   
	   
	for (i=0; i<N; i++){
			for (j=0; j<N; j++){
				K[i][j]=0;
		}
    }
    
    //make graph first try
    
/*	   
	for (i=0; i<N; i++){
		left=(k/2);    //num nodes to conect left
		right=k-left;   //num nodes to conect right
			
		for (j=1; j<=right; j++){
			rightnet=(i+j)%N;
			K[i][rightnet]=1;
			K[rightnet][i]=1;
			Edges[i]+=1;
        }
        for (j=1; j<=left; j++){
			leftnet=(i+j)%N;
			K[i][leftnet]=1;
			K[leftnet][i]=1;
			Edges[i]+=1;
        }
				
		
}*/

// make graph  second try

  for (i=0;i<N-1;i++){
      for (j=i+1;j<N;j++){
      	  left=i+k/N/2;
      	  right=i+N-k/N/2;
	        if (j<=left)  {
	         K[i][j]=1;
	         K[j][i]=1;
	        Edges[i]+=1;
	        Edges[j]+=1;
	     }
	    else if (j>=right){
	      K[i][j]=1;
	      K[j][i]=1;
	      Edges[i]+=1;
	      Edges[j]+=1;
	    }
	}
}
// write data to show delta function
 for (i=0; i<N; i++){
 	fprintf(SMALL_WORLDDelta,"%d\t%d\n",i,Edges[i]);
 }




// change a new random node  to cannect in network 
		
for (i=0; i<N-1; i++ ){
   for (j=i+1; j<N; j++){
	   if (K[i][j]==1){
			rand_num=(double)rand() / (double)((unsigned)RAND_MAX + 1);
	    	if(rand_num<=p){
	    		find=0;
	    		while (find==0){
	    			newnode=0+rand()%(0-N);
	    			if (newnode!=i && newnode!=j){
	    				find=1;
					}
				} 
				
			
            K[i][j]=0;
            K[j][i]=0;
            Edges[j]-=1;
            K[i][newnode]=1;
            K[newnode][i]=1;
            Edges[newnode]+=1;
            
        }
     }
   }
}
    



for (i=0; i<N; i++){
	printf("%d\t%d\n",i,Edges[i]);
 	fprintf(SMALL_WORLD,"%d\t%d\n",i,Edges[i]);
 }
 


return 0;	
}
