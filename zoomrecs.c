#include "zoomrecs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ZoomRecord *addZoomRecord(struct ZoomRecord *head, char *buffer)
{
	struct ZoomRecord *n = head;

	char *email = strtok(buffer, ",");
	char *name = strtok(NULL, ",");

	char *s = strtok(NULL, ",");
	char c = s[0];
	int lab = c - 'A';	
	
	s = strtok(NULL, ",");
	int duration = atoi(s);

	int found = 0;
	while(n != NULL)
	{
		if (strcmp(email, n->email) == 0)
		{
			n->durations[lab] = n->durations[lab] + duration;
			found = 1;
			break;
		}

		n = n->next;
	}
	
	// If the student is not found
	if (found == 0)
	{
		// Create a new ZoomRecord for the student
		struct ZoomRecord *newStudent;
		newStudent = (struct ZoomRecord *) malloc(sizeof(struct ZoomRecord));

		strcpy(newStudent->email, email);
		strcpy(newStudent->name, name);
		
		// Set all element in array for durations to 0
		memset(newStudent->durations, 0, 9);

		newStudent->durations[lab] = newStudent->durations[lab] + duration;

		newStudent->next = NULL;

		if (strcmp(newStudent->email,head->email) < 0)
		{
			newStudent->next = head;
			head = newStudent;
		}
		
		// Else, we have to add the node either inbetween two existing nodes or at the end of the linked list
		else
		{
			n = head;	
			while(n != NULL)
			{
				if (n->next != NULL && strcmp(newStudent->email,n->email) > 0)
				{
					if (strcmp(newStudent->email,(n->next)->email) < 0)
					{
						newStudent->next = n->next;
						n->next = newStudent;
						break;
					}
				}

				else if (n->next == NULL)
				{
					n->next = newStudent;
					newStudent->next = NULL;
					break;
				}

				n = n->next;
			}
		}
	}
	
	return head;
}

void generateAttendance(struct ZoomRecord *head, FILE *p)
{
	struct ZoomRecord *n = head;

	while(n != NULL)
	{
		int attendance = 0;

		for(int i = 0; i < 9; i++)
		{
			if (n->durations[i] >= 45)
			{
				attendance++;
			}
		}

		float percentage = (attendance/9.0) * 100;
		
		int a = n->durations[0];
		int b = n->durations[1];
		int c = n->durations[2];
		int d = n->durations[3];
		int e = n->durations[4];
		int f = n->durations[5];
		int g = n->durations[6];
		int h = n->durations[7];
		int j = n->durations[8];
		fprintf(p, "%s,%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%.2f\n", n->email, n->name, a, b, c, d, e, f, g, h, j, percentage);

		n = n->next;
		
	}

}



