#ifndef VXDBCONTORL_H
#define VXDBCONTORL_H

#include <QObject>

/* ��Ҫ���ĸ���, ��ͼ��, ���߱�, ���߼�¼��, ���߱�����, 
*  �����Ƕ����ݿ����Ҫ�����ӿ�
*/

class VxDBContorller : public QObject
{
	Q_OBJECT
public:
	
	VxDBContorller(QObject *parent = 0);

	bool InitDBEnvironment(); // ��ʼ�����ݿ⻷��


	/*
	* ��ȡ��ͼ��ϸ��Ϣ
	*/
	bool QuerySailMaps(CVxSailMapInfos &sailMapInfos); //��ͼװ��-��ȡ	
	bool InsertSailMap(const CVxSailMapInfo &sailMapInfo); //��ͼװ��-����	
	bool DeleteSailMap(QString id); //��ͼװ��-ɾ��	
	bool UpdateSailMap(const CVxSailMapInfo &sailMapInfo); //��ͼװ��-�޸�

	/*
	* ͨ����ͼ�Ż�ȡ���ߵ���ϸ��Ϣ
	*/
	bool QuerySailInfo(); //������Ϣ-��ȡ
	bool InsertSailInfo();	//������Ϣ-����
	bool DeleteSailInfo();	//������Ϣ-ɾ��
	bool UpdateSailInfo();	//������Ϣ-�޸�


	/*
	* ��ȡ���м�¼��Ϣ
	*/
	bool QuerySailRecords(); //���м�¼��Ϣ-��ȡ
	bool InsertSailRecord();	//���м�¼��Ϣ-����
	bool DeleteSailRecord();	//���м�¼��Ϣ-ɾ��


	/*
	* ���б�����Ϣ
	*/
	bool QuerySailWarningRecords(); //���б�����Ϣ-��ȡ
	bool InsertSailWarningRecord();	//���б�����Ϣ-����
	bool DeleteSailWarningRecord();	//���б�����Ϣ-ɾ��

	/*
	* �û�����
	*/
	void QueryUserPassword();	//�û�����-��ȡ
	void UpdataUserPassword();	//�û�����-�޸�


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
