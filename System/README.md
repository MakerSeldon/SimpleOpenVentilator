# Simple Open Ventilator

**Lawyers: This project is to demonstrate the possibility**

**Goal: Build a demonstration ventilator with as many locally available parts as possible**

Our [Main Page](../README.md) has the overall description and mission. These are describes the actual buildout of the system.

# Overall System Design
**System Diagram**
**Under Development -- Not accurate yet**
![System Block Diagram](SystemBlockDiagram4.png)

# Major Blocks of the Design
* **Air Pressure Delivery:** Generate enough clean Air Flow and Pressure for system
* **Air Filtration:** Filter the air for use
* **Pressure Measurement Tool** Manometer to measure pressure
* **Pressure Control Valve** Keep Constant pressure between 21.4 inH2O and 32 inH2O
* **Pressure Relief Valve** Over Pressure Safety Valve
* **Air Pressure Distribution** Move the air around
* **Individual Station Air Tap**
* **Ventilator Station**
* \- *Tidal Air Measurement and Delivery*
* \- *Respiration Rate*
* \- *Tidal Air Removal*
* \- *Tidal Air Filtration*


# [Air Source](AirPressureDelivery/README.md)
We need air pressure to run the system and to provide venturi for exhale filtering.
* **Version 1 Built**

# [Air Filtration](AirFilter/README.md)
We need air pressure to run the system and to provide venturi for exhale filtering.
* **Version 1.0 Built tested, Failed**
* *Version 2.0 Based on wooden Crate*

# [Pressure Measurement Tool](LowPressureManometer/README.md)
The Low Pressure Manometer is the critical enabling design element, without this very simple measurement tool, you are just guessing. Measurements simple and taken with yardstick / meter stick. We can measure .47mmHg with a 1/4" or .37mmHg with 0.5cm. This is because H2O is much less dense than Mercury (Hg).
* **Version 3.0 Tested, built and documented**

# [Pressure Control Valve](PressureControlValve/README.md)
Responsible for the overall system pressure regulation. Simple design based on gravity and a leaky regulator.
* **Version 3.0 Built, tested, TODO: Document**


# [Pressure Relief Valve](PressureRelief/README.md)
Responsible for overpressure protection. Fails in the OPEN position, meaning entire system pressure drops to ambient. Assumes a critical failure requires immediate attention.
* **Verision 1.0, Built,  *Testing underway***

# [Air Pressure Distribution](PressureDistribution/README.md)
* **Version 1.0 Built, in use, TODO: Document**

# [Individual Air Station](IndividualDistribution/README.md)
* **Version 1.0 Designed TODO: Build, Test, Document**

# [Ventilator Station](VentilatorStation/README.md)

* \- *Tidal Air Measurement and Delivery*
      **Recieved Ambu+ bag in mail, Discovery TODO: lots**
      
* \- *Respiration Rate*
      **RC bi-stable multi-vibrator with Relays and solenoids**

* \- *Tidal Air Removal*
      **Venturi Effect**

* \- *Tidal Air Filtration*
      **Filter in a box with UV light**
