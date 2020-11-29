#ifndef POINT_H
#define POINT_H


class Point
{
private:
    double x{0};
    double y{0};
public:
    Point() = delete;
    Point(double X, double Y);
    double getX() const;
    double getY() const;
};

#endif // POINT_H
