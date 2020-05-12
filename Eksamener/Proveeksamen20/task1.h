#include <cmath>
#include <ostream>

class Vector2d{
    public:
        double x;
        double y;
        Vector2d(double xx, double yy) : x{xx}, y{yy} {}
        double length();
        friend Vector2d operator+(const Vector2d& lhs, const Vector2d& rhs);
        friend Vector2d operator*(const Vector2d& vv, const double k);
        friend std::ostream & operator<<(std::ostream& out, const Vector2d& v);
};