/*
 * Jornada Automação na Veia
 * #DAV005
*/

void setup() {
    Serial.begin(9600);
    Serial.println("Inicializando...");
    prepareButtonMultiFuction();
    
}

void loop() {
   monitoringButtonMultiFunction();
   actionMode();
}
