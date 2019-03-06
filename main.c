#include <stdio.h>

////////////////////////
// Kacper Ledwosiński //
//		7.03.2019	  //
////////////////////////

// Credits:
// - Tomasz K. Pietrzak (http://if.pw.edu.pl/~topie/)
// - Paweł Żak (http://www.kipo.agh.edu.pl/data/NumInt.pdf)

int main(int args, char **argv) {
	
	char *input_name, *output_name;
	
	if(args != 3) {
		fprintf(stderr, "Wrong number of arguments!\n");
		return -1;
	} else {
		input_name = argv[1];
		output_name = argv[2];
		
		FILE *input = fopen(input_name, "r");
		FILE *output = fopen(output_name, "w");
		
		if(!input) {
			fprintf(stderr, "Problem with input file.\n");
			return -1;
		}
		
		// incoming point
		float x, y;
		// special variable for previous point
		float px=0, py=0;
		
		// total integral value
		float value = 0;

		while(fscanf(input, "%f\t%f", &x, &y) != EOF) {
			
			float dx = x - px;

			// rectangle method
			//value += y * dx;
			
			// trapeze method
			value += (py + y) * dx / 2;

			// set new point to special variable
			px = x;
			py = y;
		}
		
		// print value to console
		//printf("Value: %f\n", value);
		
		// save value to output file
		fprintf(output, "%f\n", value);
		
		fclose(input);
		fclose(output);
	}
	
	return 0;
}

