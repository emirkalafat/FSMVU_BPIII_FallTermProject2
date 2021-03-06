# FSMVU_BPIII_FallTermProject2
BLM19204-BLM204 Bilgisayar Programlama III ve BLM217 
Bilgisayar Programlama III Lab. Dersi 2. Proje
Son Teslim Tarihi: 23.01.2022– 23:59
Bu projede, iki adet büyük sayı (basamak sayıları çok fazla olan sayılar, 
örneğin 1000000) arasında toplama ve çıkarma işleminin yapılması 
amaçlanmaktadır. Bu sayılar sayi1.txt ve sayi2.txt isimli iki ayrı dosyadan 
okunacaktır ve işlem sonucu sonuclar.txt isimli dosyada saklanacaktır.
Kullanıcı programı çalıştırdığında karşısına aşağıdaki gibi bir menü 
çıkmalıdır;
## Buyuk sayilar ile matematiksel işlemler
* [1]-> Dosyadan sayilari oku: (1)
* [2]-> Okunan sayilari ekrana yaz: (2)
* [+/-]-> Islem seciniz: (+ veya -)
* [4]-> Sonucu ekrana yazdır: (4)
* [5]-> Cikis : (5)

Kullanıcı menüde 1 seçerse sayılar dosyadan okunur, 2 seçerse okunan sayılar 
ekrana yazılır, + veya – seçerse işlem seçilir ve gerekli matematiksel 
hesaplama yapılır, 4 seçerse işlem sonucu ekrana yazılır, 5 seçerse program 
sonlanır, 

Gösterilen menü örnektir, kendi uygulamanıza göre düzenleyip 
değiştirebilirsiniz,

C programlama dilinde bulunan veri tiplerinin belirli kapasiteleri 
bulunmaktadır, örneğin int veri tipi 2^32 büyüklüğünde bir sayıyı 
saklayabilmektedir, bu sebeple bu projede standart veri tiplerini 
kullanamazsınız. 

Örnek olarak dosyadan okunan sayı 1000 basamaklı bir ise, bu sayıyı standart 
veri tipleri ile değil tek boyutlu bir array içerisinde saklamalısınız. 
Dosyadan okunan büyük basamaklı sayının her bir basamadığı, tek boyutlu 
array’ in bir elemanında tutulması gerekmektedir.

Örnek olarak dosyadan okunan sayılar sırası ile 100 ve 89 basamaklı (bu 
sayılar örnektir) olarak belirlenmişse, aşağıdaki şekilde örnek olarak 
gösterilen hesaplamanın yapılması gerekmektedir.

Yukarıdaki şekilde gösterildiği gibi kullanıcını belirlediği sayı1 ve sayı2 
için ve belirlenen aritmetik işlem için işlem sonucu sonucunun hesaplandığı 
sonuç görülmektedir.

### Dikkat Edilmesi Gerekenler:
* main.c ana fonksiyonda hiçbir işlem yapılmayacaktır, sadece dosya 
pointer’ değişkenleri, tanımlanması gereken array’ ler ve menü için 
gereken kod bulunabilir,
* Dosyadan sayının okunması ve her bir basamağının bir array elemanına 
yazılması işlemi islemler.h kütüphanesinde yapılmalıdır (not: 
kütüphane dosyaları implementation içermez sadece fonksiyon 
prototipleri bulunabilir)
* Sayıların saklanacağı tek boyutlu arraylar byte türünde olmalıdır, C 
de byte türünde bir veri tipi bulunmamaktadır, bu sebeple 8 bit 
işaretsiz tam sayı tutulan <stdint.h> kütüphanesindeki uint8_t veri 
tipi kullanılmalıdır,
* Dosyadan okunan sayılar heap bellek bölgesinde tutulmalıdır ve program 
sonlandığında bellekten silinmelidir (çöp bellek alanları 
oluşmadığından emin olunuz),
* Matris index gezintileri için [] operatörü kullanımı yasaktır, array 
adresi kullanılarak array elemanlarına erişim sağlanmalıdır,
* Programınız tüm girdilere karşı güçlü olmalıdır, basit hatalı 
girişlerden veya mantıksal hatalardan kırılıp sonlanmamalıdır,
* Projenin teslim edilmesi aşamasında, bir adet Makefile hazılanmalıdır, 
---
> Makefile olmayan projeler 60 puan üzerinden değerledirilir,
Ödevler bireysel olarak yapılmaktadır. Ödevin sonunda bir adet rapor yazmanız 
beklenmektedir. Rapor pdf formatında olmalıdır. Raporu ayrıca çıktı olarak 
getirmenize gerek yoktur. Raporunuzda kısaca sizden istenilen, 
öğrendikleriniz, ödevde yaptıklarınız, eksik bıraktığınız yerler, 
zorlandığınız kısımlar anlatılabilir. Ödev raporunda yazı boyutu 11 punto 
olmalıdır ve rapor en az 1 sayfa en çok 4 sayfa olabilir. Raporunuza 
projenizin çalışan ekran görüntülerini ekleyebilirsiniz.
Raporunuzu ve kaynak dosya(ları)nızı (.c ve .h uzantılı) bir ana klasör 
içine koyarak .zip’leyip LMS web portalı üzerinden yüklemeniz gerekmektedir. 
Kaynak kodlarınızı .c ve .h uzantılı olarak hazırlayınız, word ya da notepad 
belgesi olarak gönderilen kaynak kodlar değerlendirmeye alınmamaktadır. 
Sistem dışında gönderilen ödevler kabul edilmeyecektir.
Yazmış olduğunuz bütün kaynak kodların en başında aşağıdaki bilgiler 
bulunmalıdır. Bilgileri kendinize göre düzenleyiniz.
``` 
/*
@file Dosya adı
@description Programınızın açıklaması ne yaptığına dair.
@assignment Kaçıncı ödev olduğu
@date Kodu oluşturduğunuz Tarih
@author yazar adı ve mail adresi
*/ 
```