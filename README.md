# Usage

## Get the project

Clone the project:

```
git clone https://github.com/Aaron-xx/lvgl_power.git
```

## Compile

```bash

cmake -B build -S .
make -C build -j

```

## Install SDL
You can download SDL from https://www.libsdl.org/

On on Linux you can install it via terminal:
```
sudo apt-get update && sudo apt-get install -y build-essential libsdl2-dev
```

# Docker
1. Build the docker container
```
docker build -t lvgl_simulator .
```
2. Run the docker container
```
docker run lvgl_simulator
```
GUI with docker is platform dependent. For example, on macOS you can follow
[this tutorial](https://cntnr.io/running-guis-with-docker-on-mac-os-x-a14df6a76efc)
and run a command similar to:
```
docker run -e DISPLAY=10.103.56.101:0 lvgl_simulator
```

For Linux environments with X Server, the following will the `docker run` command. Note that the first command, `xhost +` grants access to X server to everyone.

```
xhost +
docker run -e DISPLAY=$DISPLAY -v /tmp/.X11-unix/:/tmp/.X11-unix:ro -t lvgl_simulator
```
