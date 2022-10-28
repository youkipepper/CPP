#pragma once
#ifndef MYSQL_HELPER_H
#define MYSQL_HELPER_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <string>
using namespace std;

#include <mysql.h>

namespace mysqlhelper
{
	// �������ݿ��һЩ��Ҫ��Ϣ
	struct ConnectionInfo
	{
		const char* host;            // ������ַ
		const char* user;            // �û���
		const char* password;        // ����
		const char* database;     // ���ݿ���
		unsigned int port;           // �˿ں�
		const char* unix_socket;  // unix���ӱ�ʶ
		unsigned long clientflag;    // �ͻ������ӱ�־

		// ���캯��������һЩĬ��ֵ
		ConnectionInfo()
		{
			host = "172.16.20.175";
			port = 3306;
			user = "root";
			password = "root";
			database = "bridge";
			unix_socket = NULL;
			clientflag = 0;
		}
	};

	class MySQLManager
	{
	public:
		//��������������
		MySQLManager();

		~MySQLManager();

		//���ݿ��������ͷ�
		// �������ݿ�
		bool Init(ConnectionInfo& info);
		// �ͷ�����
		bool FreeConnect();

		//���ݿ���ɾ�Ĳ����
		// ��������
		bool InsertData(const char* sql);
		// ɾ������
		bool DeleteData(const char* sql);
		// ��������
		bool UpdateData(const char* sql);
		// ִ��sql���, �������ӡ�ɾ������������
		bool ExecuteSql(const char* sql);
		// ��ѯ����
		MYSQL_RES* QueryData(const char* sql);
		// ��ӡ�����
		void PrintQueryRes();

	private:
		MYSQL m_mysql;                // mysql����
		MYSQL_RES* m_res;             // ��ѯ�����
	};
}

#endif //MYSQL_HELPER_H
