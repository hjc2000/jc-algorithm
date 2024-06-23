#include "DoubleSinSignalSource.h"

base::DoubleSinSignalSource::DoubleSinSignalSource(double periodic)
{
	_periodic = periodic;
}

double base::DoubleSinSignalSource::Sample(double time)
{
	// y = sin(w * t)
	// w = 2pi / T
	// y = sin(2pi / T * t)
	return sin(2 * M_PI * time / _periodic);
}
