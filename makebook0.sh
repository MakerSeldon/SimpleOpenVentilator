pandoc -o SimpleVent.pdf title.txt \
  README.md \
  System/README.md \
  System/AirDistrubution/README.md \
  System/AirFilter/README.md \
  System/AirPressureDelivery/README.md \
  System/AirSource/README.md \
  System/AmbuBag/README.md \
  System/Diagrams/README.md \
  System/ElectoMechanicalControlSystem/README.md \
  System/IndividualDistribution/README.md \
  System/Lessons/README.md \
  System/LowPressureManometer/README.md \
  System/LowPressureManometer/README.md \
  System/PressureControlValve/README.md \
  System/PressureDistribution/README.md \
  System/PressureRelief/README.md \
  Documents/VulcanREQ.md \
  Documents/README.md \
  Documents/license.md \
  --variable mainfont="DejaVu Sans" \
  --variable monofont="DejaVu Sans Mono" \
  --variable fontsize=11pt \
  --variable geometry:"top=1.5cm, bottom=2.5cm, left=1.5cm, right=1.5cm" \
  --variable geometry:a4paper \
  --variable number-sections \
  --table-of-contents \
  --reference-links \
  --pdf-engine=pdflatex \
