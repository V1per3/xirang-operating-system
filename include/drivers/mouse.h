
#ifndef __XIRANGOS__DRIVERS__MOUSE_H
#define __XIRANGOS__DRIVERS__MOUSE_H

#include <common/types.h>
#include <hardwarecommunication/port.h>
#include <drivers/driver.h>
#include <hardwarecommunication/interrupts.h>

namespace xirangos
{
    namespace drivers
    {
    
        class MouseEventHandler
        {
        public:
            MouseEventHandler();

            virtual void OnActivate();
            virtual void OnMouseDown(xirangos::common::uint8_t button);
            virtual void OnMouseUp(xirangos::common::uint8_t button);
            virtual void OnMouseMove(int x, int y);
        };
        
        
        class MouseDriver : public xirangos::hardwarecommunication::InterruptHandler, public Driver
        {
            xirangos::hardwarecommunication::Port8Bit dataport;
            xirangos::hardwarecommunication::Port8Bit commandport;
            xirangos::common::uint8_t buffer[3];
            xirangos::common::uint8_t offset;
            xirangos::common::uint8_t buttons;

            MouseEventHandler* handler;
        public:
            MouseDriver(xirangos::hardwarecommunication::InterruptManager* manager, MouseEventHandler* handler);
            ~MouseDriver();
            virtual xirangos::common::uint32_t HandleInterrupt(xirangos::common::uint32_t esp);
            virtual void Activate();
        };

    }
}
    
#endif
