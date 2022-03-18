#include <cstdio>

struct Type1{
	bool a, b, c;
};

struct Type2{
	bool a : 1, b : 1, c : 1, d : 1, e : 1;
};

struct Type3{
	bool a, b, c, d, e, f, g, h, i, j;	
};

int main() {
	printf("%d\n", sizeof(Type1));
	printf("%d\n", sizeof(Type2));
	printf("%d\n", sizeof(Type3));

	return 0;
}
