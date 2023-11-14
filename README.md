# SoLong Projesi Anlatımı

<img src="https://github.com/bkarlida/Cub3d/blob/master/Screenshot%202023-10-25%20at%2001.11.26.png" width="500">

Bu proje, bir oyun motoru kullanarak basit bir 2D oyun yapmayı amaçlar. Bu projede, temel oyun döngüsü, grafik öğeler ve kullanıcı etkileşimleri yer alır.

## Proje Açıklaması

- "Solong" projesi, 2D bir oyun motorunu kullanarak bir oyun yapmayı hedefler.
- Projede, harita üzerinde karakterin hareket etmesi, nesnelerin toplanması ve belirli hedeflere ulaşılması gibi temel oyun mekanikleri bulunur.
- Oyunun grafikleri ve görüntüleri özelleştirilebilir.

## Ayağa Kaldırma Adımları

1. Öncelikle projenin kaynak kodlarını indirin.

2. İndirdiğiniz kaynak kodlarını bir dizine çıkarın.

3. Terminale gidin ve projenin ana dizinine gidin:

    ```bash
    cd /path/to/solong
    ```

4. Projeyi derlemek için aşağıdaki komutları kullanabilirsiniz:

    ```bash
    make
    ```

    Bu komut, projeyi derleyecek ve "solong" adlı bir yürütülebilir dosya oluşturacaktır.

5. Oyunu çalıştırmak için aşağıdaki komutu kullanabilirsiniz:

    ```bash
    ./solong maps/map.ber
    ```

    `maps/map.ber` yerine oynamak istediğiniz harita dosyasını belirtin.

6. Projeyi temizlemek için aşağıdaki komutu kullanabilirsiniz:

    ```bash
    make clean
    ```

    Bu komut, derleme sırasında oluşturulan geçici dosyaları temizler.

7. Projeyi sıfırlamak için aşağıdaki komutu kullanabilirsiniz:

    ```bash
    make fclean
    ```

    Bu komut, derleme sonrası oluşan dosyaları siler.
   
9. Projede boş klasör olursa ,aynı isimdeki dosyayı diğer repolardan çekebilirsiniz.

Bu adımları izleyerek "Solong" projesini derleyebilir ve oynayabilirsiniz.
