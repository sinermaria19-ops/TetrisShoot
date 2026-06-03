# Descargar repositorio

En una terminal (como la de VSCode), dirigirse a la carpeta donde se quiera descargar el repositorio y ejecutar:

```bash
git clone https://github.com/matias-bulacio/SnakeGame.git
```

# Configurar creación

Para cada posible plataforma de destino, debe modificar su compilador en el Makefile

En las primeras líneas del Makefile, encontrará las siguientes variables.

```Makefile
LINUX_CC=gcc
WINDOWS_CC=x86_64-w64-mingw32-gcc
WEB_CC=/usr/lib/emscripten/emcc
```

Si su compilador para la plataforma correspondiente es diferente al especificado después del igual, modifíquelo.
Si alguna variable esté vacía, no podrá compilar para esa plataforma en su máquina.

Para compilar para una plataforma, ejecutar `make PLATAFORMA`

Por ejemplo:
```bash
make linux
make windows
make web
```

> [!NOTE]
> Solo si se tiene la variable para la plataforma correspondiente definida se debe compilar

