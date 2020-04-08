# Simple Open Ventilator
## Updates:
4/3/2020:
**Tidal volumes look good around 650mL per breath**
* TODO: PEEP
* TODO: Vary Tidal Volume
* TODO: Capture Tidal Volume, Mass, Speed variation in a chart
* TODO: Write up Test procedures

*Introduction:*
Team Seldon is producing plans and prototypes of a ventilator that can be built by tradespeople across the planet from locally obtainable materials.

# Progress:
The block diagram shows our progress to date. Green Blocks are designed built and under test


# Overall System Design
**System Diagram: As currently Implemented**

![System Block Diagram](CurrentBlockDiagram2.png)

-----------

More [Diagrams](Diagrams/README.md) under development
[Document](COVIDventv3Seldon.pdf) detailing efforts so far.

-----------

# Major Blocks of the Design
**Note: some of these links are not complete yet**

* [ **Air Source** ](AirSource/README.md)
* [ **Pressure Relief Valve**](PressureRelief/README.md)
* [ **Air Filter Source**](AirFilter/README.md)
* [ **Pressure Control Valve**](PressureControlValve/README.md)
* [ **Pressure Gauge Header**](LowPressureManometer/README.md)
* [ **Distribution Header** ](Distribution/README.md)
* [ **Branch Outlet**](Distribution/README.md)
* [ **Flow Control Valve**](Distribution/README.md)
* [ **Time Control Solenoid -INLET**](/Valve/README.md)
* [ **Pressure Gauge - Patient** ](/LowPressureManometer/README.md)
* [ **VOLUME/PRESSURE Control Device**](/PACMAN/README.md)
* [ **Time Control Solenoid -PATIENT**](/Valve/README.md)
* [ **Pressure Gauge - Patient** ](/LowPressureManometer/README.md)
* [ **Patient -- Specifications**](/Patient/README.md)
* [ **Time Control Solenoid -EXHAUST**](/Valve/README.md)
* [ **Air Filter Exhaust**](/AirFilter/README.md)
* [ **Pressure Control Valve - PEEP**](/PEEP/README.md)
* [ **Electronic Control System**](/Controls/README.md)
* [ **Bill Of Materials ](/BuildInfo/README.md) -- Current cost 422.80
---------
# **Ventilator Station -- Design Requirements**
* \- *Tidal Air Measurement and Delivery* - 400mL to 600ML
* \- *Respiration Rate* 5-30 Cycles / min
* \- *Pressure* 40mmHg - 60mmHg ... 21.4 inH2O - 32 inH2o
* \- *Tidal Air Removal PEEP* 5-24 inH2O
* \- *Tidal Air Filtration*


---------

# **Test and Measurement**
* [Tidal Volume](TestMeasurement/README.md)
* [Pressure](TestMeasurement/README.md)


---------

# Lessons Learned
* [ Lessons Learned ](Lessons/README.md)

------------

# DISCLAIMER --
See main [Page](../README.md) **Lawyers: This project is to demonstrate the possibility**
