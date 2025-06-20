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

            double operator[](const int& index) const;
            
            Quaternion conjugate() const;

            Quaternion operator*(const Quaternion& other) const;
    };

    Quaternion getQ(const double& x, const double& y, const double& z, const double& w);

    Quaternion getH(const double& x, const double& y, const double& z);

    Quaternion rotate(const Quaternion& q, const Quaternion& h);

    double toZero(const double& number);
}
