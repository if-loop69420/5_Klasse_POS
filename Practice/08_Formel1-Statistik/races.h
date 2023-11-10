#ifndef _QX_FORMULA_ONE_RACE_H
#define _QX_FORMULA_ONE_RACE_H
#include <memory>
#include "export.h"
#include "precompiled.h"

class drivers;

class QX_FORMULA_ONE_DLL_EXPORT races {
public:
    typedef std::shared_ptr<drivers> driver_ptr;
    typedef qx::QxCollection<long, driver_ptr> list_driver;
    long r_id;
    QString r_name;

    list_driver r_driverX;
    races() : r_id(0) { ; }
    virtual ~races() { ; }
};

QX_REGISTER_PRIMARY_KEY(races,long)
QX_REGISTER_HPP_QX_FORMULA_ONE(races, qx::trait::no_base_class_defined, 0)

typedef std::shared_ptr<races> race_pointer;
typedef std::vector<race_pointer> list_races;

#endif // RACES_H
