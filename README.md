# Som Always Cleaner

Программа для удаления файлов в папке, с определённым периодом

## Пример использование

1. Создайте .bat файл в папке с исполняемым файлом SomAlwaysCleaner.exe
2. Введите в .bat файл строчку ниже

```batch
SomAlwaysCleaner "Папка для удаления" 0 0 7
```
				^              ^
				|              |
			Путь к папке      Период(год, месяц, день)

3. Запускайте .bat файл для запуска

### Заметки

*Не чистит "нулевые" файлы*
