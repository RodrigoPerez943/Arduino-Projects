
#include <LiquidCrystal.h>
const int rs = 50, en = 46, d4 = 51, d5 = 49, d6 = 47, d7 = 45;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int bot1 = 29;
int CLK = 37;
int DT = 35;
int SW = 33;
int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir = "";
unsigned long lastButtonPress = 0;
int vida = 1;
byte smiley[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B10000,
};

  byte a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn;
  
byte estado[8] = {
  'B'+a+b+c+d+e,
  'B'+f+g+h+i+j,
  'B'+k+l+m+n+o,
  'B'+p+q+r+s+t,
  'B'+u+v+w+x+y,
  'B'+z+aa+bb+cc+dd,
  'B'+ee+ff+gg+hh+ii,
  'B'+jj+kk+ll+mm+nn,
};
  
void setup() {

  a=b=c=d=e=f=g=h=i=j=k=l=m=n=o=p=q=r=s=t=u=v=w=x=y=z=aa=bb=cc=dd=ee=ff=gg=hh=ii=jj=kk=ll=mm=nn=1;
  lcd.begin(16, 2);
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);
  pinMode(bot1, INPUT);
  Serial.begin(9600);

  lastStateCLK = digitalRead(CLK);

  lcd.createChar(0, estado);

}

void loop() {

  currentStateCLK = digitalRead(CLK);

  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1) {
    if (digitalRead(DT) != currentStateCLK) {
      counter --;
      currentDir = "CCW";
    } else {
      counter ++;
      currentDir = "CW";
    }
  }
  Serial.print("Direction: ");
  Serial.print(currentDir);
  Serial.print(" | Counter: ");
  Serial.println(counter);

  lastStateCLK = currentStateCLK;

  int btnState = digitalRead(SW);

  if (btnState == LOW) {
    if (millis() - lastButtonPress > 50) {
      Serial.println("Button pressed!");
    }
    lastButtonPress = millis();
  }


  
}
