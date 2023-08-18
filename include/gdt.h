#ifndef __XIRANGOS__GDT_H
#define __XIRANGOS__GDT_H

#include <common/types.h>

namespace xirangos
{
    
    class GlobalDescriptorTable
    {
        public:

            class SegmentDescriptor
            {
                private:
                    xirangos::common::uint16_t limit_lo;
                    xirangos::common::uint16_t base_lo;
                    xirangos::common::uint8_t base_hi;
                    xirangos::common::uint8_t type;
                    xirangos::common::uint8_t limit_hi;
                    xirangos::common::uint8_t base_vhi;

                public:
                    SegmentDescriptor(xirangos::common::uint32_t base, xirangos::common::uint32_t limit, xirangos::common::uint8_t type);
                    xirangos::common::uint32_t Base();
                    xirangos::common::uint32_t Limit();
            } __attribute__((packed));

        private:
            SegmentDescriptor nullSegmentSelector;
            SegmentDescriptor unusedSegmentSelector;
            SegmentDescriptor codeSegmentSelector;
            SegmentDescriptor dataSegmentSelector;

        public:

            GlobalDescriptorTable();
            ~GlobalDescriptorTable();

            xirangos::common::uint16_t CodeSegmentSelector();
            xirangos::common::uint16_t DataSegmentSelector();
    };

}
    
#endif