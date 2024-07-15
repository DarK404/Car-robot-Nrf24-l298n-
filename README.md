# RF24 Controlled Servo and Motor System

This project demonstrates how to control a servo and motor system wirelessly using RF24 modules, Arduinos, and a pair of transmitters and receivers.

## Table of Contents

- [Introduction](#introduction)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)


## Introduction

This project utilizes two Arduino boards equipped with RF24 modules to wirelessly transmit and receive signals to control a servo and motor system. The transmitter reads analog values from potentiometers or joysticks and sends these values to the receiver, which then controls the servo and motor accordingly.

## Hardware Requirements

- 2 x Arduino Uno
- 2 x nRF24L01+ Transceiver Modules
- 2 x Joysticks or Potentiometers
- 1 x Servo Motor
- 2 x DC Motors
- Motor Driver (e.g., L298N)
- Breadboard and Jumper Wires
- Power Supply

## Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software)
- RF24 Library (available via Arduino Library Manager)
- Servo Library (built-in with Arduino IDE)

## Installation

1. **Clone the repository:**
   ```sh
   git clone https://github.com/DarK404/Car-robot-Nrf24-l298n-.git
