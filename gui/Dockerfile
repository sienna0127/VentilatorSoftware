FROM arm64v8/debian:buster

RUN apt-get update && \
    apt-get install -y \
    qt5-default \
    qtbase5-dev-tools \
    qtdeclarative5-dev \
    qtmultimedia5-dev \
    libqt5multimedia5-plugins \
    libqt5charts5-dev \
    qtquickcontrols2-5-dev \
    qml-module-qtquick-controls \
    qml-module-qtquick-controls2 \
    qml-module-qtcharts \
    qtdeclarative5-dev-tools \
    build-essential \
    xvfb

WORKDIR /home
COPY . .
RUN mkdir -p build
WORKDIR /home/build
RUN bash ../build_and_run_tests.sh
CMD ["bash"]
