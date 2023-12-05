#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;


// Define color codes
#define BLACK 0x0000
#define BLUE 0x001F
#define GREEN 0x07E0
#define RED 0xF800
#define WHITE 0xFFFF

// Define variables for time intervals
unsigned long previousMillis1, previousMillis2 = 0;
const long interval1 = 20;
const long interval2 = 5;

void setup(void)
{
  Serial.begin(9600);

  // Initiate the display
  uint16_t ID = tft.readID();
  Serial.println("Example: Font_simple");
  Serial.print("found ID = 0x");
  Serial.println(ID, HEX);
  if (ID == 0xD3D3) ID = 0x9481; // force ID if write-only display
  tft.begin(ID);

  // Set screen orientation
  tft.setRotation(1);
  tft.fillScreen(BLACK);

  // Draw the grid
  drawGrid();
}

void loop() {
  unsigned long currentMillis = millis();

  // Task1 - Draw ECG graph
  if (currentMillis - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis;
    runECG();
  }  
}

void drawGrid(){
  // Clear screen
  tft.fillScreen(BLACK);
  // Set text
  tft.setCursor(20, 20);
  tft.setTextColor(WHITE);
  tft.setTextColor(WHITE, BLACK); 
  tft.setTextSize(3);
  tft.println("ECG");

  // Draw vertical lines
  for (int i = 1; i <= 6; i++){
    tft.drawLine(80 * i,0,80*i, 320,BLUE);
  }

  // Draw horizontal lines
  for (int j = 1; j <= 4; j++){
    tft.drawLine(0,80 *j,480, 80*j,BLUE);
  }
}


void runECG(){
  // Read analog value from ADC pin
  long ecgValue = analogRead(34);

  // Normalize the value read to it screen size
  int normalizedVal = map(ecgValue, 0, 4095, 0, 320);

  static int lastX = 0;
  static int lastY = tft.height()/2 + 50;
  int x = lastX + 2;
  int y = tft.height() - normalizedVal;

  // Reset cursor if reached the right end of scren
  if (x >= tft.width()){
    x = 0;
    drawGrid();
    lastX = 0;
    lastY = tft.height()/2 + 50;
  
  }

  // Draw ECG line
  tft.drawLine(lastX, lastY, x, y, GREEN);
  lastX = x;
  lastY = y;
}