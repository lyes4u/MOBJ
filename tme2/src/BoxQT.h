#pragma once
#include "Box.h"

namespace tme2QT{
    class BoxQT : public tme2::Box {

        private:
            long x_;
            long y_;
            long width_;
            long height_;
        public:
            BoxQT() : Box(){
                this->x_ = (getX2() -getX1())/2;
                this->y_ = (getY2() -getY1())/2;
                this->height_ = getHeight();
                this->width_  = getWidth();

                 std::cout << "Debug: BoxQT::BoxQT() : "; this->print(std::cout);
            }
            ~BoxQT(){
                 std::cout << "Debug: BoxQT::~BoxQT() : "; this->print(std::cout);
            }
    };
}
