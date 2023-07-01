/*
 *  Copyright (c) 2014, Oculus VR, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant 
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#if   defined(_WIN32)
#include "WindowsIncludes.h" // Sleep







#else
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
pthread_mutex_t fakeMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t fakeCond = PTHREAD_COND_INITIALIZER;
#endif

#include "RakSleep.h"


#if defined(WINDOWS_PHONE_8) || defined(WINDOWS_STORE_RT)
#include "ThreadEmulation.h"
using namespace ThreadEmulation;
#endif

void RakSleep(unsigned int ms)
{
#ifdef _WIN32
	Sleep(ms);







#else
	usleep(1000);
#endif
}
