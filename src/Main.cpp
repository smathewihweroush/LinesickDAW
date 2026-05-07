/*
Linesick: free and modern Digital Audio Workspace for electronic music
Copyright (C) 2026 smathewih

This file is part of Linesick.

Linesick is free software: you can redistribute it and/or modify it under the terms of the 
GNU General Public License as published by the Free Software Foundation, either 
version 3 of the License, or (at your option) any later version.

Linesick is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Linesick. 
If not, see <https://www.gnu.org/licenses/>. 
*/

#include <RtAudio.h>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <numbers>

using namespace std;

typedef int16_t Samplet;

double bpm = 120.0;
int lastbeat = -1;
string sequence = "1";
const double scaletosint = 32767.0;
double phase = 0, freq = 440;
double samplerate = 48000;
unsigned int buffer;

int audioCall(void *outputBuffer, void *inputBuffer, unsigned int nFrames, double streamTime, RtAudioStreamStatus status, void *userData) {
    extern int lastbeat;
    Samplet* samplet = (Samplet*) outputBuffer;
    if (status) {
        cout << "Stream underflow detected!" << endl;
    }
    int i, j;
    double time = streamTime, gate = 0.0;
    double beattime = 60.0 / bpm, prep = 0.0;
    int beat = floor(time / beattime);
    Samplet fin;
    //cout << beat << endl;
    for (i = 0; i < nFrames; i++) {
        time += 1.0 / samplerate;
        beat = floor(time / beattime);
        if (lastbeat != beat) {
            lastbeat = beat;
            fin = 15000;
        } else {
            gate = 1;
            if (sequence[beat % sequence.size()] == '0') gate = 0;
            prep = sin(time * freq * std::numbers::pi_v<double> * 2.0) * 0.1 * gate;
            fin = (Samplet)(prep * scaletosint);
        }
        for (j = 0; j < 2; j++) {
            *samplet = fin;
            samplet++;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "The program requires two arguments!\n";
        return EXIT_FAILURE;
    }
    bpm = stod(string(argv[1]));
    sequence = argv[2];

    RtAudio rta(RtAudio::UNIX_JACK);
    cout << rta.getCurrentApi() << endl;
    rta.showWarnings(true);
    RtAudio::StreamParameters stream;
    stream.deviceId = rta.getDefaultOutputDevice();
    stream.nChannels = 2;

    rta.openStream(&stream, NULL, RTAUDIO_SINT16, rta.getDeviceInfo(stream.deviceId).preferredSampleRate, &buffer, audioCall);
    if (!rta.isStreamOpen()) {
        cerr << "Error: Could not open stream.\n";
        return EXIT_FAILURE;
    }
    cout << "Successfully opened audio stream!\n" << endl;
    cout << "Stream has properties; \n"
        << "Sample rate: " << rta.getStreamSampleRate() << '\n'
        << "Audio format: " << RTAUDIO_SINT16 << '\n'
        << "Device id: " << stream.deviceId << '\n'
        << "Numeber of output channels: " << stream.nChannels << '\n'
        << "Buffer size: " << buffer << '\n';
    samplerate = rta.getStreamSampleRate();
    rta.startStream();
    while (true) {
        usleep(10000);
    }
    rta.stopStream();
    rta.closeStream();
    // Hopefully I didn't miss something and there's a memory leak somewhere! Haha!

    return EXIT_SUCCESS;
}