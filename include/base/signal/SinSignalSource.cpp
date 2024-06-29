#include "SinSignalSource.h"

base::SinSignalSource::SinSignalSource(double sin_periodic, double sample_interval)
	: _sin_periodic(sin_periodic),
	  _sample_interval(sample_interval),
	  _sample_clock(sin_periodic)
{
}

double base::SinSignalSource::Sample()
{
	// y = sin(w * t)
	// w = 2pi / T
	// y = sin(2pi / T * t)
	double sample_value = sin(2 * M_PI * _sample_clock.Time() / _sin_periodic);
	_sample_clock += _sample_interval;
	return sample_value;
}
