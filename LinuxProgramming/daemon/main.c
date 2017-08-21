/*
 * An example of how to write daemon programs
 */
#include <unistd.h>
#include <stdbool.h>


int main(int argc, char** argv)
{
	daemon(0, 0);
	while(true) {
		sleep(3);
	}
	return 0;
}
