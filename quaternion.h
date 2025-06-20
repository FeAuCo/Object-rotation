#pragma once

#include <cmath>

namespace obj_r{
    class Quaternion{
        private:
            double components[4];

        public:
            Quaternion(const double& a, const double& b, const double& c, const double& d);

            double getA();

            double getB();

            double getC();

            double getD();

            void setA(const double& new_a);

            void setB(const double& new_b);

            void setC(const double& new_c);

            void setD(const double& new_d);

            double getAbs();

            double* build();

            Quaternion conjugate();

            Quaternion operator*(const Quaternion& other);
    };

    Quaternion getQ(const double& x, const double& y, const double& z, const double& w);

    Quaternion getH(const double& x, const double& y, const double& z);

    Quaternion rotate(const Quaternion& q, const Quaternion& h);
}
