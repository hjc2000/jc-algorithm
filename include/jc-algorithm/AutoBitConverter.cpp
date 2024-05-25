#include"AutoBitConverter.h"
#include<algorithm>
#include<jc-algorithm/BitConverter.h>

using namespace jc_algorithm;

bool jc_algorithm::AutoBitConverter::ShouldReverse()
{
	return std::endian::native != _remote_endian;
}

jc_algorithm::AutoBitConverter::AutoBitConverter(std::endian remote_endian) :
	_remote_endian(remote_endian)
{
}

uint16_t jc_algorithm::AutoBitConverter::ToUInt16(uint8_t *buffer, int offset)
{
	if (ShouldReverse())
	{
		std::reverse(buffer + offset, buffer + offset + 2);
	}

	uint16_t ret = BitConverter::ToUInt16(buffer, offset);
	return ret;
}

int16_t jc_algorithm::AutoBitConverter::ToInt16(uint8_t *buffer, int offset)
{
	if (ShouldReverse())
	{
		std::reverse(buffer + offset, buffer + offset + 2);
	}

	int16_t ret = BitConverter::ToInt16(buffer, offset);
	return ret;
}

uint32_t jc_algorithm::AutoBitConverter::ToUInt32(uint8_t *buffer, int offset)
{
	if (ShouldReverse())
	{
		std::reverse(buffer + offset, buffer + offset + 4);
	}

	uint32_t ret = BitConverter::ToUInt32(buffer, offset);
	return ret;
}

int32_t jc_algorithm::AutoBitConverter::ToInt32(uint8_t *buffer, int offset)
{
	if (ShouldReverse())
	{
		std::reverse(buffer + offset, buffer + offset + 4);
	}

	int32_t ret = BitConverter::ToInt32(buffer, offset);
	return ret;
}

uint64_t jc_algorithm::AutoBitConverter::ToUInt64(uint8_t *buffer, int offset)
{
	if (ShouldReverse())
	{
		std::reverse(buffer + offset, buffer + offset + 8);
	}

	uint64_t ret = BitConverter::ToUInt64(buffer, offset);
	return ret;
}

int64_t jc_algorithm::AutoBitConverter::ToInt64(uint8_t *buffer, int offset)
{
	if (ShouldReverse())
	{
		std::reverse(buffer + offset, buffer + offset + 8);
	}

	int64_t ret = BitConverter::ToInt64(buffer, offset);
	return ret;
}

float jc_algorithm::AutoBitConverter::ToFloat(uint8_t *buffer, int offset)
{
	if (ShouldReverse())
	{
		std::reverse(buffer + offset, buffer + offset + 4);
	}

	float ret = BitConverter::ToFloat(buffer, offset);
	return ret;
}

double jc_algorithm::AutoBitConverter::ToDouble(uint8_t *buffer, int offset)
{
	if (ShouldReverse())
	{
		std::reverse(buffer + offset, buffer + offset + 8);
	}

	double ret = BitConverter::ToDouble(buffer, offset);
	return ret;
}

std::array<uint8_t, 2> jc_algorithm::AutoBitConverter::GetBytes(uint16_t value)
{
	std::array<uint8_t, 2> ret = BitConverter::GetBytes(value);
	if (ShouldReverse())
	{
		std::reverse(ret.begin(), ret.end());
	}

	return ret;
}

std::array<uint8_t, 2> jc_algorithm::AutoBitConverter::GetBytes(int16_t value)
{
	std::array<uint8_t, 2> ret = BitConverter::GetBytes(value);
	if (ShouldReverse())
	{
		std::reverse(ret.begin(), ret.end());
	}

	return ret;
}

std::array<uint8_t, 4> jc_algorithm::AutoBitConverter::GetBytes(uint32_t value)
{
	std::array<uint8_t, 4> ret = BitConverter::GetBytes(value);
	if (ShouldReverse())
	{
		std::reverse(ret.begin(), ret.end());
	}

	return ret;
}

std::array<uint8_t, 4> jc_algorithm::AutoBitConverter::GetBytes(int32_t value)
{
	std::array<uint8_t, 4> ret = BitConverter::GetBytes(value);
	if (ShouldReverse())
	{
		std::reverse(ret.begin(), ret.end());
	}

	return ret;
}

std::array<uint8_t, 8> jc_algorithm::AutoBitConverter::GetBytes(uint64_t value)
{
	std::array<uint8_t, 8> ret = BitConverter::GetBytes(value);
	if (ShouldReverse())
	{
		std::reverse(ret.begin(), ret.end());
	}

	return ret;
}

std::array<uint8_t, 8> jc_algorithm::AutoBitConverter::GetBytes(int64_t value)
{
	std::array<uint8_t, 8> ret = BitConverter::GetBytes(value);
	if (ShouldReverse())
	{
		std::reverse(ret.begin(), ret.end());
	}

	return ret;
}

std::array<uint8_t, 4> jc_algorithm::AutoBitConverter::GetBytes(float value)
{
	std::array<uint8_t, 4> ret = BitConverter::GetBytes(value);
	if (ShouldReverse())
	{
		std::reverse(ret.begin(), ret.end());
	}

	return ret;
}

std::array<uint8_t, 8> jc_algorithm::AutoBitConverter::GetBytes(double value)
{
	std::array<uint8_t, 8> ret = BitConverter::GetBytes(value);
	if (ShouldReverse())
	{
		std::reverse(ret.begin(), ret.end());
	}

	return ret;
}