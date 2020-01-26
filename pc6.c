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
	printf("\\begin{picture}(5,1)\n");

	/*********************************/
	/* ç¿ïWé≤                        */
	/*********************************/

	printf("\t\\thicklines\\put\(-4,0\){\\vector(1,0){11}}\n");
	printf("\t\\thicklines\\put\(0,-4\){\\vector(0,1){8}}\n");

	/*********************************/
	/* â~Çï`Ç≠                      */
	/*********************************/
	
	printf("\t\\thicklines\\put\(0,0\){\\circle{6}}\n");
	printf("\t\\thicklines\\put\(3,0\){\\circle{6}}\n");
	/*********************************/
	/* â°ê¸Çà¯Ç≠                    */
	/*********************************/
	for(y=-4.0;y<=4.0;y=y+DELTA_Y_BORDER){
		for(x=-3.0;x<=6.0;x=x+DELTA_X_BORDER){
			if(x_start==DBL_MAX && y_start==DBL_MAX){
				if(
					(
						x*x+y*y<9
						&&
						(x-3)*(x-3)+y*y>=9
					)
				){
					x_start=x;
					y_start=y;
				}
			}
			if( x_start	!=DBL_MAX	&& y_start	!=DBL_MAX &&
				x_end	==DBL_MAX	&& y_end	==DBL_MAX
			){
				if(
					(
						(x+DELTA_X_BORDER)*(x+DELTA_X_BORDER)+(y)*(y)>9
						||
						(x-3+DELTA_X_BORDER)*(x-3+DELTA_X_BORDER)+(y)*(y)<9
					)
				){
					x_end=x;
					y_end=y;
				}
			}
		}
		if (x_start	!=DBL_MAX	&& y_start	!=DBL_MAX &&
			x_end	!=DBL_MAX	&& y_end	!=DBL_MAX
		){
			printf("\t\\thinlines\\path(%f,%f)(%f,%f)\n",x_start,y_start,x_end,y_end);
			x_start=DBL_MAX;
			y_start=DBL_MAX;
			x_end=DBL_MAX;
			y_end=DBL_MAX;
		}
	}

	/*********************************/
	/* ècê¸Çà¯Ç≠                    */
	/*********************************/
	for(x=-3.0;x<=6.0;x=x+DELTA_X_STRIPE){
		for(y=-4.0;y<=4.0;y=y+DELTA_Y_STRIPE){
			if(x_start==DBL_MAX && y_start==DBL_MAX){
				if(
					(
						x*x+y*y<9
						&&
						(x-3)*(x-3)+y*y>9
					)
				){
					x_start=x;
					y_start=y;
				}
			}
			
			if( x_start!=DBL_MAX && y_start!=DBL_MAX &&
				x_end==DBL_MAX   && y_end==DBL_MAX
			){
				if(
					(
						(x)*(x)+(y+DELTA_Y_STRIPE)*(y+DELTA_Y_STRIPE)>9
						||
						(x-3)*(x-3)+(y+DELTA_Y_STRIPE)*(y+DELTA_Y_STRIPE)<9
					)
				){
					x_end=x;
					y_end=y;
				}
			}
			if (x_start!=DBL_MAX && y_start!=DBL_MAX &&
				x_end!=DBL_MAX && y_end!=DBL_MAX
			){
				printf("\t\\thinlines\\path(%f,%f)(%f,%f)\n",x_start,y_start,x_end,y_end);
				x_start=DBL_MAX;
				y_start=DBL_MAX;
				x_end=DBL_MAX;
				y_end=DBL_MAX;
			}
		}
	}
	printf("\\end{picture}\n");
	printf("\\end{center}\n");
	printf("\\end{figure}\n");
	printf("\\end{document}\n");
}
