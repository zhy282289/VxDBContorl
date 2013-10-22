#include "stdafx.h"
#include "vxdbcontorl.h"

#include <qtsql/qtsql>


VxDBContorller::VxDBContorller( QObject *parent /*= 0*/ )
	:QObject(parent)
{
	m_dbPath = "./db.db";

	m_tbSailMapInfo = "SailMapInfoTable";
	m_tbPlanRoute = "PlanRouteTable";
	m_tbRouteInfo = "RouteInfoTable";
	m_tbWarnningRecord = "WarningRecordTable";
}

bool VxDBContorller::InitDBEnvironment()
{
	//QApplication::addLibraryPath("D:\\Qt\\Qt4.8.1_win32\\plugins\\");
	//QStringList driverList = QSqlDatabase::drivers();

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(m_dbPath);
	if (!db.open())
	{
		return false;
	}

	bool binit = true;
	QSqlQuery query;
	QStringList tables = db.tables();
	if (!tables.contains(m_tbSailMapInfo))
	{
		if (!query.exec(QString("CREATE TABLE %1 (id, name, scale, baselatitude,style, postion1, postion2)").arg(m_tbSailMapInfo)))
		{
			binit = false;
			qDebug() << "CREATE FAIL: " << db.lastError().text();
		}
	}

	//if (!tables.contains(m_tbPlanRoute))
	//{
	//	if (!query.exec(QString("CREATE TABLE %1 (id, name , age)").arg(m_tbPlanRoute)))
	//	{
	//		binit = false;
	//		qDebug() << "CREATE FAIL: " << db.lastError().text();
	//	}
	//}

	//if (!tables.contains(m_tbRouteInfo))
	//{
	//	if (!query.exec(QString("CREATE TABLE %1 (id, name , age)").arg(m_tbRouteInfo)))
	//	{
	//		binit = false;
	//		qDebug() << "CREATE FAIL: " << db.lastError().text();
	//	}
	//}

	//if (!tables.contains(m_tbRouteRecord))
	//{
	//	if (!query.exec(QString("CREATE TABLE %1 (id, name , age)").arg(m_tbRouteRecord)))
	//	{
	//		binit = false;
	//		qDebug() << "CREATE FAIL: " << db.lastError().text();
	//	}
	//}

	//if (!tables.contains(m_tbWarnningRecord))
	//{
	//	if (!query.exec(QString("CREATE TABLE %1 (id, name , age)").arg(m_tbWarnningRecord)))
	//	{
	//		binit = false;
	//		qDebug() << "CREATE FAIL: " << db.lastError().text();
	//	}
	//}

	return binit;
}

bool VxDBContorller::QuerySailMaps( CVxSailMapInfos &sailMapInfos )
{
	QSqlQuery query;
	query.exec(QString("SELECT * FROM %1").arg(m_tbSailMapInfo));
	CVxSailMapInfo sailMapInfo;
	while (query.next())
	{
		sailMapInfo.id = query.value(0).toString();
		sailMapInfo.name = query.value(0).toString();
		sailMapInfo.scale = query.value(0).toString();
		sailMapInfo.baselatitude = query.value(0).toString();
		sailMapInfo.style = query.value(0).toString();
		sailMapInfo.postion1 = query.value(0).toString();
		sailMapInfo.postion2 = query.value(0).toString();
		sailMapInfos.push_back(sailMapInfo);
	}
	query.finish();
	return true;
}

bool VxDBContorller::InsertSailMap( const CVxSailMapInfo &sailMapInfo )
{
	QSqlQuery query;
	query.prepare(QString("INSERT INTO %1 (id, name, scale, baselatitude,style, postion1, postion2) "
							"VALUES (:id, :name, :scale, :baselatitude, :style, :postion1, :postion2)").arg(m_tbSailMapInfo));
	query.bindValue(0, sailMapInfo.id);
	query.bindValue(1, sailMapInfo.name);
	query.bindValue(2, sailMapInfo.scale);
	query.bindValue(3, sailMapInfo.baselatitude);
	query.bindValue(4, sailMapInfo.style);
	query.bindValue(5, sailMapInfo.postion1);
	query.bindValue(6, sailMapInfo.postion2);
	bool ret = query.exec();
	query.finish();

	return ret;
}

bool VxDBContorller::DeleteSailMap( QString id )
{
	QSqlQuery query;
	bool ret = query.exec(QString("DELETE FROM %1 WHERE id=%2").arg(m_tbSailMapInfo, id));

	qDebug() << query.lastError().text();
	return ret;
}

bool VxDBContorller::UpdateSailMap( const CVxSailMapInfo &sailMapInfo )
{
	QSqlQuery query;
	//bool ret = query.exec(QString("UPDATE %1 SET name=%2, scale=%3, baselatitude=%4, style=%5, postion1=%6, postion2=%7 "
	//				"WHERE id=%8").arg(m_tbSailMapInfo, sailMapInfo.name, sailMapInfo.scale, sailMapInfo.baselatitude, 
	//				sailMapInfo.style,sailMapInfo.postion1, sailMapInfo.postion2, sailMapInfo.id));
	//bool ret = query.exec(QString("UPDATE %1 SET name=%2 WHERE id=%3").arg(m_tbSailMapInfo, sailMapInfo.name,  sailMapInfo.id));
	query.prepare(QString("UPDATE %1 SET name=%2 WHERE id=%3").arg(m_tbSailMapInfo, sailMapInfo.name, sailMapInfo.id));
	bool ret = query.exec();
	qDebug() << query.lastError().text();
	return ret;
}
