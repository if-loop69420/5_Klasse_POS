#include "results.h"
#include "races.h"
#include "driver.h"
#include <QxOrm_Impl.h>

QX_REGISTER_CPP_QX_FORMULA_ONE(results)

namespace qx{
template <> void register_class(QxClass<results> & t){
    long r_id;
    long r_number;
    long r_grid;
    long r_position;
    long r_points;

    t.id(&results::r_id, "resultId");
    t.data(&results::r_number, "number");
    t.data(&results::r_grid, "grid");
    t.data(&results::r_position, "position");
    t.data(&results::r_points,"points");
}
}
