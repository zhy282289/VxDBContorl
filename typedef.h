#pragma once

#include <qlist>
// ��ͼ��Ϣ  
struct CVxSailMapInfo
{
	QString id;				//ͼ��
	QString name;			//ͼ��
	QString scale;			//������
	QString baselatitude;	//��׼γ��
	QString	style;			//ͶӰ��ʽ
	QString postion1;		//λ��1
	QString postion2;		//λ��2
};
typedef QList<CVxSailMapInfo> CVxSailMapInfos;
// �ƻ�����  
struct CVxPlanRoute
{
	QString id;				//���
	QString name;			//������
	QString startpostion;	//���λ��
	QString endpostion;		//�յ�λ��
	QString sections;		//������
	QString type;			//����
	QString sumbittime;		//�ύʱ��
};
// ������Ϣ  
struct CVxRouteInfo
{

	QString id;				//���
	QString longitude;		//����
	QString latitude;		//γ��
	QString speed;			//����
	QString direction;		//��λ
	QString distance;		//����
	QString totaldistance;	//�ܾ���
	QString warning;		//ƫ������
	QString time;			//ʱ��
	QString totaltime;		//��ʱ��
};

// ���߼�¼
struct CVxRouteRecord
{
	QString time;			//ʱ��
	QString latitude;		//γ��
	QString longitude;		//����
	//QString				//����
	QString speed;			//����
	//QString				//������
	//QString				//����
	//QString				//����
	//QString				//����
	//QString				//����
};

// ������Ϣ
struct CVxWarnningRecrod
{
	QString desc;			//��������
	QString time;			//����ʱ��
	QString duration;		//����ʱ��
};