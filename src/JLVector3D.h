#pragma once

class JLVector3D
{
public:
    JLVector3D() noexcept;
    JLVector3D(double dX,double dY,double dZ) noexcept;
    ~JLVector3D() = default;


    double GetX() const noexcept {return m_dX;}
    double GetY() const noexcept {return m_dY;}
    double GetZ() const noexcept {return m_dZ;}

    void SetX(double dX) noexcept {m_dX = dX;}
    void SetY(double dY) noexcept {m_dY = dY;}
    void SetZ(double dZ) noexcept {m_dZ = dZ;}

    double Module() const noexcept;
    double InnerProduct(const JLVector3D& other) const noexcept;
    JLVector3D Unitize() const noexcept;

    JLVector3D operator-() const noexcept;

    JLVector3D& operator+=(const JLVector3D& other) noexcept;
    JLVector3D& operator-=(const JLVector3D& other) noexcept;
    JLVector3D& operator*=(const JLVector3D& other) noexcept;
    JLVector3D& operator*=(double dVal) noexcept;
    JLVector3D& operator/=(double dVal);

    friend JLVector3D operator+(const JLVector3D& lvec,const JLVector3D& rvec) noexcept;
    friend JLVector3D operator-(const JLVector3D& lvec,const JLVector3D& rvec) noexcept;
    friend JLVector3D operator*(const JLVector3D& lvec,double dVal) noexcept;
    friend JLVector3D operator*(double dVal,const JLVector3D& rvec) noexcept;
    friend JLVector3D operator/(const JLVector3D& lvec,double dVal);
private:
    double m_dX;
    double m_dY;
    double m_dZ;
};


bool operator==(const JLVector3D& lvec,const JLVector3D& rvec) noexcept;
bool operator!=(const JLVector3D& lvec,const JLVector3D& rvec) noexcept;
