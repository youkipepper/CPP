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
	// 连接数据库的一些必要信息
	struct ConnectionInfo
	{
		const char* host;            // 主机地址
		const char* user;            // 用户名
		const char* password;        // 密码
		const char* database;     // 数据库名
		unsigned int port;           // 端口号
		const char* unix_socket;  // unix连接标识
		unsigned long clientflag;    // 客户端连接标志

		// 构造函数，设置一些默认值
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
		//构造与析构函数
		MySQLManager();

		~MySQLManager();

		//数据库链接与释放
		// 连接数据库
		bool Init(ConnectionInfo& info);
		// 释放连接
		bool FreeConnect();

		//数据库增删改查操作
		// 增加数据
		bool InsertData(const char* sql);
		// 删除数据
		bool DeleteData(const char* sql);
		// 更新数据
		bool UpdateData(const char* sql);
		// 执行sql语句, 包括增加、删除、更新数据
		bool ExecuteSql(const char* sql);
		// 查询数据
		MYSQL_RES* QueryData(const char* sql);
		// 打印结果集
		void PrintQueryRes();

	private:
		MYSQL m_mysql;                // mysql连接
		MYSQL_RES* m_res;             // 查询结果集
	};
}

#endif //MYSQL_HELPER_H
