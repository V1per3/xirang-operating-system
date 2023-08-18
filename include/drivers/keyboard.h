
#ifndef __XIRANGOS__DRIVERS__KEYBOARD_H
#define __XIRANGOS__DRIVERS__KEYBOARD_H

#include <common/types.h>
#include <hardwarecommunication/interrupts.h>
#include <drivers/driver.h>
#include <hardwarecommunication/port.h>

namespace xirangos
{
    namespace drivers
    {
    
        class KeyboardEventHandler
        {
        public:
            KeyboardEventHandler();

            virtual void OnKeyDown(char);
            virtual void OnKeyUp(char);
        };
        
        class KeyboardDriver : public xirangos::hardwarecommunication::InterruptHandler, public Driver
        {
            xirangos::hardwarecommunication::Port8Bit dataport;
            xirangos::hardwarecommunication::Port8Bit commandport;
            
            KeyboardEventHandler* handler;
        public:
            KeyboardDriver(xirangos::hardwarecommunication::InterruptManager* manager, KeyboardEventHandler *handler);
            ~KeyboardDriver();
            virtual xirangos::common::uint32_t HandleInterrupt(xirangos::common::uint32_t esp);
            virtual void Activate();
        };

    }
}
    
#endif