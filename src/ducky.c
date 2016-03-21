/*
 * The NorthernSec Personal Rubber Ducky Debugger.
 *	Are you running into funky errors? Are you getting
 *	unexpected output? Having trouble locating where it
 *	all went wrong? Look no further, Nucky is here for you!
 *	Consult Nucky and he'll help you with all the great
 *	wisdom a virtual duck can posses!
 *
 *	Author: Northern Security
 *	Author: Robin Abony <robin.abony@gmail.com>
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "knowledge.h"

#define		MAX_USER_LEN	32
#define		NAME_OF_DUCK	"Nucky"
#define		VERSION_MAJOR	0
#define		VERSION_MINOR	1

/* Function prototypes. */
void		usage();
void		listen_to_programmer(char *);
void		answer_to_programmer();
const char	*seek_answer_within();

/*
 * main():
 *	Main entrypoint of application.
 */
int main(int argc, char *argv[]) {
	if (argc != 2) {
		usage();
		exit (EXIT_FAILURE);
	}

	/*
	 * The super advanced thought process of Nucky.
	 * Probably the closest to a real A.I we've ever been.
	 */
	listen_to_programmer(argv[1]);
	answer_to_programmer();

	exit(EXIT_SUCCESS);
}

/*
 * usage():
 *	For those who fail to fathom the simplicity of Nucky.
 */
void usage() {
	printf("%s version %d.%d usage:\n", NAME_OF_DUCK, VERSION_MAJOR, VERSION_MINOR);
	printf("\t./nucky \"<question>\"\n");
}

/*
 * listen_to_programmer(important_question):
 *	Nucky always takes time to listen to your most important
 *	questions. He's always there for you. Always watching.
 */
void listen_to_programmer(char *important_question) {
	char programmer[MAX_USER_LEN];

	getlogin_r(programmer, MAX_USER_LEN); 
	printf("%s: %s\n", programmer, important_question);
}

/*
 * answer_to_programmer():
 *	Nucky seeks deep within to find the best possible
 *	answer to any question asked.
 */
void answer_to_programmer() {
	const char *answer = seek_answer_within();

	printf("%s: %s\n", NAME_OF_DUCK, answer);
}

/*
 * seek_answer_within():
 *	The core of Nuckys deep thought process.
 */
const char *seek_answer_within() {
	srand(time(NULL));
	int limit = sizeof(knowledge) / sizeof(knowledge[0]);
	int pick = rand() % limit;
	return (knowledge[pick].answer);
}
