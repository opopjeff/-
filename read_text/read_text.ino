float col;

void setup() { 

  Serial.begin(9600); 

} 

 

void loop() { 

  while(Serial.available()>0){

    col=Serial.parseFloat();

    Serial.print("Read: "); 

    Serial.println(col);

    delay(1000);

  } 

}
