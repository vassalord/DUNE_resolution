# DUNE_resolution

Для дослідження роздільної здатності потрібно згенерувати файл anatree.root. Для повної симуляції виконати всі наведені кроки https://github.com/DUNE/garsoft для симуляції окремих частинок можна скористатися баш скриптом fv.sh, запускати за домомогою команди:

     bash fv.sh
 
Даний скрипт гетенрує текстовий файл з інформацією у форматі hepevt. https://github.com/DUNE/garsoft/blob/develop/EventGenerator/TextFileGen_module.cc - можна подивитись за що відповідає яка змінна.

Для того щоб записувати необхідні змінні потрібно встановити прапорці true: https://github.com/DUNE/garsoft/blob/develop/Ana/anatree.fcl
Наприклад:

    physics.analyzers.anatree.WriteMCPTrajectory: true

Коди для дослідження роздільної здатності написані для виконання в середовщі root. За допомогою makeclass згенеровано два файли .h .C. Детальніше: https://root.cern.ch/root/htmldoc/guides/users-guide/Trees.html#using-ttreemakeclass

Коди для дослідження роздільної здатності в файлах .С, ana2.C код для дослідження роздільної здатності TPC кластерів, написаний на c++. Код, фактично, це цикл по індексу кластерів TPC, отриманий від вектора розміру TPCClusterX. Всередині циклу по кластерам TPC знаходиться внутрішній цикл по точкам траєкторії МС(Монте-Карло) частинок. Програма аналізу просто вибирає найближчі два інтерполятори, і знаходиться перпендикулярну відстань від кластера TPC до місця інтерпольованої доріжки.
Типовими командами для запуску є:

    root> .L ana2.C
    root> ana2 t
    root> t.GetEntry(12); // Fill t data members with entry number 12
    root> t.Show();       // Show values of entry 12
    root> t.Show(16);     // Read and show values of entry 16
    root> t.Loop();

Для дослідження точкової розлільної здатності, за основу був взятий триплетний метод Triplet_metod.C. Для запуску даного файлу також потрібний відповідний файл .h його можна згенерувати за допомогою makeclass або використати ana2.h перейменувавши всі потрібні назви файлу. Детальніше про метод тут: https://inspirehep.net/files/c95c46b5e10066cc9a78fd629b43bf3c сторінка 57. Сам код бере три точки, та шукає відстань від від другої точки до лінії що проведена між першою та третьою точками. 

Залишки для даних методів підпорядковані розподілу Гауса. 





