#include "races.h"
#include "driver.h"

#include <QxOrm_Impl.h>

QX_REGISTER_CPP_QX_FORMULA_ONE(races)

namespace qx {
template <> void register_class(QxClass<races> & t)
{
    t.id(& races::r_id, "raceId");
    t.data(& races::r_name, "name");

    t.relationManyToMany(& races::r_driverX, "list_driver", "result", "raceId", "driverId");
}}
