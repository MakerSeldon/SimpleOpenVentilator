# Valve Control Design
**Verion 1.0**
**TODO: Build, Test, Document**

Ideally we have one mechanical valve to do it all with only actuating that valve.
But that is probably not possible.

**FailSafe Condition**
* Ambu+ bag works with a hand.
* System can be extracted without disconnecting patient.

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

**Fill [Ambu+ Bag](/System/AmbuBag/ambubagdrawing.jpg)**
Normally the anti-backflow valve is closed by the suction created when the bag re-inflates. We need to close our Flow valve (B). The Ambu+ Bag suction is created by the bag attempting to return to the open state. The air infills through two one way ports on the intake side of the bag. We will have to defeat these ports to make the bag inflate, assuming that is complete. Valve A will need to be open and Valve B will need to be closed to inflate the bag.

**Fill Patient Lungs**
For this we need to Close Valve A to limit the volume of air entering the lungs. The valving on the bag will keep the bag inflated even under pressure from The Pac-man actuator, giving us stabilization time. Valve C (Exhaust) Valve also needs to be closed (possibility of elimination). Now we open Valve B. The open valve lets the weight on top of the pac-man close on the Ambu+ bag at a particular rate based on the weight(makes pressure) and the orifice that air is going through. We are looking for an ideal Inspiratory Time of 0.4 seconds (Vulcan Reference). Then Valve B closes enabling refill of the amub+ bag

**Patient Exhale**
In most cases the weight of the patients chest exhausts the air. In the normal case the air is pushed out an open orifice for minimum resistance. We want to filter the output air. We will need to add a little assistance for patients that are bad off, or if the filter box puts too much resistance. Once B is closed, C opens. Enbling Venturi assist exhale to equalize the resistance of the filter box or assist the patient.

Is this true ? In All Cases -- Even Off Case:
valve B = !Valve(A)


![Schematic Diagram -- Current](/System/SystemBlockDiagram4.png)
# Logical Control -- Practicing with tables.
| Valve Name|
|State Name | A | B | C |
-------------------------
|Input| Open | Closed | Open|
|Dwell| Closed| Closed | Closed|
|Output| Closed|Open|Open|
| Power out | Open| Closed |Open|
