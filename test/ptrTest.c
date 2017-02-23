#include <stdio.h>
#include <stdlib.h>

typedef struct s_test t_test;

struct		s_test
{
	char *test;
};

t_test	*singleton(void)
{
	static t_test test = {.test = NULL};

	return (&test);
}

void	testdemodifptr(char *ptr)
{
	dprintf(1, "Test dans le testmodif : %p - %p\n", ptr, ptr);
	ptr = malloc(10);
	dprintf(1, "Test dans le testmodif : %p - %p\n", ptr, ptr);
}

void	*testdemodifptr2(char *ptr)
{
	dprintf(1, "Test dans le testmodif : %p\n", ptr);
	ptr = malloc(10);
	dprintf(1, "Test dans le testmodif : %p\n", ptr);
	return (ptr);
}


int main(void)
{
	t_test *test;

	test = singleton();
	dprintf(1, "Test dans le main : %p - %p\n", &test->test, test->test);
	test->test = testdemodifptr2(test->test);
	dprintf(1, "Test dans le main : %p - %p\n", &test->test, test->test);
	dprintf(1, "Test singleton : %p - %p\n", &singleton()->test, singleton()->test);
}
