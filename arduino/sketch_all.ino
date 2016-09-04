#include <RCSwitch.h>  // libreria Modulo RC - RF 433
#include <DHT.h>       // libreria Sensor DHT22

// Sensor FC-28  Higrómetro: Medidor humedad del suelo
// Sensor DHT 22 Medidor de Temperatura y humedad
// Sensor LM393  Medidor de luminosidad
// Sensor MQ 2   Medidor de gas combustible y humo
// Sensor MQ 135 Medidor de Calidad Air
// Modulo RF 433 emisor de radiofrecuencia en la banda de 433Mhz

#define DHTTYPE DHT22       // DHT 22


const int DHTPin = 5;       //  DHT 22 - Digital pin
const int RF433  = 10;      //  RF 433 - Digital pin
const int FC28   = A0;      //  FC 28  - Analogico pin
const int LM393  = A1;      //  LM393  - Analogico pin
const int MQ2    = A2;      //  MQ 2   - Analogico pin
const int MQ135  = A3;      //  MQ 135 - Analogico pin

DHT dht(DHTPin, DHTTYPE);   //  DHT 22
RCSwitch rfSwitch = RCSwitch();     //  RF433

void setup() {
	Serial.begin(9600);
	rfSwitch.enableTransmit(RF433);

	dht.begin();
}


void loop() {
	delay(10000);
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



	rfSwitch.send( 100000 + a, 24);
	delay(1000);
	rfSwitch.send( 200000 + g, 24);
	delay(1000);
	rfSwitch.send( 300000 + l, 24);
	delay(1000);
	rfSwitch.send( 400000 + s, 24);
	delay(1000);
	rfSwitch.send( 500000 + h, 24);
	delay(1000);
	rfSwitch.send( 600000 + t, 24);
	delay(1000);




}
