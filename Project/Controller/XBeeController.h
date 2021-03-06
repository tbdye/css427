// ----------------------------------------------------------------------------
// CSS 427 - Embedded Systems
// Author:  Thomas Dye, John Walter - 12/9/2016
// School:  University of Washington | Bothell
// Instructor:  Dr. Yang Peng
//
// Controller  - XBee Radio Wrapper
// ----------------------------------------------------------------------------

#ifndef XBEE_CONTROLLER_H
#define XBEE_CONTROLLER_H

#include <WString.h>
#include <XBee.h>
#include <SoftwareSerial.h>     // console serial output

class XBeeController
{
public:
    XBeeController();
    XBeeController(long SHaddress, long SLaddress, SoftwareSerial *object);
    ~XBeeController();

    void sendData(String payload);
    bool ackSentData(String payload);
    String receiveData();

private:
    bool retransmit(String payload);

    // Diagnostic output
    SoftwareSerial *mySerial;
    
    // Radio library
    XBee xbee;

    // Sender globals
    XBeeAddress64 addr64;
    TxStatusResponse txStatus;
    const static byte TOTAL_RETRANSMITS = 5;

    // Receiver globals
    XBeeResponse response;
    ZBRxResponse rx64;

    // Other globals
    byte sendID;
    byte receiveID;
    byte retransmission;
};

#endif

