#pragma once

class JLVector3D
{
public:
    JLVector3D() noexcept;
    JLVector3D(double dX,double dY,double dZ) noexcept;
    ~JLVector3D() = default;

    double Module() noexcept;
private:
    double m_dX;
    double m_dY;
    double m_dZ;
};