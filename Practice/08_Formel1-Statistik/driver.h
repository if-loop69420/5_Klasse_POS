#ifndef _QX_FORMULA_ONE_DRIVER_H
#define _QX_FORMULA_ONE_DRIVER_H
#include <memory>
#include "export.h"
#include "precompiled.h"

class driver;

class QX_FORMULA_ONE_DLL_EXPORT drivers {
public:
    typedef std::shared_ptr<driver> driver_ptr;
    typedef std::vector<driver_ptr> list_drivers;
    long d_id;
    QString d_ref;
    QString d_num;
    QString d_code;
    QString d_forename;
    QString d_surname;
    QString d_dob;
    QString d_nation;
    QString d_url;

    list_drivers d_driverX;
    drivers() : d_id(0) { ; }
    virtual ~drivers() { ; }
};

QX_REGISTER_PRIMARY_KEY(drivers,long)
QX_REGISTER_HPP_QX_FORMULA_ONE(drivers, qx::trait::no_base_class_defined, 0)


#endif // _QX_FORMULA_ONE_DRIVER_H
