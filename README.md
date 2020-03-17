# OpenVert -
Open Source, Open Hardware experimental design for home built ventilator for learning about how they work. We take learning very seriously. Our system design and build can be seen: 

---------
 # [System/README.md](System/README.md)
Progress of current build out. Not a lot of software, it is Physics based.
We

----------
# Disclaimer
Due to liability issues
**No warranty of usefulness at all**

# Donations
If you want to donate to the project you may donate to a developer directly for parts etc:
```
BTC: 12VbmzcMsj5VtiCuqSdMPihkLPt9UEqHfd
```

Or you can done to a 501(c)3
**The Asymmetrical Biodiversity Studies and Observation Group**
[(ABSOG)](https://threesecondsuntilmidnight.com/absog/)
They are working on a direct donation page.

# License
Until we get further guidance the project is licensed as such:
* CERN Open Hardware Licence Version 2 - Permissive [license](/license.md)

# Motivation
COVID-19 has exposed a critical shortage in our medical care capabilities, and supply chain. (REF Italy doc report). Throwing money at the vendors to produce more and faster is unlikely to work in serious world-wide pandemic where supply-chains are shut down, the need for ventilators vastly outstrips the manufacturing capability, or quarantine simply shuts down transportation.


The total number of ventilators available is around 600-800k(1). Of the total ventilators 80% are currently in use for car accidents, surgery recovery, etc. Even if we had 1M and 20% avail that only leave 200k avail. The CDC is predicting over 1M dead in one model. These people might live if ventilators were available. We think we can help, and it is our duty to help. We don't want doctors and nurses having to choose who lives and who dies in the emergency room based on the number of ventilators available.


(1) Based on off the record conversations with USG officials.

# Mission Statement
Our guiding principle is the same of Henry Watt's approach to development of Radar for Britian in WW2
- Perfect is the enemy of good enough and never gets here.
- Second best is always too late.
- Third best will do

'''Watt: The system was deliberately developed using existing commercially available technology to speed introduction.[60] The development team could not afford the time to develop and debug new technology. Watt, a pragmatic engineer, believed "third-best" would do if "second-best" would not be available in time and "best" never available at all. -- quote from wikipedia
'''

# What we have volunteering part time
- Doc reviewing our effort
- Senior Hydraulic Engineer
- Master Fabricator
- Senior Electrical Engineer

# What we need
- Documentation help
- Fabrication duplication
- Imagineers
- Nurses / PA's
- Makers to help
- Funding for parts & help
- Bitcoin Account for donations
- Accounting Method to show expenditures

# System Diagram
- Diagram is incomplete. Needs reviewing
![Overall System Design](/RawDesigns/openventsystemdiagram.jpg)

# Mass Casualty Ventilator system

COVID-19 has exposed a critical shortage in our medical care capabilities, and supply chain. (REF Italy doc report). Throwing money at the vendors to produce more and faster is unlikely to work in serious world-wide pandemic where supply-chains are shut down, the need for ventilators vastly outstrips the manufacturing capability, or quarantine simply shuts down transportation.

We have a nation of makers, builders, engineers, scientists, and handy people. We need to be able to leverage all of them. We are designing and building a prototype ventilator that can be built from locally available parts. This is meant to spur the innovation that has been stifled by attorneys, government regulation, and fear.

We are using locally sourced parts, our local home improvement store, plumbing store, and party store should carry everything you need.

-----------

What is a ventilator:

At the core a ventilator is a device that assists the breathing in a compromised patient.

Mechanically, it is a device that provides slightly elevated air pressure for assistance for inhaling and slightly lower pressure air for exhaling.

We will start with the constant problem – coughing / sneezing are problems we need to keep in mind but are tomorrow problems – worst case we supply a blow off valve for over pressure

------------
What we need – as absolutely as simple as possible. Mechanical preferred for field repair.

1)	Low Pressure source (2psi – 103mmhg)
2)	Clean air – Free of particles, and contaminates
3)	Pressure regulator for individual patients
4)	Method to deliver air at a slightly elevated pressure
5)	Method to meter the total air volume delivered per inhale breath
6)	Method to assist exhale at slightly lower pressure
7)	Method to meter total air volume exhaled
8)	Method to capture and clean exhaled air


---------------
Guidance Received to date:
From Board Certified Anesthesiologist
* Ideal Tidal Volumes 500-700mL
* Peek Pressure shouldn't exceed 40mmhg, ability to push 60mmhg
* suction is bad -- Need verification of neg pressure vs suction
