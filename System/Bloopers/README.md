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

# Developing and testing the highest risk (PCV)
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

**Manometer is necessary, otherwise we are just guessing, and likely to injure someone**   
________




---
## Initial Build
The initial build started with the hypothesis that assisted breathing can't be
that hard. We should be able to use a reasonably low cost device to provide automated
breathing assistance.

Our First experimental concept was to use a shop vac as an air source, and filter
the output. The hypothesis was to push air into a large box with 1-3 HEPA filters
and UV lighting. The Large box should provide nice low speed laminar flow through
the filters providing for heavier particle to sink to the floor of the filter box.
The low speed laminar flow greatly aids that. The HEPA filters provide the
additional filtering, and the UV lighting in the box kills significant living
bacteria, virii, and other living things in the suspended air. The box was constructed
using cardboard, tape, shower drain fittings, and a HEPA filter.

During the same time frame we were developing the manometer and the pressure control
valve. Testing the PCV and the manometer worked 100% -- Rock stable pressure.
We successfully transformed a constant power source into a constant pressure source
using a linear (lossy) PCV.

Combining the filter, manometer, and PCV showed that the cardboard box was not
going to work it leaked 95% of all the pressure down. Followup calculations show that
a wooden crate with significant reinforcement was going to be required to keep the
filter box nearly airtight.

## Next Step - Safety
We understand that we are new to this world, but in the sub-sea engineering field
safety is always a concern. We added a Pressure Relief Valve to the design.
This makes the system inherently safe to the patient as the supply pressure cannot exceed
a maximum set value. We know this will work, but we are unclear if we need it yet.
Build is complete, but testing is delayed.

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
