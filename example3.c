/*************************************************************************
	> File Name: example3.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年08月29日 星期六 20时44分10秒
 ************************************************************************/

/*
 * 表的创建与删除，数据的插入,更新与删除。
 */

#include<stdio.h>
#include<stdlib.h>
#include"sqlite3.h"

static print_info(void *params,int column_size,char **column_value,char **column_name)
{
    int i;
    
    for(i=0;i<column_size;i++)
        printf("\t%s",column_value[i]);
    printf("\n");
    
    return 0;
}

int main(void)
{
    char *filename = "./first.db";
    sqlite3 *pDB = NULL;
    int ret = 0;

    /*open*/
    ret = sqlite3_open(filename,&pDB);
    if(ret != SQLITE_OK)
    {
        fprintf(stderr,"%s\n",sqlite3_errmsg(pDB));
        exit(EXIT_FAILURE);
    }

    /*创建表*/
    const char *create_table = "create table t(id int primary key,name vachar(128))";
    char *errmsg = 0;
    ret = sqlite3_exec(pDB,create_table,NULL,NULL,&errmsg);
    if(ret != SQLITE_OK)
        fprintf(stderr,"create table error:%s\n",errmsg);
    sqlite3_free(errmsg);

    /*插入数据*/
    const char *insert_data = "insert into t(id,name) values(1,'answer')";
    ret = sqlite3_exec(pDB,insert_data,NULL,NULL,&errmsg);
    if(ret != SQLITE_OK)
        fprintf(stderr,"insert data error:%s\n",errmsg);

    /*查询表中数据*/
    ret = sqlite3_exec(pDB,"select * from t",print_info,NULL,&errmsg);
    if(ret != SQLITE_OK)
        fprintf(stderr,"select error:%s\n",errmsg);
    printf("\n");
  
    /*更新表中数据*/
    const char *update_data = "update t set name='jack' where id=1";
    ret = sqlite3_exec(pDB,update_data,NULL,NULL,&errmsg);
    if(ret != SQLITE_OK)
        fprintf(stderr,"update_data error:%s\n",errmsg);
   
    /*查询表中数据*/
    ret = sqlite3_exec(pDB,"select * from t",print_info,NULL,&errmsg);
    if(ret != SQLITE_OK)
        fprintf(stderr,"select error:%s\n",errmsg);
    printf("\n");
    
    /*删除数据*/
    const char *delete_data = "delete from t where id = 1";
    ret = sqlite3_exec(pDB,delete_data,NULL,NULL,&errmsg);
    if(ret != SQLITE_OK)
        fprintf(stderr,"delete data error:%s\n",errmsg);

    /*查询受上次操作影响的记录数*/
    printf("delete data records:%i\n",sqlite3_changes(pDB));
    printf("\n");

    /*删除表*/
    const char *drop_table = "drop table if exists t";
    ret = sqlite3_exec(pDB,drop_table,NULL,NULL,&errmsg);
    if(ret != SQLITE_OK)
        fprintf(stderr,"drop table error:%s\n",errmsg);

    /*close*/
    if(pDB != NULL)
    {
        sqlite3_close(pDB);
        pDB = NULL;
    }

    return 0;
}

