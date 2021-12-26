int input1 = A0; //Sensor LDR dihubungkan ke pin A0
int input2 = A1; // Sensor LOADCELL dihubungkan ke pin A1
int input3 = A2; // Sensor Suhu dihubungkan ke pin A2


int sensor1 = 0; // Menampung nilai Analog Sensor LDR
int sensor2 = 0; // Menampung nilai Analog LOADCELL
int sensor3 = 0; // Menampung nilai Analog Sensor Suhu


#define led1 2 // Led1 (Warna Merah) terpasang di pin Digital 2
#define led2 3 // Led2 (Warna Kuning) terpasang di pin Digital 3
#define led3 4 // Led3 (Warna Hijau) terpasang di pin Digital 4

void setup() {
  // Mengatur seluruh Led berfungsi sebagai Output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  Serial.begin(9600); // Memulai Pembacaan di Virtual Terminal
  // Seluruh Sensor mulai membaca secara analog
  sensor1 = analogRead(input1);
  sensor2 = analogRead(input2);
  sensor3 = analogRead(input3);
  //untuk menyalakan LED 1
  if ((sensor1 > 173 )&&(sensor3 < 102)){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  
  //untuk menyalakan LED 2
  else if ((sensor1 < 173) && (sensor2 < 623) ){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
  //untuk menyalakan LED 3
  else if ((sensor3 > 102)&&(sensor2 > 622)){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  // Menampilkan Hasil Pembacaan Analog ke Virtual Terminal
  Serial.println("---------");
  Serial.println(sensor1);
  Serial.println(sensor2);
  Serial.println(sensor3);
  Serial.println("---------");
  delay(1000);
}
