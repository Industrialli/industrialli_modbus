#include "industrialli_modbus_rtu.h"
#include <HardwareSerial.h>
#include <arduino.h>

void IndustrialliModbusRTU::begin(HardwareSerial *_serial){
    serial = _serial;
    t15    = 15000000/9600; 
    t35    = 35000000/9600;
}

void IndustrialliModbusRTU::send(uint8_t _address, uint8_t *_pdu, int _pdusize){
    serial->write(_address);

    for (int i = 0; i < _pdusize; i++){
        serial->write(_pdu[i]);
    }

    uint16_t crc_value = crc(_address, _pdu, _pdusize);

    serial->write(crc_value >> 8);
    serial->write(crc_value & 0xFF);

    delay(t35);

    serial->flush();
}

void IndustrialliModbusRTU::receive(uint8_t *frame, int framesize){
    for (int i = 0; i < framesize; i++){
        frame[i] = serial->read();
    }
}

uint16_t IndustrialliModbusRTU::crc(uint8_t address, uint8_t *pdu, int pdusize){
    uint8_t uchCRCHi = 0xFF;
    uint8_t uchCRCLo = 0xFF;
    uint8_t uIndex;

    uIndex   = uchCRCLo ^ address;
    uchCRCLo = uchCRCHi ^ auchCRCHi[uIndex];
    uchCRCHi = auchCRCLo[uIndex];
    
    while(pdusize--){
        uIndex   = uchCRCLo ^ *pdu++;
        uchCRCLo = uchCRCHi ^ auchCRCHi[uIndex];
        uchCRCHi = auchCRCLo[uIndex];
    }

    return (uchCRCHi << 8 | uchCRCLo);
}