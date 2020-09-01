#ifndef _LOGGING_H
#define _LOGGING_H

#include <stdlib.h>
#include <stdio.h>

#define L_ERROR     2
#define L_WARNING   1
#define L_LOG       0

void log_(unsigned int type, const char* message);



#endif // _LOGGING_H
