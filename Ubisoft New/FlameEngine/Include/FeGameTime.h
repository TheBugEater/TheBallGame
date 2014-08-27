#pragma once
#include<time.h>

class FeGameTime
{
	static long int tCurrentTime;
	static long int tInitialFeGameTime;
	static long int tTempTime;
	static long int tCurrentElapsedTime;
	static long int tTotalFeGameTime;
public:

	FeGameTime(void);
	static void StartTime();
	long int ElapsedGameTime();
	long int TotalGameTime();
	static void Update();
	~FeGameTime(void);
};

