# Pushed to hub.docker.com, image jengelen/finitefield

FROM ubuntu:20.04

ENV TZ=Europe/Moscow
# needed for tz-data https://rtfm.co.ua/en/docker-configure-tzdata-and-timezone-during-build/
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update 

RUN apt-get install -y \
        wget

RUN apt-get install -y \
        build-essential \
        git \
        libgmp3-dev \
        libgtest-dev \
        libprocps-dev \
        libssl-dev \
        pkg-config 

RUN wget -O cmake-Linux-x86_64.sh https://cmake.org/files/v3.10/cmake-3.10.3-Linux-x86_64.sh \
    && sh ./cmake-Linux-x86_64.sh --prefix=/usr/local --skip-license \
    && cmake --version \
    && rm -f ./cmake-Linux-x86_64.sh

RUN apt-get install -y python-dev python3-dev
RUN apt-get install -y libpthread-stubs0-dev
RUN apt-get install -y libboost-all-dev
RUN apt-get install -y gdb
RUN apt-get install -y sudo

# create user developer
RUN useradd --create-home --shell /bin/bash --groups sudo developer
RUN echo 'developer ALL=(ALL) NOPASSWD:ALL' > /etc/sudoers

USER developer

#CMD [""]
#ENTRYPOINT [ '/bin/bash' ]
