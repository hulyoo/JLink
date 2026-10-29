#include "JLVector3D.h"
#include "math.h"
#include "DataDef.h"

JLVector3D::JLVector3D() noexcept
    :m_dX(0.0)
    ,m_dY(0.0)
    ,m_dZ(0.0)
{

}

JLVector3D::JLVector3D(double dX,double dY,double dZ) noexcept
    :m_dX(dX)
    ,m_dY(dY)
    ,m_dZ(dZ)
{

}

double JLVector3D::Module() const noexcept
{
    return sqrt(m_dX * m_dX + m_dY * m_dY + m_dZ * m_dZ);
}

double JLVector3D::InnerProduct(const JLVector3D& other) const noexcept
{
    return (m_dX * other.m_dX + m_dY * other.m_dY + m_dZ * other.m_dZ);
}

JLVector3D JLVector3D::Unitize() const noexcept
{

    double dModule = Module();
    return (*this / dModule);
}


JLVector3D JLVector3D::operator-() const noexcept
{
    return JLVector3D(-m_dX,-m_dY,-m_dZ);
}

JLVector3D& JLVector3D::operator+=(const JLVector3D& other) noexcept
{
    this->m_dX += other.m_dX;
    this->m_dY += other.m_dY;
    this->m_dZ += other.m_dZ;
    return *this;
}

JLVector3D& JLVector3D::operator-=(const JLVector3D& other) noexcept
{
    *this += (-other);
    return *this;
}

JLVector3D& JLVector3D::operator*=(const JLVector3D& other) noexcept
{
    this->m_dX *= other.m_dX;
    this->m_dY *= other.m_dY;
    this->m_dZ *= other.m_dZ;
    return *this;
}

JLVector3D& JLVector3D::operator*=(double dVal) noexcept
{
    m_dX *= dVal;
    m_dY *= dVal;
    m_dZ *= dVal;
    return *this;
}

JLVector3D& JLVector3D::operator/=(double dVal)
{
    m_dX /= dVal;
    m_dY /= dVal;
    m_dZ /= dVal;
    return *this;
}



bool operator==(const JLVector3D& lvec,const JLVector3D& rvec) noexcept
{
    return((lvec.GetX() == rvec.GetX()) && (lvec.GetY() == rvec.GetY()) 
    && (lvec.GetZ() == rvec.GetZ()));
}

bool operator!=(const JLVector3D& lvec,const JLVector3D& rvec) noexcept
{
    return true;
}

JLVector3D operator+(const JLVector3D& lvec,const JLVector3D& rvec) noexcept
{
    JLVector3D res;
    res.SetX(lvec.GetX() + rvec.GetX());
    res.SetY(lvec.GetY() + rvec.GetY());
    res.SetZ(lvec.GetZ() + rvec.GetZ());
    return res;
}

JLVector3D operator-(const JLVector3D& lvec,const JLVector3D& rvec) noexcept
{
    return lvec + (-rvec);
}

JLVector3D operator/(const JLVector3D& lvec,double dVal)
{
    
}

