/*************************************************************************
	> File Name: example1.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年08月29日 星期六 14时17分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"sqlite3.h"

int main(void)
{
    char *filename = "./first.db";
    sqlite3 *pDB = NULL;
    int ret = 0;

    ret = sqlite3_open(filename,&pDB);
    if(ret != SQLITE_OK)
    {
        fprintf(stderr,"%s\n",sqlite3_errmsg(pDB));
        exit(EXIT_FAILURE);
    }

    /*do something*/
    printf("open successfully!\n");

    if(pDB != NULL)
    {
        sqlite3_close(pDB);
        pDB = NULL;
    }

    printf("close successfully!\n");

    return 0;
}
