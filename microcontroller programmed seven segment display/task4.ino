
const int a = 7; 
const int b = 8;  
const int c = 9;  
const int d = 10;  
const int e = 11;  
const int f = 12;  
const int g = 13;  

bool bPress = false;

const int Inc = 5;
const int Dec = 6;

int buttonPushCounter = 0;   
int IncbuttonState = 0;         
int lastIncbuttonState = 0;     
int DecbuttonState = 0;         
int lastDecbuttonState = 0;     
void setup() {

  pinMode(a, OUTPUT);      //A
  pinMode(b, OUTPUT);      //B
  pinMode(c, OUTPUT);     //C
  pinMode(d, OUTPUT);     //D
  pinMode(e, OUTPUT);     //E
  pinMode(f, OUTPUT);    //F
  pinMode(g, OUTPUT);    //G
  pinMode( Inc , INPUT_PULLUP );
  pinMode( Dec , INPUT_PULLUP );
  Serial.begin(9600);  
  displayDigit(buttonPushCounter);  
}
void loop() {  

   IncbuttonState = digitalRead(Inc);

   DecbuttonState = digitalRead(Dec);
   checkIncButtonPress();
   checkDecButtonPress();  
  if( bPress ){
    bPress = false;
     turnOff();
     displayDigit(buttonPushCounter);
  }
  
}
void checkIncButtonPress()
{
  
  if (IncbuttonState != lastIncbuttonState) {
   
    if (IncbuttonState == LOW) {
      
      bPress = true;
      buttonPushCounter++;
      if( buttonPushCounter > 9) buttonPushCounter =0 ;
      Serial.println("on");      
    } else {
      
      Serial.println("off");
    }
    
    delay(50);
  }
  
  lastIncbuttonState = IncbuttonState;
}
void checkDecButtonPress()
{
  
  if (DecbuttonState != lastDecbuttonState) {
    
    if (DecbuttonState == LOW) {
     
      bPress = true;
      buttonPushCounter--;
      if( buttonPushCounter < 0) buttonPushCounter =9 ;
      Serial.println("on");      
    } else {
      
      Serial.println("off");
    }
    
    delay(50);
  }
  
  lastDecbuttonState = DecbuttonState;
}  
void displayDigit(int digit)
{
 
 if(digit!=1 && digit != 4)

 digitalWrite(a,HIGH);
 
 if(digit != 5 && digit != 6)

 digitalWrite(b,HIGH);
 
 if(digit !=2)

 digitalWrite(c,HIGH);
 
 if(digit != 1 && digit !=4 && digit !=7)

 digitalWrite(d,HIGH);
 
 if(digit == 2 || digit ==6 || digit == 8 || digit==0)

 digitalWrite(e,HIGH);
 
 if(digit != 1 && digit !=2 && digit!=3 && digit !=7)

 digitalWrite(f,HIGH);

 if (digit!=0 && digit!=1 && digit !=7)

 digitalWrite(g,HIGH);
}

void turnOff()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}