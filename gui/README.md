# OpenSourceVentilatorGUI

GUI for RespiraWorks open source ventilator.

Build instructions go here

# Docker-based GUI deployment proposal

Using Docker will allow us to build, test, and deploy the same Qt-based code on both x86 and ARMv7 or ARMv8 64 bit. In fact, since Docker now supports ARM emulation (courtesy of Linux's binfmt extension) allowing us to built, test, and run the same Docker image on the Raspberry Pi and on a development machine.

## Docker build

Included is a Dockerfile based on Debian Buster for ARM64v8. It creates an image that contains all of the necessary Qt dependencies, builds the application, and runs the (trivial, at present) test script.

In order to build and run it, follow [this guide](https://www.docker.com/blog/getting-started-with-docker-for-arm-on-linux/) to enable ARM emulation (via binfmt+QEMU) for Docker on x86.

Once your local Docker supports building and running ARM-based images, you can simply run

    docker build -t twslankard/respiraworks .

to build, and 

    docker run -it twslankard/respiraworks /bin/bash

to run a shell from this image in a new docker container.

## Docker TODO

  * Run static analysis and unit testing.
  * Publish test coverage reports.
  * Use multi-stage Docker build or similar to exclude unnecessary build artifacts or other things needed for the build, but not required in production.
  * CI/CD pipeline publishes good builds to a repository.
