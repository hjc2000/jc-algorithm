#include"BitConverter.h"

using namespace jccpp;

uint16_t jccpp::BitConverter::ToUInt16(uint8_t *buffer, int offset)
{
	uint16_t *p = reinterpret_cast<uint16_t *>(buffer + offset);
	return *p;
}

int16_t jccpp::BitConverter::ToInt16(uint8_t *buffer, int offset)
{
	int16_t *p = reinterpret_cast<int16_t *>(buffer + offset);
	return *p;
}

uint32_t jccpp::BitConverter::ToUInt32(uint8_t *buffer, int offset)
{
	uint32_t *p = reinterpret_cast<uint32_t *>(buffer + offset);
	return *p;
}

int32_t jccpp::BitConverter::ToInt32(uint8_t *buffer, int offset)
{
	int32_t *p = reinterpret_cast<int32_t *>(buffer + offset);
	return *p;
}

uint64_t jccpp::BitConverter::ToUInt64(uint8_t *buffer, int offset)
{
	uint64_t *p = reinterpret_cast<uint64_t *>(buffer + offset);
	return *p;
}

int64_t jccpp::BitConverter::ToInt64(uint8_t *buffer, int offset)
{
	int64_t *p = reinterpret_cast<int64_t *>(buffer + offset);
	return *p;
}

float jccpp::BitConverter::ToFloat(uint8_t *buffer, int offset)
{
	float *p = reinterpret_cast<float *>(buffer + offset);
	return *p;
}

double jccpp::BitConverter::ToDouble(uint8_t *buffer, int offset)
{
	double *p = reinterpret_cast<double *>(buffer + offset);
	return *p;
}

std::array<uint8_t, 2> jccpp::BitConverter::GetBytes(uint16_t value)
{
	uint8_t *buffer = reinterpret_cast<uint8_t *>(&value);
	std::array<uint8_t, 2> ret { buffer[0], buffer[1] };
	return ret;
}

std::array<uint8_t, 2> jccpp::BitConverter::GetBytes(int16_t value)
{
	uint8_t *buffer = reinterpret_cast<uint8_t *>(&value);
	std::array<uint8_t, 2> ret { buffer[0], buffer[1] };
	return ret;
}

std::array<uint8_t, 4> jccpp::BitConverter::GetBytes(uint32_t value)
{
	uint8_t *buffer = reinterpret_cast<uint8_t *>(&value);
	std::array<uint8_t, 4> ret { buffer[0], buffer[1], buffer[2], buffer[3] };
	return ret;
}

std::array<uint8_t, 4> jccpp::BitConverter::GetBytes(int32_t value)
{
	uint8_t *buffer = reinterpret_cast<uint8_t *>(&value);
	std::array<uint8_t, 4> ret { buffer[0], buffer[1], buffer[2], buffer[3] };
	return ret;
}

std::array<uint8_t, 8> jccpp::BitConverter::GetBytes(uint64_t value)
{
	uint8_t *buffer = reinterpret_cast<uint8_t *>(&value);
	std::array<uint8_t, 8> ret {
		buffer[0], buffer[1], buffer[2], buffer[3],
		buffer[4], buffer[5], buffer[6], buffer[7],
	};

	return ret;
}

std::array<uint8_t, 8> jccpp::BitConverter::GetBytes(int64_t value)
{
	uint8_t *buffer = reinterpret_cast<uint8_t *>(&value);
	std::array<uint8_t, 8> ret {
		buffer[0], buffer[1], buffer[2], buffer[3],
		buffer[4], buffer[5], buffer[6], buffer[7],
	};

	return ret;
}

std::array<uint8_t, 4> jccpp::BitConverter::GetBytes(float value)
{
	uint8_t *buffer = reinterpret_cast<uint8_t *>(&value);
	std::array<uint8_t, 4> ret { buffer[0], buffer[1], buffer[2], buffer[3], };
	return ret;
}

std::array<uint8_t, 8> jccpp::BitConverter::GetBytes(double value)
{
	uint8_t *buffer = reinterpret_cast<uint8_t *>(&value);
	std::array<uint8_t, 8> ret {
		buffer[0], buffer[1], buffer[2], buffer[3],
		buffer[4], buffer[5], buffer[6], buffer[7],
	};

	return ret;
}
