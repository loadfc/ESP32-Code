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

<hr>





