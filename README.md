# LiquidCrystalCur

LiquidCrystalCur - это надстройка над библиотекой LiquidCrystal (или LiquidCrystal_I2C), которая позволяет выводить кириллицу на дисплеи HD44780, которые русских букв не содержат.


## Ограничение

* На экране одновременно могут присутствовать только 7 разных букв, написания которых нет в латинице. 
* Строки в исходных файлах должны храниться в кодировке Windows 1251

## Использование

Всё, что нужно - включить нужную библиотеку перед этой и изменить имя создаваемого класса:

```cpp
#include <LiquidCrystal.h>
#include <LiquidCrystalCyr.h>

LiquidCrystalCyr lcd (1,2,3,4,5,6)
```

Или, при подключении по I2C:

```cpp
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystalCyr.h>

LiquidCrystalCyr lcd (0x27,20,4)
```
Дальше все полностью аналогично исходным библиотекам.
