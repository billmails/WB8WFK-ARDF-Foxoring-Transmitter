<h2>WB8WFK ARDF Foxoring Transmitter</h2>
<p>This is a simple, inexpensive, transmitter controller for conducting ARDF Foxoring competitions and for demonstrating ARDF principles. The software project is an Arduino script that builds for and runs on most Arduino-like products, including <a href="https://www.adafruit.com/product/2590">AdaFruit's Metro Mini 328</a>, or <a href="https://www.sparkfun.com/products/11113">SparkFun's Arduino Pro Mini 328</a>, and many more.</p>

<p>After being programmed, the controller is configured via a serial port on the microprocessor. An Arduino board that includes a USB-to-Serial converter will allow you to configure the controller with a simple USB cable running between a USB port on your computer to one on the Arduino board. Less sophisticated Arduino boards lacking a USB-to-Serial converter will require a special FTDI cable like <a href="https://www.adafruit.com/product/70">AdaFruit's FTDI Serial TTL-232 USB Cable</a>, or <a href="https://www.sparkfun.com/products/9718">SparkFun's FTDI Cable 5V</a>.</p>

<p>The controller includes an output pin for controlling a transmitter for sending Morse code characters (high = key down; low = key up) and a separate pin that sends the Morse code as audio tones that can be used to drive a speaker. The controller can also provide a sequence of starting-tones prompting competitors to begin a competition, and can thus serve as an electronic starting "gun" for use in ARDF events.</p>

<h3>Serial Commands</h3>
<p>The controller serial interface operates at 57600 baud that can be accessed using any serial TTY interface program such as PuTTY or Arduino's own Serial Monitor tool. It provides a command prompt > indicating that it is ready to receive recognized the following commands.<p>
  
  <p>	CAL <num>\n
  FAC\n
  DIP\n
  LED\n
  SYN\n
  TEM\n
  ID\n
  GO\n
  RST\n
  SPD\n
  STA\n
  VER\n
  <p/>

<p>A schematic design, a bill of materials, and a source for ordering a printed circuit board will be made available soon.</p>

