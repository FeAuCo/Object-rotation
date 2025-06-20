#include "quaternion.h"

typedef obj_r::Quaternion quaternion;
typedef obj_r::ImaginaryUnit imUnit;

const std::map<std::string, std::string> obj_r::i_row = {{"i", "-1"}, {"j", "k"}, {"k", "-j"}};
const std::map<std::string, std::string> obj_r::j_row = {{"i", "-k"}, {"j", "-1"}, {"k", "i"}};
const std::map<std::string, std::string> obj_r::k_row = {{"i", "j"}, {"j", "-i"}, {"k", "-1"}};

const std::map<std::string, const std::map<std::string, std::string>> obj_r::TABLE  = {{"i", obj_r::i_row}, {"j", obj_r::j_row}, {"k", obj_r::k_row}};

quaternion::Quaternion(const double& a, const double& b, const double&  c, const double& d)
    : a(a), b(b), c(c), d(d)
{}

double quaternion::getA(){
    return this->a;
}

double quaternion::getB(){
    return this->b;
}

double quaternion::getC(){
    return this->c;
}

double quaternion::getD(){
    return this->d;
}

void quaternion::setA(const double& new_a){
    this->a = new_a;
}

void quaternion::setB(const double& new_b){
    this->b = new_b;
}

void quaternion::setC(const double& new_c){
    this->c = new_c;
}

void quaternion::setD(const double& new_d){
this->d = new_d;
}

double quaternion::getAbs(){
    return sqrt((this->a) * (this->a) + (this->b) * (this->b) + (this->c) * (this->c) + (this->d) * (this->d));
}

quaternion quaternion::conjugate(){
    return quaternion(this->a, this->b * (-1), this->c * (-1), this->d * (-1));
}
//-------
quaternion quaternion::operator*(const quaternion& other){
    std::string this_q = std::to_string(this->getA()
);

    return quaternion(0, 0, 0, 0);
}
//-------

imUnit::ImaginaryUnit(const std::string& unit)
    : unit(unit)
{}

imUnit  imUnit::operator*(imUnit& other){
    return imUnit((obj_r::TABLE.at(this->unit)).at(other.unit));
}

quaternion getQ(const double& x, const double& y, const double& z, const double& w){
    return quaternion(cos(w/2), sin(w/2) * x, sin(w/2) * y, sin(w/2) * z);
}

quaternion getH(const double& x, const double& y, const double& z){
    return quaternion(0 , x, y, z);
}
//-------
// quaternion rotate(const quaternion& q, const quaternion& h){
//     return q * h * q.conjugate();
// }
//-------
