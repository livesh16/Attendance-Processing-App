#include "zoomrecs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *p = fopen(argv[1], "rt");

	// Character array
	char buffer[1000];

	// Do an fgets to move the stream to the next line since the first line
	// is just a header
	fgets(buffer, 1000, p);

	// Store first line in input file into a character array
	fgets(buffer, 1000, p);
	struct ZoomRecord *head;
	head = (struct ZoomRecord *) malloc(sizeof(struct ZoomRecord));

	char *t = strtok(buffer, ",");
	strcpy(head->email, t);

	t = strtok(NULL, ",");
	strcpy(head->name, t);

	t = strtok(NULL, ",");
	char c = t[0];
	int lab = c - 'A';

	t = strtok(NULL, ",");
	int duration = atoi(t);

	memset(head->durations, 0, 9);
	
	head->durations[lab] = head->durations[lab] + duration;

	head->next = NULL;

	// Read the second line from the file and put it into the buffer
	fgets(buffer, 1000, p);
	while(!feof(p))
	{
		head = addZoomRecord(head, buffer);
		
		// Read the next line from the input file
		fgets(buffer, 1000, p);
	}

	// Close the input file
	fclose(p);

	// Open the file in which we need to write the output
	FILE *q = fopen(argv[2], "wt");

	fprintf(q, "User Email,Name (Original Name),A,B,C,D,E,F,G,H,I,Attendance (Percentage)\n");

	generateAttendance(head, q);

	fclose(q);

	struct ZoomRecord *n = head;

	// Free the linked list
	struct ZoomRecord *tmp;
	while (n != NULL)
	{
		tmp = n->next;
		free(n);
		n = tmp;
	}
}





