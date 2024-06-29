#include "SinSignalSource.h"

base::SinSignalSource::SinSignalSource(double periodic)
{
	_periodic = periodic;
}

double base::SinSignalSource::Sample(PeriodicSamplingClock<double> time)
{
	// y = sin(w * t)
	// w = 2pi / T
	// y = sin(2pi / T * t)
	return sin(2 * M_PI * time.Time() / _periodic);
}
