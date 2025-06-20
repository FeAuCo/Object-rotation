#pragma once

#include <cmath>

namespace obj_r{
    class Quaternion{
        private:
            double components[4];

        public:
            Quaternion(const double& a, const double& b, const double& c, const double& d);

            void setA(const double& new_a);

            void setB(const double& new_b);

            void setC(const double& new_c);

            void setD(const double& new_d);

            double getAbs();

            double operator[](const int& index);
            
            Quaternion conjugate();

            Quaternion operator*(Quaternion& other);
    };

    Quaternion getQ(const double& x, const double& y, const double& z, const double& w);

    Quaternion getH(const double& x, const double& y, const double& z);

    Quaternion rotate(Quaternion& q, Quaternion& h);
}
