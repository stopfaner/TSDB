#include <iostream>
#include "core/metric/metric_manager.h"

using namespace std;



int main() {

    MetricManager* metric_manager = new MetricManager();
    metric_manager->create_metric("ctest42");

    return 0;
}