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
#include <string.h>
#include "knowledge.h"

#define		MEMORY_STORAGE	"sessions/"
#define		NAME_OF_DUCK	"Nucky"
#define		BUFFER_SIZE	256
#define		VERSION_MAJOR	0
#define		VERSION_MINOR	1

/* Function prototypes. */
void		remember_session(const char *);
int		listen_to_programmer();
void		answer_to_programmer();
void		usage();

/* Nasty globals. */
FILE		*session;

/*
 * main():
 *	Main entrypoint of application.
 */
int main(int argc, char *argv[]) {
	if (argc != 2) {
		usage();
		exit (EXIT_FAILURE);
	}

	srand(time(NULL));
	printf("Welcome to Nucky, the advanced virtual rubber ducky.\n");
	printf("He will listen to you as you work your way through the ");
	printf("debugging session.\nTo quit, simply write 'quit' and Nucky ");
	printf("will remember where you left off.\n\n");

	/* Have nucky talked about this issue before? */
	remember_session(argv[1]);

	/*
	 * The super advanced thought process of Nucky.
	 * Probably the closest to a real A.I we've ever been.
	 */
	while (listen_to_programmer()) {
		answer_to_programmer();
	}

	exit(EXIT_SUCCESS);
}

/*
 * usage():
 *	For those who fail to fathom the simplicity of Nucky.
 */
void usage() {
	printf("%s version %d.%d usage:\n", NAME_OF_DUCK, VERSION_MAJOR,
	    VERSION_MINOR);
	printf("\t./nucky \"<question>\"\n");
}

/*
 * listen_to_programmer(important_question):
 *	Nucky always takes time to listen to your most important
 *	questions. He's always there for you. Always watching.
 */
int listen_to_programmer() {
	char buffer[BUFFER_SIZE];

	printf("Input: ");
	fgets(buffer, BUFFER_SIZE, stdin);
	if (strncmp("quit", buffer, 4) == 0)
		return (0);

	fputs(buffer, session);

	return (1);
}

/*
 * answer_to_programmer():
 *	Nucky seeks deep within to find the best possible
 *	answer to any question asked.
 */
void answer_to_programmer() {
	int limit = sizeof(knowledge) / sizeof(knowledge[0]);
	int pick = rand() % limit;

	printf("%s: %s\n", NAME_OF_DUCK, knowledge[pick].answer);
}
/*
 * remember_session(issue):
 *	Nucky will try his hardest to remember if he's been 
 *	consulted with this issue before.
 */
void remember_session(const char *issue) {
	char memory_location[BUFFER_SIZE + strlen(MEMORY_STORAGE)];

	snprintf(memory_location, strlen(issue) + strlen(MEMORY_STORAGE),
	    "%s/%s", MEMORY_STORAGE, issue);
	if (access(memory_location, F_OK) != -1) {
		session = fopen(memory_location, "a+");
		char buffer[256];

		fseek(session, 0, SEEK_SET);
		while (!feof(session)) {
			memset(buffer, 0x00, 256);
			fscanf(session, "%[^\n]\n", buffer);
		}

		printf("%s: Last thing you told me was:\n", NAME_OF_DUCK);
		printf("\t'%s'\n", buffer);
		printf("%s: Did you manage to fix it?\n", NAME_OF_DUCK);
	} else {
		session = fopen(memory_location, "w+");
		printf("%s: Can you explain what your code is meant to do?\n",
		    NAME_OF_DUCK);
	}
}
