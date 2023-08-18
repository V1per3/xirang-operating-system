 
#ifndef __XIRANGOS__GUI__DESKTOP_H
#define __XIRANGOS__GUI__DESKTOP_H

#include <gui/widget.h>
#include <drivers/mouse.h>

namespace xirangos
{
    namespace gui
    {
        
        class Desktop : public CompositeWidget, public xirangos::drivers::MouseEventHandler
        {
        protected:
            common::uint32_t MouseX;
            common::uint32_t MouseY;
            
        public:
            Desktop(common::int32_t w, common::int32_t h,
                common::uint8_t r, common::uint8_t g, common::uint8_t b);
            ~Desktop();
            
            void Draw(common::GraphicsContext* gc);
            
            void OnMouseDown(xirangos::common::uint8_t button);
            void OnMouseUp(xirangos::common::uint8_t button);
            void OnMouseMove(int x, int y);
        };
        
    }
}


#endif