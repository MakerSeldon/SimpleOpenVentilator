# Valve Design

Ideally we have one mechanical valve to do it all with only actuating that valve.
But that is probably not possible.

# Design constrants
* Base pressure and flow is regulated by a globe valve and monitored with a low cost [manometer](/System/LowPressureManometer/README.md).
* During power failure, Ambu+ Must still be able to be operated manually

# Theory:
In the power down state the Accumulator/ Ambu+ bag needs to operate normally. Assuming that all the valves on the Ambu+ bag are left intact. Air can enter the ambu bag thru the intake vents. Hand Forced air exits the valve into the mask. Exhaust from the patient returns back up the hose and exits the exhaust port in the front of the bag.

**Power Off State**
These settings are taken care of by putting normally open or normally closed valves in these positions.

* **Valve A CLOSED or Dont Care**
* **Valve B OPEN**
* **Valve C CLOSED**

**Fill Ambu+ Bag**
Normally the anti-backflow valve is closed by the suction created when the bag re-inflates. We need to close our Flow valve (B). The air intake for the bag 


![Schematic Diagram -- Current](/System/SystemBlockDiagram4.png)
# Logical Control -- Practicing with tables.
| Valve Name|
|State Name | A | B | C |
-------------------------
|Input| Open | Closed | Open|
|Dwell| Closed| Closed | Closed|
|Output| Closed|Open|Open|
| Power out | Open| Closed |Open|
