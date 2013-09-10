
int x=0;
int y=0;
long startTime=0;
int pin=8;
String a[48][2]={
  {".-","A"}, {"-...","B"}, {"-.-.","C"}, {"-..","D"}, {".","E"}, {"..-.","F"}, {"--.","G"}, {"....","H"}, {"..","I"},
  {".---","J"}, {"-.-","K"}, {"..-.","L"}, {"--","M"}, {"-.","N"}, {"---","O"}, {".--.","P"}, {"--.-","Q"}, {".-.","R"}, {"...","S"},
  {"-","T"}, {"..-","U"}, {"...-","V"}, {".--","W"}, {"-..-","X"}, {"-.--","Y"}, {"--..","Z"}, {"-----","0"}, {".----","1"}, {"..---","2"},
  {"...--","3"}, {"....-","4"}, {".....","5"}, {"-....","6"}, {"--...","7"}, {"---..","8"}, {"----.","9"}, {".-.-.-","."}, {"--..--",","}, {"---...",":"},
  {"..--..","?"}, {".----.","'"}, {"-....-","-"}, {"-..-.","/"}, {"","("}, {"",")"}, {""," \" "}, {"","@"}, {"-...-","="}};
 void setup()
  {
    pinMode(pin, OUTPUT);
    Serial.begin(9600);
  }

void loop()
  {
   String s = "";
   //d=getChar();
   while(analogRead(6)<300){
   for(int i=0; i<6; i++)
   {
   y = analogRead(i);
  
  if(y>200) 
    {
       startTime = millis(); 
       while(y>0)
     {y = analogRead(i);
   }
       long duration = millis() - startTime;
       if(duration>70 && duration<300){
         //Serial.println(".");
         s+=".";
       }
       else if(duration>=300 && duration<=1000){
              //Serial.println("-");
              s+="-";
            }
      // Serial.println(duration);
   }  
   }}
   Serial.println(s);
   //Serial.println(findChar(s));
   if(s!=""){
     int x= findChar(s);
   if(x!=-1){
   Serial.println(a[x][1]);}
   }
   s="";
} 

//caracterul de la un senzor
 /*String getChar(){
   String s = "";
   for(int i=0; i<6; i++)
   {
   y = analogRead(i);
  
  if(y>200) 
    {
       startTime = millis(); 
       while(y>0)
     {y = analogRead(i);
   }
       long duration = millis() - startTime;
       if(duration>70 && duration<300){
         //Serial.println(".");
         s+=".";
       }
       else if(duration>=300 && duration<=1000){
              //Serial.println("-");
              s+="-";
            }
      // Serial.println(duration);
   }  
   }
   return s;
 }*/

int findChar(String t){
  for(int i=0; i<48; i++){
    if(a[i][0].equals(t)) { 
      return i; //return pozitia literei in matrice 
  }
  else return -1;
  }
}
