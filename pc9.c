#include<stdio.h>
#include<math.h>
#include<float.h>

#define DELTA_X_BORDER	0.05
#define DELTA_Y_BORDER	0.065

#define DELTA_X_STRIPE	0.065
#define DELTA_Y_STRIPE	0.006

void main(void){
	
	double t;

	printf("\\documentclass{jarticle}\n");
	printf("\\usepackage{epic,eepic} \n");
	printf("\\begin{document}\n");
	printf("\\begin{figure}[htbp]\n");
	printf("\\begin{center}\n");
	printf("\\setlength{\\unitlength}{10mm}\n");
	printf("\\begin{picture}(5,3)\n");

	/*********************************/
	/* 座標軸                        */
	/*********************************/

	printf("\t\\thicklines\\put\(-1,0\){\\vector(1,0){6}}\n");
	printf("\t\\thicklines\\put\(0,-1\){\\vector(0,1){6}}\n");

	/***********************************/
  /* 放物線　　　　　　　　　　　　　*/
	/***********************************/
	for(t=0.0;t<4.5;t=t+DELTA_X_BORDER){
		printf("\t\\path\(%lf,%lf\)\(%lf,%lf\)\n",t,t*t/4,t+DELTA_X_BORDER,(t+DELTA_X_BORDER)*(t+DELTA_X_BORDER)/4);
	}

	printf("\t\n");	
	for(t=0.0;t<20;t=t+DELTA_X_BORDER){
		printf("\t\\path\(%lf,%lf\)\(%lf,%lf\)\n",t/4,sqrt(t),(t+DELTA_X_BORDER)/4,sqrt(t+DELTA_X_BORDER));
	}

	printf("\t\n");
	for(t=0.1;t<4;t=t+0.2){
		printf("\t\\path\(%lf,4)\(%f,4\)\n",t,t+0.1);
	}

	printf("\t\n");
	for(t=0.1;t<4;t=t+0.2){
		printf("\t\\path\(4,%lf)\(4,%lf\)\n",t,t+0.1);
	}

	printf("\\end{picture}\n");
	printf("\\end{center}\n");
	printf("\\end{figure}\n");
	printf("\\end{document}\n");
}
