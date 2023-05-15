# Algoritma-Analizi-ve-Tasarimi-Kisa-Sinav-2.1
Algoritma Analizi ve Tasarımı Kısa Sınav 2.1 Kod

Eski kodla karşılaştırıldığında:
Bubble Sort Algoritması yerine Merge Sort Algoritması
Floyd-Warshall Algoritması yerine Dijkstra Algoritması kullanılmıştır.

Kullanılan Algoritmaların Zaman Karmaşıkları Açıklaması:
-Merge Sort
-->Merge sort algoritmasının zaman karmaşıklığı O(n log n) şeklindedir. 
-->Merge sort, sıralanacak diziyi ikiye böler ve ardından her iki yarıyı ayrı ayrı sıralar.
-->Ardından iki sıralı alt diziyi birleştirerek sonuç diziyi elde eder. 
-->Her bir bölünme işlemi O(log n) zaman alırken, her bir birleştirme işlemi O(n) zaman alır.
-->Bu nedenle toplamda O(n log n) zaman karmaşıklığına sahiptir.

-Dijkstra
-->Dijksta alogritmasının zaman karmaşıklığı O((Düğüm Sayısı + Kenar Sayısı) log Düğüm Sayısı) veya O(Düğüm Sayısı ^2) şeklindedir.
-->Lakin bizim kodumuzda grafımız sabit bir boyuta sahip olduğundan ve matris şeklinde temsil edildiğinden,Dijkstra algoritması için zaman karmaşıklığı O(Düğüm Sayısı ^2) olarak hesaplanabilir.
-->Bunun sebebi iç içe iki döngü kullanılarak her düğümün diğer düğümlere olan en kısa yolları hesaplanmasıdır.
-->Bundan dolayı bizim kodumuzda Dijkstra algoritmasının zaman karmaşıklığı O(Düğüm Sayısı ^2) şeklindedir.
