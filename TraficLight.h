#ifndef TP5_TRAFICLIGHT_H
#define TP5_TRAFICLIGHT_H

#include <iostream>

enum class SignalColor {
    RED,
    YELLOW,
    GREEN
};

class TraficLight {
private:
    SignalColor color;
public:

    TraficLight(SignalColor color);

    void changeColor();
    SignalColor getColor() const;
    void setColor(SignalColor color);

    void print();
};


#endif //TP5_TRAFICLIGHT_H
