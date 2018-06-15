<h4> ตั้งใจจะใช้เป็น Repository สำหรับวิธีการและการใช้งาน ESP32 ตั้งแต่แรกเริ่ม เพื่อจะได้กลับมาทบทวนในภายหลัง</h4>

<h4> สำหรับ Spec ของ ESP-WROOM32 ซึ่งเป็นตัวที่ใช้กันในปัจจุบัน มี Spec ดังนี้ </h4>
<ol>
<li>หน่วยประมวลผล Dual Core Tensilica LX6 ความเร็วสูงสุด 240MHz</li>
<li>RAM ภายใน 520KB</li>
<li>WiFi transceiver B/G/N</li>
<li>Bluetooth  Dual-mode classic และ BLE</li>
<li>Power 2.2 ถึง 3.6V กินกระแสน้อยที่สุด 2.5 µA (ในสถานะ deep sleep)</li>
<li>32 GPIO</li>
<ul>
    <li>10 ช่อง Capacitive Touch</li>
    <li>18 ช่อง Analog-to-Digital converter (ADC)</li>
    <li>3 ช่อง SPI </li>
    <li>3 ช่อง UART </li>
    <li>2 ช่อง I2C </li>
    <li>16 ช่อง ของ PWM</li>
    <li>2 ช่อง Digital-to-Analog Converters (DAC)</li>
    <li>2 ช่อง I2S </li>
 </ul>
 <li>มี Hardware Accelerated Encryption (AES, SHA2, ECC, RSA-4096)</li>
 </ol>    
<h4> สำหรับ Dev. Board ที่ใช้คือ ESP32 ของ DOIT มี PinOut ดังนี้ </h4>
 
<img src="https://raw.githubusercontent.com/playelek/pinout-doit-32devkitv1/master/pinoutDOIT32devkitv1.png" alt="DOIT Pinout">

<br>
<hr>
<h4>การติดตั้ง </h4>
เริ่มต้นก็ต้องติดตั้ง Arduino Core ก่อน โดยไป Download ได้ที่ https://github.com/espressif/arduino-esp32

เมื่อ Download เรียบร้อยแล้ว ก็ให้แตกไฟล์ และนำไปวางที่ C:\Users\[YourName]\Documents\Arduino\hardware\espressif\esp32 
โดยหากไม่มี folder ตั้งแต่ espressif ก็ให้สร้าง folder ขึ้นมาให้ได้ตามข้างต้น โดยให้เปลี่ยนชื่อจาก arduino-esp32-master เป็น esp32 เฉยๆ 

จากนั้นให้เข้าไปที่ C:\Users\[YourName]\Documents\Arduino\hardware\espressif\esp32\tools และรันโปรแกรมชื่อ get.exe 
โดยโปรแกรมนี้จะทำหน้าที่โหลด โปรแกรมและ Library ของ ESP32 

ให้รอจนเสร็จ โปรแกรมจะปิดเอง 

หลังจากนั้นให้ตั้งบอร์ด โดยผมใช้เป็น DOIT ESP32 DEV KIT V.1 แล้วกำหนดพอร์ดให้ถูก จากนั้นทดลองโหลดโปรแกรม Blink ไฟกระพริบเทพลงไป ถ้ามีการกระพริบ ก็แสดงว่าใช้ได้ 

ปล. โปรแกรมทั้งหมด เขียนผ่าน Platform I/O 

https://github.com/khthana/ESP32-Code/blob/master/Blink.cpp

<hr>

<h4>Digital Input : </h4>หลังจากทำไฟกระพริบกันแล้ว ส่วนต่อมาที่มักทำกัน คือ Input เนื่องจากหลายครั้งที่ต้องการการกดปุ่ม <br>
สำหรับการต่อวงจร ผมจะต่อเข้ากับขา 12 ของบอร์ด โดยต่อแบบ Pull Down คือ ปกติจะอ่านได้ Low แต่กดเมื่อไรจะอ่านได้ High <br><br>
โปรแกรมก็จะมีดังนี้ <br>


https://github.com/khthana/ESP32-Code/blob/master/SwitchInput.cpp

<hr>

<h4>Interrupt : </h4>ต่อไปก็จะเป็นการ Attach Interrupt โดยใช้ Hardware เดิม คือ ต่อ Switch เข้าที่ขา 12 ของบอร์ด โดยแทนที่จะต้องมาวนลูปอ่าน Switch ก็ใช้ Interrupt แทน <br>


https://github.com/khthana/ESP32-Code/blob/master/AttachInterrupt.cpp

<hr>

<h4>Analog Input : </h4> ความสามารถที่ Upgrade มาจาก ESP8266 มาก ก็คือ Analog to Digital Converter หรือ ADC โดยมีมาให้ถึง 8 Channel 
โดยจะอยู่ที่ขา ดังนี้ channel 0 = GPIO36, channel 1 = GPIO37, channel 2 = GPIO38, channel 3 = GPIO39, channel 4 = GPIO32, channel 5 = GPIO33, channel 6 = GPIO34, channel 7 = GPIO35

และความละเอียดก็มากขึ้นด้วย โดยมีให้ถึง 0-4096 ระดับ 

สำหรับโปรแกรมนี้ก็จะใช้ GPIO34

https://github.com/khthana/ESP32-Code/blob/master/ADC.cpp

<hr>

<h4>PWM : </h4>ใน ESP32 จะต่างจาก Arduino หรือ ESP8266 เพราะไม่มีคำสั่ง AnalogWrite ให้ใช้ แต่จะใช้ไลบรารีชื่อ LEDC โดยมีรูปแบบคำสั่งดังนี้


void ledcSetup(byte channel, double freq, byte resolution_bits);

channel คือ หมายเลขของ Timer ที่อยู่ภายใน ESP32 โดยมีตั้งแต่ 0-15 
freq คือ ความถี่ที่จะให้ Timer สร้างให้ โดยใช้เป็นความถี่ฐาน 
resolution_bits คือ ค่าความละเอียด ใช้ได้ตั้งแต่ 0-15 (บิต) หากจะใช้เท่ากับ Arduino ก็ใช้ 8 บิต ซึ่งจะต้องสัมพันธ์กับคำสั่ง ledcWrite ด้วย เช่น จากโปรแกรมจะใช้ 13 บิต ดังนั้นในคำสั่ง ledcWrite จะใช้ค่าสูงสุด 8096 โดยค่านี้จะเป็นความละเอียดของ Duty Cycle ที่สามารถใช้ได้ 

อีกฟังก์ชันที่ใช้ คือ 
 
void ledcAttachPin(int pin, byte channel);

จะใช้ในการเชื่อมขาของ ESP32 เข้ากับ Timer (แปลว่าจะใช้ขาอะไรก็ได้) นอกจากนั้น Timer 1 ตัวจะเชื่อมกับหลายขาก็ได้ด้วย 

ฟังก์ชันสุดท้าย คือ 

void ledcWrite(byte channel, int duty);

จะใช้ในการสั่งคลื่นให้ออกทางขา โดยสามารถกำหนด Duty Cycle ได้ (ต้องสัมพันธ์กับ resolution) 

https://github.com/khthana/ESP32-Code/blob/master/PWM.cpp

<hr>
<h4>tone</h4>
เนื่องจากไลบรารีของ ESP32 ไม่มีฟังก์ชัน tone (อีกแล้วครับท่าน ดังนั้นจึงต้องใช้ PWM มาใช้ด้วย โดยในการนี้เราจะ Fix Duty Cycle และเปลี่ยนความถี่ โดยเขาว่ากันว่า Duty Cycle ที่เหมาะสมคือ 5% และเราก็จะเปลี่ยนเฉพาะความถี่ โดยเขาทำเป็นฟังก์ชัน ledcWriteTone(channel, freq); มาให้ โดยเราก็กำหนดเฉพาะความถี่อย่างเดียว และเพื่อให้เห็นภาพ ผมจะทำเป็นเพลง


<hr>

เมื่อเป็น ESP32 ก็ต้องทดสอบกับ DHT22 ซะหน่อย เพราะน่าจะเป็น Input หลักตัวหนึ่ง โดย Code ก็อยู่ใน Link ด้านล่างนี้

https://github.com/khthana/ESP32-Code/blob/master/dht22.ino

<hr>





