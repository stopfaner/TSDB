#include <iostream>
#include "core/metric/metric_manager.h"

using namespace std;

void test_db()
{

}


int main() {

    MetricManager* metric_manager = new MetricManager();
    metric_manager->insert_metric("testmetric", 24.2D);

    return 0;
}