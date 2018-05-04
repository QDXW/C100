/*
 * Signalprocess.h
 *
 *  Created on: 2018Äê4ÔÂ4ÈÕ
 *      Author: Administrator
 */

#ifndef MANAGEMENT_SIGNALPROCESS_SIGNALPROCESS_H_
#define MANAGEMENT_SIGNALPROCESS_SIGNALPROCESS_H_

/******************************************************************************/
#include "comDef.h"
#include "stm32f10x.h"

/******************************************************************************/
#define SIGNALPROCESS_RESULT_INVALID_C		(0)

/******************************************************************************/
uint16 arrayXFit[20] = {0};
uint16 arrayYFit[20] = {0};
uint16 sizeFit = 0;
uint8 fitArraySize = 0;
uint8 validity = 0;

/******************************************************************************/
/* Signal calcInfo */
typedef struct {
	uint16 indexC; 			/* indexC */
	uint8  result; 			/* result */
	uint16 indexT; 			/* indexT */
	uint16 base1;			/* base1 */
	uint16 base2;			/* base2 */
	uint16 base3;			/* base3 */
	uint16 base4;			/* base4 */
	float coefA;			/* coefA */
	float coefB;			/* coefB */
	uint32 areaC;			/* areaC */
	uint32 areaT;			/* areaT */
	float ratioC_T;			/* ratioC_T */
} SIGNALl_CALCINFO;

/******************************************************************************/
/* Signal posInfo */
typedef struct {
	uint16 dist_Edge_Center; 			/* dist_Edge_Center */
	uint16 dist_Ccenter_T1center; 		/* dist_Ccenter_T1center */
	uint16 dist_Ccenter_Peak1; 			/* dist_Ccenter_Peak1 */
	uint16 dist_Ccenter_Peak2;			/* dist_Ccenter_Peak2 */
	uint16 dist_Ccenter_Peak3;			/* dist_Ccenter_Peak3 */
	uint16 dist_Ccenter_Peak4;			/* dist_Ccenter_Peak4 */
} SIGNALl_POSINFO;

/******************************************************************************/
/* Signal limitInfo */
typedef struct {
	uint16 C_MIN; 						/* processLength */
} SIGNALl_LIMITINFO;

/******************************************************************************/
/* Signal Data */
typedef struct {
	uint16 processBuffer[512]; 			/* processBuffer */
	SIGNALl_POSINFO posInfo;
	SIGNALl_CALCINFO calcInfo;
	SIGNALl_LIMITINFO limitInfo;
	uint16 sampleLength; 				/* sampleLength */
	uint16 processLength; 				/* processLength */
} SIGNALl_DATA;

/******************************************************************************/
SIGNALl_DATA SignalProcess_Alg_data;

/******************************************************************************/
/* Calculate concentration value */
//SignalProcess_IdentifyResult(twoTs, crp_2t, fenjiedian);
void Data_Analysis(void);
uint16 Alg_GetMin(uint16 *src, uint16 count);
uint16 Alg_GetMax(uint16 *src, uint16 count);
uint16 Alg_WindowAverage(uint16 *src, uint16 count, uint8 winSize);
uint16 Alg_GetValleyIndex(uint16 *src, uint16 startIndex, uint16 endIndex);
uint8 Alg_JudgeCValidity(uint16 *src, uint16 index, uint16 stepSize, uint16 INC);
void Alg_FittingLine(uint16 arrayX[], uint16 arrayY[], uint16 size,
		float *coefA, float *coefB);
uint16 Alg_MoveToFitArray(uint16 dataArray[], uint16 midIndex, uint16 *xPtr,
		uint16 *yPtr, uint16 curSize);
float Alg_CalcualteArea(uint16 src[], uint16 midIndex, uint16 halfWidth,
		float *coefA, float *coefB);

#endif /* MANAGEMENT_SIGNALPROCESS_SIGNALPROCESS_H_ */
