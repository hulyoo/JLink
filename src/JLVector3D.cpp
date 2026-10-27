#include "JLVector3D.h"
#include "math.h"

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

double JLVector3D::Module() noexcept
{
    return sqrt(m_dX * m_dX + m_dY * m_dY + m_dZ * m_dZ);
}

double JLVector3D::InnerProduct(const JLVector3D& other) noexcept
{

}


bool operator==(const JLVector3D& lvec,const JLVector3D& rvec) noexcept
{
    return((lvec.GetX() == rvec.GetX()) && (lvec.GetY() == rvec.GetY()) 
    && (lvec.GetZ() == rvec.GetZ()));
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
}