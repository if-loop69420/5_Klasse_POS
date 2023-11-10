#ifndef RESULTS_H
#define RESULTS_H
#include <memory>
#include <vector>


class races;
class drivers;

class QX_FORMULA_ONE_DLL_EXPORT results {
public:
    long r_id;
    long r_number;
    long r_grid;
    long r_position;
    long r_points;
};

QX_REGISTER_PRIMARY_KEY(results, long);
QX_REGISTER_HPP_QX_FORMULA_ONE(results, qx::trait::no_base_class_defined, 0);

typedef std::shared_ptr<results> result_ptr;
typedef std::vector<result_ptr> list_results;

#endif // RESULTS_H
