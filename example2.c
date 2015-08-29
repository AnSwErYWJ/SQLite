/*************************************************************************
	> File Name: example2.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年08月29日 星期六 20时11分06秒
 ************************************************************************/

/*
 * 查询数据库
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

    /*select*/
    char *errmsg;
    ret = sqlite3_exec(pDB,"select * from stutable",print_info,NULL,&errmsg);
    if(ret != SQLITE_OK)
        fprintf(stderr,"select error:%s\n",errmsg);

    /*close*/
    if(pDB != NULL)
    {
        sqlite3_close(pDB);
        pDB = NULL;
    }

    return 0;
}
