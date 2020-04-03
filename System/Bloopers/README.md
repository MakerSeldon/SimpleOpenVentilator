# Design Notes  & Lessons Learned

## Gravity: Our Friend --
In designing the system we understood that each of the trades groups would be on
their own building these systems. There would be no one to provide oversight and
calibrations. We had to keep the designs as simple as possible, and as accurate as
possible. We chose gravity, mass, and air pressure as the main methods of controls
for the systems. Below is a summation of our impressions:

Basic system concepts
* Only readily available and substitutable parts
* Gravity -- pretty constant +/- small error across the planet
* Mass -- based on gravity
* Water -- readily available
* Air pressure -- most trades people need this anyway
* Self measurement and calibration techniques
* -- Long Time differences
* -- Large Volume changes

**Calibration labs use gravity based instrumentation**

# Concept 1:
The initial concept was to build a pneumatic system that would inflate a manual
assist medical ventilation bag automatically. We joined the #OSventilator movement
and saw that was already being taken care of with multiple different efforts. We
moved on to assist those who will have no access to medical devices.

*The best mechanical squasher we have seen is the Virgin Space (Branson) rotational
electric motor driven version. It is super simple to control and fabricate. It
replaces the human with a very nice robust mechanical squasher that can deliver
repeated precise performance. The squasher should outlast the bag easily. Fabrication
should easily be in the 1000's per week depending on bag and motor availability.*

# Developing and testing the highest risk items: (PCV & Measurement)
The hypothesis that we could use a shop vac (blower side) to power the system had
to be developed first. A shop vac is a constant power device. Meaning if the
input or output becomes partially blocked the pressure increases and the flow decreases.
We needed a constant pressure system. To accomplish this we needed a way to measure
the pressure to even start.

# Manometer development
The medical folks we talked with before the Vulcan Challenge came out told us that
we needed to maintain between 40-60mmHg. Mercury is a bit challenging and difficult
to obtain and use safely. Luckily for us 1mmHg is just over 1/2" H2O. 60mmHg is 32.15".

A manometer is just a U shaped tube filled with a fluid. In our case it was water.
18" on both sides gives us a possible 36" of height measurement. We started with less
and sent water squirting across the lab it really needs to be 24" tall to get good
differential measurements. We added food coloring to make the measurements that
much easier. We went through several designs, before landing on the final one that
is super simple, low cost ($35 for 3) and highly accurate.

________
**Manometer is necessary, otherwise we are just guessing, and likely to injure someone**   
________

## Pressure Control Valve
We went through multiple iterations. We knew what we needed to build. A weight
floating above a pipe that leaked air perpendicular to the force. The weight
was not going to magically be stable, so we needed a robust method that would
guild the weight as it moved up and down. The area needed to be large enough
to lift a significant weight. By using a largish weight and force area, we could
account for large power swings, and the sensitivity of the system to exact weights
was decreased. Our initial thoughts were around coinage. Coinage mass is highly
regulated and accurate. The pressure could easily be adjusted with pocket change.

But making a method to keep the coinage still was challenge. We eventually settled
on a steel pipe inside a standpipe with a cap that went overlapped the standpipe.

Our first build sent the lid into the ceiling of the lab. *After COVID crisis is
over, we will be launching all sorts of things with this system.* Version 1 of our
manometer also sprayed water at the same time. We added some air drain holes to the
overlapping cap, and it began to behave well.

Version 1 of the PCV and manometer were too complicated, we then did several iterations
on these two items to reach near our final design.

## Input filter testing
The main critical parts of the system now functional. We moved on to testing Input
air filtering.

Our First experimental concept was to use a shop vac as an air source, and filter
the output. The hypothesis was to push air into a large box with 1-3 HEPA filters
and UV lighting. The Large box should provide nice low speed laminar flow through
the filters providing for heavier particle to sink to the floor of the filter box.
The low speed laminar flow greatly aids that. The HEPA filters provide the
additional filtering, and the UV lighting in the box kills significant living
bacteria, virii, and other living things in the suspended air. The box was constructed
using cardboard, tape, shower drain fittings, and a HEPA filter.

We placed a manometer on the input and output of the cardboard filter box. It was
basically a super lossy filter. Input pressure was a nice 30 inH2O, output pressure
was around 4 inH2O. This was a failed experiment
Output:
* Shower Drain assemblies make good I/O ports as they are 2"
* Our manometers work nicely
* Filters need to be assembled like crates with the structure on the outside.

**Filters have been put on hold, as it is a construction exercise**

## Emergency Pressure Relief Valve: -- SAFETY
We understand that we are new to this world, but in the sub-sea engineering field
safety is always a concern. We added a Pressure Relief Valve to the design.
This makes the system inherently safe to the patient as the supply pressure cannot exceed
a maximum set value. We know this will work, but we are unclear if we need it yet.
Build is complete, but testing is delayed.


## Accumulator
Next is how to get that constant pressure to cycle to ON/OFF. We began to think
of this as an automated bellows. The Ambu+ bag is designed to work just that way.
We examined the build of the bag and noticed the complex network of mechanical
valves that make the bag work, and keep the patient safe.

Experiment 1:
We were going to use the Ambu+ bag as the accumulator. We tried it by stuffing the
1/2" pipe in the input side and blew air constantly, pumping the bag up nicely.
We needed something that would squash the bag reliably. The bag is shaped like
a football and must be held for operation. We decided a PACMAN or board on a hinge
was the easiest method to fabricate.

After Version 1 of PACMAN was complete, We attempted to use the Ambu+ bag, but could
not get it to reliably fill as the input side of the bag had too many relief valves.
And we couldn't get a good enough seal to lift the weight.

Experiment 2:
Replacement of Ambu+ bag with Turkey Roasting bag. We fabricated a seal with two
PVC plumbing parts, a 2" coupler and a 2" to 3/4 Reducer. This worked remarkably well.

Experiment 3:
Replacement of turkey bag with water bag. This gave us a more robust bag and a bit more
control. This what is currently being used.


## PACMAN
### Version 1: 1 4' piece of leftover laminate flooring and a piano hinge
This went poorly, the piano hinge was wrong for 2 reasons. We needed it to fully
close, but the hinge is optimized for fully opening. And it does not cut very well.

### Version 2: left over door hinge and laminate flooring
This also went poorly as the carriage bolts, we had available prevented the
closing of the hinge

### Verison 3: Hinge mounted to 2x4 block
This version works pretty well.

### Version 3a: 2x4 screwed to deck
During testing it bounced too much

### Version 3b: 1x8 replaced top board
Weight required for squashing and thin laminate flexed and bounced too much.  


 The Ambu+ bag showed us that we needed to make a automates bellows.


---
## Initial Build
The initial build started with the hypothesis that assisted breathing can't be
that hard. We should be able to use a reasonably low cost device to provide automated
breathing assistance.


During the same time frame we were developing the manometer and the pressure control
valve. Testing the PCV and the manometer worked 100% -- Rock stable pressure.
We successfully transformed a constant power source into a constant pressure source
using a linear (lossy) PCV.

Combining the filter, manometer, and PCV showed that the cardboard box was not
going to work it leaked 95% of all the pressure down. Followup calculations show that
a wooden crate with significant reinforcement was going to be required to keep the
filter box nearly airtight.


## Accumulator
We received a Ambu+ Bag as a donation for this effort. The bag has multiple safety
features, valves. We believed this would make a fantastic accumulator. We tested the
bag initially by jamming a 1/2" PVC pipe in the intake side and seeing if we could
inflate the bag safely.

≈

This makes the system
 Now with a inheritly pressure safe system

The initial build started as a way to squish an ambu+ bag. The bag is an approved
medical device designed to manually assist breathing.

The initial experiments
trying to fill the bag with forced air
