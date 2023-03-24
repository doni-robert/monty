#include "monty.h"

/**
 *
 *
 *
 *
 */
#define BUFSIZE 128
char **read(FILE *fp)
{
	char **cmd, *buf;
	int i = 0;

	cmd = malloc(100 * sizeof(char *));
	if (cmd == NULL)
		malloc_fail();
	*cmd = malloc(sizeof(char) * 160);

	buf = malloc(sizeof(char) * 100);
	if (buf == NULL)
		malloc_fail();
	
	fgets(buf, 100, fp);
	strcpy(cmd[i], buf);
	printf("%s\n", cmd[0]);
	while (cmd[i] != NULL)
	{
		printf("%s%i\n", cmd[i], i);
		i++;
		fgets(buf, 100, fp);
		strcpy(cmd[i], buf);
	}


/*	while(fgets(buf, 100, fp))
	{
		

		
		if (BUFSIZE - strlen(buf) < sizeof(buf))
			_realloc(buf, BUFSIZE, BUFSIZE * 2);

		printf("%s\n", buf);

		strcpy(cmd[i], "buf");
		printf("%s\n", line[0]);
		i += 1;	
		arg = strtok(NULL, " ");
              if (arg == NULL)
                {
                       (cmd[i])[strlen(cmd[i]) - 1] = '\0';
                      data = 0;
                }
                else
			data = atoi(arg);
*/
	
	printf("%s\n", cmd[0]);
	printf("%s\n", cmd[1]);
        /*printf("%s\n", line[7]);
        printf("%s\n", line[6]);
*/	
		return (cmd);
}
