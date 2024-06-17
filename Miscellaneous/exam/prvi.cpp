#include <cstdio>
#include <cstring>
using namespace std;

int palindrom(char* s, int i, int j)
{
	while (i < j && s[i] == s[j])
	{
		i ++;
		j --;
	}
	if (i >= j) return 1;
	else return 0;
}
int nadji_najduzi(char* s, int* poc, int* kraj)
{
	int n, i, j;
	int max = 1;
	int max_i = 0;
	int max_j = 0;

	n = strlen(s);
	for(i = 0; i < n; i ++)
		for(j = n-1; j > i; j --)
			if (palindrom(s, i, j)) {
				if (j - i + 1 > max) {
					max = j - i + 1;
					max_i = i;
					max_j = j;
				}
				break;
			}

	*poc = max_i;
	*kraj = max_j;

	return max;
}

int main()
{
	int i, j, duz;
	char s[100];

	scanf("%s", s);
	duz = nadji_najduzi(s, &i, &j);
	s[j + 1] = '\0';
	printf("Najduzi palindrom je '%s' od %d do %d duzine %d\n", s + i, i, j, duz);
	return 0;
}
