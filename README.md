🏠 AURA HOME

IoT-Based Smart Home Automation System

AURA HOME is an IoT-based smart home automation system that allows users to remotely control four lights using Arduino IoT Cloud. The system uses an LPC2129 ARM7 microcontroller, UART communication, a 4-channel relay module, and a 16×4 LCD.

---

📌 Project Overview

In a conventional home, electrical appliances are controlled manually using switches.

AURA HOME provides a simple IoT-based solution where the user can control lights remotely from an IoT Cloud dashboard.

The cloud command is transferred to the embedded controller through UART. The LPC2129 processes the command and controls the corresponding relay. The relay then switches the lighting load.

The LCD displays the current status of all four lights.

---

⚙️ Working Principle

The complete working process is:

User
  ↓
Arduino IoT Cloud
  ↓
IoT Controller
  ↓
UART Communication
  ↓
LPC2129
  ↓
GPIO Control
  ↓
4-Channel Relay Module
  ↓
Light

Step-by-Step Working

1. User Gives a Command

The user opens the Arduino IoT Cloud dashboard and changes the required light from OFF to ON.

For example:

Light 1 → ON

The IoT Cloud variable associated with Light 1 changes its state.

---

2. IoT Controller Processes the Command

When the cloud variable changes, the corresponding callback function is executed.

For example:

onLight1Change()

The controller converts the change into a command such as:

light1on

For turning it OFF:

light1off

The same process is used for the other three lights.

---

3. Command Is Sent Through UART

The IoT controller sends the command to the LPC2129 through UART.

For example:

IoT Controller
      │
      │  "light1on"
      ↓
    UART
      ↓
   LPC2129

UART provides the serial communication link between the IoT section and the embedded control section.

---

4. LPC2129 Receives the Command

The LPC2129 continuously checks the UART receiver.

When a command is received, the characters are stored in a receive buffer.

For example:

l → i → g → h → t → 1 → o → n

The complete command is then compared with the predefined commands in the program.

For example:

strcmp(rx_buf, "light1on")

---

5. LPC2129 Controls the Relay

If the received command is:

light1on

the LPC2129 changes the corresponding GPIO output.

The GPIO signal is connected to Relay 1.

LPC2129 P0.14
      ↓
Relay 1
      ↓
Light 1

Similarly:

P0.15 → Relay 2 → Light 2
P0.16 → Relay 3 → Light 3
P0.17 → Relay 4 → Light 4

---

6. Relay Switches the Light

The LPC2129 does not directly supply the current required by the light.

Instead, the relay acts as an electrically controlled switch.

LPC2129
   ↓
Relay Module
   ↓
Relay Contact
   ↓
Lighting Load

When the relay is activated, its contact changes state and completes the external lighting circuit.

For a normally OFF light:

Relay OFF → Light OFF
Relay ON  → Light ON

A 4-channel 5 V relay module using SRD-05VDC-SL-C relays can be used for the four lighting channels.

---

7. LCD Displays the Status

After controlling the relay, the LPC2129 updates the 16×4 LCD.

For example:

LIGHT_1:ON
LIGHT_2:OFF
LIGHT_3:OFF
LIGHT_4:OFF

This provides local feedback about the current state of the lights.

---

🔄 Example: Turning ON Light 1

Suppose the user wants to turn ON Light 1.

Step 1:
User selects Light 1 → ON

        ↓

Step 2:
Arduino IoT Cloud detects the change

        ↓

Step 3:
onLight1Change() is executed

        ↓

Step 4:
Controller sends "light1on"

        ↓

Step 5:
UART transfers the command

        ↓

Step 6:
LPC2129 receives "light1on"

        ↓

Step 7:
LPC2129 identifies the command

        ↓

Step 8:
P0.14 controls Relay 1

        ↓

Step 9:
Relay 1 switches the lighting circuit

        ↓

Step 10:
Light 1 turns ON

        ↓

Step 11:
LCD displays LIGHT_1:ON

---

🔌 Relay Interface

The relay is used as the interface between the low-power microcontroller and the lighting load.

Relay Mapping

LPC2129 GPIO| Relay Channel| Load
P0.14| Relay 1| Light 1
P0.15| Relay 2| Light 2
P0.16| Relay 3| Light 3
P0.17| Relay 4| Light 4

The relay module provides the switching interface so that the LPC2129 GPIO does not directly carry the load current.

«Safety: For mains-powered lights, use an appropriately rated relay, protection, insulation, enclosure, and wiring. Mains connections should be handled by a qualified person.»

---

📡 UART Commands

The system uses simple commands for controlling the lights:

Command| Function
"light1on"| Turn Light 1 ON
"light1off"| Turn Light 1 OFF
"light2on"| Turn Light 2 ON
"light2off"| Turn Light 2 OFF
"light3on"| Turn Light 3 ON
"light3off"| Turn Light 3 OFF
"light4on"| Turn Light 4 ON
"light4off"| Turn Light 4 OFF

---

🔧 Hardware Components

- LPC2129 ARM7 Microcontroller
- Arduino IoT Cloud compatible controller
- 4-Channel 5 V Relay Module
- SRD-05VDC-SL-C Relays
- 16×4 LCD
- Four Lights / Loads
- Power Supply
- Connecting Wires

---

💻 Technologies Used

- Embedded C
- ARM7 / LPC2129
- GPIO Programming
- UART Communication
- LCD Interfacing
- Relay Interfacing
- Arduino IoT Cloud
- Arduino IDE
- Keil µVision

---

📂 Project Structure

AURA-HOME/
│
├── home.c
├── lcdheader.h
├── uartheader.h
├── Untitled_jul12a.ino
├── thingProperties.h
├── arduino_secrets.h
└── sketch.json

---

✨ Features

- Remote control of four lights
- Arduino IoT Cloud integration
- UART communication
- LPC2129-based embedded control
- Relay-based load switching
- 16×4 LCD status display
- Individual ON/OFF control for each light

---

🚀 Future Enhancements

- Automatic light control using sensors
- Energy consumption monitoring
- Temperature and humidity monitoring
- Appliance scheduling
- Mobile notifications
- Voice-controlled appliances
- Fan and motor control
- Smart energy management

---

🎯 Skills Demonstrated

Embedded C • ARM7/LPC2129 • GPIO • UART • LCD Interfacing • Relay Interfacing • IoT • Arduino IoT Cloud
