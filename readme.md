# Flappy Bird

## Autor: Vazgen Arutyunyan

---

## Obsah
- [Uživatelská dokumentace](#uživatelská-dokumentace)
- [Dokumentace pro vývojáře](#dokumentace-pro-vývojáře)

## Uživatelská dokumentace

### Úvod
Flappy Bird je jednoduchá arkádová hra, kde hráč ovládá ptáka, který musí proletět mezi překážkami. Hra byla vytvořena jako projekt pro výuku programování a zábavu.

### Instalace
1. Stáhněte si hru z oficiálního webu nebo repozitáře.
2. Rozbalte stažený soubor do požadovaného adresáře.
3. Spusťte soubor `FlappyBird.exe`.

### Ovládání
- **Mezerník**: Pták vzlétne.
- **R**: Restart hry.
- **C**: Aktivace "Collider módu" (režim bez kolizí).
- **Esc**: Ukončení hry.

### Pravidla hry
Cílem hry je proletět co nejdále mezi překážkami, aniž byste do nich narazili. Každá překonaná překážka přidává jeden bod k vašemu skóre.

### Odměny
Hráč může získat následující medaile na základě dosaženého skóre:
- **Bronzová medaile**: 10 bodů.
- **Stříbrná medaile**: 15 bodů.
- **Zlatá medaile**: 25 bodů.
- **Platinová medaile**: 50 bodů.

---

## Dokumentace pro vývojáře

### Úvod
Tento projekt je implementací hry Flappy Bird. Kód je napsán v C++ a používá knihovnu Raylib pro grafiku a zvuk. Projekt je strukturován pro snadnou rozšiřitelnost a údržbu.

### Struktura projektu
Projekt je organizován do následujících složek:

- `src/`: Zdrojové soubory hry.
  - `game.cpp`, `game.hpp`: Hlavní logika hry.
  - `bird.cpp`, `bird.hpp`: Implementace ptáka.
  - `pipe.cpp`, `pipe.hpp`: Implementace překážek.
  - `logger.cpp`, `logger.hpp`: Systém logování.
  - `app_sound.cpp`, `app_sound.hpp`: Zvukové efekty.
  - `consts.cpp`, `consts.hpp`: Konstanty a konfigurace hry.
  - `controllers/`: Řadiče pro různé herní objekty.
    - `pipe_controller.cpp`, `pipe_controller.hpp`: Řadič překážek.
    - `sky_controller.cpp`, `sky_controller.hpp`: Řadič oblohy.
  - `models/`: Modely herních objektů.
    - `entity.cpp`, `entity.hpp`: Základní třída pro všechny herní objekty.
    - `dash_board.cpp`, `dash_board.hpp`: Implementace palubní desky.
- `tests/`: Jednotkové testy.
  - `game_test.cpp`: Testy pro hlavní logiku hry.
  - `bird_test.cpp`: Testy pro ptáka.
  - `pipe_test.cpp`: Testy pro překážky.
  - `test_constants.hpp`, `test_constants.cpp`: Konstanty a pomocné funkce pro testy.
- `assets/`: Soubory s obrázky a zvuky.
- `src/include/`: Obsahuje všechny hlavičkové soubory projektu.

### Závislosti
- [Raylib](https://www.raylib.com/): Knihovna pro grafiku a zvuk.
- [Google Test](https://github.com/google/googletest): Knihovna pro jednotkové testy.

#### Instalace Raylib
Pokud nemáte nainstalovanou knihovnu Raylib, můžete ji nainstalovat pomocí MinGW:

```sh
pacman -S mingw-w64-x86_64-raylib
```

### Kompilace a spuštění
1. Ujistěte se, že máte nainstalované všechny závislosti.
2. Vytvořte adresář pro build:

```sh
mkdir build
cd build
```

3. Spusťte CMake:
```sh
cmake ..
```

4. Zkompilujte projekt:
```sh
cmake --build .
```

5. Spusťte hru:
```sh
./FlappyBird
```