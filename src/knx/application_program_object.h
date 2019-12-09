#pragma once

#include "table_object.h"

class ApplicationProgramObject : public TableObject
{
  public:
    ApplicationProgramObject(Memory& memory);
    void readProperty(PropertyID id, uint32_t start, uint32_t& count, uint8_t* data);
    void writeProperty(PropertyID id, uint32_t start, uint8_t* data, uint32_t& count);
    uint8_t propertySize(PropertyID id);
    ObjectType objectType() { return OT_APPLICATION_PROG; }    
    uint8_t* data(uint32_t addr);
    uint8_t getByte(uint32_t addr);
    uint16_t getWord(uint32_t addr);
    uint32_t getInt(uint32_t addr);
    uint8_t* save(uint8_t* buffer);
    uint8_t* restore(uint8_t* buffer);
    uint16_t saveSize();

  protected:
    uint8_t propertyCount();
    PropertyDescription* propertyDescriptions();

  private:
    uint8_t _programVersion[5] = {0, 0, 0, 0, 0};
};