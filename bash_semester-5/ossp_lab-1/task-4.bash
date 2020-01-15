#!/bin/bash

# Перемещение файлов, в имении которых содержится больше трех
# цифр, в другой подкаталог. Искомый каталог и каталог для
# перемещения передаются параметрами пакетному файлу.
# Перемещаемые файлы вывести.

mask='*[0-9]*[0-9]*[0-9]*'
find "$1" -name "${mask}"
find "$1" -name "${mask}" -print0 | xargs -0r mv -t "$2"