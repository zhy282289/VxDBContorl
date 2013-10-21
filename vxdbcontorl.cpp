#include "stdafx.h"
#include "vxdbcontorl.h"

#include <QSqlDatabase>

VxDBContorller::VxDBContorller( QObject *parent /*= 0*/ )
	:QObject(parent)
{
	m_dbPath = "./db.db";
}

bool VxDBContorller::InitDBEnvironment()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("qsplite");
	db.setDatabaseName(m_dbPath);
	if (!db.open())
	{
		return false;
	}

	QStringList tbList = db.tables();
	if (!tbList.contains(m_tbSailMapInfo))
	{

	}

	if (!tbList.contains(m_tbPlanRoute))
	{

	}

	if (!tbList.contains(m_tbRouteInfo))
	{

	}

	if (!tbList.contains(m_tbRouteRecord))
	{

	}

	if (!tbList.contains(m_tbWarnningRecrod))
	{

	}


	return true;
}
