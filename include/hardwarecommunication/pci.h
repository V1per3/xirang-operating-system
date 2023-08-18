 
#ifndef __XIRANGOS__HARDWARECOMMUNICATION__PCI_H
#define __XIRANGOS__HARDWARECOMMUNICATION__PCI_H

#include <hardwarecommunication/port.h>
#include <drivers/driver.h>
#include <common/types.h>
#include <hardwarecommunication/interrupts.h>

#include <memorymanagement.h>

namespace xirangos
{
    namespace hardwarecommunication
    {

        enum BaseAddressRegisterType
        {
            MemoryMapping = 0,
            InputOutput = 1
        };
        
        
        
        class BaseAddressRegister
        {
        public:
            bool prefetchable;
            xirangos::common::uint8_t* address;
            xirangos::common::uint32_t size;
            BaseAddressRegisterType type;
        };
        
        
        
        class PeripheralComponentInterconnectDeviceDescriptor
        {
        public:
            xirangos::common::uint32_t portBase;
            xirangos::common::uint32_t interrupt;
            
            xirangos::common::uint16_t bus;
            xirangos::common::uint16_t device;
            xirangos::common::uint16_t function;

            xirangos::common::uint16_t vendor_id;
            xirangos::common::uint16_t device_id;
            
            xirangos::common::uint8_t class_id;
            xirangos::common::uint8_t subclass_id;
            xirangos::common::uint8_t interface_id;

            xirangos::common::uint8_t revision;
            
            PeripheralComponentInterconnectDeviceDescriptor();
            ~PeripheralComponentInterconnectDeviceDescriptor();
            
        };


        class PeripheralComponentInterconnectController
        {
            Port32Bit dataPort;
            Port32Bit commandPort;
            
        public:
            PeripheralComponentInterconnectController();
            ~PeripheralComponentInterconnectController();
            
            xirangos::common::uint32_t Read(xirangos::common::uint16_t bus, xirangos::common::uint16_t device, xirangos::common::uint16_t function, xirangos::common::uint32_t registeroffset);
            void Write(xirangos::common::uint16_t bus, xirangos::common::uint16_t device, xirangos::common::uint16_t function, xirangos::common::uint32_t registeroffset, xirangos::common::uint32_t value);
            bool DeviceHasFunctions(xirangos::common::uint16_t bus, xirangos::common::uint16_t device);
            
            void SelectDrivers(xirangos::drivers::DriverManager* driverManager, xirangos::hardwarecommunication::InterruptManager* interrupts);
            xirangos::drivers::Driver* GetDriver(PeripheralComponentInterconnectDeviceDescriptor dev, xirangos::hardwarecommunication::InterruptManager* interrupts);
            PeripheralComponentInterconnectDeviceDescriptor GetDeviceDescriptor(xirangos::common::uint16_t bus, xirangos::common::uint16_t device, xirangos::common::uint16_t function);
            BaseAddressRegister GetBaseAddressRegister(xirangos::common::uint16_t bus, xirangos::common::uint16_t device, xirangos::common::uint16_t function, xirangos::common::uint16_t bar);
        };

    }
}
    
#endif