#define sensorPin2 A0 //DHT11
#define sensorPin2 A1 //SMD
#define sensorPin2 A2 //LDR


int relay1_pin = 5;
int relay2_pin = 6;
int relay3_pin = 7;


int led_pin = 9;
int motor_pin = 10;
int fan_pin = 11;

void setup()
{ 
  //Pinmode for LDR
  pinMode(relay1_pin,OUTPUT);
  pinMode(led_pin,OUTPUT);  
  digitalWrite(led_pin,HIGH);

  //Pinmode for SMD
  pinMode(relay2_pin,OUTPUT);
  pinMode(motor_pin,OUTPUT);  
  digitalWrite(motor_pin,HIGH);
  
  //Pinmode for DHT11
  pinMode(relay3_pin,OUTPUT);
  pinMode(fan_pin,OUTPUT);  
  digitalWrite(fan_pin,HIGH);

  Serial.begin(9600);

}


void loop()
{

  Serial.println("**********************************************");
  Serial.println("**********************************************");

  Serial.println("--------GREENHOUSE AUTOMATION DEVICE----------");

  Serial.println("**********************************************");
  Serial.println("**********************************************");


  unsigned int AnalogValueLDR;
  AnalogValueLDR = analogRead(A2);

  unsigned int AnalogValueSMD;
  AnalogValueSMD = analogRead(A1);

  unsigned int AnalogValueDHT;
  AnalogValueDHT = analogRead(A0);
  
  delay(2000);

  Serial.print("Visibility : ");
  
  if(AnalogValueLDR < 450){
      
     Serial.println("HIGH");

  }else{
  
  Serial.println("LOW (Ligth Required)");
  }
  

  Serial.print("Soil Moisture : ");
  if(AnalogValueSMD < 850){
     Serial.print(AnalogValueSMD);
     Serial.println("HIGH");

  }else{
  
  Serial.println("LOW (Water Required)");
  }
  
//  Serial.print("Temperature & Humidity : ");
//  if(AnalogValueDHT < 450){
//      
//     Serial.println("HIGH(Exhausting Required)");
//
//  }else{
//  
//  Serial.println("LOW");
//  }
//  

  Serial.println("----------------------------------------------");
  Serial.println("----------------------------------------------");

  //if-else for LDR

  if(AnalogValueLDR < 450){
      
      digitalWrite(relay1_pin,HIGH);
      delay(2000);
  }else{
  
  digitalWrite(relay1_pin,LOW);
  delay(2000);
  }

  //if-else for SMD

  if(AnalogValueSMD < 500){
      
      digitalWrite(relay2_pin,HIGH);
      delay(2000);
  }else{
  
  digitalWrite(relay2_pin,LOW);
  delay(2000);
  }

  //if-else for DHT

    if(AnalogValueDHT < 450){
      
      digitalWrite(relay3_pin,HIGH);
      delay(2000);
  }else{
  
  digitalWrite(relay3_pin,LOW);
  delay(2000);
  }

  

}
