/*  StoreCredit API
 *  Connector to the Phidget RFID
 *
 *  Created on: 17 sep. 2015
 *      Modifying designer: Ryan Dias
 */


// Copyright 2008 Phidgets Inc.  All rights reserved.
// This work is licensed under the Creative Commons Attribution 2.5 Canada License.
// view a copy of this license, visit http://creativecommons.org/licenses/by/2.5/ca/

#include "mysql_db.h"
#include <phidget21.h>
#include "mysql_db.c"


static int serialNo;
//static int serialNoC;
static const char *name;


int CCONV AttachHandler(CPhidgetHandle RFID, void *userptr)
{
    //int serialNo;
    //const char *name;
	CPhidget_getDeviceName (RFID, &name);
	CPhidget_getSerialNumber(RFID, &serialNo);
	printf("%s %10d attached!\n", name, serialNo);

	/* open mysql connection*/
	return mysql_rfid_connect();
	//return 0;

}
/*
int CCONV AttachHandlerB(CPhidgetHandle RFID, void *userptr)
{
	CPhidget_getDeviceName (RFID, &name);
	CPhidget_getSerialNumber(RFID, &serialNoB);
	printf("%s %10d attached!\n", name, serialNoB);

	/* open mysql connection
	//return mysql_rfid_connect();
	return 0;

}

int CCONV AttachHandlerC(CPhidgetHandle RFID, void *userptr)
{
	CPhidget_getDeviceName (RFID, &name);
	CPhidget_getSerialNumber(RFID, &serialNoC);
	printf("%s %10d attached!\n", name, serialNoC);

	/* open mysql connection
	//return mysql_rfid_connect();
	return 0;

}

*/
int CCONV DetachHandler(CPhidgetHandle RFID, void *userptr)
{
	int serialNo;
	const char *name;

	CPhidget_getDeviceName (RFID, &name);
	CPhidget_getSerialNumber(RFID, &serialNo);
	printf("%s %10d detached!\n", name, serialNo);

	/* close mysql connection */
	return mysql_rfid_disconnect();
	//return 0;
}
/*
int CCONV DetachHandlerB(CPhidgetHandle RFID, void *userptr)
{
	int serialNoB;
	const char *name;

	CPhidget_getDeviceName (RFID, &name);
	CPhidget_getSerialNumber(RFID, &serialNoB);
	printf("%s %10d detached!\n", name, serialNo);

	/* close mysql connection
	//return mysql_rfid_disconnect();
	return 0;
}

int CCONV DetachHandlerC(CPhidgetHandle RFID, void *userptr)
{
	int serialNoC;
	const char *name;

	CPhidget_getDeviceName (RFID, &name);
	CPhidget_getSerialNumber(RFID, &serialNoC);
	printf("%s %10d detached!\n", name, serialNoC);

	/* close mysql connection
	//return mysql_rfid_disconnect();
	return 0;
}
*/

int CCONV ErrorHandler(CPhidgetHandle RFID, void *userptr, int ErrorCode, const char *unknown)
{
	printf("Error handled. %d - %s\n", ErrorCode, unknown);
	return 0;
}



int CCONV OutputChangeHandler(CPhidgetRFIDHandle RFID, void *usrptr, int Index, int State)
{
	if(Index == 0 || Index == 1)
	{
		printf("Output: %d > State: %d\n", Index, State);
	}
	return 0;
}



int CCONV TagHandler(CPhidgetRFIDHandle RFID, void *usrptr, unsigned char *TagVal)
{
	//char tagid[11];
	char readerid[11];

	//turn on the Onboard LED
	CPhidgetRFID_setLEDOn(RFID, 1);

	//printf("Tag read: %02x%02x%02x%02x%02x\n", TagVal[0], TagVal[1], TagVal[2], TagVal[3], TagVal[4]);
	//sprintf(tagid, "%02x%02x%02x%02x%02x", TagVal[0], TagVal[1], TagVal[2], TagVal[3], TagVal[4]);
	sprintf(readerid, "%10i", serialNo);
	printf("Readerid: %s\n",readerid);
    printf("Tag Read: %s\n", TagVal);
	mysql_rfid_insert(TagVal, readerid, name);
   // printf("Tag Read: %s\n", TagVal);
	return 0;

}
/*
int CCONV TagHandlerB(CPhidgetRFIDHandle RFID, void *usrptr, unsigned char *TagVal)
{
	char tagid[11];
	char readerid[11];

	//turn on the Onboard LED
	CPhidgetRFID_setLEDOn(RFID, 1);

	printf("Tag read: %02x%02x%02x%02x%02x\n", TagVal[0], TagVal[1], TagVal[2], TagVal[3], TagVal[4]);
	sprintf(tagid, "%02x%02x%02x%02x%02x", TagVal[0], TagVal[1], TagVal[2], TagVal[3], TagVal[4]);
	sprintf(readerid, "%10i", serialNoB);
	printf("Readerid: %s\n",readerid);
	//mysql_rfid_insert(tagid, readerid, name);

	return 0;
}

int CCONV TagHandlerC(CPhidgetRFIDHandle RFID, void *usrptr, unsigned char *TagVal)
{
	char tagid[11];
	char readerid[11];

	//turn on the Onboard LED
	CPhidgetRFID_setLEDOn(RFID, 1);

	printf("Tag read: %02x%02x%02x%02x%02x\n", TagVal[0], TagVal[1], TagVal[2], TagVal[3], TagVal[4]);
	sprintf(tagid, "%02x%02x%02x%02x%02x", TagVal[0], TagVal[1], TagVal[2], TagVal[3], TagVal[4]);
	sprintf(readerid, "%10i", serialNoC);
	printf("Readerid: %s\n",readerid);
	//mysql_rfid_insert(tagid, readerid, name);

	return 0;
}
*/
int CCONV TagLostHandler(CPhidgetRFIDHandle RFID, void *usrptr, unsigned char *TagVal)
{
	//turn off the Onboard LED
	CPhidgetRFID_setLEDOn(RFID, 0);

	//printf("Tag Lost: %02x%02x%02x%02x%02x\n", TagVal[0], TagVal[1], TagVal[2], TagVal[3], TagVal[4]);
    printf("Tag Lost: %s\n", TagVal);

	return 0;
}
/*
int CCONV TagLostHandlerB(CPhidgetRFIDHandle RFID, void *usrptr, unsigned char *TagVal)
{
	//turn off the Onboard LED
	CPhidgetRFID_setLEDOn(RFID, 0);

	printf("Tag Lost: %02x%02x%02x%02x%02x\n", TagVal[0], TagVal[1], TagVal[2], TagVal[3], TagVal[4]);


	return 0;
}

int CCONV TagLostHandlerC(CPhidgetRFIDHandle RFID, void *usrptr, unsigned char *TagVal)
{
	//turn off the Onboard LED
	CPhidgetRFID_setLEDOn(RFID, 0);

	printf("Tag Lost: %02x%02x%02x%02x%02x\n", TagVal[0], TagVal[1], TagVal[2], TagVal[3], TagVal[4]);


	return 0;
}
*/
//Display the properties of the attached phidget to the screen.  We will be displaying the name, serial number and version of the attached device.
//We will also display the nu,mber of available digital outputs
int display_properties(CPhidgetRFIDHandle phid)
{
	int serialNo, version, numOutputs, antennaOn, LEDOn;
	const char* ptr;

	CPhidget_getDeviceType((CPhidgetHandle)phid, &ptr);
	CPhidget_getSerialNumber((CPhidgetHandle)phid, &serialNo);
	CPhidget_getDeviceVersion((CPhidgetHandle)phid, &version);

	CPhidgetRFID_getOutputCount (phid, &numOutputs);
	CPhidgetRFID_getAntennaOn (phid, &antennaOn);
	CPhidgetRFID_getLEDOn (phid, &LEDOn);


	printf("%s\n", ptr);
	printf("Serial Number: %10d\nVersion: %8d\n", serialNo, version);
	printf("# Outputs: %d\n\n", numOutputs);
	printf("Antenna Status: %d\nOnboard LED Status: %d\n", antennaOn, LEDOn);

	return 0;
}

int rfid_simple()
{
	int result;
	//int resultB;
//	int resultC;


	const char *err;
	/*
	int readerA=91042;
	int readerB=102831;
	int readerC=103424;
*/

	//Declare an RFID handle
	CPhidgetRFIDHandle rfid = 0;
	/*
	CPhidgetRFIDHandle rfidB = 0;
	CPhidgetRFIDHandle rfidC = 0;
*/

	//create the RFID object
	CPhidgetRFID_create(&rfid);
	/*
	CPhidgetRFID_create(&rfidB);
	CPhidgetRFID_create(&rfidC);
	*/

	//Set the handlers to be run when the device is plugged in or opened from software, unplugged or closed from software, or generates an error.
	CPhidget_set_OnAttach_Handler((CPhidgetHandle)rfid, AttachHandler, NULL);
	//CPhidget_set_OnAttach_Handler((CPhidgetHandle)rfidB, AttachHandlerB, NULL);
	//CPhidget_set_OnAttach_Handler((CPhidgetHandle)rfidC, AttachHandlerC, NULL);
	CPhidget_set_OnDetach_Handler((CPhidgetHandle)rfid, DetachHandler, NULL);
	//CPhidget_set_OnDetach_Handler((CPhidgetHandle)rfidB, DetachHandlerB, NULL);
	//CPhidget_set_OnDetach_Handler((CPhidgetHandle)rfidC, DetachHandlerC, NULL);
	CPhidget_set_OnError_Handler((CPhidgetHandle)rfid, ErrorHandler, NULL);
	//CPhidget_set_OnError_Handler((CPhidgetHandle)rfidB, ErrorHandler, NULL);
	//CPhidget_set_OnError_Handler((CPhidgetHandle)rfidC, ErrorHandler, NULL);



	//Registers a callback that will run if an output changes.
	//Requires the handle for the Phidget, the function that will be called, and an arbitrary pointer that will be supplied to the callback function (may be NULL).
	CPhidgetRFID_set_OnOutputChange_Handler(rfid, OutputChangeHandler, NULL);
	//CPhidgetRFID_set_OnOutputChange_Handler(rfidB, OutputChangeHandler, NULL);
	//CPhidgetRFID_set_OnOutputChange_Handler(rfidC, OutputChangeHandler, NULL);

	//Registers a callback that will run when a Tag is read.
	//Requires the handle for the PhidgetRFID, the function that will be called, and an arbitrary pointer that will be supplied to the callback function (may be NULL).
	CPhidgetRFID_set_OnTag2_Handler(rfid, TagHandler, NULL);
	//CPhidgetRFID_set_OnTag_Handler(rfidB, TagHandlerB, NULL);
	//CPhidgetRFID_set_OnTag_Handler(rfidC, TagHandlerC, NULL);

	//Registers a callback that will run when a Tag is lost (removed from antenna read range).
	//Requires the handle for the PhidgetRFID, the function that will be called, and an arbitrary pointer that will be supplied to the callback function (may be NULL).
	CPhidgetRFID_set_OnTagLost2_Handler(rfid, TagLostHandler, NULL);
	//CPhidgetRFID_set_OnTagLost_Handler(rfidB, TagLostHandlerB, NULL);
	//CPhidgetRFID_set_OnTagLost_Handler(rfidC, TagLostHandlerC, NULL);

	//open the RFID for device connections
	CPhidget_open((CPhidgetHandle)rfid, -1);
	//CPhidget_openRemote((CPhidgetHandle)rfid, readerA, NULL, NULL);
	//CPhidget_openRemote((CPhidgetHandle)rfidB, readerB, NULL, NULL);
	//CPhidget_openRemote((CPhidgetHandle)rfidC, readerC, NULL, NULL);
	//CPhidget_openRemote((CPhidgetHandle)rfid, -1, NULL, NULL);



	//get the program to wait for an RFID device to be attached
	printf("Waiting for RFID to be attached....\n");
	if((result = CPhidget_waitForAttachment((CPhidgetHandle)rfid, 10000)))
	{
		CPhidget_getErrorDescription(result, &err);
		printf("Problem waiting for attachment: %s\n", err);
		return 0;
	}

	//get the program to wait for an RFID device to be attached
	/*
		printf("Waiting for RFID B to be attached....\n");
		if((resultB = CPhidget_waitForAttachment((CPhidgetHandle)rfidB, 10000)))
		{
			CPhidget_getErrorDescription(resultB, &err);
			printf("Problem waiting for attachment: %s\n", err);
			return 0;
		}

	//get the program to wait for an RFID device to be attached
			printf("Waiting for RFID C to be attached....\n");
			if((resultC = CPhidget_waitForAttachment((CPhidgetHandle)rfidC, 10000)))
			{
				CPhidget_getErrorDescription(resultC, &err);
				printf("Problem waiting for attachment: %s\n", err);
				return 0;
			}
*/
		//Display the properties of the attached RFID device
		display_properties(rfid);
		//Display the properties of the attached RFID device
		//display_properties(rfidB);
		//Display the properties of the attached RFID device
		//display_properties(rfidC);

		CPhidgetRFID_setAntennaOn(rfid, 1);
		//CPhidgetRFID_setAntennaOn(rfidB, 1);
		//CPhidgetRFID_setAntennaOn(rfidC, 1);

	//read RFID event data
	printf("Reading.....\n\n");

	printf("Press any key to end\n");
	getchar();

	//since user input has been read, this is a signal to terminate the program so we will close the phidget and delete the object we created
	printf("Closing...\n");
	CPhidget_close((CPhidgetHandle)rfid);
	//CPhidget_close((CPhidgetHandle)rfidB);
	//CPhidget_close((CPhidgetHandle)rfidC);
	CPhidget_delete((CPhidgetHandle)rfid);
	//CPhidget_delete((CPhidgetHandle)rfidB);
	//CPhidget_delete((CPhidgetHandle)rfidC);


	//all done, exit
	return 0;
}

