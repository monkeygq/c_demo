#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	for(int i = 0; i < 32000; i++) {
		pid_t pid = fork();
		if(pid < 0)
			return -1;
		if(pid == 0)
			return 0;
		waitpid(pid, NULL, 0);
	}
	return 0;
}
