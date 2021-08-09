#ifndef __ZOOMRECS_H__ 
#define __ZOOMRECS_H__ 

#include <stdio.h>
struct ZoomRecord
{
char email[60]; // email of the student
char name[60]; // name of the student
int durations[9]; // duration for each lab.
struct ZoomRecord *next;
};

struct ZoomRecord * addZoomRecord(struct ZoomRecord *head, char *buffer);

void generateAttendance(struct ZoomRecord *head, FILE *p);

#endif // __ZOOMRECS_H__ 


