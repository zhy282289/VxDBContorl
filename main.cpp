#include "stdafx.h"
#include "vxdbcontorl.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//VxDBContorl w;
	//w.show();


	VxDBContorller DBController;
	if(!DBController.InitDBEnvironment())
	{
		return -1;
	}

	CVxSailMapInfo sailmapInfo;
	sailmapInfo.id = "1";
	sailmapInfo.name = "2";
	sailmapInfo.scale = "3";
	sailmapInfo.baselatitude = "4";
	sailmapInfo.style = "5";
	sailmapInfo.postion1 = "6";
	sailmapInfo.postion2 = "7";
	DBController.InsertSailMap(sailmapInfo);

	CVxSailMapInfos sailmapInfos;
	DBController.QuerySailMaps(sailmapInfos);

	sailmapInfo.name = "boy";
	DBController.UpdateSailMap(sailmapInfo);

	CVxSailMapInfos sailmapInfos2;
	DBController.QuerySailMaps(sailmapInfos2);

	DBController.DeleteSailMap("1");

	CVxSailMapInfos sailmapInfos3;
	DBController.QuerySailMaps(sailmapInfos3);

	return a.exec();
}
