#ifndef MYSQL_DB_H_INCLUDED
#define MYSQL_DB_H_INCLUDED
int mysql_rfid_connect(void);
int mysql_rfid_disconnect(void);
int mysql_rfid_insert(char * cardid, char * readerid, char * readername);


#endif // MYSQL_DB_H_INCLUDED
