#include <stdio.h>
#include <stdlib.h>

extern void imgCvtGrayDoubleToInt(double *in, unsigned char *out, size_t count);

int main(void) {
    size_t h, w;
    scanf("%zu %zu", &h, &w) ;
        
	
    size_t n = h * w;
    double *in  = malloc(n * sizeof(double));
    unsigned char *out = malloc(n);

    for (size_t i = 0; i < n; i++) {
        if (scanf("%lf", &in[i]) != 1)
            return 1;
    }

    imgCvtGrayDoubleToInt(in, out, n);

    for (size_t i = 0; i < n; i++) {
		printf("%3hhu", out[i]);
    if ((i + 1) % w == 0) {
        printf("\n");
    } else {
        printf(", ");
    }
}



    free(in);
    free(out);
    return 0;
}
