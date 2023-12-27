
#   AudioIdentifier
> An algorithm for recognizing and fingerprinting audio files, implemented in C++.

## Table of Contents
* [General Info](#general-information)
* [Requirements](#requirements)
* [Screenshots](#screenshots)
* [Setup](#setup)
* [Project Status](#project-status)
* [Contribution](#contribution)
* [TODO](#todo)
* [Acknowledgements](#acknowledgements)


## General Information
AudioIdentifier is a C++ application designed for audio fingerprinting and recognition. Unlike traditional audio recognition systems, AudioIdentifier stands out by avoiding external libraries for fingerprinting, making it a self-contained solution. The project utilizes SFML for building a graphical user interface (UI), SQLite for efficient database management, and PortAudio for handling audio input.

## Requirements
- SFML
- SQLite
- PortAudio
- Cmake
## Screenshots
![UI](/images/UI.png)

## Setup
1.  **Clone the Repository:**
    ```bash
    git clone git@github.com:PlungedInCode/AudioIdentifier.git
    cd AudioIdentifier
    ``` 
2.  **Build the Project:**
    ```bash
    mkdir build && cd build
    cmake ..
    make
    ``` 
3. **Run project**
	```bash
	./AudioIdentifier 
	```

## Project Status
Project is: _in progress_ 

## Contribution

Feel free to contribute to AudioIdentifier by submitting issues or pull requests.

## TODO
- [ ] Optimize peak detection algorithm
- [ ] Optimize hashing and matching algorithms
- [ ] Extract metadata from `.wav` files
- [ ]  Better UI
- [ ] Concurrency
- [ ] Expand list of supported formats


## Thanks to
- [Audio Fingerprinting with Python and Numpy](https://willdrevo.com/fingerprinting-and-audio-recognition-with-python/)
- [abracadabra: How does Shazam work?](https://www.cameronmacleod.com/blog/how-does-shazam-work)
- Avery Wang: [An Industrial-Strength Audio Search Algorithm](https://www.ee.columbia.edu/~dpwe/papers/Wang03-shazam.pdf)
- [Audio Identification](https://www.audiolabs-erlangen.de/resources/MIR/FMP/C7/C7S1_AudioIdentification.html) by [Meinard Müller](https://www.audiolabs-erlangen.de/fau/professor/mueller) and [Patricio López-Serrano](https://www.audiolabs-erlangen.de/fau/assistant/lopez).
- [SpectroMap: Peak detection algorithm for audio fingerprinting](https://arxiv.org/abs/2211.00982)
