#include "task1.h"
#include "std_lib_facilities.h" //1f ++
#include <algorithm>


double Vector2d::length(){
    return sqrt(x*x+y*y);
}

Vector2d operator+(const Vector2d& lhs, const Vector2d& rhs){
    Vector2d addedV = Vector2d(lhs.x+rhs.x, lhs.y+rhs.y);
    return addedV;
}

Vector2d operator*(const Vector2d& vv, const double k){
    return Vector2d(k*vv.x, k*vv.y);
}

std::ostream & operator<<(std::ostream& out, const Vector2d& v){
    out << '[' << v.x << ',' << v.y << ']';
    return out;
}
Vector2d vectorSum(const vector<Vector2d>& vectors){
    double sumX = 0;
    double sumY = 0;
    for (auto v : vectors){
        sumX+=v.x;
        sumY+=v.y;
    }
    return Vector2d(sumX, sumY);
}

void trackStats(const vector<Vector2d>& track){
    double tLen = 0;
    double maxSpeed = 0;
    double endX = 0;
    double endY = 0;
    for(auto v : track){
        tLen += v.length();
        endX += v.x;
        endY += v.y;
        //sorry suger i fysikk men hastigheten er vel v.length()?
        if(v.length>maxSpeed){maxSpeed=v.length;}
    }
    maxSpeed *= 100; //convert to m/min
    Vector2d endV = Vector2d(endX, endY);
    cout << "Length: " << fixed << setprecision(2) << tLen << "km, "
    << "max-speed: " << maxSpeed << " m/min, "
    << "ended at " << endV << endl;
}

void cleanTrack(vector<Vector2d>& track){
    std::tranform(track.begin(), track.end(), track.begin(), //vet ikke hvorfor denne ikke kjenner igjen transform men jaja
    [](Vector2d t) -> Vector2d {return Vector2d(0,0);});
}