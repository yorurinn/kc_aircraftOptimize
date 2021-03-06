#include "core.h"

using namespace std;

void core_initialization(){
    //initialize category map
    for(int i=0;i<PLANE_CATE_NUM;i++)
        plane_cate_m[PLANE_CATE_NAME[i]]=i;
    for(int i=0;i<CARRIER_CATE_NUM;i++)
        carrier_cate_m[CARRIER_CATE_NAME[i]]=i;

    //read preset data
    planes.push_back(Plane());//UNDEFINE_PLANE
    read_planes(planes_tot,planes,planes_m);

    carriers.push_back(Carrier());//UNDEFINE_CARRIER
    read_carriers(carriers_tot,carriers,carriers_m);
}

stringstream &core_query(stringstream &st){
    cal_dataReady(st);
    if(cal_run())
        return cal_get_res();
    else return *(new stringstream());
}
