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

	printf("\t\\thicklines\\put\(-3,0\){\\circle{6}}\n");
	printf("\t\\thicklines\\put\(0,0\){\\circle{4}}\n");
	printf("\t\\thicklines\\put\(-1,-2\){\\circle{4}}\n");

	/*********************************/
	/* â°ê¸Çà¯Ç≠                    */
	/*********************************/
	for(y=-4.0;y<=4.0;y=y+DELTA_Y_BORDER){
		for(x=-3.0;x<=6.0;x=x+DELTA_X_BORDER){
			if(x_start==DBL_MAX && y_start==DBL_MAX){
				if(
					(
						(x+3)*(x+3)+y*y<9
						&&
						x*x+y*y<4
					)
						||
					(x+1)*(x+1)+(y+2)*(y+2)<4
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
						(x+3+DELTA_X_BORDER)*(x+3+DELTA_X_BORDER)+(y)*(y)>9
						||
						(x+DELTA_X_BORDER)*(x+DELTA_X_BORDER)+(y)*(y)>4
					)
						&&	
					(x+1+DELTA_X_BORDER)*(x+1+DELTA_X_BORDER)+(y+2)*(y+2)>4
				){
					x_end=x;
					y_end=y;
				}
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

	/*********************************/
	/* ècê¸Çà¯Ç≠                    */
	/*********************************/
	for(x=-3.0;x<=6.0;x=x+DELTA_X_STRIPE){
		for(y=-4.0;y<=4.0;y=y+DELTA_Y_STRIPE){
			if(x_start==DBL_MAX && y_start==DBL_MAX){
				if(
					(
						(x+3)*(x+3)+y*y<9
						&&
						x*x+y*y<4
					)
						||
					(x+1)*(x+1)+(y+2)*(y+2)<4
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
						(x+3)*(x+3)+(y+DELTA_Y_STRIPE)*(y+DELTA_Y_STRIPE)>9
						||
						(x)*(x)+(y+DELTA_Y_STRIPE)*(y+DELTA_Y_STRIPE)>4
					)
						&&	
					(x+1)*(x+1)+(y+2+DELTA_Y_STRIPE)*(y+2+DELTA_Y_STRIPE)>4
				){
					x_end=x;
					y_end=y;
				}
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

	printf("\t\\thicklines\\put\(6,0\){\\circle{6}}\n");
	printf("\t\\thicklines\\put\(9,0\){\\circle{4}}\n");
	printf("\t\\thicklines\\put\(8,-2\){\\circle{4}}\n");
	x_start=DBL_MAX;
	y_start=DBL_MAX;
	x_end=DBL_MAX;
	y_end=DBL_MAX;

	/*********************************/
	/* â°ê¸Çà¯Ç≠                    */
	/*********************************/
	for(y=-4.0;y<=4.0;y=y+DELTA_Y_BORDER){
		for(x=6.0;x<=12.0;x=x+DELTA_X_BORDER){
			if(x_start==DBL_MAX && y_start==DBL_MAX){
				if(
					(
						(x-6)*(x-6)+y*y<9
						||
						(x-9)*(x-9)+y*y<4
					)
						&&
					(x-8)*(x-8)+(y+2)*(y+2)<4
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
						(x-6+DELTA_X_BORDER)*(x-6+DELTA_X_BORDER)+(y)*(y)>9
						&&
						(x-9+DELTA_X_BORDER)*(x-9+DELTA_X_BORDER)+(y)*(y)>4
					)
						||
					(x-8+DELTA_X_BORDER)*(x-8+DELTA_X_BORDER)+(y+2)*(y+2)>4
				){
					x_end=x;
					y_end=y;
				}
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

	/*********************************/
	/* ècê¸Çà¯Ç≠                    */
	/*********************************/
	for(x=6.0;x<=12.0;x=x+DELTA_X_STRIPE){
		for(y=-4.0;y<=4.0;y=y+DELTA_Y_STRIPE){
			if(x_start==DBL_MAX && y_start==DBL_MAX){
				if(
					(
						(x-6)*(x-6)+y*y<9
						||
						(x-9)*(x-9)+y*y<4
					)
						&&
					(x-8)*(x-8)+(y+2)*(y+2)<4
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
						(x-6)*(x-6)+(y+DELTA_Y_STRIPE)*(y+DELTA_Y_STRIPE)>9
						&&
						(x-9)*(x-9)+(y+DELTA_Y_STRIPE)*(y+DELTA_Y_STRIPE)>4
					)
						||	
					(x-8)*(x-8)+(y+2+DELTA_Y_STRIPE)*(y+2+DELTA_Y_STRIPE)>4
				){
					x_end=x;
					y_end=y;
				}
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

	printf("\\end{picture}\n");
	printf("\\end{center}\n");
	printf("\\end{figure}\n");
	printf("\\end{document}\n");
}
