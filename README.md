# Tuatara: Deep Learning OCR Engine

### N.B. all credentials goes to [Jack Vial](https://github.com/jackvial) this repository is just the dockerization of his c++ ocr engine [tuatara](https://github.com/jackvial/tuatara) 

Tuatara is a deep learning based OCR engine built on [CRAFT](https://github.com/clovaai/CRAFT-pytorch) for text detection, and [PARSEQ](https://github.com/baudm/parseq) for text recognition. This project is mainly a way for me to explore and experiment with vision and NPL model performance.

This code is currently a work in progress and is not intended for production use.

The project is named after the [tuatara](https://en.wikipedia.org/wiki/Tuatara), a lizard-like ([rhynchocephalia](https://en.wikipedia.org/wiki/Rhynchocephalia)) reptile native to New Zealand. Like it's lizard cousin's the tuatara has a parietal eye/third eye, symbolic of prescient abilities.

## Design Goals
Easy to understand and hackable - All the main code is in tuatara.cpp and is currently about 500 LOC

## Build the project
#### It may be easier to work directly with visual code cf. [here](#Build-and-debug-through-visual-studio-code) but instructions to work from command line are also provided.
### Get the code source 
Clone the code in any working directory
```
git clone https://github.com/BBO-repo/cpp-ocr-engine.git /my/working/directory/tuatara
```
### Build the docker container
Build a docker image named for example `ocr_engine` from the `Dockerfile` inside the `/my/working/directory/tuatara` directory.<br>
For information, a `Dockerfile` step builds OpenCV from source which may take long time. On my machine it takes an hour and half. 
```
$ docker build --progress=plain -t ocr_engine /my/working/directory/tuatara
```
Build a container named for example `tuatara` from the `ocr_engine` generated image
```
$ docker create --name tuatara --mount type=bind,source=/my/working/directory/tuatara,target=/workspaces/ocr-c++/tuatara ocr_engine:latest
```
You can now start, stop or restart the generated `tuatara` container.<br>
From a terminal, enter the following command to start the container in interactive mode
```
$ docker container start tuatara
$ docker exec -ti tuatara bash
```
You should have a bash terminal inside the container, entering `pwd` and `ls` commands should output the following:
```
$ pwd
/workspaces/ocr-c++
$ ls
models  thirdparty  tuatara
```
To exit the container just enter exit in the container terminal prompt
```
$ exit
```
To stop the container, in a host command prompt enter
```
docker container stop tuatara
```

### Build the cor engnie with example application
Let now build the c++ ocr engine inside the container. Make sure the container is running

```
$ docker container start tuatara
```
Similarly to previously, get a terminal prompt inside the terminal
```
$ docker exec -ti tuatara bash
```
As usual with cmake project, go to source code folder `cd /workspaces/ocr-c++/tuatara`, make a folder `build` and go inside, then `cmake ..`
```
$ cd /workspaces/ocr-c++/tuatara
$ mkdir build
$ cd build
$ cmake ..
```
Finally build the project running `make`, if everything run correctly you should have something similar to the following ouput
```
$ make
[ 28%] Building CXX object libtuatara/CMakeFiles/tuatara.dir/src/libtuatara/utils.cpp.o
[ 28%] Building CXX object libtuatara/CMakeFiles/tuatara.dir/src/libtuatara/tuatara.cpp.o
[ 42%] Linking CXX shared library libtuatara.so
[ 42%] Built target tuatara
[ 71%] Building CXX object application/CMakeFiles/ocrize.dir/ocrize.cpp.o
[ 71%] Building CXX object bindings/CMakeFiles/pytuatara.dir/python.cpp.o
[ 85%] Linking CXX executable ocrize
[ 85%] Built target ocrize
[100%] Linking CXX shared module pytuatara.cpython-311-x86_64-linux-gnu.so
[100%] Built target pytuatara
```
You can run the example application with the following command run from the `build` directory
```
$ ./application/ocrize
```
You should see in the terminal all detected texts with the text box's coordinates in the image `application/test.png`.

### Build the tuatara ocr engine
Run the `tuatara` container and mount your `/my/working/directory/tuatara` folder as a volume to your container

### Build the container and the code with visual studio code
To build and run through visual studio code, make sure the remote development extension is installed. The repository provides a .devcontainer.json which should allow you to directly reopen the `/my/working/directory/tuatara` in a container