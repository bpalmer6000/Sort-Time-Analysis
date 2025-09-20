// P02_bpalmer
// Sort Time Analysis
// Brandon Palmer
// CIS 221
// Dencler

#pragma once

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;


/* Slightly modified StopWatch class from A010. Class name change to Timer and
addition of Reset() method.*/
class Timer {
private:
	clock_t beginTime;			// Records begin time
	clock_t endTime;			// Records end time
	clock_t timeDiff;			// Redorded in ms, holds value of endTime - beginTime
	bool amITicking;			// Holds value determining whether clock object is ticking
public:
	Timer();					// Default constructor
	bool Start();				// Starts timer based on value held in amITicking
	bool Stop();				// Stops timer based on value held in amITicking
	bool Reset();				/* Resets all time recordings to 0 if timer is finished ticking
								(isTicking() returns false).*/
	bool isTicking();			// Returns value held in amITicking
	void DisplayTimerInfo();	// Displays value in timeDiff
};