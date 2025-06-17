#pragma once

#include <cmath>

namespace obj_r{
    class Quaternion{
        private:
            double a, b, c, d;

        public:
            Quaternion(double a, double b, double c, double d);

            double getA();

            double getB();

            double getC();

            double getD();

            void setA(double new_a);

            void setB(double new_b);

            void setC(double new_c);

            void setD(double new_d);

            double getAbs();

            Quaternion conjugate();
    };
}
