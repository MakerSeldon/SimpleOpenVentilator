pandoc -o SimpleVent.pdf title.txt \
  README.md.pandoc \
  System/README.md.pandoc \
  System/AirDistrubution/README.md.pandoc \
  System/AirFilter/README.md.pandoc \
  System/AirPressureDelivery/README.md.pandoc \
  System/AirSource/README.md.pandoc \
  System/AmbuBag/README.md.pandoc \
  System/Diagrams/README.md.pandoc \
  System/ElectoMechanicalControlSystem/README.md.pandoc \
  System/IndividualDistribution/README.md.pandoc \
  System/Lessons/README.md.pandoc \
  System/LowPressureManometer/README.md.pandoc \
  System/LowPressureManometer/README.md.pandoc \
  System/PressureControlValve/README.md.pandoc \
  System/PressureDistribution/README.md.pandoc \
  System/PressureRelief/README.md.pandoc \
  Documents/VulcanREQ.md.pandoc \
  Documents/README.md.pandoc \
  Documents/license.md.pandoc \
  --variable mainfont="DejaVu Sans" \
  --variable monofont="DejaVu Sans Mono" \
  --variable fontsize=11pt \
  --variable geometry:"top=1.5cm, bottom=2.5cm, left=1.5cm, right=1.5cm" \
  --variable geometry:a4paper \
  --variable number-sections \
  --variable documentclass=scrbook \
  --table-of-contents \
  --toc-depth=2 \
  --reference-links \
  --pdf-engine=pdflatex \
