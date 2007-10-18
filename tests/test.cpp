/***************************************************************************
 *            test.cpp
 *
 *  Mon May 15 11:26:07 2006
 *  Copyright  2006  User
 *  Email
 ****************************************************************************/

#include "mozembed.h"
int main( int argc, const char* argv[]);
#include <stdio.h>
int main( int argc, const char* argv[] )
{
    CallbackBin bin;
    Handle *ptr = mozembed_create(&bin);
    mozembed_init(ptr,(Handle)0);
    return 0;
};
