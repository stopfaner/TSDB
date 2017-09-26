#include <iostream>
#include "core/metric/metric_manager.h"

using namespace std;



int main() {

    MetricManager* metric_manager = new MetricManager();
    MetricData data(255.5);

    metric_manager->insert_metric("datalife", data);

    return 0;
}