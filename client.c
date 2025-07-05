# include <libc.h>

int main(int argc, char **argv)
{
	(void)argc;
	kill(atoi(argv[1]), SIGSEGV);
	return 0;
}
