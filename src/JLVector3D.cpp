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
