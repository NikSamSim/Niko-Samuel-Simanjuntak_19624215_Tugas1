Penjelasan Program Robot Pertarungan

Saya membuat projek pertarungan robot, yaitu bentu variasi pemrograman pertarungan robot yang lebih baik daripada pertarungan robot pada tugas awal.
Terdapat beberapa perubahan, seperti penambahan kemampuan khusus, interaksi pemain yang lebih dinamis, otomatisasi untuk robot lawan, pengaturan pertarungan yang lebih baik, desain nama robot dan atribut khusus.

Aturan Permainan
1. Pilih Robot: Pemain diminta untuk memilih robot yang akan digunakan dalam pertarungan. Robot yang dapat dipilih memiliki atribut kesehatan, kekuatan serangan, dan kekuatan pertahanan yang berbeda-beda.
2. Pilih Lawan: Setelah memilih robot, pemain kemudian memilih robot lawan dari daftar robot yang tersedia.
3. Giliran Bertarung: Pertarungan berlangsung dalam giliran. Pada setiap giliran, pemain dapat memilih untuk menggunakan kemampuan khusus robotnya:
   a. Kemampuan Bertahan: Meningkatkan kekuatan pertahanan robot, tetapi hanya dapat digunakan sekali.
   b. Bonus Kesehatan: Menambah jumlah kesehatan robot, hanya dapat digunakan sekali.
   c. Serangan Kritis: Menggandakan (atau melipatgandakan) kerusakan serangan, hanya dapat digunakan sekali.
4. Serangan Otomatis: Robot lawan secara otomatis menggunakan kemampuan kesehatan dan serangan kritis jika belum digunakan.
5. Kemenangan: Pertarungan berlanjut sampai salah satu robot kalah (kesehatannya mencapai 0).

Penjelasan Program
Program ini menggunakan OOP (Object-Oriented Programming) dalam bahasa pemrograman C++. Terdapat tiga kelas utama:
a. Robot: Merepresentasikan robot dengan atribut seperti nama, kesehatan, kekuatan serangan, kekuatan pertahanan, dan kemampuan khusus. Kelas ini juga memiliki metode untuk menyerang lawan dan menggunakan kemampuan khusus.
b. Battle: Mengelola pertarungan antara dua robot. Kelas ini mengatur giliran, mengizinkan pemain untuk menggunakan kemampuan dan melakukan serangan, serta menentukan pemenang.
c. Game: Mengelola koleksi robot, memungkinkan pemain untuk memilih robot dan lawan, serta memulai permainan.

Arti Nama Masing-Masing Robot
1. AegisX
   "Aegis" dalam mitologi Yunani berarti perisai atau pelindung. Nama ini mencerminkan kemampuan bertahan robot ini yang unggul, memberikan perlindungan ekstra dalam pertarungan.
   Kemampuan Khusus: Memiliki kemampuan bertahan terbaik di antara robot lainnya.
2. Vitalis
   Berasal dari kata Latin "vitalis" yang berarti "hidup" atau "penting". Nama ini mencerminkan kekuatan robot dalam memulihkan kesehatan, membuatnya tangguh dalam hal stamina.
   Kemampuan Khusus: Memiliki kemampuan bonus kesehatan yang terbaik di antara robot lainnya.
3. CritStorm
   Kombinasi dari "Critical" (serangan kritis) dan "Storm" (badai). Nama ini menunjukkan kekuatan serangan kritisnya yang sangat kuat, seperti badai yang menghancurkan.
   Kemampuan Khusus: Memiliki kemampuan serangan kritis yang paling kuat di antara robot lainnya.

Setiap robot dalam permainan ini memiliki karakteristik unik sehingga pemain harus berpikir dengan cermat untuk menggunakan kemampuan khusus yang dimiliki oleh robot.
Berikut adalah perbedaan utama antara program robot pertarungan yang baru dengan program awal yang saya buat untuk tugas awal:
1. Penambahan Kemampuan Khusus
   Program Awal: Setiap robot hanya memiliki kesehatan dan kekuatan serangan.
   Program Baru: Setiap robot memiliki tiga kemampuan khusus yang dapat digunakan sekali selama pertarungan:
   Kemampuan Bertahan: Meningkatkan kekuatan pertahanan robot.
   Bonus Kesehatan: Menambah kesehatan robot.
   Serangan Kritis: Menggandakan (atau melipatgandakan) kerusakan yang diberikan saat menyerang.
2. Interaksi Pemain yang Lebih Dinamis
   Program Awal: Pemain hanya mengatur serangan dalam giliran tanpa opsi untuk memilih kemampuan tambahan.
   Program Baru: Pemain diberikan kesempatan untuk memilih apakah ingin menggunakan kemampuan bertahan, bonus kesehatan, dan serangan kritis pada setiap serangan, menciptakan elemen strategi yang lebih mendalam.
3. Otomatisasi untuk Robot Lawan
   Program Awal: Tidak ada kemampuan otomatis untuk robot lawan.
   Program Baru: Robot lawan secara otomatis menggunakan kemampuan kesehatan dan serangan kritis jika belum digunakan, menambah elemen kejutan dan tantangan dalam pertarungan.
4. Pengaturan Pertarungan yang Lebih Baik
   Program Awal: Proses pertarungan cenderung lebih linear tanpa pilihan untuk interaksi yang lebih strategis.
   Program Baru: Memperkenalkan sistem giliran yang lebih kompleks, di mana keputusan pemain mempengaruhi hasil pertarungan dengan cara yang lebih signifikan.
5. Desain Nama Robot dan Atribut Khusus
   Program Awal: Robot hanya memiliki nama generik seperti RoboOne, RoboTwo, dan RoboThree.
   Program Baru: Nama robot diubah menjadi lebih kreatif dan bermakna, seperti AegisX, Vitalis, dan CritStorm, dengan kemampuan yang disesuaikan dengan nama-nama tersebut.
