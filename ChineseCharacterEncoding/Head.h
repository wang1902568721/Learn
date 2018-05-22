#pragma once
#include <vector>
using namespace std;

typedef struct _RegionData
{
	unsigned char ucRegionType;
	unsigned char ucRegionXCoordinate[2];
	unsigned char ucRegionYCoordinate[2];
	unsigned char ucRegionWidth[2];
	unsigned char ucRegionHeight[2];
	unsigned char ucRegionNo;
	unsigned char ucRowInterval;
	unsigned char ucRunMode;
	unsigned char ucExporedTime[2];
	unsigned char ucReserved[3];
	unsigned char ucIsSingleLine;
	unsigned char ucAutoNewLine;
	unsigned char ucShowType;
	unsigned char ucExitType;
	unsigned char ucShowSpeed;
	unsigned char ucLeaveTime;
	unsigned char ucDataLength[4];
	vector<unsigned char> vShowText;
}ST_RegionData;

//��������
typedef struct _CommandData
{
	unsigned char ucCommandGroupNo;
	unsigned char ucCommandNo;
	unsigned char ucControllerMustAck;
	unsigned char ucReserved[2];
	unsigned char ucNumberOfDelRegion;
	unsigned char ucNumberOfUpdateRegion;
	unsigned char ucRegionLength[2];
	vector<unsigned char> ucRegionData;
}ST_CommandData;

//֡����
typedef struct _Frame
{
	unsigned char ucScreenAddr[2];
	unsigned char ucSrcAddr[2];
	unsigned char ucReserved[5];
	unsigned char ucShowModel;
	unsigned char ucDevType;
	unsigned char ucProtocolVersion;
	unsigned char ucDataLength[2];
	vector<unsigned char> vCommandData;
}ST_FrameData;

//����������
typedef struct _PACKAGE
{
	unsigned char ucFrameHead[8];
	vector<unsigned char> vFrameData;
	unsigned char ucCRC[2];
	unsigned char ucFrameTail;
}ST_Package;