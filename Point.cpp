//
// Created by klara on 22.08.2023.
//
#include "Point.h"
#include <stdexcept>

Point::Point(Matrix m) {
    if(m.getWidth() != 1 || m.getHeight() < 2 || m.getHeight() > 4){
        throw std::domain_error("Incomptible dimensions.");
    }
    x = m.getValueAt(0, 0);
    y = m.getValueAt(1, 0);
    z = m.getHeight() < 3 ? 0 : m.getValueAt(2, 0);
}
