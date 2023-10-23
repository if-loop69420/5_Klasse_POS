#ifndef _QX_FORMULA_ONE_DRIVER_H
#define _QX_FORMULA_ONE_DRIVER_H
#include <memory>
#include "export.h"
#include "precompiled.h"

class driver;

class QX_FORMULA_ONE_DLL_EXPORT driver {
public:
    typedef std::shared_ptr<driver> driver_ptr;
    typedef std::vector<driver_ptr> list_driver;
    long d_id;
    QString d_ref;
    QString d_num;
    QString d_code;
    QString d_forename;
    QString d_surname;
    QString d_dob;
    QString d_nation;
    QString d_url;

    list_driver d_driverX;
    driver() : d_id(0) { ; }
    virtual ~driver() { ; }
};

QX_REGISTER_PRIMARY_KEY(driver,long)
QX_REGISTER_HPP_QX_FORMULA_ONE(driver, qx::trait::no_base_class_defined, 0)


#endif // _QX_FORMULA_ONE_DRIVER_H
