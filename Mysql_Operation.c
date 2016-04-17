#include<stdio.h>
#include<mysql/mysql.h>
#include<stdlib.h>
#define	HOST		"localhost"
#define	USERNAME	"root"
#define	PASSWORD	"lyh12063259"
#define	DATABASE	"test"
void query_sql(char* query);
void main()
{
	char* query;
	query="select * from first_table";
	query_sql(query);
}
void query_sql(char* query)
{
	MYSQL connection;	//connection handle
	int res;	//return flag of sql_query
	MYSQL_RES* res_ptr;	//pointer of query result
	MYSQL_FIELD* field_ptr;	//pointer of field struct
	MYSQL_ROW result_row;		//data of one row
	unsigned int column;
	long long row;
	int i,j;
	mysql_init(&connection);
	if(mysql_real_connect(&connection,HOST,USERNAME,PASSWORD,DATABASE,0,NULL,CLIENT_FOUND_ROWS)==NULL)
	{
		printf("connection error\n");
	}
	else
	{
		if(mysql_query(&connection,query)!=0)
		{
			printf("query error\n");
			mysql_close(&connection);
		}
		else
		{
			res_ptr=mysql_store_result(&connection);
			if(res_ptr)
			{
				row=mysql_num_rows(res_ptr);
				column=mysql_num_fields(res_ptr);
				for(i=0;i<column;i++)
				{
					field_ptr=mysql_fetch_fields(res_ptr);
					printf("%10s",field_ptr->name);
				}
				printf("\n");
				for(i=0;i<row;i++)
				{
					result_row=mysql_fetch_row(res_ptr);
					for(j=0;j<column;j++)
					{
						printf("%10s",result_row[j]);
					}
					printf("\n");
				}
			}
			mysql_close(&connection);
		}
	}
}
	
		
	
		
