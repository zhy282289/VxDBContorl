#ifndef VXDBCONTORL_H
#define VXDBCONTORL_H

#include <QObject>

/* 主要有四个表, 海图表, 航线表, 航线记录表, 航线报警表, 
*  下面是对数据库的主要操作接口
*/

class VxDBContorller : public QObject
{
	Q_OBJECT
public:
	
	VxDBContorller(QObject *parent = 0);

	bool InitDBEnvironment(); // 初始化数据库环境


	/*
	* 获取海图详细信息
	*/
	bool QuerySailMaps(CVxSailMapInfos &sailMapInfos); //海图装订-读取	
	bool InsertSailMap(const CVxSailMapInfo &sailMapInfo); //海图装订-插入	
	bool DeleteSailMap(QString id); //海图装订-删除	
	bool UpdateSailMap(const CVxSailMapInfo &sailMapInfo); //海图装订-修改

	/*
	* 通过海图号获取航线的详细信息
	*/
	bool QuerySailInfo(); //航线信息-读取
	bool InsertSailInfo();	//航线信息-插入
	bool DeleteSailInfo();	//航线信息-删除
	bool UpdateSailInfo();	//航线信息-修改


	/*
	* 获取航行记录信息
	*/
	bool QuerySailRecords(); //航行记录信息-读取
	bool InsertSailRecord();	//航行记录信息-插入
	bool DeleteSailRecord();	//航行记录信息-删除


	/*
	* 航行报警信息
	*/
	bool QuerySailWarningRecords(); //航行报警信息-读取
	bool InsertSailWarningRecord();	//航行报警信息-插入
	bool DeleteSailWarningRecord();	//航行报警信息-删除

	/*
	* 用户密码
	*/
	void QueryUserPassword();	//用户密码-读取
	void UpdataUserPassword();	//用户密码-修改


private:


private:
	QString			m_dbPath;
	QString			m_tbSailMapInfo;
	QString			m_tbPlanRoute;
	QString			m_tbRouteInfo;
	QString			m_tbRouteRecord;
	QString			m_tbWarnningRecord;
};





#endif // VXDBCONTORL_H
