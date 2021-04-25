
# Task 2


# Prerequire
   Docker comatible linux distro. (Ubuntu 20.04 - ok )


## Using docker 

 - install docker from  offical site https://docs.docker.com/engine/install/debian/
 - install docker-compuse tool https://docs.docker.com/compose/install/
 - add your user to docker group (to avoid sudo ): sudo usermod -aG docker $USER

 - choose option - 1)pull ready image or 2)build on your own:

### Option 1) Pull ready image from dockerhub
  run `./docker_pull.sh`

### Option 2) Build image form scratch
  run `./docker_build.sh`

### Start sandbox
  run `./docker_start.sh`

`
# Build
  after "Start sandbox"

  run `build.sh`

  or

  `mkdir build`

  `cd build`

  `cmake ../`

  `make`

# clean build  
  after "Start sandbox"

  run `clean.sh`


# Unit test
 - cd build
 - make test


    