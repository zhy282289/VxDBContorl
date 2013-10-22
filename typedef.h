#pragma once

#include <qlist>
// 海图信息  
struct CVxSailMapInfo
{
	QString id;				//图号
	QString name;			//图名
	QString scale;			//比例尺
	QString baselatitude;	//基准纬度
	QString	style;			//投影方式
	QString postion1;		//位置1
	QString postion2;		//位置2
};
typedef QList<CVxSailMapInfo> CVxSailMapInfos;
// 计划般线  
struct CVxPlanRoute
{
	QString id;				//序号
	QString name;			//航线名
	QString startpostion;	//起点位置
	QString endpostion;		//终点位置
	QString sections;		//航段数
	QString type;			//类型
	QString sumbittime;		//提交时间
};
// 航线信息  
struct CVxRouteInfo
{

	QString id;				//序号
	QString longitude;		//经度
	QString latitude;		//纬度
	QString speed;			//航速
	QString direction;		//方位
	QString distance;		//距离
	QString totaldistance;	//总距离
	QString warning;		//偏航报警
	QString time;			//时间
	QString totaltime;		//总时间
};

// 航线记录
struct CVxRouteRecord
{
	QString time;			//时间
	QString latitude;		//纬度
	QString longitude;		//经度
	//QString				//航向
	QString speed;			//航速
	//QString				//航迹向
	//QString				//地速
	//QString				//流向
	//QString				//流速
	//QString				//风向
};

// 报警信息
struct CVxWarnningRecrod
{
	QString desc;			//报警内容
	QString time;			//报警时间
	QString duration;		//持续时间
};