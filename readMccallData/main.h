#include <string>
#include <iostream>

using namespace std;

typedef struct {
    string name;
    float T;
    float t1;
    float t1Error;
    float xSheet;
    float xSheetError;
    float mks;
    float mksError;
    float logMstars;
    float logMstarsError;
    float vFlat;
    float vFlatError;
    float lSheet;
    float vSun;
    float vSunError;
    float DM;
    float DMError;
    float ySheet;
    float ySheetError;
    float mv;
    float mvError;
    float i;
    float iError;
    float lSheetAM;
    float lSheetAMError;
    float bSheet;
    float vLG;
    float vLGError;
    string method;
    float zSheet;
    float zSheetError;
    float b_v;
    float b_vError;
    float PA;
    float PAError;
    float bSheetAM;
    float bSheetAMError;
    
    
}galaxy;

typedef struct{
    galaxy *galxies;
    int num_galaxies;
}galaxy_list;
