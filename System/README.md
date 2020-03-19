# Simple Open Ventilator
**Lawyers: This project is to demonstrate the possibility**

The goal of this project is to demonstrate that a complex ventilator is possible to build with nearly all hardware store parts. We are actually building one that can be demonstrated and tested. We are documenting our efforts here.

What does a ventilator need to do in the simplest case. It needs to gently push air to lungs and assist with exhale. We can do this with a constant pressure source, a few valves, and the Venturi effect. We will not be worried about noise or efficiency.

This simplest diagram shows and airsource, a valve that opens one side or the ether (L/R) allowing gas to pass vertially on that side. The left hand side flows air into the balloon. The right hand side allows air to leave the balloon, but assists the exhaust applying a slight vac to the output.

![Simple Diagram](Simple.jpg)

.

 What is preventing more innovation in this field? Simply put -- lawye

We have to convert medical terms into regular physics and engineering terms for the design to move forward.




# Overall System Design
**System Diagram**
**Under Development -- Not accurate yet**
![System Block Diagram](SystemBlockDiagram4.png)
As many parts from HD as possible

Air Pressure Delivery
* \- Manometer -- Pressure control Vale
* \- Pressure Control Valve
* \- Over Pressure Relief Valve
* \- Distribution System
* \- Individual tap
* \- Ambubag compressor
* \- Exhale Filter

# [Air Pressure Delivery](AirPressureDelivery/README.md)
We need air pressure to run the system and to provide venturi for exhale filtering.

# [Low Pressure Manometer](LowPressureManometer/README.md)
Critical Enabling design element, without this very simple measurement tool, you are just guessing. Measurements are taken with yardstick / meter stick. We can measure .47mmHg with a 1/4" or .37mmHg with 0.5cm. This is because H2O is much less dense than Mercury (Hg).

# [Pressure Control Valve](PressureControlValve/README.md)
Responsible for the overall system pressure regulation. Simple design based on gravity and a leaky regulator. *Still working to make it simpler*

# [Pressure Relief Valve](PressureRelief/README.md)
Responsible for overpressure protection. Fails in the OPEN position, meaning entire system pressure drops to ambient. Assumes a critical failure requires immediate attention. *Testing underway*
