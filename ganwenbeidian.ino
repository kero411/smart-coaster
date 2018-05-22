#include "DHT.h"
int potPin = A0;
int temperature = 0;
float val=0;


void setup() {
  Serial.begin(9600);    //这是设定串行波特率为9600
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}
void loop() {
  temperature = analogRead(potPin); //temp变量为从LM35信号口读取到的数值
  val = ((temperature+1)*0.0048828125*100); //把读取到的temp转换为温度数值
  
  delay(500);                 //延时半秒，1000为1秒，主要是防止刷新过快
  
if (val>80)                                               //热水温区，红色
{
  digitalWrite(13, 0);
  digitalWrite(12, 0);
  digitalWrite(11, 255);
}
else if (val>=70 && val<80)                              //最佳冲泡区，橙色
{
  digitalWrite(13, 0);
  digitalWrite(12, 181);
  digitalWrite(11, 248);
}
else if (val>60 && val<70)                              //冲泡区~饮用区，黄绿色
{
  digitalWrite(13, 0);
  digitalWrite(12, 248);
  digitalWrite(11, 188);
}
else if (val=60)                                               //响铃温度，60，黄色
{
  digitalWrite(13, 0);
  digitalWrite(12, 255);
  digitalWrite(11, 255);
  for(int i=200;i<=800;i++)                    //用循环的方式将频率从200HZ 增加到800HZ
{
  pinMode(9,OUTPUT);
  tone(9,i);                            //在九号端口输出频率
  delay(5);                              //该频率维持5毫秒   
}
delay(4000);                            //最高频率下维持4秒钟
for(int i=800;i>=200;i--)
{
  pinMode(9,OUTPUT);
  tone(9,i);
  delay(10);
}
}
else if (val>=45 && val<60)                              //此区域间温度饮茶等既能保证最佳风味又能尽可能保护口腔及食道黏膜不受伤害，绿色
{
  digitalWrite(13, 0);
  digitalWrite(12, 255);
  digitalWrite(11, 0);
}
else if (val>=20 && val<=45)                              //温水区，日常饮水的适宜温度，蓝色
{
  digitalWrite(13, 255);
  digitalWrite(12, 0);
  digitalWrite(11, 0);
}
else if (val<=20)                                         //凉水区，紫色
{
  digitalWrite(13, 249);
  digitalWrite(12, 119);
  digitalWrite(11, 192);
}

}
