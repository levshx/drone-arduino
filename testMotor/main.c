#include <Servo.h> 

Servo motor;

int mot_pin_left = 7;    //Подключаем мотор к пину 7

int js_position = 1500;  //Начальная позиция, всегда 1.5 мс для регуляторов бесколлекторных двигателей
int max_position = 2300; //Максимальное значение ШИМ 2.3 мс
int min_position = 800;  //Минимальное значени ШИМ 0.8 мс

int start = 1;  //Флаг задержки запуска

void setup() 
{
  motor.attach(mot_pin_left, js_position, max_position);    //Инициальзация мотора (порт, начальная позиция, максимальная позиция)       !!!
} 

void loop() 
{
  //Начальная установка регуляторов в нулевое положение
  if(start == 1) {
    motor.write(js_position);
    delay(700);
    start = 0;
  }
  
  js_position = analogRead(A0);  //Считывание положения потенциометра
  
  js_position = map(js_position, 0, 1023, 75, 140);  //Преобразование положения потенциометра в угол поворота
  motor.write(js_position);     //Записываем положение и отправляем на регулятор мотора 
  
  delay(20);  //Задержка цикла 20 мс
}
