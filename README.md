<h1>WB8WFK ARDF Foxoring Transmitter</h1>
<p>This is a simple, inexpensive, transmitter and controller for conducting ARDF Foxoring competitions and for demonstrating ARDF principles. The software project is an Arduino script that builds for and runs on most Arduino-like products, including <a href="https://www.adafruit.com/product/2590">AdaFruit's Metro Mini 328</a>, or <a href="https://www.sparkfun.com/products/11113">SparkFun's Arduino Pro Mini 328</a>, and most any board with an ATMEGA328P processor.</p>

<p>Controller support for all the common ARDF competition formats is provided: Classic, Sprint, and Foxoring.</p>

<h2>Software</h2>
<p>The software is a proper Arduino script that will open and build without warnings or errors in Arduino IDE version 1.8.12 and later. It has also been shown to work with the online <a href="https://create.arduino.cc/editor">Arduino Web Editor</a>. The Arduino IDE can be used to program a device that contains a compatible bootloader. Most Arduino products ship with a bootloader pre-installed.</p>

<p>After being programmed, the controller can be configured via a serial port on the board. An Arduino board that includes a USB-to-Serial converter will allow you to configure the controller with a simple USB cable (standard to micro) connected between a USB port on your computer to one on the Arduino board. Less sophisticated Arduino boards lacking a USB-to-Serial converter will require a special FTDI cable like <a href="https://www.adafruit.com/product/70">AdaFruit's FTDI Serial TTL-232 USB Cable</a>, or <a href="https://www.sparkfun.com/products/9718">SparkFun's FTDI Cable 5V</a>.</p>

<p>The fox-controller software provides an output pin for controlling a transmitter for sending Morse code characters (high = key down; low = key up) and a separate pin that sends the Morse code as audio tones that can be used to drive a speaker. The controller can also provide a sequence of starting-tones prompting competitors to begin a competition, and can thus serve as an electronic starting "gun" for use in ARDF events.</p>

<h3>Serial Commands</h3>
<p>The fox-controller serial interface operates at 57600 baud, and can be accessed using any serial TTY interface program such as PuTTY or Arduino's own Serial Monitor tool. It provides a command prompt > indicating that it is ready to receive any of the following commands.
</p>

<pre><p><b>> CAL [num]</b>  <= <i>* Sets the clock calibration for precise timing</i><br>
<b>> CAL</b>  <= <i>Displays the clock calibration setting</i><br>
<b>> DIP [val]</b>  <= <i>* Sets the competition format, overriding the DIP switch settings</i><br>
<b>> DIP</b>  <= <i>Displays the competition format setting</i><br>
<b>> FAC</b>  <= <i>Sets saved EEPROM values to their original defaults</i><br>
<b>> GO</b>  <= <i>Starts operation from zero seconds, equivalent to pressing the sync button</i><br>
<b>> ID [string]</b>  <= <i>* Sets the callsign that gets sent</i><br>
<b>> ID</b>  <= <i>Displays the saved callsign setting</i><br>
<b>> LED [on|off]</b>  <= <i>* Turns on/off LED pin</i><br>
<b>> LED</b>  <= <i>Displays the LED pin setting</i><br>
<b>> RST</b>  <= <i>Resets the processor</i><br>
<b>> SPD ID [num]</b>  <= <i>* Sets the ID code speed in WPM</i><br>
<b>> SPD</b>  <= <i>Displays the ID code speed setting</i><br>
<b>> STA [on|off]</b>  <= <i>* Turns on/off the starting tones function</i><br>
<b>> STA</b>  <= <i>Displays the starting tones setting</i><br>
<b>> TEM</b>  <= <i>Displays the processor's temperature in C</i><br>
<b>> TXE [on|off]</b>  <= <i>* Turns on/off the transmitter</i><br>
<b>> TXE</b>  <= <i>Displays the transmitter setting</i><br>
<b>> VER</b>  <= <i>Displays the software version number</i></p></pre>

<p>* These values get stored to EEPROM and are retained between power cycles. </p>
<h2>Hardware</h2>
<p>Look in the Hardware folder for all hardware-related documents</p>
<h3>Pinout</h3>

![Docs/ControllerPinout.png](Docs/ControllerPinout.png)

<pre><p><b>PB1 - Board Pin 9  (Output)</b> <= Audio Out (=Gnd when no tone)<br>
<b>PB5 - Board Pin 13 (Output)</b> <= LED On=VCC<br>
<b>PD2 - Board Pin 2  (Output)</b> <= Key/PTT On=VCC<br>
<b>PD3 - Board Pin 3  (Input)</b>  <= Synchronize (mom. switch to Gnd)<br>
<b>PD4 - Board Pin 4  (Input)</b> <= DIP Switch Bit 0 (switch to Gnd)<br>
<b>PD5 - Board Pin 5  (Input)</b> <= DIP Switch Bit 1 (switch to Gnd)<br>
<b>PD6 - Board Pin 6  (Input)</b> <= DIP Switch Bit 2 (switch to Gnd)</p></pre>

<h2>Usage</h2>
<p>The transmitter can be configured using the serial port, or using the DIP switch and sync-button hardware interface. Only a subset of the possible configurations is available when using only the hardware interface. Configuring the DIP setting with a serial port command to anything but CLASSIC BEACON (zero) will disable the hardware DIP switch.</p>
<p>In the table below, default settings are shown in <b>boldface</b>. Serial command arguments may be abbreviated using the first letter of the word. For example: <b>> DIP CLASSIC BEACON</b> can be shortened to <b>> DIP C B</b>.</p>
<p>
    <table>
        <tr>
            <th>Function</th>
            <th>Software Commands</th>
            <th>Hardware Settings</th>
        </tr>
        <tr>
            <td>Homing Beacon</td>
            <td><b>> DIP CLASSIC BEACON</b><br>[Note: the DIP switch must also be set to 0-0-0]</td>
            <td>DIP = 0-0-0</td>
        </tr>
        <tr>
            <td>Classic Fox#1</td>
            <td>> DIP CLASSIC 1<br>> GO</td>
            <td>DIP = 0-0-1<br>Sync to start</td>
        </tr>
        <tr>
            <td>Classic Fox#2</td>
            <td>> DIP CLASSIC 2<br>> GO</td>
            <td>DIP = 0-1-0<br>Sync to start</td>
        </tr>
        <tr>
            <td>Classic Fox#3</td>
            <td>> DIP CLASSIC 3<br>> GO</td>
            <td>DIP = 0-1-1<br>Sync to start</td>
        </tr>
        <tr>
            <td>Classic Fox#4</td>
            <td>> DIP CLASSIC 4<br>> GO</td>
            <td>DIP = 1-0-0<br>Sync to start</td>
        </tr>
        <tr>
            <td>Classic Fox#5</td>
            <td>> DIP CLASSIC 5<br>> GO</td>
            <td>DIP = 1-0-1<br>Sync to start</td>
        </tr>
        <tr>
            <td>Classic Demonstration</td>
            <td>> DIP CLASSIC DEMO</td>
            <td>DIP = 1-1-0</td>
        </tr>
        <tr>
            <td>Foxoring</td>
            <td>> DIP FOXORING</td>
            <td>DIP = 1-1-1</td>
        </tr>
        <tr>
            <td>Spectator Beacon</td>
            <td>> DIP FOXORING SPEC</td>
            <td>N/A</td>
        </tr>
        <tr>
            <td>Sprint Fox Slow #1</td>
            <td>> DIP SPRINT S1</td>
            <td>N/A</td>
        </tr>
        <tr>
            <td>Sprint Fox Slow #2</td>
            <td>> DIP SPRINT S2</td>
            <td>N/A</td>
        </tr>
        <tr>
            <td>Sprint Fox Slow #3</td>
            <td>> DIP SPRINT S3</td>
            <td>N/A</td>
        </tr>
        <tr>
            <td>Sprint Fox Slow #4</td>
            <td>> DIP SPRINT S4</td>
            <td>N/A</td>
        </tr>
        <tr>
            <td>Sprint Fox Slow #5</td>
            <td>> DIP SPRINT S5</td>
            <td>N/A</td>
        </tr>
        <tr>
            <td>Sprint Fox Fast #1</td>
            <td>> DIP SPRINT F1</td>
            <td>N/A</td>
        </tr>
        <tr>
            <td>Sprint Fox Fast #2</td>
            <td>> DIP SPRINT F2</td>
            <td>N/A</td>
        </tr>
        <tr>
            <td>Sprint Fox Fast #3</td>
            <td>> DIP SPRINT F3</td>
            <td>N/A</td>
        </tr>
        <tr>
            <td>Sprint Fox Fast #4</td>
            <td>> DIP SPRINT F4</td>
            <td>N/A</td>
        </tr>
        <tr>
            <td>Sprint Fox Fast #5</td>
            <td>> DIP SPRINT F5</td>
            <td>N/A</td>
        </tr>
        <tr>
            <td>Sprint Demonstration</td>
            <td>> DIP SPRINT DEMO</td>
            <td>N/A</td>
        </tr>
        <tr>
            <td>Starting Tones Generator</td>
            <td>> DIP [any of the above]<br><b>> STA ON</b><br>> GO</td>
            <td>N/A</td>
        </tr>
        <tr>
            <td>Synchronize</td>
            <td>> GO</td>
            <td>Pull sync pin low for at least 1 second<br>Allow sync pin to rise<br>[Must happen within 1 fox cycle after power-on]</td>
        </tr>
    </table>
</p>
