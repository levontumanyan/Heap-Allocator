// will put some snippets here for educational purposes
#include <stdio.h>

struct Human {
	char sign;
	int id;
	short age;
};

struct betterHuman {
	int id;
	short age;
	char sign;
};

int main() {
	printf("The size of the struct Human is: %zu\n", sizeof(struct Human));
	printf("The size of the struct betterHuman is: %zu\n", sizeof(struct betterHuman));
	
	struct Human humanoid;
	struct Human* humanoidpointer = &humanoid;

	humanoid.sign = 10;

	printf("The location of humanoid is: %p\n", humanoidpointer);
	printf("The location of human struct is: %p\n", *humanoidpointer);

	return 0;
}
