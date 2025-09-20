// P02_bpalmer
// Sort Time Analysis
// Brandon Palmer
// CIS 221
// Dencler


#include "TimerHeader.h"

/* Slightly modified StopWatch class from A010. Class name change to Timer and
addition of Reset() method.*/

// Default constructor
Timer::Timer() {
	this->beginTime = 0;
	this->endTime = 0;
	this->timeDiff = 0;
	this->amITicking = false;
}

/* Starts timer if isTicking() (getter for amITicking) returns false/not ticking
and assigns start time to beginTime.*/
bool Timer::Start() {
	if (!isTicking()) {
		this->beginTime = clock();
		this->amITicking = true;
		return true;
	}
	else {
		return false;
	}
}

/* Stops timer if isTicking() (getter for amITicking) returns true/ticking and
assigns stop time to endTime. Then calculates timeDiff and divides by
clocks per second of the processor to assign an accurate time.*/
bool Timer::Stop() {
	if (isTicking()) {
		this->endTime = clock();
		// timeDiff recorded in milliseconds
		this->timeDiff = endTime - beginTime;
		this->amITicking = false;
		return true;
	}
	else {
		return false;
	}
}

 /* Resets all time recordings to 0 if timer is finished ticking/isTicking()
 returns false. Returns true for successful reset, otherwise returns false.*/
bool Timer::Reset() {
	if (!isTicking()) {
		this->beginTime = 0;
		this->endTime = 0;
		this->timeDiff = 0;
		return true;
	}
	else {
		return false;
	}
}

// Returns value held in amITicking
bool Timer::isTicking() {
	return this->amITicking;
}

// Displays time held in timeDiff up to 3 decimal places
void Timer::DisplayTimerInfo() {
	cout << timeDiff << " milliseconds" << endl;
}