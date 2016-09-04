#include <DHT.h>  // libreria Sensor DHT22

// Sensor FC-28  Higrómetro: Medidor humedad del suelo
// Sensor DHT 22 Medidor de Temperatura y humedad
// Sensor LM393  Medidor de luminosidad
// Sensor MQ 2   Medidor de gas combustible y humo
// Sensor MQ 135 Medidor de Calidad Air

#define DHTTYPE DHT22       // DHT 22


const int DHTPin = 5;       //  DHT 22 - Digital pin
const int FC28   = A0;      //  FC 28  - Analogico pin
const int LM393  = A1;      //  LM393  - Analogico pin
const int MQ2    = A2;      //  MQ 2   - Analogico pin
const int MQ135  = A3;      //  MQ 135 - Analogico pin

DHT dht(DHTPin, DHTTYPE);   //  DHT 22


void setup() {
	Serial.begin(9600);

  Serial.println("DHT22 - ?");
	dht.begin();
}


void loop() {
	delay(2500);
// DHT 22 - Leer valores
	int h = dht.readHumidity()    * 100;
	int t = dht.readTemperature() * 100;
// FC 28 - Leer valores
	int s = analogRead(FC28);
// LM393
	int l = analogRead(LM393);
// MQ 2
	int g = analogRead(MQ2);
// MQ 135
	int a = analogRead(MQ135);

// DHT 22 -  No hay datos todo a 0
  if ( isnan(h) ) {
    h = 0000;
  }
  if ( isnan(t) ) {
    t = 0000;
  }

// FC 28 -  No hay datos todo a 0
	if ( isnan(s) ) {
	  s = 0000;
	}

// LM393 -  No hay datos todo a 0
if ( isnan(l) ) {
	l = 0000;
}

// MQ 2 -  No hay datos todo a 0
if ( isnan(g) ) {
	g = 0000;
}

// MQ 135 -  No hay datos todo a 0
if ( isnan(a) ) {
	a = 0000;
}


// DHT 22 - Imprimir datos
  Serial.print("Hum: ");
  Serial.print(h);
  Serial.print("   ");
  Serial.print("Temp: ");
  Serial.print(t);
	Serial.print("   ");

// FC 28
	Serial.print("Suelo: ");
	Serial.print(s);
	Serial.print("   ");

// LM393
	Serial.print("Luz: ");
	Serial.print(l);
	Serial.print("   ");
	Serial.println("");

// MQ 2
	Serial.print("Gases: ");
	Serial.print(g);
	Serial.print("   ");

// LM393
	Serial.print("Aire: ");
	Serial.print(a);
	Serial.print("   ");
	Serial.println("");

 	Serial.println("------------------ 2500 delay");


}
