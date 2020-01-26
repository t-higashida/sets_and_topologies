#include<stdio.h>
#include<math.h>

void main(void){
	
	double t,x,y;
	
	printf("\\documentclass{jarticle}\n");
	printf("\\usepackage{epic,eepic} \n");
	printf("\\begin{document}\n");
	printf("\\begin{figure}[htbp]\n");
	printf("\\begin{center}\n");
	printf("\\setlength{\\unitlength}{10mm}\n");
	printf("\\begin{picture}(1.5,1)\n");

	for(t=0;t<=2*M_PI;t=t+.02) {
		printf("\t\\put\(%f,%f\){\\rule{1.5pt}{1.5pt}}\n",3*(cos(t)-1),3*sin(t));
	}
	
	for(t=0;t<=2*M_PI;t=t+.02) {
		printf("\t\\put\(%f,%f\){\\rule{1.5pt}{1.5pt}}\n",2*(cos(t)+0.3),2*sin(t));
	}
	
	for(x=-1.4;x<2.6;x=x+.03){
		for(y=-2.0;y<2.0;y=y+.03){
			if(	(x+3.0)*(x+3.0)+y*y<=9.0000){
				if((x-0.6)*(x-0.6)+y*y<4.0000000){
					printf("\t\\put(%lf,%lf){\\rule{.2pt}{.2pt}}\n",x,y);
				}
			}
		}
	}	
	printf("\\end{picture}\n");
	printf("\\end{center}\n");
	printf("\\end{figure}\n");
	printf("\\end{document}\n");
}
