/*
 * mysql_db.c
 *
 *  Created on: 17 sep. 2015
 *      Author: shrnds
 */


#include <string.h>
#include <mysql.h>

static MYSQL *conn;

int mysql_rfid_connect(void)
{
	  printf("MySQL client version: %s\nConnecting to database...\n", mysql_get_client_info());

	  conn = mysql_init(NULL);

	  if (conn == NULL) {
	      printf("Error 1 %u: %s\n", mysql_errno(conn), mysql_error(conn));
	      return 1;
	  }

	 if (mysql_real_connect(conn, "localhost", "phidget",
	         "my_phidget", NULL, 0, NULL, 0) == NULL) {
        printf("Error 2 %u: %s\n", mysql_errno(conn), mysql_error(conn));
	      return 1;
	  }

	  return 0;
}

int mysql_rfid_insert(char * cardid, char * readerid, char * readername)
{
	int result;

	/* truncate inputs sizes */
	if (strlen(cardid) > 10) cardid[10] = '\0';
	if (strlen(readerid) > 10) readerid[10] = '\0';
	if (strlen(readername) > 100) readername[100] = '\0';

	char query[255];

	 sprintf(query, "INSERT INTO phidget_rfid.rfid_rawdate(card_id, reader_id, reader_name, timestamp) VALUES ('%s', '%s', '%s', CURRENT_TIMESTAMP)", cardid, readerid, readername);

	result = mysql_query(conn, query);

	if (result)
	{
	      printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
	}

	return result;
}

int mysql_rfid_disconnect(void)
{
      printf("Disconnection from database...\n");

      mysql_close(conn);

	  return 0;
}

