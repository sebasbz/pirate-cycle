#include "SMSModule.h"
#include "StorageModule.h"
#include "PrinterModule.h"
// numero del modulo 611212746
// prueba 646491607
SMSModule *smsModule;
StorageModule *storageModule;

void setup()
{

  //  Serial.begin(115200);
  //  storageModule = new StorageModule(8, 10);
//  storageModule = new StorageModule(10);
    smsModule = new SMSModule(2, 3, 4);
}

void loop()
{
  //  if (storageModule->save("pepe.txt", "hola")) {
  //    Serial.println("ok");
  //  }else{
  //    Serial.println("nada");
  //  }
  if (smsModule->searching()) {

    char *usernum;
    char *sms;

    if (smsModule->getLastUserNumber()) {

      usernum = smsModule->getCallerIDbuffer();

      smsModule->readLastSMS();
      sms = smsModule->getReplybuffer();

      String numberPhone(usernum);
      String userSMS(sms);
      String fileName = numberPhone + ".txt";

      if (smsModule->sendSMS(usernum, "Bienvenido a pirate cycle")) {
        Serial.println("Mensaje enviado");
      }

      //        Serial.println(numberPhone);
      //        Serial.println(userSMS);
      //        Serial.println(fileName);

      //        if (storageModule->save(usernum, userSMS)) {
      //          Serial.println("Grabado..");
      //        }
    }
    //    Serial.println("Recibio algo");
    //    smsModule->readLastSMS();
    //smsModule->deleteLastSMS();
    //    char usernum;
    //    char userSMS;
    //
    //    if (smsModule->getLastUserNumber()) {
    //
    //      usernum = smsModule->getReplybuffer();
    //      smsModule->readLastSMS();
    //      userSMS = smsModule->getReplybuffer();
    //
    //      if (storageModule->save(usernum, userSMS)) {
    //        smsModule->deleteLastSMS();
    //      }
    //
    //    }

    //  } else {
    //
    //Serial.println("Nada");
    //    char *usernum;
    //    char *sms;
    //
    //    if (smsModule->getLastUserNumber()) {
    //
    //      usernum = smsModule->getCallerIDbuffer();
    //
    //      smsModule->readLastSMS();
    //      sms = smsModule->getReplybuffer();
    //
    //      String numberPhone(usernum);
    //      String userSMS(sms);
    //      String fileName = numberPhone + ".txt";
    //
    //      Serial.println(numberPhone);
    //      Serial.println(userSMS);
    //      Serial.println(fileName);
    //      if (storageModule->save(usernum, userSMS)) {
    //        Serial.println("Grabado..");
    //      }
    //    }
    //  }
    //  smsModule->getUserNumber(9);
    //  if (smsModule->searching()) {
    ////    if (storageModule->save("foo.txt", "hola a todo el mundo")) {
    ////
    ////    }
    //  }else{
    //
    //  }
  }else{
    Serial.println("Nada..");
  }
}
