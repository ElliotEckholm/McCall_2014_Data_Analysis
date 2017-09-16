#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <cstring>


//Local includes
#include "main.h"
#include "readWriteHeader.h"

//Function prototypes
void loadMccallData(char *fn);

//Using namespace
using namespace std;

//Globals
vector<galaxy> galaxyList;
galaxy_list mccallList;

int main(int argc, char * argv[]){
    
    loadMccallData("McCallData.txt");
    
   
    printf("%f\n", galaxyList[59].bSheetAMError);
    
    
    
    //writeBinaryFile1D("mcCallData.bin", mccallList.galxies, mccallList.num_galaxies);
    
    return 0;
}



/*
 void loadMccallData(char *fn){
	int i, j = 0;
	char buffer[4000];
	FILE *input;
	galaxy g;
 
	int CHUNK_SIZE = 1000000;
 
	//mccallList.galxies = (galaxy *)realloc(mccallList.galxies, sizeof(galaxy)*(CHUNK_SIZE));
 
	fopen_s(&input, fn, "r");
	if (!input) {
 printf("Failed to open file %s for reading!\n", fn);
 exit(1);
	}
 
	while (fgets(buffer, 4000, input)) {
 
 if (j % CHUNK_SIZE == 0) {
 mccallList.galxies = (galaxy *)realloc(mccallList.galxies, sizeof(galaxy)*(CHUNK_SIZE*(1+(j/CHUNK_SIZE))));
 }
 
 
 i = sscanf_s(buffer, "%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f",
 &(g.T),  &(g.t1),
 &(g.xSheet), &(g.mks), &(g.logMstars),
 &(g.vFlat), &(g.lSheet), &(g.vSun),
 &(g.DM), &(g.ySheet), &(g.mv),
 &(g.i), &(g.lSheetAM), &(g.bSheet),
 &(g.vLG), &(g.zSheet),
 &(g.b_v), &(g.PA), &(g.bSheetAM));
 if (i<20) {
 printf("Couldn't parse line!\n%s\n", buffer);
 continue;
 }
 mccallList.galxies[j] = g;
 j++;
	}
 
	mccallList.num_galaxies = j;
	
	
 
	printf("McCall read complete");
 
 
	fclose(input);
 
 }
 */

void loadMccallData(char *fn){
	
    string name;
    string T;
    string t1;
    string t1Error;
    string xSheet;
    string xSheetError;
    string mks;
    string mksError;
    string logMstars;
    string logMstarsError;
    string vFlat;
    string vFlatError;
    string lSheet;
    string vSun;
    string vSunError;
    string DM;
    string DMError;
    string ySheet;
    string ySheetError;
    string mv;
    string mvError;
    string i;
    string iError;
    string lSheetAM;
    string lSheetAMError;
    string bSheet;
    string vLG;
    string vLGError;
    string method;
    string zSheet;
    string zSheetError;
    string b_v;
    string b_vError;
    string PA;
    string PAError;
    string bSheetAM;
    string bSheetAMError;

 
    
	ifstream galaxyFile(fn);
 
	if (!galaxyFile){
        printf("Cannot open Galaxy File");
	}
    
	while (galaxyFile >> name >> T >> t1 >> t1Error >> xSheet >> xSheetError >>mks >> mksError
           >> logMstars >> logMstarsError >> vFlat >> vFlatError >>lSheet
           >> vSun >> vSunError >> DM >> DMError >> ySheet >> ySheetError
           >> mv >> mvError >> i >> iError >> lSheetAM >> lSheetAMError
           >> bSheet >> vLG >> vLGError >> method >> zSheet >> zSheetError >> b_v >> b_vError
           >> PA >> PAError >> bSheetAM >> bSheetAMError){
 
        galaxy currentGalaxy;
        currentGalaxy.name = name;
        currentGalaxy.T = atof(T.c_str());
        currentGalaxy.t1 = atof(t1.c_str());
        currentGalaxy.t1Error = atof(t1Error.c_str());
        currentGalaxy.xSheet = atof(xSheet.c_str());
        currentGalaxy.xSheetError = atof(xSheetError.c_str());
        currentGalaxy.mks = atof(mks.c_str());
        currentGalaxy.mksError = atof(mksError.c_str());
        currentGalaxy.logMstars = atof(logMstars.c_str());
        currentGalaxy.logMstarsError = atof(logMstarsError.c_str());
        currentGalaxy.vFlat = atof(vFlat.c_str());
        currentGalaxy.vFlatError = atof(vFlatError.c_str());
        currentGalaxy.lSheet = atof(lSheet.c_str());
        currentGalaxy.vSun = atof(vSun.c_str());
        currentGalaxy.vSunError = atof(vSunError.c_str());
        currentGalaxy.DM = atof(DM.c_str());
        currentGalaxy.DMError = atof(DMError.c_str());
        currentGalaxy.ySheet = atof(ySheet.c_str());
        currentGalaxy.ySheetError = atof(ySheetError.c_str());
        currentGalaxy.mv = atof(mv.c_str());
        currentGalaxy.mvError = atof(mvError.c_str());
        currentGalaxy.i = atof(i.c_str());
        currentGalaxy.iError = atof(iError.c_str());
        currentGalaxy.lSheetAM = atof(lSheetAM.c_str());
        currentGalaxy.lSheetAMError = atof(lSheetAMError.c_str());
        currentGalaxy.bSheet = atof(bSheet.c_str());
        currentGalaxy.vLG = atof(vLG.c_str());
        currentGalaxy.vLGError = atof(vLGError.c_str());
        currentGalaxy.method = method;
        currentGalaxy.zSheet = atof(zSheet.c_str());
        currentGalaxy.zSheetError = atof(zSheetError.c_str());
        currentGalaxy.b_v = atof(b_v.c_str());
        currentGalaxy.b_vError = atof(b_vError.c_str());
        currentGalaxy.PA = atof(PA.c_str());
        currentGalaxy.PAError = atof(PAError.c_str());
        currentGalaxy.bSheetAM = atof(bSheetAM.c_str());
        currentGalaxy.bSheetAMError = atof(bSheetAMError.c_str());
        
       // printf("\n%f\n", currentGalaxy.bSheetAMError);
        
        galaxyList.push_back(currentGalaxy);
        
        
	}
   
 
 }
