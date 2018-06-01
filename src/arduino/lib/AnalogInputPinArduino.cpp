#include "AnalogInputPinArduino.h"

#include <Arduino.h>
#include <string.h>
#include "frozen.h"

namespace omni
{
//private
    AnalogInputPinArduino* AnalogInputPinArduino::createFromJson(const char* json)
    {
        unsigned int len = strlen(json);

        unsigned short pin;
        float minVoltage;
        float maxVoltage;

        if(json_scanf(json, len, "{pin: %u, minVoltage: %f, maxVoltage: %f}", &pin, &minVoltage, &maxVoltage)!=3)
            return nullptr;

        return new AnalogInputPinArduino(pin, minVoltage, maxVoltage);
    }

//protected
    unsigned int AnalogInputPinArduino::readPin()
    {
        return analogRead(getPin());
    }

//public
    AnalogInputPinArduino::AnalogInputPinArduino(unsigned short pin, float minVolt, float maxVolt):
        AnalogInputPin(pin, 1023, minVolt, maxVolt)
    {

    }

    AnalogInputPinArduino::~AnalogInputPinArduino()
    {

    }

    InputUInt* AnalogInputPinArduino::createUIntFromJson(const char* json)
    {
        return createFromJson(json);
    }

    InputFloat* AnalogInputPinArduino::createFloatFromJson(const char* json)
    {
        return createFromJson(json);
    }

    const char* AnalogInputPinArduino::Type = "AnalogInputPinArduino";
    static ObjectConfig<InputUInt> AnalogInputPinArduino::InputUIntConf(Type, createUIntFromJson);
    static ObjectConfig<InputFloat> AnalogInputPinArduino::InputFloatConf(Type, createFloatFromJson);
}