#ifndef INDUSTRIALLI_MODBUS_RTU_H
#define INDUSTRIALLI_MODBUS_RTU_H

#include <cstdint>

class IndustrialliModbusRTU{
    public:
        uint8_t slave_address;
        uint8_t function_code;
        uint8_t data[252];
        uint8_t crc[2];

        int TX;
        int RX;
        int RE_DE;
};

#endif