#pragma once

#include <cmath>
#include <map>
#include <string>

namespace obj_r{
    extern const std::map<std::string, std::string> i_row, j_row, k_row;
    extern const std::map<std::string, const std::map<std::string, std::string>> TABLE;

    class ImaginaryUnit{
        public:
            std::string unit;

            ImaginaryUnit(const std::string& unit);

            ImaginaryUnit operator*(ImaginaryUnit& other); 
    };

    class Quaternion{
        private:
            double a, b, c, d;

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

            Quaternion conjugate();

            Quaternion operator*(const Quaternion& other);
    };

    Quaternion getQ(const double& x, const double& y, const double& z, const double& w);

    Quaternion getH(const double& x, const double& y, const double& z);

    Quaternion rotate(const Quaternion& q, const Quaternion& h);
}
