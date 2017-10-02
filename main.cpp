
// include headers that implement a archive in simple text format
#include <fstream>
#include <iostream>
#include "core/types/field_time.h"
#include "core/types/field_uuid.h"
#include "core/types/field_name.h"
#include "core/types/field_metric.h"
#include "core/metric_engine/metric_manager.h"

using namespace std;


int main() {

    MetricManager* manager = new MetricManager();
// for sample only
//    for (auto& t : *manager->get_loaded_map())
//    {
//        cout <<"OLD" << t.second.get_metric_field()->get_metric_name() << endl;
//    }


    return 0;
}