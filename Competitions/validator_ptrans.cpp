#include "testlib.h"

bool composite[1000200];
int phi;

long long mod_exp(long long b, long long e, long long m) {
	long long r = 1;
	while (e > 0) {
		if (e & 1)
			r = (r*b) % m;
		b = (b*b) % m;
		e >>= 1;
	}
	return r;
}

int main(int argc, char* argv[]) {

    registerValidation(argc, argv);

    int N = inf.readInt(1, 1000123, "N");
    inf.readSpace();
    int M = inf.readInt(1, 1000123, "M");
    inf.readSpace();
    int a = inf.readInt(2, 1000123, "a");
    inf.readSpace();
    int Q = inf.readInt(7, 1000000123, "Q");
    inf.readEoln();
    inf.readEof();

    for (int i=2; i<=1000123; ++i){
        if (!composite[i] && mod_exp(a, i, Q) == 1) { phi = i; break; }
        else if (!composite[i]){
            for (int j=2; j*i <=1000123; ++j)
            composite[j*i] = true;
        }
    }

    ensuref((phi>N)&&(phi>M)&&(mod_exp(a,phi,Q)==1), "Multiplicative order has to be prime and smaller than 1000124, and bigger than M and N!");
}
