#include "stdafx.h"
#include "vxdbcontorl.h"

#include <QSqlDatabase>
#include <QSqlQuery>

VxDBContorller::VxDBContorller( QObject *parent /*= 0*/ )
	:QObject(parent)
{
	m_dbPath = "./db.db";
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
		if (!query.exec("CREATE TABLE boy(id, name , age)"))
		{
			binit = false;
			qDebug() << "CREATE FAIL: " << db.lastError().text();
		}
	}

	if (!tables.contains(m_tbPlanRoute))
	{
		if (!query.exec("CREATE TABLE boy(id, name , age)"))
		{
			binit = false;
			qDebug() << "CREATE FAIL: " << db.lastError().text();
		}
	}

	if (!tables.contains(m_tbRouteInfo))
	{
		if (!query.exec("CREATE TABLE boy(id, name , age)"))
		{
			binit = false;
			qDebug() << "CREATE FAIL: " << db.lastError().text();
		}
	}

	if (!tables.contains(m_tbRouteRecord))
	{
		if (!query.exec("CREATE TABLE boy(id, name , age)"))
		{
			binit = false;
			qDebug() << "CREATE FAIL: " << db.lastError().text();
		}
	}

	if (!tables.contains(m_tbWarnningRecrod))
	{
		if (!query.exec("CREATE TABLE boy(id, name , age)"))
		{
			binit = false;
			qDebug() << "CREATE FAIL: " << db.lastError().text();
		}
	}


	return binit;
}

bool VxDBContorller::QuerySailMaps( CVxSailMapInfos &sailMapInfos )
{
	//for (int i = 0; i < 10000; ++i)
	//{
	//	query.prepare("INSERT INTO boy (id, name, age) "
	//		"VALUES (:id, :name, :age)");
	//	query.bindValue(0, 2+i);
	//	query.bindValue(1, "girl");

	//	query.bindValue(2, "bad");


	//	ok = query.exec();
	//	QString err = query.lastError().text();
	//	query.finish();
	//}


	QSqlQuery query;
	query.exec("SELECT * FROM boy");

	CVxSailMapInfo sailMapInfo;
	while (query.next())
	{
		sailMapInfo.id = query.value(0).toString();
	}
	//while (query.next())
	//{
	//	qDebug() << query.value(0).toInt() << " " << query.value(1).toString() << " " ;
	//	//QByteArray array = query.value(2).toByteArray();
	//	//ZBoy boyboy = query.value(2).value<ZBoy>();
	//	//ZBoy boyz;
	//	//QBuffer buf(&array);
	//	//buf.open(QIODevice::ReadOnly);
	//	//QDataStream stream(&buf);
	//	//stream >> boyz;
	//	//buf.close();

	//	//qDebug() << zboy.i << zboy.ch;
	//}

	//int size = query.size();
	//query.seek(1000);
	//qDebug() << query.value(0).toInt() << " " << query.value(1).toString() << " " ;
	//QSqlTableModel *mdel = new QSqlTableModel();
	////mdel->setQuery("SELECT * FROM boy");
	//mdel->setTable("boy");
	//mdel->setHeaderData(0, Qt::Horizontal, "id");
	//mdel->setHeaderData(1, Qt::Horizontal, "name");
	//mdel->setHeaderData(2, Qt::Horizontal, "age");
	//mdel->select();

	//QTableView *view = new QTableView;
	//view->setModel(mdel);
	//view->setSortingEnabled(true);
	//view->show();


	//QComboBox	*cmb = new QComboBox;
	//QLineEdit	*led = new QLineEdit;
	//QDataWidgetMapper	*mapper = new QDataWidgetMapper;
	//mapper->setModel(mdel);
	////mapper->addMapping(cmb,0 );
	//mapper->addMapping(led, 1);
	//mapper->toFirst();
	//cmb->setEditable(true);
	//cmb->setModel(mdel);
	//cmb->setModelColumn(1);
	//cmb->show();
	//led->show();

}
