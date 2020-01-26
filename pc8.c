#include<stdio.h>
#include<math.h>
#include<float.h>

#define DELTA_X_BORDER	0.001
#define DELTA_Y_BORDER	0.065

#define DELTA_X_STRIPE	0.065
#define DELTA_Y_STRIPE	0.006

void main(void){
	
	double t,x,y,
			x_start=DBL_MAX,
			y_start=DBL_MAX,
			x_end=DBL_MAX,
			y_end=DBL_MAX;
	
	printf("\\documentclass{jarticle}\n");
	printf("\\usepackage{epic,eepic} \n");
	printf("\\begin{document}\n");
	printf("\\begin{figure}[htbp]\n");
	printf("\\begin{center}\n");
	printf("\\setlength{\\unitlength}{10mm}\n");
	printf("\\begin{picture}(5,3)\n");

	/*********************************/
	/* ç¿ïWé≤                        */
	/*********************************/

	printf("\t\\thicklines\\put\(-1,0\){\\vector(1,0){8}}\n");
	printf("\t\\thicklines\\put\(0,-1\){\\vector(0,1){8}}\n");

	printf("\t\\thicklines\\path(-1,-1)(6,6)\n");
	printf("\\end{picture}\n");
	printf("\\end{center}\n");
	printf("\\end{figure}\n");
	printf("\\end{document}\n");
}
